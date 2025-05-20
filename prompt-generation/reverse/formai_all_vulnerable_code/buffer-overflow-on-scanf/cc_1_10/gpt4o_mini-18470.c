//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_RECORDS 50

typedef struct {
    char name[MAX_LENGTH];
    int age;
    char gender[10];
    char email[MAX_LENGTH];
} Student;

void displayMenu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

void addStudent(Student *students, int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Student list is full!\n");
        return;
    }
    Student newStudent;
    printf("Enter name: ");
    fgets(newStudent.name, MAX_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter age: ");
    scanf("%d", &newStudent.age);
    getchar(); // Clear '\n' from buffer

    printf("Enter gender: ");
    fgets(newStudent.gender, 10, stdin);
    newStudent.gender[strcspn(newStudent.gender, "\n")] = '\0'; // Remove trailing newline

    printf("Enter email: ");
    fgets(newStudent.email, MAX_LENGTH, stdin);
    newStudent.email[strcspn(newStudent.email, "\n")] = '\0'; // Remove trailing newline

    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully!\n");
}

void viewStudents(Student *students, int count) {
    if (count == 0) {
        printf("No students to display!\n");
        return;
    }
    printf("\n--- List of Students ---\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: Name: %s, Age: %d, Gender: %s, Email: %s\n", 
            i + 1, students[i].name, students[i].age, students[i].gender, students[i].email);
    }
}

void searchStudent(Student *students, int count) {
    if (count == 0) {
        printf("No students to search!\n");
        return;
    }
    char name[MAX_LENGTH];
    printf("Enter the name of the student to search: ");
    fgets(name, MAX_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(name, students[i].name) == 0) {
            printf("Found Student: Name: %s, Age: %d, Gender: %s, Email: %s\n", 
                students[i].name, students[i].age, students[i].gender, students[i].email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with name '%s' not found!\n", name);
    }
}

void deleteStudent(Student *students, int *count) {
    if (*count == 0) {
        printf("No students to delete!\n");
        return;
    }
    
    char name[MAX_LENGTH];
    printf("Enter the name of the student to delete: ");
    fgets(name, MAX_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove trailing newline

    int found = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(name, students[i].name) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < *count - 1; i++) {
            students[i] = students[i + 1]; // Shift records left
        }
        (*count)--;
        printf("Student '%s' deleted successfully!\n", name);
    } else {
        printf("Student with name '%s' not found!\n", name);
    }
}

int main() {
    Student students[MAX_RECORDS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // Clear trailing newline from buffer

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                deleteStudent(students, &count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}