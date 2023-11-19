#include <iostream>
#include <vector>
using namespace std;
class Student {
public:
    string name;
    int grade;

    Student(const std::string& n, int g) : name(n), grade(g) {}
};

class StudentList {
private:
    vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    std::vector<Student> getStudentsWithGrade(int targetGrade) const {
        std::vector<Student> result;

        for (const auto& student : students) {
            if (student.grade == targetGrade) {
                result.push_back(student);
            }
        }

        return result;
    }
};

int main() {
    // Example usage:
    // Create some students
    Student student1("Alice", 5);
    Student student2("Bob", 4);
    Student student3("Charlie", 5);

    // Create a StudentList
    StudentList studentList;

    // Add students to the list
    studentList.addStudent(student1);
    studentList.addStudent(student2);
    studentList.addStudent(student3);

    // Get students with grade 5
    vector<Student> studentsWithGrade5 = studentList.getStudentsWithGrade(5);

    // Print the result
    if (studentsWithGrade5.empty()) {
        cout << "No students with grade 5 found." << std::endl;
    }
    else {
        cout << "Students with grade 5:" << std::endl;
        for (const auto& student : studentsWithGrade5) {
            cout << "Name: " << student.name << ", Grade: " << student.grade << std::endl;
        }
    }

    return 0;
}
