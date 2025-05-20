//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    float grades[5];
    float average;
} Student;

void inputStudentData(Student* student) {
    printf("Enter student name: ");
    fgets(student->name, NAME_LENGTH, stdin);
    student->name[strcspn(student->name, "\n")] = 0; // Remove trailing newline

    printf("Enter student age: ");
    scanf("%d", &student->age);

    printf("Enter grades for 5 subjects:\n");
    float total = 0;
    for (int i = 0; i < 5; i++) {
        printf("Grade for subject %d: ", i + 1);
        scanf("%f", &student->grades[i]);
        total += student->grades[i];
    }
    
    student->average = total / 5;
    // Clear input buffer after reading grades
    while(getchar() != '\n');
}

void displayStudentData(const Student* student) {
    printf("\n----- Student Details -----\n");
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", student->grades[i]);
    }
    printf("\nAverage Grade: %.2f\n", student->average);
}

void findTopStudent(Student students[], int numStudents) {
    float highestAverage = 0;
    int topStudentIndex = -1;
    
    for(int i = 0; i < numStudents; i++) {
        if (students[i].average > highestAverage) {
            highestAverage = students[i].average;
            topStudentIndex = i;
        }
    }

    if (topStudentIndex != -1) {
        printf("\nTop Student:\n");
        displayStudentData(&students[topStudentIndex]);
    } else {
        printf("\nNo students to evaluate.\n");
    }
}

void sortStudentsByName(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void displayAllStudents(const Student students[], int numStudents) {
    printf("\n----- All Students -----\n");
    for (int i = 0; i < numStudents; i++) {
        displayStudentData(&students[i]);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    char choice;
    
    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Find Top Student\n");
        printf("4. Sort Students by Name\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        choice = getchar();
        while(getchar() != '\n'); // Clear input buffer

        switch (choice) {
            case '1':
                if (numStudents < MAX_STUDENTS) {
                    inputStudentData(&students[numStudents]);
                    numStudents++;
                } else {
                    printf("Maximum number of students reached.\n");
                }
                break;
            case '2':
                displayAllStudents(students, numStudents);
                break;
            case '3':
                findTopStudent(students, numStudents);
                break;
            case '4':
                sortStudentsByName(students, numStudents);
                printf("Students sorted by name.\n");
                break;
            case '5':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != '5');

    return 0;
}