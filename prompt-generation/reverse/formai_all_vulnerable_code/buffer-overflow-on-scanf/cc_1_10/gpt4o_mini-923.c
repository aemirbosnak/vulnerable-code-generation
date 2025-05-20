//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

void display_student(Student *s);
void add_student(Student **students, int *count);
void free_students(Student *students, int count);
void sort_students(Student *students, int count);
void display_all_students(Student *students, int count);

int main() {
    Student *students = NULL;
    int count = 0;
    int option;

    // Allocate memory for students initially
    students = (Student *)malloc(MAX_STUDENTS * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Sort Students by Grade\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (count < MAX_STUDENTS) {
                    add_student(&students, &count);
                } else {
                    printf("Maximum student limit reached!\n");
                }
                break;
            case 2:
                display_all_students(students, count);
                break;
            case 3:
                sort_students(students, count);
                printf("Students sorted by grade.\n");
                break;
            case 4:
                printf("Exiting program. Freeing resources...\n");
                free_students(students, count);
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }

    } while(option != 4);
    
    return 0;
}

void add_student(Student **students, int *count) {
    Student *s = &((*students)[*count]);

    printf("Enter name: ");
    scanf("%s", s->name);
    printf("Enter age: ");
    scanf("%d", &s->age);
    printf("Enter grade: ");
    scanf("%f", &s->grade);

    (*count)++;
}

void display_student(Student *s) {
    printf("Name: %s, Age: %d, Grade: %.2f\n", s->name, s->age, s->grade);
}

void display_all_students(Student *students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    for (int i = 0; i < count; i++) {
        display_student(&students[i]);
    }
}

void sort_students(Student *students, int count) {
    // Simple bubble sort for demonstration purposes
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].grade < students[j + 1].grade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void free_students(Student *students, int count) {
    // As we allocated a contiguous block of memory,
    // we simply free it in one go
    if (students != NULL) {
        free(students);
        printf("Memory freed for %d students.\n", count);
    }
}