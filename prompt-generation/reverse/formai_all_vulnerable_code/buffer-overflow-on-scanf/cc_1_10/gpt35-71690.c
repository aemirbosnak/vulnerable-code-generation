//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
// C Database Simulation Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for student data
struct Student {
    char name[50];
    int id;
    int age;
    float gpa;
};

// Function prototypes
void insertStudent(struct Student* db, int* numStudents);
void searchStudent(struct Student* db, int numStudents);
void displayDatabase(struct Student* db, int numStudents);

int main() {
    int option;
    int numStudents = 0;
    struct Student database[100];  // Database can hold up to 100 students
    
    do {
        // Display menu
        printf("\nDATABASE MENU\n");
        printf("1. Insert student data\n");
        printf("2. Search student data\n");
        printf("3. Display database\n");
        printf("4. Exit\n");
        printf("Enter option (1-4): ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                insertStudent(database, &numStudents);
                break;
            case 2:
                searchStudent(database, numStudents);
                break;
            case 3:
                displayDatabase(database, numStudents);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);
    
    return 0;
}

// Function to insert student data into database
void insertStudent(struct Student* db, int* numStudents) {
    struct Student newStudent;
    
    // Get input from user
    printf("\nEnter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student age: ");
    scanf("%d", &newStudent.age);
    printf("Enter student GPA: ");
    scanf("%f", &newStudent.gpa);
    
    // Add new student to database
    db[*numStudents] = newStudent;
    (*numStudents)++;
    
    // Confirmation message
    printf("Student data added to database!\n");
}

// Function to search for student data in database
void searchStudent(struct Student* db, int numStudents) {
    int searchId, found = 0;
    
    // Get input from user
    printf("\nEnter student ID to search for: ");
    scanf("%d", &searchId);
    
    // Search through database for matching ID
    for (int i = 0; i < numStudents; i++) {
        if (db[i].id == searchId) {
            found = 1;
            printf("\nStudent data found!\n");
            printf("Name: %s\n", db[i].name);
            printf("ID: %d\n", db[i].id);
            printf("Age: %d\n", db[i].age);
            printf("GPA: %.1f\n", db[i].gpa);
            break;
        }
    }
    
    // Output message if no matching ID found
    if (!found) {
        printf("\nNo matching student ID found.\n");
    }
}

// Function to display database
void displayDatabase(struct Student* db, int numStudents) {
    // Output database header
    printf("\n%-20s %-10s %-10s %-10s\n", "Name", "ID", "Age", "GPA");
    
    // Output each student's data
    for (int i = 0; i < numStudents; i++) {
        printf("%-20s %-10d %-10d %-10.1f\n", db[i].name, db[i].id, db[i].age, db[i].gpa);
    }
    
    // Output message if database is empty
    if (numStudents == 0) {
        printf("\nDatabase is empty.\n");
    }
}