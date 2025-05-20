//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float grades[5];  // Assuming five subjects
    float average;
} Student;

void calculate_average(Student *student) {
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student->grades[i];
    }
    student->average = sum / 5;
}

void print_student_info(const Student *student) {
    printf("Student ID: %d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", student->grades[i]);
    }
    printf("\nAverage Grade: %.2f\n", student->average);
}

void input_student_info(Student *student) {
    printf("Enter Student ID: ");
    scanf("%d", &student->id);
    printf("Enter Student Name: ");
    getchar();  // To consume newline character left in the buffer
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    student->name[strcspn(student->name, "\n")] = 0;  // Remove newline character

    for (int i = 0; i < 5; i++) {
        printf("Enter grade for subject %d: ", i + 1);
        scanf("%f", &student->grades[i]);
    }

    calculate_average(student);
}

void print_all_students(Student *students, int count) {
    printf("\nPrinting all student information:\n");
    for (int i = 0; i < count; i++) {
        print_student_info(&students[i]);
        printf("------------------------------\n");
    }
}

int search_student_by_id(Student *students, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;  // Return index of student found
        }
    }
    return -1;  // Not found
}

void delete_student(Student *students, int *count, int id) {
    int index = search_student_by_id(students, *count, id);
    if (index != -1) {
        for (int i = index; i < *count - 1; i++) {
            students[i] = students[i + 1];  // Shift students left
        }
        (*count)--;  // Decrease the total count of students
        printf("Student with ID %d has been removed successfully.\n", id);
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int student_count = 0;
    int choice, id;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (student_count < MAX_STUDENTS) {
                    input_student_info(&students[student_count]);
                    student_count++;
                } else {
                    printf("Maximum student limit reached!\n");
                }
                break;

            case 2:
                print_all_students(students, student_count);
                break;

            case 3:
                printf("Enter Student ID to delete: ");
                scanf("%d", &id);
                delete_student(students, &student_count, id);
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}