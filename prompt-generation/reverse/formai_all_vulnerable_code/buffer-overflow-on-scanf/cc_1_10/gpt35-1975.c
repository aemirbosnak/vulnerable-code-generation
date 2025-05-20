//FormAI DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    int id;
    float cgpa;
} Student;

void insertStudent(Student *students, int *count) {
    printf("Enter name: ");
    scanf("%s", students[*count].name);
    printf("Enter id: ");
    scanf("%d", &students[*count].id);
    printf("Enter cgpa: ");
    scanf("%f", &students[*count].cgpa);
    (*count)++;
    printf("Student added successfully!\n\n");
}

void searchStudent(Student *students, int count) {
    int id;
    printf("Enter id to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Name: %s\n", students[i].name);
            printf("ID: %d\n", students[i].id);
            printf("CGPA: %.2f\n\n", students[i].cgpa);
            return;
        }
    }
    printf("Student not found!\n\n");
}

void printAllStudents(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", students[i].name);
        printf("ID: %d\n", students[i].id);
        printf("CGPA: %.2f\n\n", students[i].cgpa);
    }
}

int main() {
    int count = 0;
    Student students[100];
    int choice;
    while (1) {
        printf("1. Insert student\n2. Search student\n3. Print all students\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertStudent(students, &count);
                break;
            case 2:
                searchStudent(students, count);
                break;
            case 3:
                printAllStudents(students, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n\n");
        }
    }
    return 0;
}