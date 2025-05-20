//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 255
#define MAX_AGE 100
#define MAX_GPA 4.0

// Structure to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    double gpa;
} student_t;

// Function to print a menu for the user to input student information
void print_menu() {
    printf("Welcome to the student information program!\n");
    printf("Please enter the following information for each student:\n");
    printf("Name (up to %d characters): ", MAX_NAME_LENGTH);
    printf("Age: ");
    printf("GPA (on scale of 1.0 to %f): ", MAX_GPA);
    printf("\n");
}

// Function to input student information and validate user input
student_t get_student_info() {
    student_t student;
    printf("Enter student name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[MAX_NAME_LENGTH - 1] = '\0'; // Truncate input to MAX_NAME_LENGTH characters
    printf("Enter age: ");
    scanf("%d", &student.age);
    printf("Enter GPA: ");
    scanf("%lf", &student.gpa);
    return student;
}

// Function to print student information in a creative way
void print_student(student_t student) {
    printf("Student: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("GPA: %lf\n", student.gpa);
    printf("-----------+\n");
    printf("        /_/\n");
    printf("      ( o.o )\n");
    printf("      > ^ <\n");
    printf("      /       \n");
    printf("     (_____)\n");
    printf("      /     \n");
    printf("     (_____)\n");
    printf("      \  ^__^ \n");
    printf("        /  \\");
}

int main() {
    srand(time(NULL)); // Seed the random number generator for reproducible output

    // Create an array to store student information
    student_t students[5];

    // Loop to input and store student information
    for (int i = 0; i < 5; i++) {
        student_t student = get_student_info();
        students[i] = student;
    }

    // Print student information in a creative way
    for (int i = 0; i < 5; i++) {
        print_student(students[i]);
    }

    return 0;
}