//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct Student {
    int id;
    char name[NAME_LENGTH];
    int age;
    struct Student* next;
} Student;

// Global head pointer for the student linked list
Student* head = NULL;

// Function to create a new student
Student* create_student(int id, const char* name, int age) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    new_student->id = id;
    strcpy(new_student->name, name);
    new_student->age = age;
    new_student->next = NULL;
    return new_student;
}

// Function to add a student to the database
void add_student(int id, const char* name, int age) {
    Student* new_student = create_student(id, name, age);
    new_student->next = head;
    head = new_student;
    printf("Added student: %s (ID: %d, Age: %d)\n", name, id, age);
}

// Function to delete a student by ID
void delete_student(int id) {
    Student* current = head;
    Student* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    printf("Deleted student with ID %d.\n", id);
}

// Function to display all students
void display_students() {
    if (head == NULL) {
        printf("No students found in the database.\n");
        return;
    }
    Student* current = head;
    printf("Student Database:\n");
    printf("ID\tName\t\tAge\n");
    printf("---------------------------\n");
    while (current != NULL) {
        printf("%d\t%-15s\t%d\n", current->id, current->name, current->age);
        current = current->next;
    }
}

// Function to save the database to a file
void save_to_file() {
    FILE* file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    Student* current = head;
    while (current != NULL) {
        fprintf(file, "%d,%s,%d\n", current->id, current->name, current->age);
        current = current->next;
    }
    fclose(file);
    printf("Database saved to students.txt\n");
}

// Function to load students from a file
void load_from_file() {
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("No saved database found.\n");
        return;
    }

    int id;
    char name[NAME_LENGTH];
    int age;

    while (fscanf(file, "%d,%49[^,],%d\n", &id, name, &age) != EOF) {
        add_student(id, name, age);
    }
    fclose(file);
}

// Main menu for database operations
void menu() {
    int choice, id, age;
    char name[NAME_LENGTH];

    do {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Save to File\n");
        printf("5. Load from File\n");
        printf("6. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                add_student(id, name, age);
                break;
            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete_student(id);
                break;
            case 3:
                display_students();
                break;
            case 4:
                save_to_file();
                break;
            case 5:
                load_from_file();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

// Main function
int main() {
    menu();
    return 0;
}