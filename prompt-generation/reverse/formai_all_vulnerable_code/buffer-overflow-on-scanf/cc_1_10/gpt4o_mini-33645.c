//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

void addStudent(Student **students, int *count) {
    *students = realloc(*students, (*count + 1) * sizeof(Student));
    if (*students == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    printf("Enter name: ");
    scanf("%s", (*students)[*count].name);
    printf("Enter age: ");
    scanf("%d", &(*students)[*count].age);
    printf("Enter grade: ");
    scanf("%f", &(*students)[*count].grade);

    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(Student *students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: Name: %s, Age: %d, Grade: %.2f\n", 
               i + 1, students[i].name, students[i].age, students[i].grade);
    }
}

void freeStudents(Student *students) {
    free(students);
    printf("All allocated memory for students has been freed.\n");
}

int main() {
    Student *students = NULL;
    int studentCount = 0;
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                freeStudents(students);
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}