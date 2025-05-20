//FormAI DATASET v1.0 Category: Scientific ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[40];
    int id;
    float gpa;
} Student;

// function to display student information
void displayStudentInfo(Student *s) {
    printf("Name: %s\nID: %d\nGPA: %.2f\n", s->name, s->id, s->gpa);
}

int main() {
    int choice;
    Student *students = NULL;
    int numStudents = 0;

    while(1) {
        printf("Menu:\n1. Add Student\n2. Display Student Information\n3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            numStudents++;
            students = (Student*)realloc(students, numStudents * sizeof(Student));
            printf("Enter student name: ");
            scanf("%s", students[numStudents-1].name);
            printf("Enter student ID: ");
            scanf("%d", &students[numStudents-1].id);
            printf("Enter student GPA: ");
            scanf("%f", &students[numStudents-1].gpa);
        }
        else if (choice == 2) {
            printf("Enter student ID to display information: ");
            int searchId;
            scanf("%d", &searchId);
            int found = 0;
            for (int i = 0; i < numStudents; i++) {
                if (students[i].id == searchId) {
                    displayStudentInfo(&students[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Student not found with the provided ID.\n");
            }
        }
        else if (choice == 3) {
            free(students);
            break;
        }
        else {
            printf("Invalid Choice. Try Again.\n");
        }
    }

    return 0;
}