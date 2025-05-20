//FormAI DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student { // Define a struct to store student data
    char name[50];
    int id;
    float gpa;
};

int main() {

    int numStudents = 0; // Initialize number of students to 0
    struct Student *students = NULL; // Initialize pointer to Store student data

    while (1) { // Loop indefinitely until the user quits
        printf("Enter a command (a for add, p for print, q for quit): ");
        char command;
        scanf(" %c", &command);

        if (command == 'a') { // Add a student
            numStudents++;
            students = realloc(students, sizeof(struct Student) * numStudents); // Resize memory space to store more students
            printf("Enter the student's name: ");
            scanf("%s", students[numStudents-1].name);
            printf("Enter the student's ID: ");
            scanf("%d", &students[numStudents-1].id);
            printf("Enter the student's GPA: ");
            scanf("%f", &students[numStudents-1].gpa);
        } 
        else if (command == 'p') { // Print all students
            for (int i = 0; i < numStudents; i++) {
                printf("Student %d\n", i+1);
                printf("Name: %s\n", students[i].name);
                printf("ID: %d\n", students[i].id);
                printf("GPA: %.2f\n\n", students[i].gpa);
            }
        } 
        else if (command == 'q') { // Quit the program
            free(students); // Free memory allocated to students
            students = NULL; // Set pointer to NULL to avoid dangling pointers
            break;
        } 
        else { // Invalid command
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}