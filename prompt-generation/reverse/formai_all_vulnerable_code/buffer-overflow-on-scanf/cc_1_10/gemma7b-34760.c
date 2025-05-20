//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10

typedef struct Student {
    char name[20];
    int roll_no;
    float marks;
} Student;

Student students[MAX_STUDENTS];

void insertStudent() {
    Student newStudent;

    printf("Enter student's name: ");
    scanf("%s", newStudent.name);

    printf("Enter student's roll number: ");
    scanf("%d", &newStudent.roll_no);

    printf("Enter student's marks: ");
    scanf("%f", &newStudent.marks);

    students[MAX_STUDENTS - 1] = newStudent;
}

void displayStudents() {
    int i;

    for (i = 0; i < MAX_STUDENTS; i++) {
        printf("Name: %s, Roll No: %d, Marks: %.2f\n", students[i].name, students[i].roll_no, students[i].marks);
    }
}

int main() {
    int choice;

    printf("Enter 1 to insert a student, 2 to display students: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            insertStudent();
            break;
        case 2:
            displayStudents();
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}