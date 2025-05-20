//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 5
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    float grades[MAX_SUBJECTS];
    float average;
} Student;

void displayMenu();
void addStudent(Student* students, int* count);
void calculateAverage(Student* student);
void displayStudents(Student* students, int count);
void saveToFile(Student* students, int count);
void loadFromFile(Student* students, int* count);

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    loadFromFile(students, &studentCount);
    
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                saveToFile(students, studentCount);
                printf("Data saved successfully!\n");
                break;
            case 4:
                loadFromFile(students, &studentCount);
                printf("Data loaded successfully!\n");
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n--- Student Database Menu ---\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Save to File\n");
    printf("4. Load from File\n");
    printf("5. Exit\n");
}

void addStudent(Student* students, int* count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum student limit reached!\n");
        return;
    }

    Student newStudent;
    printf("Enter student's roll number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter student's name: ");
    scanf(" %[^\n]s", newStudent.name);

    printf("Enter grades for %s:\n", newStudent.name);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &newStudent.grades[i]);
    }

    calculateAverage(&newStudent);
    students[(*count)++] = newStudent;
    printf("Student %s added successfully!\n", newStudent.name);
}

void calculateAverage(Student* student) {
    float total = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        total += student->grades[i];
    }
    student->average = total / MAX_SUBJECTS;
}

void displayStudents(Student* students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        printf("Grades: ");
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            printf("%.2f ", students[i].grades[j]);
        }
        printf("\nAverage: %.2f\n", students[i].average);
        printf("---------------------\n");
    }
}

void saveToFile(Student* students, int count) {
    FILE* file = fopen("students.dat", "wb");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
}

void loadFromFile(Student* students, int* count) {
    FILE* file = fopen("students.dat", "rb");
    if (!file) {
        printf("Error opening file for reading!\n");
        return;
    }
    *count = fread(students, sizeof(Student), MAX_STUDENTS, file);
    fclose(file);
}