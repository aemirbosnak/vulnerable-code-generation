//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float grades[5]; // Assuming each student has 5 grades
    float average;
} Student;

void inputStudentData(Student *student) {
    printf("Enter name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    student->name[strcspn(student->name, "\n")] = 0; // Remove newline
    printf("Enter age: ");
    scanf("%d", &student->age);
    printf("Enter 5 grades: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &student->grades[i]);
    }
    // Clear input buffer
    while (getchar() != '\n');
}

void calculateAverage(Student *student) {
    float sum = 0.0;
    for (int i = 0; i < 5; i++) {
        sum += student->grades[i];
    }
    student->average = sum / 5;
}

void printStudentData(const Student *student) {
    printf("\nStudent Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", student->grades[i]);
    }
    printf("\nAverage: %.2f\n", student->average);
}

void findTopStudent(Student students[], int count) {
    Student *topStudent = &students[0];
    for (int i = 1; i < count; i++) {
        if (students[i].average > topStudent->average) {
            topStudent = &students[i];
        }
    }
    printf("\nTop Student:\n");
    printStudentData(topStudent);
}

void menu() {
    printf("Student Management System\n");
    printf("1. Add Student\n");
    printf("2. Show All Students\n");
    printf("3. Find Top Student\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        // Clear input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                if (studentCount < MAX_STUDENTS) {
                    printf("\nAdding Student %d\n", studentCount + 1);
                    inputStudentData(&students[studentCount]);
                    calculateAverage(&students[studentCount]);
                    studentCount++;
                } else {
                    printf("Maximum number of students reached.\n");
                }
                break;
            case 2:
                printf("\nAll Students:\n");
                for (int i = 0; i < studentCount; i++) {
                    printStudentData(&students[i]);
                }
                break;
            case 3:
                if (studentCount > 0) {
                    findTopStudent(students, studentCount);
                } else {
                    printf("No students available to find top student.\n");
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
        printf("\n");
    }
    
    return 0;
}