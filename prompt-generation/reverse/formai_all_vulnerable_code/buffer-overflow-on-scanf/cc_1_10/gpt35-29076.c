//FormAI DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct student {
    char name[20];
    int age;
    int roll_no;
};

// Function to insert a student record into the database
void insert(struct student s[], int *size_ptr) {
    // Check if the database is already full
    if (*size_ptr == MAX) {
        printf("Database is full. Cannot insert more records.\n");
        return;
    }

    // Prompt user for details of the student
    struct student new_student;
    printf("Enter name of student: ");
    scanf("%s", new_student.name);
    printf("Enter age of student: ");
    scanf("%d", &new_student.age);
    printf("Enter roll number of student: ");
    scanf("%d", &new_student.roll_no);

    // Add the new record to the database
    s[*size_ptr] = new_student;
    (*size_ptr)++;
    printf("Student record added successfully.\n");
}

// Function to search for a student record using either the name or the roll number
void search(struct student s[], int size) {
    int choice;
    printf("How would you like to search?\n");
    printf("1. By name\n2. By roll number\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Search by name
        char name[20];
        printf("Enter name of student: ");
        scanf("%s", name);

        // Traverse the database to find a matching record
        for (int i = 0; i < size; i++) {
            if (strcmp(s[i].name, name) == 0) {
                printf("Record found:\n");
                printf("Name: %s\nAge: %d\nRoll Number: %d\n", s[i].name, s[i].age, s[i].roll_no);
                return;
            }
        }
        printf("No record found with name '%s'.\n", name);
    } else if (choice == 2) {
        // Search by roll number
        int roll_no;
        printf("Enter roll number of student: ");
        scanf("%d", &roll_no);

        // Traverse the database to find a matching record
        for (int i = 0; i < size; i++) {
            if (s[i].roll_no == roll_no) {
                printf("Record found:\n");
                printf("Name: %s\nAge: %d\nRoll Number: %d\n", s[i].name, s[i].age, s[i].roll_no);
                return;
            }
        }
        printf("No record found with roll number %d.\n", roll_no);
    } else {
        printf("Invalid choice.\n");
    }
}

int main() {
    struct student db[MAX];  // Create a database of students
    int size = 0;  // Keep track of the number of records in the database

    printf("Welcome to the Student Database!\n");

    // Display the menu and prompt user for choice
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Add a student record\n2. Search for a student record\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the appropriate action based on user's choice
        switch (choice) {
            case 1: insert(db, &size); break;
            case 2: search(db, size); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}