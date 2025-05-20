//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int id;
    float grades[3];  // Assuming 3 subjects for simplicity
    float average;
} Student;

void addStudent(Student *students, int *count);
void displayStudents(const Student *students, int count);
void calculateAverages(Student *students, int count);
void findTopStudent(const Student *students, int count);
void saveToFile(const Student *students, int count);

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Calculate Averages\n");
        printf("4. Find Top Student\n");
        printf("5. Save to File\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                calculateAverages(students, count);
                break;
            case 4:
                findTopStudent(students, count);
                break;
            case 5:
                saveToFile(students, count);
                break;
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

void addStudent(Student *students, int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    Student newStudent;

    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);

    for (int i = 0; i < 3; i++) {
        printf("Enter grade for subject %d: ", i + 1);
        scanf("%f", &newStudent.grades[i]);
    }

    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(const Student *students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    printf("ID\tName\t\tGrades\t\tAverage\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f, %.2f, %.2f\t%.2f\n", 
               students[i].id, 
               students[i].name, 
               students[i].grades[0], 
               students[i].grades[1], 
               students[i].grades[2],
               students[i].average);
    }
}

void calculateAverages(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        students[i].average = (students[i].grades[0] + students[i].grades[1] + students[i].grades[2]) / 3;
    }
    printf("Averages calculated for all students.\n");
}

void findTopStudent(const Student *students, int count) {
    if (count == 0) {
        printf("No students to evaluate.\n");
        return;
    }

    int topIndex = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].average > students[topIndex].average) {
            topIndex = i;
        }
    }

    printf("Top Student:\n");
    printf("ID: %d, Name: %s, Average: %.2f\n", 
           students[topIndex].id, 
           students[topIndex].name, 
           students[topIndex].average);
}

void saveToFile(const Student *students, int count) {
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "ID: %d, Name: %s, Grades: %.2f, %.2f, %.2f, Average: %.2f\n", 
                students[i].id, 
                students[i].name, 
                students[i].grades[0], 
                students[i].grades[1], 
                students[i].grades[2], 
                students[i].average);
    }

    fclose(file);
    printf("Data saved to students.txt successfully!\n");
}