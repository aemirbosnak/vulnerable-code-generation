//FormAI DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>

#define MAX_STUDENTS 20
#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    int id;
    float gpa;
};

void print_student_information(struct Student s) {
    printf("Name: %s\n", s.name);
    printf("ID: %d\n", s.id);
    printf("GPA: %.2f\n", s.gpa);
}

int main() {
    struct Student students[MAX_STUDENTS];
    int num_students = 0;

    char choice;
    do {
        printf("Add new student? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            if (num_students >= MAX_STUDENTS) {
                printf("Maximum number of students reached.\n");
            } else {
                // Get student name
                printf("Enter student name: ");
                scanf(" %[^\n]s", students[num_students].name);

                // Get student ID
                printf("Enter student ID: ");
                scanf("%d", &students[num_students].id);

                // Get student GPA
                printf("Enter student GPA: ");
                scanf("%f", &students[num_students].gpa);

                num_students++;
            }
        }
    } while (choice != 'n' && choice != 'N');

    // Print all student information
    printf("\nStudent Information\n");
    printf("-------------------\n");

    for (int i = 0; i < num_students; i++) {
        print_student_information(students[i]);
        printf("-------------------\n");
    }

    return 0;
}