//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

typedef struct {
    int roll_number;
    char name[50];
    float marks;
} Student;

void read_student_data(Student students[], int *count) {
    Student student;
    int n = *count;

    printf("Enter student data (Roll Number, Name, Marks) or '0' to exit:\n");

    while (n < MAX_STUDENTS && scanf("%d%s%f", &student.roll_number, student.name, &student.marks) == 3) {
        strcpy(students[*count].name, student.name);
        students[*count].roll_number = student.roll_number;
        students[*count].marks = student.marks;
        (*count)++;

        printf("Student data added successfully.\n");
        printf("Enter student data (Roll Number, Name, Marks) or '0' to exit:\n");
    }
}

void search_student(Student students[], int count) {
    int roll_number;
    int i;

    printf("Enter roll number of student to search for: ");
    scanf("%d", &roll_number);

    for (i = 0; i < count; i++) {
        if (students[i].roll_number == roll_number) {
            printf("Name: %s\nMarks: %.2f\n", students[i].name, students[i].marks);
            return;
        }
    }

    printf("Student not found.\n");
}

void print_menu() {
    printf("\n1. Add Student\n2. Search Student\n3. Exit\n");
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                read_student_data(students, &count);
                break;
            case 2:
                search_student(students, count);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}