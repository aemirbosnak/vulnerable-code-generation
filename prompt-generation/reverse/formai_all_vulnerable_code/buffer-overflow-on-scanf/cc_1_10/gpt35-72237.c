//FormAI DATASET v1.0 Category: File handling ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int id;
    float gpa;
};

void add_student() {
    struct student stu;

    printf("Enter student name: ");
    scanf("%s", stu.name);

    printf("Enter student ID: ");
    scanf("%d", &stu.id);

    printf("Enter student GPA: ");
    scanf("%f", &stu.gpa);

    FILE *fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }

    fprintf(fp, "%s\t%d\t%.2f\n", stu.name, stu.id, stu.gpa);

    printf("Student added to file successfully. \n");

    fclose(fp);
}

void list_students() {
    printf("\n");
    printf("Student Name\tStudent ID\tGPA\n");

    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }

    struct student stu;
    while(fscanf(fp, "%s%d%f", stu.name, &stu.id, &stu.gpa) == 3) {
        printf("%s\t\t%d\t\t%.2f\n", stu.name, stu.id, stu.gpa);
    }

    fclose(fp);
}

void search_student() {
    int id;
    printf("Enter the ID of the student you want to search: ");
    scanf("%d", &id);

    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!");
        return;
    }

    struct student stu;
    int found = 0;
    while(fscanf(fp, "%s%d%f", stu.name, &stu.id, &stu.gpa) == 3) {
        if (stu.id == id) {
            printf("Student found: \n");
            printf("Name: %s\n", stu.name);
            printf("ID: %d\n", stu.id);
            printf("GPA: %.2f\n", stu.gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found. \n", id);
    }

    fclose(fp);
}

int main() {
    printf("Welcome to Student Record Management System. \n");
    printf("Please enter a number from the following options: \n");
    printf("1. Add student to the record. \n");
    printf("2. List all students on the record. \n");
    printf("3. Search for a student in the record. \n");
    printf("4. Exit. \n");

    int choice;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                list_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                printf("Thank you for using Student Record Management System. \n");
                return 0;
            default:
                printf("Invalid choice. Please try again. \n");
        }
    } while (1);

    return 0;
}