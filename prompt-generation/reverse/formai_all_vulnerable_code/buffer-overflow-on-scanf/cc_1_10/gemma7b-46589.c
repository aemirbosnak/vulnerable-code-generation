//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 50

typedef struct Student {
    char name[50];
    int roll_no;
    float marks[4];
    struct Student* next;
} Student;

Student* insertStudent(Student* head) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    printf("Enter name: ");
    scanf("%s", newStudent->name);
    printf("Enter roll no: ");
    scanf("%d", &newStudent->roll_no);
    printf("Enter marks: ");
    for (int i = 0; i < 4; i++) {
        scanf("%f", &newStudent->marks[i]);
    }

    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        head->next = newStudent;
    }

    return head;
}

void displayStudents(Student* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Roll No: %d\n", head->roll_no);
        printf("Marks: ");
        for (int i = 0; i < 4; i++) {
            printf("%f ", head->marks[i]);
        }
        printf("\n");
        head = head->next;
    }
}

int main() {
    Student* head = NULL;

    while (1) {
        int choice;
        printf("1. Insert Student\n");
        printf("2. Display Students\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertStudent(head);
                break;
            case 2:
                displayStudents(head);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}