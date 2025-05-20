//FormAI DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[20];
    int age;
    char address[50];
    int student_id;
} Student;

void insertStudent(Student* students, int* size);
void displayStudent(Student* students, int size);
void searchStudent(Student* students, int size);
void deleteStudent(Student* students, int* size);

int main() {

    Student* students = malloc(sizeof(Student));
    int size = 0;
    int choice;

    printf("Welcome to the Student Database!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Insert Student\n");
        printf("2. Display all Students\n");
        printf("3. Search for a Student\n");
        printf("4. Delete a Student\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent(students, &size);
                break;
            case 2:
                displayStudent(students, size);
                break;
            case 3:
                searchStudent(students, size);
                break;
            case 4:
                deleteStudent(students, &size);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 5);

    free(students);

    return 0;
}

void insertStudent(Student* students, int* size) {
    Student newStudent;
    printf("\nEnter Student name: ");
    scanf("%s", newStudent.name);
    printf("Enter Student age: ");
    scanf("%d", &newStudent.age);
    printf("Enter Student address: ");
    scanf("%s", newStudent.address);
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.student_id);

    students[*size] = newStudent;
    *size += 1;
}

void displayStudent(Student* students, int size) {
    if (size == 0) {
        printf("\nNo students have been added yet.\n");
        return;
    }

    printf("\n%-20s %-10s %-50s %-10s\n", "Name", "Age", "Address", "ID");
    for (int i = 0; i < size; i++) {
        printf("%-20s %-10d %-50s %-10d\n", students[i].name, students[i].age, students[i].address, students[i].student_id);
    }
}

void searchStudent(Student* students, int size) {
    if (size == 0) {
        printf("\nNo students have been added yet.\n");
        return;
    }

    int student_id;
    printf("\nEnter the student ID to search for: ");
    scanf("%d", &student_id);

    for (int i = 0; i < size; i++) {
        if (students[i].student_id == student_id) {
            printf("\n%-20s %-10s %-50s %-10s\n", "Name", "Age", "Address", "ID");
            printf("%-20s %-10d %-50s %-10d\n", students[i].name, students[i].age, students[i].address, students[i].student_id);
            return;
        }
    }

    printf("\nStudent with ID %d not found.\n", student_id);
}

void deleteStudent(Student* students, int* size) {
    if (*size == 0) {
        printf("\nNo students have been added yet.\n");
        return;
    }

    int student_id;
    printf("\nEnter the student ID to delete: ");
    scanf("%d", &student_id);

    for (int i = 0; i < *size; i++) {
        if (students[i].student_id == student_id) {
            for (int j = i; j < *size - 1; j++) {
                students[j] = students[j + 1];
            }
            *size -= 1;
            printf("\nStudent with ID %d has been deleted.\n", student_id);
            return;
        }
    }

    printf("\nStudent with ID %d not found.\n", student_id);
}