//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define FILE_NAME "student_records.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float marks;
} Student;

// Function to add a student record
void addStudent() {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        fprintf(stderr, "Could not open %s for appending.\n", FILE_NAME);
        return;
    }

    Student student;
    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    printf("Enter Student Name: ");
    getchar(); // consume the newline character
    fgets(student.name, NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // remove newline
    printf("Enter Student Marks: ");
    scanf("%f", &student.marks);
    
    fprintf(file, "%d,%s,%.2f\n", student.id, student.name, student.marks);
    fclose(file);
    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open %s for reading.\n", FILE_NAME);
        return;
    }

    Student student;
    printf("\nList of Student Records:\n");
    printf("ID\tName\t\tMarks\n");
    printf("-----------------------------------------\n");

    while (fscanf(file, "%d,%49[^,],%f\n", &student.id, student.name, &student.marks) != EOF) {
        printf("%d\t%-20s%.2f\n", student.id, student.name, student.marks);
    }
    
    fclose(file);
}

// Function to delete a student record
void deleteStudent() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open %s for reading.\n", FILE_NAME);
        return;
    }

    Student students[MAX_RECORDS];
    int count = 0;

    while (fscanf(file, "%d,%49[^,],%f\n", &students[count].id, students[count].name, &students[count].marks) != EOF) {
        count++;
    }
    fclose(file);

    int idToDelete;
    printf("Enter the Student ID to delete: ");
    scanf("%d", &idToDelete);
    
    file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open %s for writing.\n", FILE_NAME);
        return;
    }

    for (int i = 0; i < count; i++) {
        if (students[i].id != idToDelete) {
            fprintf(file, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].marks);
        }
    }
    fclose(file);
    printf("Student record with ID %d deleted successfully, if it existed.\n", idToDelete);
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Delete Student Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}