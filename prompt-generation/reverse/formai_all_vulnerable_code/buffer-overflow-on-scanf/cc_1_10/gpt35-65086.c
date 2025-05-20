//FormAI DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char firstName[50];
    char lastName[50];
    int grade;
} Student;

int main() {
    int choice, numStudents = 0;
    Student *students = NULL;

    printf("Welcome to the Student Grade Database!\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Add a student grade\n");
        printf("2. Display all students and their grades\n");
        printf("3. Search for a student and their grade\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                numStudents++;
                students = realloc(students, numStudents * sizeof(Student));
                printf("\nEnter the student's first name: ");
                scanf("%s", students[numStudents-1].firstName);
                printf("Enter the student's last name: ");
                scanf("%s", students[numStudents-1].lastName);
                printf("Enter the student's grade: ");
                scanf("%d", &students[numStudents-1].grade);
                break;
            case 2:
                printf("\nStudent Grade Database:\n");
                for (int i = 0; i < numStudents; i++) {
                    printf("%s %s: %d\n", students[i].firstName, students[i].lastName, students[i].grade);
                }
                break;
            case 3:
                printf("\nEnter the student's first name: ");
                char searchFirst[50];
                scanf("%s", searchFirst);
                printf("Enter the student's last name: ");
                char searchLast[50];
                scanf("%s", searchLast);
                for (int i = 0; i < numStudents; i++) {
                    if (strcmp(students[i].firstName, searchFirst) == 0 && strcmp(students[i].lastName, searchLast) == 0) {
                        printf("%s %s: %d\n", students[i].firstName, students[i].lastName, students[i].grade);
                        break;
                    }
                }
                break;
            case 4:
                printf("\nGoodbye!\n");
                free(students);
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
}