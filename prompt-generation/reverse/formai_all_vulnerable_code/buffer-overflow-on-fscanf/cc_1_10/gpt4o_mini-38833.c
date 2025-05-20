//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define FILE_NAME "students.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grades[5];
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

void loadStudents() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file) {
        while (fscanf(file, "%d %s", &students[studentCount].id, students[studentCount].name) != EOF) {
            for (int i = 0; i < 5; i++) {
                fscanf(file, "%f", &students[studentCount].grades[i]);
            }
            studentCount++;
        }
        fclose(file);
    }
}

void saveStudents() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file) {
        for (int i = 0; i < studentCount; i++) {
            fprintf(file, "%d %s ", students[i].id, students[i].name);
            for (int j = 0; j < 5; j++) {
                fprintf(file, "%.2f ", students[i].grades[j]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
    }
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students.\n");
        return;
    }
    
    Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    
    printf("Enter 5 grades: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &newStudent.grades[i]);
    }
    
    students[studentCount++] = newStudent;
    saveStudents();
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students found.\n");
        return;
    }
    
    printf("\nID\tName\tGrades\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%s\t", students[i].id, students[i].name);
        for (int j = 0; j < 5; j++) {
            printf("%.2f ", students[i].grades[j]);
        }
        printf("\n");
    }
}

void deleteStudent() {
    if (studentCount == 0) {
        printf("No students to delete.\n");
        return;
    }
    
    int idToDelete;
    printf("Enter student ID to delete: ");
    scanf("%d", &idToDelete);
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == idToDelete) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            saveStudents();
            printf("Student deleted successfully!\n");
            return;
        }
    }
    
    printf("Student with ID %d not found.\n", idToDelete);
}

void showMenu() {
    printf("\n1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Delete Student\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    loadStudents();
    
    int choice = 0;
    while (choice != 4) {
        showMenu();
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
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}