//FormAI DATASET v1.0 Category: Database simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store student information
typedef struct {
    int id;
    char name[20];
    int math;
    int english;
} Student;

// Declare functions
void add_student(Student *students, int *num_students);
void remove_student(Student *students, int *num_students);
void print_student(Student student);
void print_all_students(Student *students, int num_students);

int main() {
    int choice, num_students = 0;
    Student students[50];

    do {
        // Display menu and get user input
        printf("\n1. Add a student\n2. Remove a student\n3. Print all students\n4. Quit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_student(students, &num_students);
                break;
            case 2:
                remove_student(students, &num_students);
                break;
            case 3:
                print_all_students(students, num_students);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void add_student(Student *students, int *num_students) {
    // Make sure there is space in the array
    if(*num_students == 50) {
        printf("Error: database is full\n");
        return;
    }

    // Get input from user and assign to new student struct
    Student new_student;
    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student name: ");
    scanf("%s", new_student.name);
    printf("Enter math grade: ");
    scanf("%d", &new_student.math);
    printf("Enter english grade: ");
    scanf("%d", &new_student.english);

    // Add new student to array and increment number of students
    students[*num_students] = new_student;
    *num_students += 1;

    printf("Student added successfully\n");
}

void remove_student(Student *students, int *num_students) {
    int id, index = -1;

    // Get ID of student to remove
    printf("Enter ID of student to remove: ");
    scanf("%d", &id);

    // Find index of student with matching ID
    for(int i=0; i<*num_students; i++) {
        if(students[i].id == id) {
            index = i;
            break;
        }
    }

    // If student is not found, print error message and return
    if(index == -1) {
        printf("Error: student with ID %d not found\n", id);
        return;
    }

    // Shift elements of array to remove student
    for(int i=index; i<*num_students-1; i++) {
        students[i] = students[i+1];
    }

    // Decrement number of students
    *num_students -= 1;

    printf("Student with ID %d removed successfully\n", id);
}

void print_student(Student student) {
    printf("ID: %d\nName: %s\nMath Grade: %d\nEnglish Grade: %d\n\n", student.id, student.name, student.math, student.english);
}

void print_all_students(Student *students, int num_students) {
    // Print header
    printf("\nDatabase: %d Students\n\n", num_students);

    // Loop through array and print each student
    for(int i=0; i<num_students; i++) {
        print_student(students[i]);
    }
}