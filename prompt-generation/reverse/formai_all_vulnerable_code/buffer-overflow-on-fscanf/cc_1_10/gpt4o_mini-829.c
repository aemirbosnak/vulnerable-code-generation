//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_ENTRIES 1000
#define FILENAME "students.txt"

// Structure to hold student data
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Function declarations
void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();
void configure();

// Main Function
int main() {
    int choice;
    
    configure(); // Load configuration options
    
    do {
        printf("\n=== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to configure system parameters
void configure() {
    // A placeholder for configuration setup in future (like max entries)
    printf("Configuration Loaded.\n");
}

// Function to add a student to the file
void addStudent() {
    Student student;
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter Student GPA: ");
    scanf("%f", &student.gpa);

    fprintf(file, "%d,%s,%.2f\n", student.id, student.name, student.gpa);
    printf("Student added successfully!\n");

    fclose(file);
}

// Function to view all students from the file
void viewStudents() {
    Student student;
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\n=== List of Students ===\n");
    while (fscanf(file, "%d,%49[^,],%f", &student.id, student.name, &student.gpa) == 3) {
        printf("ID: %d | Name: %s | GPA: %.2f\n", student.id, student.name, student.gpa);
    }

    fclose(file);
}

// Function to search for a student by ID
void searchStudent() {
    int searchId, found = 0;
    Student student;
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("Enter Student ID to search: ");
    scanf("%d", &searchId);

    while (fscanf(file, "%d,%49[^,],%f", &student.id, student.name, &student.gpa) == 3) {
        if (student.id == searchId) {
            printf("Student Found! ID: %d | Name: %s | GPA: %.2f\n", student.id, student.name, student.gpa);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student with ID %d not found.\n", searchId);

    fclose(file);
}

// Function to delete a student from the file
void deleteStudent() {
    int delId, found = 0;
    Student student;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (!file || !tempFile) {
        perror("Unable to open file");
        if (file) fclose(file);
        if (tempFile) fclose(tempFile);
        return;
    }

    printf("Enter Student ID to delete: ");
    scanf("%d", &delId);

    while (fscanf(file, "%d,%49[^,],%f", &student.id, student.name, &student.gpa) == 3) {
        if (student.id == delId) {
            printf("Student with ID %d deleted.\n", delId);
            found = 1;
            continue; // skip writing this student to temp
        }
        fprintf(tempFile, "%d,%s,%.2f\n", student.id, student.name, student.gpa);
    }

    if (!found)
        printf("Student with ID %d not found.\n", delId);

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);
}