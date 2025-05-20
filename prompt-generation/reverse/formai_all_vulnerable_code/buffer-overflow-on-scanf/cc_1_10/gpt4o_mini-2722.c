//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple structure to hold student data
typedef struct {
    int id;
    char name[50];
} Student;

// Function to print student details
void printStudentDetails(Student *student) {
    if (student != NULL) {
        printf("Student ID: %d\n", student->id);
        printf("Student Name: %s\n", student->name);
    } else {
        printf("Invalid student reference!\n");
    }
}

// Function to create a new student
Student* createStudent(int id, const char* name) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory cannot be allocated
    }
    
    newStudent->id = id;
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0'; // Ensuring null-termination
    return newStudent;
}

// Function to delete a student and free memory
void deleteStudent(Student* student) {
    if (student != NULL) {
        free(student);
        student = NULL; // Avoid dangling pointer
        printf("Student successfully deleted.\n");
    } else {
        printf("No student to delete!\n");
    }
}

// Function to demonstrate dynamic array of students
void dynamicStudentArrayDemo(int numberOfStudents) {
    // Create an array of pointers to Student structs
    Student** studentArray = (Student**)malloc(numberOfStudents * sizeof(Student*));
    
    if (studentArray == NULL) {
        printf("Memory allocation for student array failed!\n");
        exit(1);
    }
    
    // Populate the student array with student data
    for (int i = 0; i < numberOfStudents; i++) {
        char name[50];
        printf("Enter name for student %d: ", i + 1);
        scanf("%49s", name); // Safe input for name
        studentArray[i] = createStudent(i + 1, name);
    }

    // Print details of all students
    printf("\nDetails of Students:\n");
    for (int i = 0; i < numberOfStudents; i++) {
        printStudentDetails(studentArray[i]);
    }
    
    // Cleanup: Delete all students and free the array
    for (int i = 0; i < numberOfStudents; i++) {
        deleteStudent(studentArray[i]);
    }
    
    free(studentArray); // Free the array of pointers
}

// Main function to run the program
int main() {
    int numberOfStudents;

    printf("How many students do you want to input? ");
    scanf("%d", &numberOfStudents);
    
    if (numberOfStudents <= 0) {
        printf("Please enter a positive integer for number of students.\n");
        return 1; // Exit program
    }

    dynamicStudentArrayDemo(numberOfStudents);
    
    return 0; // Successful execution
}