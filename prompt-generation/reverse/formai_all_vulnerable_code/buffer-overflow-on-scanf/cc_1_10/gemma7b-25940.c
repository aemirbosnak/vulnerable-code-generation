//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct Student {
    char name[50];
    int roll_no;
    float marks[3];
    struct Student* next;
} Student;

void insertStudent(Student** head) {
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

    if (*head == NULL) {
        *head = newStudent;
    } else {
        (*head)->next = newStudent;
    }
}

void displayStudents(Student* head) {
    while (head) {
        printf("%s (Roll No: %d)\n", head->name, head->roll_no);
        printf("Marks: %.1f, %.1f, %.1f\n", head->marks[0], head->marks[1], head->marks[2]);
        printf("\n");
        head = head->next;
    }
}

int main() {
    Student* head = NULL;

    insertStudent(&head);
    insertStudent(&head);
    insertStudent(&head);

    displayStudents(head);

    return 0;
}