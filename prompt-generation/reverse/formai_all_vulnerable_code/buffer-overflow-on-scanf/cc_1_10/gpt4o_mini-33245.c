//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

// Structure to hold student information
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float grades[5];
    float average;
} Student;

// Function prototypes
void addStudent(Student *students, int *studentCount);
void viewStudents(const Student *students, int studentCount);
void calculateAverage(Student *student);
void sortStudentsDescending(Student *students, int studentCount);
void printMenu();

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // to consume the newline character

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                viewStudents(students, studentCount);
                break;
            case 3:
                sortStudentsDescending(students, studentCount);
                printf("Students sorted by average grades in descending order!\n");
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void printMenu() {
    printf("\n*** Student Management System ***\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Sort Students by Average Grades\n");
    printf("4. Exit\n");
}

void addStudent(Student *students, int *studentCount) {
    if (*studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    Student newStudent;
    newStudent.id = *studentCount + 1;

    printf("Enter name for student %d: ", newStudent.id);
    fgets(newStudent.name, MAX_NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // removes newline

    printf("Enter grades for 5 subjects (separated by space): ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &newStudent.grades[i]);
    }
    getchar(); // consume remaining newline

    calculateAverage(&newStudent);
    students[*studentCount] = newStudent;
    (*studentCount)++;

    printf("Student %d added successfully!\n", newStudent.id);
}

void calculateAverage(Student *student) {
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student->grades[i];
    }
    student->average = sum / 5;
}

void viewStudents(const Student *students, int studentCount) {
    if (studentCount == 0) {
        printf("No students available to display.\n");
        return;
    }

    printf("\nID\tName\t\tAverage Grade\n");
    printf("------------------------------------\n");
    for (int i = 0; i < studentCount; i++) {
        printf("%d\t%-15s\t%.2f\n", students[i].id, students[i].name, students[i].average);
    }
}

void sortStudentsDescending(Student *students, int studentCount) {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}