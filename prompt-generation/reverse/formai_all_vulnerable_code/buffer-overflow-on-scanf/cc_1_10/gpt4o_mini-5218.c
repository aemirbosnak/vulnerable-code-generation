//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define MAJOR_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    char major[MAJOR_LENGTH];
} Student;

Student studentDatabase[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }

    Student newStudent;
    newStudent.id = studentCount + 1; // simple ID assignment
    printf("Enter name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter age: ");
    scanf("%d", &newStudent.age);
    printf("Enter major: ");
    scanf(" %[^\n]", newStudent.major);

    studentDatabase[studentCount] = newStudent;
    studentCount++;
    printf("Student added successfully! ID: %d\n", newStudent.id);
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Age: %d, Major: %s\n", 
               studentDatabase[i].id, 
               studentDatabase[i].name, 
               studentDatabase[i].age, 
               studentDatabase[i].major);
    }
    printf("-----------------------\n");
}

void searchStudent() {
    int searchId;
    printf("Enter student ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < studentCount; i++) {
        if (studentDatabase[i].id == searchId) {
            printf("Found! ID: %d, Name: %s, Age: %d, Major: %s\n", 
                   studentDatabase[i].id, 
                   studentDatabase[i].name, 
                   studentDatabase[i].age, 
                   studentDatabase[i].major);
            return;
        }
    }
    printf("No student found with ID: %d\n", searchId);
}

void showMenu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search for a Student\n");
    printf("4. Exit\n");
    printf("----------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}