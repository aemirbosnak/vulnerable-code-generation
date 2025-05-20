//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int scores[5];
    float average;
} Student;

void inputScores(Student *student) {
    printf("Enter scores for %s (out of 100):\n", student->name);
    for (int i = 0; i < 5; i++) {
        printf("Score for Subject %d: ", i + 1);
        scanf("%d", &student->scores[i]);
        // Input validation
        while (student->scores[i] < 0 || student->scores[i] > 100) {
            printf("Invalid score! Please enter score for Subject %d again: ", i + 1);
            scanf("%d", &student->scores[i]);
        }
    }
}

void calculateAverage(Student *student) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += student->scores[i];
    }
    student->average = total / 5.0;
}

void displayStudentInfo(const Student *student) {
    printf("\nStudent Name: %s\n", student->name);
    printf("Scores: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", student->scores[i]);
    }
    printf("\nAverage Score: %.2f\n", student->average);
}

void sortStudentsByAverage(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                // Swap students
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayAllStudents(const Student students[], int count) {
    printf("\n=== All Students Information ===\n");
    for (int i = 0; i < count; i++) {
        displayStudentInfo(&students[i]);
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
        
        printf("Enter the name of student %d: ", studentCount + 1);
        scanf(" %[^\n]s", students[studentCount].name);
        
        inputScores(&students[studentCount]);
        calculateAverage(&students[studentCount]);
        studentCount++;
        
        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    sortStudentsByAverage(students, studentCount);
    displayAllStudents(students, studentCount);

    return 0;
}