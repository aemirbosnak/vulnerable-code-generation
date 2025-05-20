//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100

// Structure to hold student data
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;

// Function declarations
void addStudent(FILE *file, Student *student);
void displayStudents(FILE *file);
void findStudentById(FILE *file, int id);
void updateStudentGrade(FILE *file, int id, float newGrade);
void deleteStudentById(FILE *file, int id);
void listMenu();

int main() {
    FILE *file;
    file = fopen("students.dat", "r+b");
    if (file == NULL) {
        file = fopen("students.dat", "wb+");
        if (file == NULL) {
            perror("Unable to create file");
            return EXIT_FAILURE;
        }
    }

    int choice;
    int studentId;
    float studentGrade;
    Student student;

    do {
        listMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student ID: ");
                scanf("%d", &student.id);
                printf("Enter student name: ");
                scanf("%s", student.name);
                printf("Enter student grade: ");
                scanf("%f", &student.grade);
                addStudent(file, &student);
                break;
            case 2:
                displayStudents(file);
                break;
            case 3:
                printf("Enter student ID to find: ");
                scanf("%d", &studentId);
                findStudentById(file, studentId);
                break;
            case 4:
                printf("Enter student ID to update grade: ");
                scanf("%d", &studentId);
                printf("Enter new grade: ");
                scanf("%f", &studentGrade);
                updateStudentGrade(file, studentId, studentGrade);
                break;
            case 5:
                printf("Enter student ID to delete: ");
                scanf("%d", &studentId);
                deleteStudentById(file, studentId);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        fflush(stdin);
    } while (choice != 6);

    fclose(file);
    return EXIT_SUCCESS;
}

void listMenu() {
    printf("\nStudent Records Management\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Find Student by ID\n");
    printf("4. Update Student Grade\n");
    printf("5. Delete Student by ID\n");
    printf("6. Exit\n");
}

void addStudent(FILE *file, Student *student) {
    fseek(file, 0, SEEK_END);
    fwrite(student, sizeof(Student), 1, file);
    printf("Student added successfully!\n");
}

void displayStudents(FILE *file) {
    fseek(file, 0, SEEK_SET);
    Student student;
    printf("\nStudent Records:\n");
    printf("%s%15s%15s\n", "ID", "Name", "Grade");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("%d%15s%15.2f\n", student.id, student.name, student.grade);
    }
}

void findStudentById(FILE *file, int id) {
    fseek(file, 0, SEEK_SET);
    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            printf("Student found: %d %s %.2f\n", student.id, student.name, student.grade);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void updateStudentGrade(FILE *file, int id, float newGrade) {
    fseek(file, 0, SEEK_SET);
    Student student;
    long pos = -1;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            pos = ftell(file) - sizeof(Student);
            student.grade = newGrade;
            break;
        }
    }

    if (pos != -1) {
        fseek(file, pos, SEEK_SET);
        fwrite(&student, sizeof(Student), 1, file);
        printf("Student grade updated successfully!\n");
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

void deleteStudentById(FILE *file, int id) {
    FILE *tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        perror("Unable to create temporary file");
        return;
    }

    fseek(file, 0, SEEK_SET);
    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            found = 1;
            continue; // Skip the student to delete
        }
        fwrite(&student, sizeof(Student), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found) {
        printf("Student with ID %d deleted successfully!\n", id);
    } else {
        printf("Student with ID %d not found for deletion.\n", id);
    }
}