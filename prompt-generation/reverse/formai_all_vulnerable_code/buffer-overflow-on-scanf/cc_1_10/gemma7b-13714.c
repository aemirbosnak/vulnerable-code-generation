//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10

typedef struct Student {
    char name[20];
    int roll_no;
    float marks;
} Student;

Student students[MAX_STUDENTS];

void add_student() {
    Student new_student;

    printf("Enter student's name: ");
    scanf("%s", new_student.name);

    printf("Enter student's roll number: ");
    scanf("%d", &new_student.roll_no);

    printf("Enter student's marks: ");
    scanf("%f", &new_student.marks);

    students[MAX_STUDENTS - 1] = new_student;
}

void display_students() {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("Name: %s, Roll No: %d, Marks: %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }
}

int main() {
    int choice;

    printf("Welcome to the Student Database!\n");

    while (1) {
        printf("Enter 1 to add a student, 2 to display students, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}