//FormAI DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    float gpa;
};

int main() {
    struct Student students[100];
    int numStudents = 0;
    int option = 0;

    while (option != 5) {
        printf("Welcome to the Student Database Simulator 3000!\n");
        printf("1. Add a student\n");
        printf("2. Search for a student\n");
        printf("3. Print all students\n");
        printf("4. Update a student's GPA\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &students[numStudents].id);
                printf("Enter student name: ");
                scanf("%s", students[numStudents].name);
                printf("Enter student age: ");
                scanf("%d", &students[numStudents].age);
                printf("Enter student GPA: ");
                scanf("%f", &students[numStudents].gpa);
                numStudents++;
                printf("Student added successfully!\n\n");
                break;
            case 2:
                printf("Enter student ID: ");
                int searchID;
                scanf("%d", &searchID);
                for (int i = 0; i < numStudents; i++) {
                    if (students[i].id == searchID) {
                        printf("Name: %s\n", students[i].name);
                        printf("Age: %d\n", students[i].age);
                        printf("GPA: %.2f\n\n", students[i].gpa);
                        break;
                    }
                    if (i == numStudents-1) {
                        printf("Student not found!\n\n");
                    }
                }
                break;
            case 3:
                printf("All students:\n");
                for (int i = 0; i < numStudents; i++) {
                    printf("%d. %s (ID: %d, Age: %d, GPA: %.2f)\n", i+1, students[i].name, students[i].id, students[i].age, students[i].gpa);
                }
                printf("\n");
                break;
            case 4:
                printf("Enter student ID: ");
                int updateID;
                scanf("%d", &updateID);
                for (int i = 0; i < numStudents; i++) {
                    if (students[i].id == updateID) {
                        printf("Enter new GPA: ");
                        scanf("%f", &students[i].gpa);
                        printf("GPA updated successfully!\n\n");
                        break;
                    }
                    if (i == numStudents-1) {
                        printf("Student not found!\n\n");
                    }
                }
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n\n");
                break;
        }
    }

    return 0;
}