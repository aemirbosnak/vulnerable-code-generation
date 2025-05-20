//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store student information
typedef struct Student {
    char name[50];
    int roll_no;
    float marks;
} Student;

// Function to insert a student into the database
void insert_student(Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter student roll number: ");
    scanf("%d", &student->roll_no);

    printf("Enter student marks: ");
    scanf("%f", &student->marks);
}

// Function to search for a student in the database
Student *search_student(Student *students, int num_students, int roll_no) {
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_no == roll_no) {
            return &students[i];
        }
    }

    return NULL;
}

// Function to update student marks
void update_marks(Student *student) {
    printf("Enter new student marks: ");
    scanf("%f", &student->marks);
}

// Function to delete a student from the database
void delete_student(Student *students, int num_students, int roll_no) {
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_no == roll_no) {
            students[i] = students[num_students - 1];
            num_students--;
            break;
        }
    }
}

int main() {
    // Create an array of students
    Student students[100];

    // Initialize the number of students
    int num_students = 0;

    // Insert a student into the database
    insert_student(&students[num_students]);
    num_students++;

    // Search for a student in the database
    Student *student = search_student(students, num_students, 12);

    // Update student marks
    if (student) {
        update_marks(student);
    }

    // Delete a student from the database
    delete_student(students, num_students, 12);

    // Print the updated student list
    for (int i = 0; i < num_students; i++) {
        printf("%s, %d, %f\n", students[i].name, students[i].roll_no, students[i].marks);
    }

    return 0;
}