//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_SUBJECTS 5
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int marks[MAX_SUBJECTS];
    float average;
} Student;

void inputStudentData(Student *student) {
    printf("Enter name of the student: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    student->name[strcspn(student->name, "\n")] = 0;  // Remove newline character

    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Enter marks for subject %d (0-100): ", i + 1);
        while (1) {
            scanf("%d", &student->marks[i]);
            if (student->marks[i] >= 0 && student->marks[i] <= 100) {
                break;
            } else {
                printf("Invalid input. Please enter marks between 0 and 100: ");
            }
        }
    }
}

void calculateAverage(Student *student) {
    int total = 0;
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        total += student->marks[i];
    }
    student->average = total / (float)MAX_SUBJECTS;
}

void displayStudentData(Student student) {
    printf("\nStudent Name: %s\n", student.name);
    printf("Marks:\n");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Subject %d: %d\n", i + 1, student.marks[i]);
    }
    printf("Average Marks: %.2f\n", student.average);
}

void sortStudentsByAverage(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayAllStudents(Student students[], int count) {
    printf("\nAll Students Data:\n");
    for (int i = 0; i < count; i++) {
        displayStudentData(students[i]);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    char choice;

    do {
        if (studentCount >= MAX_STUDENTS) {
            printf("Maximum student limit reached.\n");
            break;
        }

        // Input student data
        inputStudentData(&students[studentCount]);
        calculateAverage(&students[studentCount]);
        studentCount++;

        // Ask if user wants to enter another student
        printf("Do you want to enter details of another student? (y/n): ");
        while (getchar() != '\n'); // Clear input buffer
        scanf("%c", &choice);

    } while (choice == 'y' || choice == 'Y');

    // Sort students by average marks
    sortStudentsByAverage(students, studentCount);

    // Display all students
    displayAllStudents(students, studentCount);

    return 0;
}