//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
    float grade;
} Student;

typedef struct {
    Student records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addStudent(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }
    
    Student newStudent;
    
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);
    getchar(); // To consume the newline character
    
    printf("Enter Student Name: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Remove newline
    
    printf("Enter Student Age: ");
    scanf("%d", &newStudent.age);
    
    printf("Enter Student Grade: ");
    scanf("%f", &newStudent.grade);
    
    db->records[db->count] = newStudent;
    db->count++;
    
    printf("Student added successfully!\n");
}

void deleteStudent(Database *db) {
    int id, found = 0;

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1]; // Shift records left
            }
            db->count--;
            printf("Student with ID %d deleted successfully!\n", id);
            break;
        }
    }
    
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void viewStudents(Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    printf("ID\tName\t\tAge\tGrade\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t%d\t%.2f\n", db->records[i].id, db->records[i].name, db->records[i].age, db->records[i].grade);
    }
    printf("----------------------------------------\n");
}

void menu() {
    printf("Student Database Management System\n");
    printf("1. Add Student\n");
    printf("2. Delete Student\n");
    printf("3. View Students\n");
    printf("4. Exit\n");
    printf("Please select an option: ");
}

int main() {
    Database db;
    initializeDatabase(&db);
    
    int choice;
    
    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(&db);
                break;
            case 2:
                deleteStudent(&db);
                break;
            case 3:
                viewStudents(&db);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}