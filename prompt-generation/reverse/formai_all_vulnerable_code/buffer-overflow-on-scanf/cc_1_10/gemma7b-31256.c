//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 10

typedef struct Student {
    char name[50];
    int roll_no;
    float marks[3];
    struct Student* next;
} Student;

Student* insertStudent(Student* head) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    printf("Enter student name: ");
    scanf("%s", newStudent->name);
    printf("Enter student roll number: ");
    scanf("%d", &newStudent->roll_no);
    printf("Enter student marks: ");
    scanf("%f", &newStudent->marks[0]);
    scanf("%f", &newStudent->marks[1]);
    scanf("%f", &newStudent->marks[2]);
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        head->next = newStudent;
    }

    return head;
}

void displayStudents(Student* head) {
    Student* currentStudent = head;

    while (currentStudent) {
        printf("Name: %s, Roll No: %d, Marks: %.1f, %.1f, %.1f\n", currentStudent->name, currentStudent->roll_no, currentStudent->marks[0], currentStudent->marks[1], currentStudent->marks[2]);
        currentStudent = currentStudent->next;
    }
}

int main() {
    Student* head = NULL;

    while (1) {
        printf("Enter 1 to insert a student, 2 to display students, or 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertStudent(head);
                break;
            case 2:
                displayStudents(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}