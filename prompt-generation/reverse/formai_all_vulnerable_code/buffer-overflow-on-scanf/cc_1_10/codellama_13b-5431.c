//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: Ken Thompson
// Ken Thompson-style C Online Examination System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store student information
struct Student {
    char name[100];
    int roll_no;
    int score;
};

// Function to add a new student to the system
void add_student(struct Student* students, int* num_students) {
    printf("Enter the student's name: ");
    scanf("%s", students[*num_students].name);
    printf("Enter the student's roll number: ");
    scanf("%d", &students[*num_students].roll_no);
    printf("Enter the student's score: ");
    scanf("%d", &students[*num_students].score);
    *num_students += 1;
}

// Function to display the student information
void display_student(struct Student student) {
    printf("Name: %s\n", student.name);
    printf("Roll Number: %d\n", student.roll_no);
    printf("Score: %d\n", student.score);
}

// Function to sort the student information
void sort_students(struct Student* students, int num_students) {
    int i, j;
    struct Student temp;
    for (i = 0; i < num_students - 1; i++) {
        for (j = i + 1; j < num_students; j++) {
            if (students[i].score < students[j].score) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to search for a student by name
void search_student(struct Student* students, int num_students, char* name) {
    int i;
    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found: ");
            display_student(students[i]);
            return;
        }
    }
    printf("Student not found.\n");
}

// Function to display all the students
void display_all_students(struct Student* students, int num_students) {
    int i;
    for (i = 0; i < num_students; i++) {
        display_student(students[i]);
    }
}

// Function to display the highest scoring student
void display_highest_scoring(struct Student* students, int num_students) {
    int i;
    int highest_score = 0;
    char* highest_name = NULL;
    for (i = 0; i < num_students; i++) {
        if (students[i].score > highest_score) {
            highest_score = students[i].score;
            highest_name = students[i].name;
        }
    }
    printf("The highest scoring student is %s with a score of %d.\n", highest_name, highest_score);
}

// Main function
int main() {
    // Initialize variables
    struct Student* students = NULL;
    int num_students = 0;
    char name[100];
    char choice;

    // Loop until the user exits
    while (1) {
        // Display the menu
        printf("Menu:\n");
        printf("a) Add a new student\n");
        printf("b) Display all students\n");
        printf("c) Search for a student\n");
        printf("d) Display the highest scoring student\n");
        printf("e) Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        // Perform the selected action
        switch (choice) {
            case 'a':
                add_student(students, &num_students);
                break;
            case 'b':
                display_all_students(students, num_students);
                break;
            case 'c':
                printf("Enter the student's name: ");
                scanf("%s", name);
                search_student(students, num_students, name);
                break;
            case 'd':
                display_highest_scoring(students, num_students);
                break;
            case 'e':
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}