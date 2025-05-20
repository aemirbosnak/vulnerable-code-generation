//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student data
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Function to compare two students based on their GPA for sorting
int compareGPA(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    if (studentA->gpa < studentB->gpa) return -1;
    if (studentA->gpa > studentB->gpa) return 1;
    return 0;
}

// Function to compare two students based on their name for sorting
int compareName(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return strcmp(studentA->name, studentB->name);
}

// Function to display the students
void displayStudents(Student *students, int count) {
    printf("ID\tName\t\tGPA\n");
    printf("-----------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-10s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

int main() {
    // Sample student data
    Student students[] = {
        {1, "Alice", 3.5},
        {2, "Bob", 3.8},
        {3, "Charlie", 3.2},
        {4, "David", 3.9},
        {5, "Eve", 3.1}
    };
    
    int studentCount = sizeof(students) / sizeof(students[0]);
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Sort by GPA\n");
        printf("2. Sort by Name\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                qsort(students, studentCount, sizeof(Student), compareGPA);
                printf("Students sorted by GPA.\n");
                break;

            case 2:
                qsort(students, studentCount, sizeof(Student), compareName);
                printf("Students sorted by Name.\n");
                break;

            case 3:
                displayStudents(students, studentCount);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}