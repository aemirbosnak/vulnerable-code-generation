//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: calm
/*
 * Unique C Database Querying Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to represent a student
struct student {
    char name[50];
    int age;
    char grade;
};

// Function to add a student to the database
void add_student(struct student *students, int *num_students) {
    // Prompt the user for input
    char name[50];
    int age;
    char grade;
    printf("Enter the student's name: ");
    scanf("%s", name);
    printf("Enter the student's age: ");
    scanf("%d", &age);
    printf("Enter the student's grade: ");
    scanf(" %c", &grade);

    // Add the student to the database
    struct student new_student;
    strcpy(new_student.name, name);
    new_student.age = age;
    new_student.grade = grade;
    students[*num_students] = new_student;
    *num_students += 1;
}

// Function to search for a student in the database
int search_student(struct student *students, int num_students, char *name) {
    // Loop through the database and compare the name of each student
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;
        }
    }

    // If the student was not found, return -1
    return -1;
}

// Function to print the details of a student
void print_student(struct student *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Grade: %c\n", student->grade);
}

int main() {
    // Initialize the database
    struct student students[100];
    int num_students = 0;

    // Add some students to the database
    add_student(students, &num_students);
    add_student(students, &num_students);
    add_student(students, &num_students);

    // Search for a student in the database
    char name[50];
    printf("Enter the name of the student you want to search for: ");
    scanf("%s", name);
    int index = search_student(students, num_students, name);

    // Print the details of the student if found, otherwise print an error message
    if (index != -1) {
        print_student(&students[index]);
    } else {
        printf("Student not found\n");
    }

    return 0;
}