//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define FILE_NAME "student_records.txt"

// Struct to store student data
typedef struct {
    char name[NAME_LENGTH];
    int age;
    float grade;
} Student;

// Function prototypes
void addRecord();
void viewRecords();
void updateRecord();
void deleteRecord();
void clearBuffer();

int main() {
    int choice;

    do {
        printf("\n--- Student Records Management ---\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                viewRecords();
                break;
            case 3:
                updateRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a student record
void addRecord() {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Student student;
    printf("Enter student name: ");
    fgets(student.name, NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Remove newline

    printf("Enter student age: ");
    scanf("%d", &student.age);
    clearBuffer(); // Clear newline from input buffer

    printf("Enter student grade: ");
    scanf("%f", &student.grade);
    clearBuffer(); // Clear newline from input buffer

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Record added successfully!\n");
}

// Function to view all student records
void viewRecords() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    Student student;
    printf("\n--- Student Records ---\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("Name: %s, Age: %d, Grade: %.2f\n", student.name, student.age, student.grade);
    }
    fclose(file);
}

// Function to update a student record
void updateRecord() {
    FILE *file = fopen(FILE_NAME, "r+b");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the name of the student to update: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (strcmp(student.name, name) == 0) {
            found = 1;
            printf("Updating record for %s.\n", student.name);
            printf("Enter new age: ");
            scanf("%d", &student.age);
            clearBuffer(); // Clear newline from input buffer

            printf("Enter new grade: ");
            scanf("%f", &student.grade);
            clearBuffer(); // Clear newline from input buffer

            fseek(file, -sizeof(Student), SEEK_CUR); // Go back one record
            fwrite(&student, sizeof(Student), 1, file); // Write the updated record
            printf("Record updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("No record found for the student named %s.\n", name);
    }
    fclose(file);
}

// Function to delete a student record
void deleteRecord() {
    FILE *file = fopen(FILE_NAME, "r+b");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w+b");
    if (!tempFile) {
        perror("Failed to open temporary file");
        fclose(file);
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the name of the student to delete: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (strcmp(student.name, name) == 0) {
            found = 1;
            printf("Deleting record for %s.\n", student.name);
            continue; // Skip writing this record to the temp file
        }
        fwrite(&student, sizeof(Student), 1, tempFile); // Write to temp file
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Record deleted successfully!\n");
    } else {
        remove("temp.txt"); // Remove temp file if no record was found
        printf("No record found for the student named %s.\n", name);
    }
}

// Function to clear input buffer
void clearBuffer() {
    while (getchar() != '\n');
}