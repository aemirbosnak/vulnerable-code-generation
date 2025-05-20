//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    float grade;
    struct Student *next;
} Student;

Student *head = NULL;

void addStudent(int id, const char *name, float grade) {
    Student *newStudent = malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed!\n");
        return;
    }
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->grade = grade;
    newStudent->next = head;
    head = newStudent;
    printf("Student added: %d, %s, %.2f\n", id, name, grade);
}

void listStudents() {
    if (head == NULL) {
        printf("No students in the database.\n");
        return;
    }

    Student *current = head;
    printf("Listing students:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", current->id, current->name, current->grade);
        current = current->next;
    }
}

void findStudent(int id) {
    Student *current = head;
    while (current != NULL) {
        if (current->id == id) {
            printf("Student found: ID: %d, Name: %s, Grade: %.2f\n", current->id, current->name, current->grade);
            return;
        }
        current = current->next;
    }
    printf("Student with ID %d not found.\n", id);
}

void freeStudents() {
    Student *current = head;
    Student *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All student records have been deleted.\n");
}

int main() {
    int choice, id;
    char name[50];
    float grade;

    do {
        printf("\nStudent Database Menu:\n");
        printf("1. Add Student\n");
        printf("2. List Students\n");
        printf("3. Find Student by ID\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]", name); // To read string with spaces
                printf("Enter Grade: ");
                scanf("%f", &grade);
                addStudent(id, name, grade);
                break;

            case 2:
                listStudents();
                break;

            case 3:
                printf("Enter ID to find: ");
                scanf("%d", &id);
                findStudent(id);
                break;

            case 4:
                freeStudents();
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}