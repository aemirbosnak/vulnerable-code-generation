//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple C program to simulate a database of students */

typedef struct {
    char name[50];
    int age;
    int id;
} Student;

int menu() {
    int choice;
    printf("\n--- Student Database Management ---\n");
    printf("1. Add Student\n");
    printf("2. Search Student by ID\n");
    printf("3. Display All Students\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void addStudent(Student* students, int* size) {
    Student newStudent;
    printf("\nEnter the student's name: ");
    scanf("%s", newStudent.name);
    printf("Enter the student's age: ");
    scanf("%d", &newStudent.age);
    printf("Enter the student's ID: ");
    scanf("%d", &newStudent.id);

    students = realloc(students, ((*size) + 1) * sizeof(Student));
    students[*size] = newStudent;
    (*size)++;
}

void searchStudent(Student* students, int size) {
    int id;
    printf("\nEnter the student ID to search: ");
    scanf("%d", &id);

    for(int i = 0; i < size; i++) {
        if(students[i].id == id) {
            printf("\nStudent Found:\n");
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("ID: %d\n", students[i].id);
            return;
        }
    }

    printf("\nStudent with ID %d not found.\n", id);
}

void displayAllStudents(Student* students, int size) {
    printf("\nAll Students:\n");
    for(int i = 0; i < size; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("ID: %d\n", students[i].id);
        printf("\n");
    }
}

int main() {
    Student* students = (Student*) malloc(sizeof(Student));
    int size = 0;
    int choice;

    while(1) {
        choice = menu();

        switch(choice) {
            case 1:
                addStudent(students, &size);
                break;
            case 2:
                searchStudent(students, size);
                break;
            case 3:
                displayAllStudents(students, size);
                break;
            case 4:
                free(students);
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}