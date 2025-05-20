//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: unmistakable
// Example program to illustrate memory management in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a student
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Function to create a new student
Student* create_student(char* name, int age, float gpa) {
    Student* student = malloc(sizeof(Student));
    strcpy(student->name, name);
    student->age = age;
    student->gpa = gpa;
    return student;
}

// Function to print a student
void print_student(Student* student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("GPA: %f\n", student->gpa);
}

// Function to delete a student
void delete_student(Student* student) {
    free(student);
}

// Main function to test the program
int main() {
    // Create a student
    Student* student = create_student("John", 25, 3.5);

    // Print the student
    print_student(student);

    // Delete the student
    delete_student(student);

    // Check if the student was successfully deleted
    if (student == NULL) {
        printf("Student deleted successfully.\n");
    } else {
        printf("Error deleting student.\n");
    }

    return 0;
}