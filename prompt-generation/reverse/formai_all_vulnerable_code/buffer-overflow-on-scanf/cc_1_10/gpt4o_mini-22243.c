//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student information
struct Student {
    char name[100];
    int age;
    float gpa;
};

// Function to compare two students by name
int compareStudents(const void *a, const void *b) {
    struct Student *studentA = (struct Student *)a;
    struct Student *studentB = (struct Student *)b;
    return strcmp(studentA->name, studentB->name);
}

// Function to display student information
void displayStudents(struct Student *students, int n) {
    printf("\nStudent Information:\n");
    printf("%-30s %-5s %-5s\n", "Name", "Age", "GPA");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-30s %-5d %-5.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

// Main function
int main() {
    struct Student students[100];
    int n = 0;
    char choice;

    // Menu
    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. Sort Students by Name\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        choice = getchar();
        getchar();  // to consume the newline after choice

        switch (choice) {
            case '1':
                if (n < 100) {
                    printf("Enter Name: ");
                    fgets(students[n].name, 100, stdin);
                    students[n].name[strcspn(students[n].name, "\n")] = 0; // Remove newline
                    printf("Enter Age: ");
                    scanf("%d", &students[n].age);
                    printf("Enter GPA: ");
                    scanf("%f", &students[n].gpa);
                    getchar(); // to consume the newline after GPA
                    n++;
                } else {
                    printf("Maximum student limit reached!\n");
                }
                break;

            case '2':
                if (n > 0) {
                    qsort(students, n, sizeof(struct Student), compareStudents);
                    printf("Students have been sorted by name.\n");
                } else {
                    printf("No students to sort!\n");
                }
                break;

            case '3':
                if (n > 0) {
                    displayStudents(students, n);
                } else {
                    printf("No students to display!\n");
                }
                break;

            case '4':
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != '4');

    return 0;
}