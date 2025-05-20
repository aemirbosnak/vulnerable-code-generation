//FormAI DATASET v1.0 Category: Database simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
    int age;
    float gpa;
} Student;

void add_student(Student** database, int* size) {
    (*size)++;
    *database = realloc(*database, (*size) * sizeof(Student));
    printf("Enter student id, name, age, and GPA (separated by spaces):\n");
    scanf("%d %s %d %f", &((*database)[(*size)-1].id), (*database)[(*size)-1].name, &((*database)[(*size)-1].age), &((*database)[(*size)-1].gpa));
}

void delete_student(Student** database, int* size, int id) {
    int index = -1;
    for (int i = 0; i < *size; i++) {
        if ((*database)[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }
    for (int i = index + 1; i < *size; i++) {
        (*database)[i-1] = (*database)[i];
    }
    (*size)--;
    *database = realloc(*database, (*size) * sizeof(Student));
    printf("Student with ID %d deleted.\n", id);
}

void print_student(Student student) {
    printf("ID: %d\tName: %s\tAge: %d\tGPA: %.2f\n", student.id, student.name, student.age, student.gpa);
}

void print_all_students(Student* database, int size) {
    printf("Students in database:\n");
    for (int i = 0; i < size; i++) {
        print_student(database[i]);
    }
}

void search_student(Student* database, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (database[i].id == id) {
            printf("Student with ID %d found:\n", id);
            print_student(database[i]);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void update_student(Student* database, int size, int id) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (database[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }
    printf("Enter new name, age, and GPA (separated by spaces):\n");
    scanf("%s %d %f", database[index].name, &(database[index].age), &(database[index].gpa));
    printf("Student with ID %d updated.\n", id);
}

void recursive_menu(Student** database, int* size) {
    printf("\nWhat would you like to do?\n");
    printf("1. Add student\n");
    printf("2. Delete student\n");
    printf("3. Print all students\n");
    printf("4. Search student\n");
    printf("5. Update student\n");
    printf("6. Exit\n");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            add_student(database, size);
            recursive_menu(database, size);
            break;
        case 2:
            printf("Enter student ID to delete:\n");
            int id;
            scanf("%d", &id);
            delete_student(database, size, id);
            recursive_menu(database, size);
            break;
        case 3:
            print_all_students(*database, *size);
            recursive_menu(database, size);
            break;
        case 4:
            printf("Enter student ID to search:\n");
            scanf("%d", &id);
            search_student(*database, *size, id);
            recursive_menu(database, size);
            break;
        case 5:
            printf("Enter student ID to update:\n");
            scanf("%d", &id);
            update_student(*database, *size, id);
            recursive_menu(database, size);
            break;
        case 6:
            printf("Goodbye.\n");
            free(*database);
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            recursive_menu(database, size);
    }
}

int main() {
    Student* database = NULL;
    int size = 0;
    recursive_menu(&database, &size);
    return 0;
}