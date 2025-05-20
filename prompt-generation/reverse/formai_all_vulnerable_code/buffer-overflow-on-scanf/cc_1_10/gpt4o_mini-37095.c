//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a student
typedef struct Student {
    char name[50];
    int age;
    int grade;
    struct Student* next; // pointer to the next student
} Student;

// Function to create a new student node
Student* createStudent(char name[], int age, int grade) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->grade = grade;
    newStudent->next = NULL;
    return newStudent;
}

// Function to add a student to the end of the linked list
void addStudent(Student** head, char name[], int age, int grade) {
    Student* newStudent = createStudent(name, age, grade);
    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
}

// Function to delete a student by name
void deleteStudent(Student** head, char name[]) {
    Student* temp = *head;
    Student* prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student with name \"%s\" not found.\n", name);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display all students in the linked list
void displayStudents(Student* head) {
    if (head == NULL) {
        printf("No students available.\n");
        return;
    }

    Student* temp = head;
    printf("\nList of Students:\n");
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Grade: %d\n", temp->name, temp->age, temp->grade);
        temp = temp->next;
    }
}

// Function to search for a student by name
void searchStudent(Student* head, char name[]) {
    Student* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Student Found - Name: %s, Age: %d, Grade: %d\n", temp->name, temp->age, temp->grade);
            return;
        }
        temp = temp->next;
    }
    printf("Student with name \"%s\" not found.\n", name);
}

// Main function to demonstrate the linked list operations
int main() {
    Student* head = NULL;
    int choice;
    char name[50];
    int age, grade;

    while (1) {
        printf("\nStudent Management System:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character left after scanf

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline character
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter grade: ");
                scanf("%d", &grade);
                addStudent(&head, name, age, grade);
                break;
            case 2:
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline character
                deleteStudent(&head, name);
                break;
            case 3:
                displayStudents(head);
                break;
            case 4:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline character
                searchStudent(head, name);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}