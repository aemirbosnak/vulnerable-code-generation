//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define FILENAME "students.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grade;
} Student;

void addStudent();
void listStudents();
void findStudent();
void deleteStudent();
void updateStudent();
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                listStudents();
                break;
            case 3:
                findStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. List Students\n");
    printf("3. Find Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("0. Exit\n");
}

void addStudent() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file for appending");
        return;
    }

    Student student;

    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter Student Grade: ");
    scanf("%f", &student.grade);

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);

    printf("Student added successfully!\n");
}

void listStudents() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    Student student;
    printf("\n--- List of Students ---\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
    }
    fclose(file);
}

void findStudent() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    int id, found = 0;
    Student student;

    printf("Enter Student ID to find: ");
    scanf("%d", &id);

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            found = 1;
            printf("Student found: ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }

    fclose(file);
}

void updateStudent() {
    FILE *file = fopen(FILENAME, "r+b");
    if (file == NULL) {
        perror("Unable to open file for updating");
        return;
    }

    int id, found = 0;
    Student student;

    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            found = 1;

            printf("Updating Student... \n");
            printf("Current Name: %s\n", student.name);
            printf("Current Grade: %.2f\n", student.grade);
            printf("Enter New Name: ");
            scanf(" %[^\n]", student.name);
            printf("Enter New Grade: ");
            scanf("%f", &student.grade);

            fseek(file, -sizeof(Student), SEEK_CUR); // Move the file pointer back
            fwrite(&student, sizeof(Student), 1, file);
            printf("Student updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }

    fclose(file);
}

void deleteStudent() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Unable to open temporary file for writing");
        fclose(file);
        return;
    }

    int id, found = 0;
    Student student;

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            found = 1; // Mark that we found the student
            printf("Deleting Student: ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
            continue; // Skip writing this student to the temp file
        }
        fwrite(&student, sizeof(Student), 1, tempFile);
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    } else {
        printf("Student deleted successfully!\n");
    }

    fclose(file);
    fclose(tempFile);

    // Replace original file with the temp file
    remove(FILENAME);
    rename("temp.txt", FILENAME);
}