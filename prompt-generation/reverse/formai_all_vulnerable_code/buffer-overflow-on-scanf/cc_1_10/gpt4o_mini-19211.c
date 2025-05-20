//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student information
typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// Function declarations
void addStudent(Student *students, int *count);
void displayStudents(const Student *students, int count);
void saveToFile(const Student *students, int count);
void loadFromFile(Student *students, int *count);
void clearBuffer();

#define MAX_STUDENTS 100

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    loadFromFile(students, &count);

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n2. Display Students\n3. Save to File\n4. Load from File\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                saveToFile(students, count);
                break;
            case 4:
                loadFromFile(students, &count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(Student *students, int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum number of students reached!\n");
        return;
    }

    // Gather student information
    Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    clearBuffer();
    printf("Enter student name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Remove newline character
    printf("Enter student grade: ");
    scanf("%f", &newStudent.grade);
    
    // Add student to list
    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(const Student *students, int count) {
    if (count == 0) {
        printf("No students to display!\n");
        return;
    }

    printf("\nList of Students:\n");
    printf("ID\tName\t\tGrade\n");
    printf("-----------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

void saveToFile(const Student *students, int count) {
    FILE *file = fopen("students.dat", "wb");
    if (file == NULL) {
        printf("Failed to open file for writing.\n");
        return;
    }
    
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
    printf("Students saved to file successfully!\n");
}

void loadFromFile(Student *students, int *count) {
    FILE *file = fopen("students.dat", "rb");
    if (file == NULL) {
        printf("Failed to open file for reading. Starting fresh.\n");
        return;
    }
    
    *count = fread(students, sizeof(Student), MAX_STUDENTS, file);
    fclose(file);
    printf("Students loaded from file successfully!\n");
}

void clearBuffer() {
    while (getchar() != '\n');
}