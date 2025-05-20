//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float scores[5];
    float average;
} Student;

void inputStudentData(Student* student) {
    printf("Enter the student's name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    student->name[strcspn(student->name, "\n")] = 0; // Remove newline character

    printf("Enter 5 scores for %s:\n", student->name);
    float total = 0;
    for (int i = 0; i < 5; i++) {
        printf("Score %d: ", i + 1);
        scanf("%f", &student->scores[i]);
        total += student->scores[i];
    }
    student->average = total / 5;
}

void displayStudentData(const Student* student) {
    printf("\nStudent Name: %s\n", student->name);
    printf("Scores: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", student->scores[i]);
    }
    printf("\nAverage Score: %.2f\n", student->average);
}

void findTopStudent(const Student* students, int count) {
    float highestAverage = 0;
    int topIndex = -1;

    for (int i = 0; i < count; i++) {
        if (students[i].average > highestAverage) {
            highestAverage = students[i].average;
            topIndex = i;
        }
    }

    if (topIndex != -1) {
        printf("\nTop Student: %s with an average score of %.2f\n",
               students[topIndex].name, students[topIndex].average);
    } else {
        printf("\nNo students available to find the top student.\n");
    }
}

void sortStudents(Student* students, int count) {
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

void displayAllStudents(const Student* students, int count) {
    printf("\nAll Students Data:\n");
    for (int i = 0; i < count; i++) {
        displayStudentData(&students[i]);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    char choice;

    do {
        if (studentCount >= MAX_STUDENTS) {
            printf("Maximum number of students reached.\n");
            break;
        }
        
        inputStudentData(&students[studentCount]);
        studentCount++;

        printf("Do you want to enter another student? (y/n): ");
        getchar(); // Consume leftover newline
        choice = getchar();
    } while (choice == 'y' || choice == 'Y');

    displayAllStudents(students, studentCount);
    findTopStudent(students, studentCount);
    sortStudents(students, studentCount);

    printf("\nStudents sorted by average score:\n");
    displayAllStudents(students, studentCount);

    return 0;
}