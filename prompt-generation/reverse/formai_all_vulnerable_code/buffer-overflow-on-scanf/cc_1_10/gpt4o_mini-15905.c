//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define FILE_NAME "students.dat"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grade;
} Student;

void addStudent(FILE *file);
void viewStudents(FILE *file);
void searchStudent(FILE *file);
void deleteStudent(FILE *file);
void updateStudent(FILE *file);
void clearInputBuffer();

int main() {
    FILE *file = fopen(FILE_NAME, "ab+");
    if (!file) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    int choice;
    
    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1: addStudent(file); break;
            case 2: viewStudents(file); break;
            case 3: searchStudent(file); break;
            case 4: updateStudent(file); break;
            case 5: deleteStudent(file); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid option. Please try again.\n");
        }
    } while (choice != 0);

    fclose(file);
    return EXIT_SUCCESS;
}

void addStudent(FILE *file) {
    Student student;

    printf("Enter student ID: ");
    scanf("%d", &student.id);
    clearInputBuffer();
    
    printf("Enter student name: ");
    fgets(student.name, NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // Remove newline character
    
    printf("Enter student grade: ");
    scanf("%f", &student.grade);

    fseek(file, 0, SEEK_END);
    fwrite(&student, sizeof(Student), 1, file);
    printf("Student added successfully.\n");
}

void viewStudents(FILE *file) {
    Student student;
    rewind(file);

    printf("\n--- List of Students ---\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
    }
}

void searchStudent(FILE *file) {
    int id;
    Student student;
    int found = 0;

    printf("Enter student ID to search: ");
    scanf("%d", &id);
    
    rewind(file);
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            printf("ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void deleteStudent(FILE *file) {
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        perror("Unable to create temporary file");
        return;
    }

    int id;
    Student student;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    
    rewind(file);
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id != id) {
            fwrite(&student, sizeof(Student), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(tempFile);
    fclose(file);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("Student with ID %d deleted successfully.\n", id);
    } else {
        printf("Student with ID %d not found.\n", id);
    }

    file = fopen(FILE_NAME, "ab+");
}

void updateStudent(FILE *file) {
    int id;
    Student student;
    int found = 0;

    printf("Enter student ID to update: ");
    scanf("%d", &id);
    
    rewind(file);
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            found = 1;
            printf("Current details - ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);

            clearInputBuffer();
            printf("Enter new name: ");
            fgets(student.name, NAME_LENGTH, stdin);
            student.name[strcspn(student.name, "\n")] = 0; // Remove newline character

            printf("Enter new grade: ");
            scanf("%f", &student.grade);

            fseek(file, -sizeof(Student), SEEK_CUR);
            fwrite(&student, sizeof(Student), 1, file);
            printf("Student details updated successfully.\n");
            break;
        }
    }
    
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void clearInputBuffer() {
    while (getchar() != '\n');
}