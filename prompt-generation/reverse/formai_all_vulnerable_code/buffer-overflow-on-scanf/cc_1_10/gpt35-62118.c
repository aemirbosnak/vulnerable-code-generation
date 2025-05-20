//FormAI DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define MAX_GRADE_LENGTH 3
#define MAX_STUDENTS 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    char grade[MAX_GRADE_LENGTH];
} Student;

void print_students(Student students[], int num_students) {
    printf("\n\t-----------------------------\n");
    printf("\t|  Name\t   |  ID\t| Grade |\n");
    printf("\t-----------------------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("\t| %s\t| %d\t|   %s  |\n", students[i].name, students[i].id, students[i].grade);
        printf("\t-----------------------------\n");
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int num_students = 0;

    int choice = 0;
    while (choice != 4) {
        printf("\n1. Add Student\n2. Remove Student\n3. Print All Students\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_students >= MAX_STUDENTS) {
                printf("Error: Maximum number of students reached.\n");
                continue;
            }
            Student s;
            printf("Name: ");
            scanf("%s", s.name);
            printf("ID: ");
            scanf("%d", &s.id);
            printf("Grade: ");
            scanf("%s", s.grade);
            students[num_students++] = s;
        } else if (choice == 2) {
            if (num_students == 0) {
                printf("Error: No students to remove.\n");
                continue;
            }
            int id;
            printf("Enter ID of student to remove: ");
            scanf("%d", &id);
            int found = 0;
            for (int i = 0; i < num_students; i++) {
                if (students[i].id == id) {
                    found = 1;
                    for (int j = i; j < num_students-1; j++) {
                        students[j] = students[j+1];
                    }
                    num_students--;
                    break;
                }
            }
            if (!found) {
                printf("Error: Student with ID %d not found.\n", id);
            }
        } else if (choice == 3) {
            if (num_students == 0) {
                printf("Error: No students to print.\n");
                continue;
            }
            print_students(students, num_students);
        } else if (choice == 4) {
            printf("Goodbye!\n");
        } else {
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}