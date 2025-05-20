//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct student {
    char name[50];
    int roll_no;
    float marks;
};

// Function to add a student to the database
void add_student(struct student *students, int *size) {
    // Ask for student name
    printf("Enter student name: ");
    fgets(students[*size].name, 50, stdin);

    // Ask for roll number
    printf("Enter roll number: ");
    scanf("%d", &students[*size].roll_no);

    // Ask for marks
    printf("Enter marks: ");
    scanf("%f", &students[*size].marks);

    // Increment size
    *size += 1;
}

// Function to display student information
void display_student(struct student *students, int size) {
    // Iterate over all students
    for (int i = 0; i < size; i++) {
        // Print student information
        printf("Student name: %s\n", students[i].name);
        printf("Roll number: %d\n", students[i].roll_no);
        printf("Marks: %f\n", students[i].marks);
    }
}

int main() {
    // Initialize size to 0
    int size = 0;

    // Initialize array of students
    struct student students[100];

    // Add students to the database
    add_student(students, &size);
    add_student(students, &size);
    add_student(students, &size);

    // Display student information
    display_student(students, size);

    return 0;
}