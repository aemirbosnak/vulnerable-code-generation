//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 10

typedef struct Student {
    char name[50];
    int rollNo;
    float marks[3];
    struct Student* next;
} Student;

Student* insertAtTail(Student* head) {
    Student* newNode = (Student*)malloc(sizeof(Student));
    printf("Enter name: ");
    scanf("%s", newNode->name);
    printf("Enter roll no: ");
    scanf("%d", &newNode->rollNo);
    printf("Enter marks: ");
    scanf("%f", &newNode->marks[0]);
    newNode->marks[1] = newNode->marks[0] * 2;
    newNode->marks[2] = newNode->marks[0] * 3;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void displayStudents(Student* head) {
    Student* currentStudent = head;
    while (currentStudent) {
        printf("Name: %s\n", currentStudent->name);
        printf("Roll No: %d\n", currentStudent->rollNo);
        printf("Marks: ");
        for (int i = 0; i < 3; i++) {
            printf("%f ", currentStudent->marks[i]);
        }
        printf("\n");
        currentStudent = currentStudent->next;
    }
}

int main() {
    Student* head = NULL;
    head = insertAtTail(head);
    displayStudents(head);

    return 0;
}