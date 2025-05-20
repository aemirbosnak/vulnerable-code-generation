//FormAI DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct student {
    char name[20];
    int id;
    float gpa;
};

void readStudent(struct student*, int);
void newStudent(struct student*, int*);
void displayStudents(struct student*, int);
void searchStudents(struct student*, int);
void updateGPA(struct student*, int);

int main() {
    struct student database[MAX_SIZE];

    int num_students = 0;

    while (1) {
        printf("\n***DATABASE MENU***\n");
        printf("1. Add a new student\n");
        printf("2. Display all students\n");
        printf("3. Search for a student by ID\n");
        printf("4. Update a student's GPA\n");
        printf("5. Exit\n");
        printf("\nEnter your option: ");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                newStudent(database, &num_students);
                break;
            case 2:
                displayStudents(database, num_students);
                break;
            case 3:
                searchStudents(database, num_students);
                break;
            case 4:
                updateGPA(database, num_students);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option!");
        }
    }

    return 0;
}

void readStudent(struct student* s, int index) {
    printf("\nEnter details of student %d:\n", index+1);
    printf("Name: ");
    scanf("%s", s[index].name);
    printf("ID: ");
    scanf("%d", &s[index].id);
    printf("GPA: ");
    scanf("%f", &s[index].gpa);
}

void newStudent(struct student* database, int* num_students) {
    if (*num_students >= MAX_SIZE) {
        printf("Database is full!");
        return;
    }

    readStudent(database, *num_students);
    (*num_students)++;
}

void displayStudents(struct student* database, int num_students) {
    if (num_students == 0) {
        printf("No students in database!\n");
        return;
    }

    printf("\nList of students:\n");
    printf("Name\t ID\t GPA\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s\t %d\t %.2f\n", database[i].name, database[i].id, database[i].gpa);
    }
}

void searchStudents(struct student* database, int num_students) {
    if (num_students == 0) {
        printf("No students in database!\n");
        return;
    }

    int id_to_find;
    printf("\nEnter ID of student to search for: ");
    scanf("%d", &id_to_find);

    for (int i = 0; i < num_students; i++) {
        if (database[i].id == id_to_find) {
            printf("\nStudent found:\n");
            printf("Name\t ID\t GPA\n");
            printf("%s\t %d\t %.2f\n", database[i].name, database[i].id, database[i].gpa);
            return;
        }
    }

    printf("Student not found!\n");
}

void updateGPA(struct student* database, int num_students) {
    if (num_students == 0) {
        printf("No students in database!\n");
        return;
    }

    int id_to_update;
    printf("\nEnter ID of student to update GPA: ");
    scanf("%d", &id_to_update);

    for (int i = 0; i < num_students; i++) {
        if (database[i].id == id_to_update) {
            printf("\nEnter new GPA: ");
            scanf("%f", &database[i].gpa);
            printf("GPA updated!\n");
            return;
        }
    }

    printf("Student not found!\n");
}