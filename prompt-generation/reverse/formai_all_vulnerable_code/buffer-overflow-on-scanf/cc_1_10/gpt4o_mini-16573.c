//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define FILENAME "students.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grade;
} Student;

void addStudent(Student *students, int *count);
void viewStudents(Student *students, int count);
void saveToFile(Student *students, int count);
void loadFromFile(Student *students, int *count);
void displayMenu();

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    // Load existing students from file
    loadFromFile(students, &studentCount);

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                viewStudents(students, studentCount);
                break;
            case 3:
                saveToFile(students, studentCount);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addStudent(Student *students, int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    
    Student newStudent;
    newStudent.id = *count + 1; // Assign a simple unique ID
    printf("Enter name of student %d: ", newStudent.id);
    scanf(" %[^\n]", newStudent.name);
    printf("Enter grade of student %d: ", newStudent.id);
    scanf("%f", &newStudent.grade);

    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully!\n");
}

void viewStudents(Student *students, int count) {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("----------------------------------------\n");
    printf("| ID | Name                           | Grade |\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %2d | %-30s | %.2f  |\n", students[i].id, students[i].name, students[i].grade);
    }
    printf("----------------------------------------\n");
}

void saveToFile(Student *students, int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%.2f\n", students[i].id, students[i].name, students[i].grade);
    }
    fclose(file);
    printf("Data saved to %s successfully!\n", FILENAME);
}

void loadFromFile(Student *students, int *count) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No previous records found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%f\n", &students[*count].id, students[*count].name, &students[*count].grade) != EOF) {
        (*count)++;
    }
    fclose(file);
    printf("Loaded %d student records from %s.\n", *count, FILENAME);
}

void displayMenu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Save to File\n");
    printf("4. Exit\n");
}