//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENT 100

typedef struct Student {
    char name[50];
    int roll_no;
    float marks[5];
    struct Student *next;
} Student;

Student *insert_at_tail(Student *head) {
    Student *new_node = (Student *)malloc(sizeof(Student));
    printf("Enter name: ");
    scanf("%s", new_node->name);
    printf("Enter roll no: ");
    scanf("%d", &new_node->roll_no);
    printf("Enter marks: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &new_node->marks[i]);
    }

    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }

    return head;
}

void display_students(Student *head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Roll No: %d\n", head->roll_no);
        printf("Marks: ");
        for (int i = 0; i < 5; i++) {
            printf("%f ", head->marks[i]);
        }
        printf("\n");
        head = head->next;
    }
}

int main() {
    Student *head = NULL;
    int choice;

    printf("Enter 1 to insert a student, 2 to display students: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            head = insert_at_tail(head);
            break;
        case 2:
            display_students(head);
            break;
        default:
            printf("Invalid choice");
            break;
    }

    return 0;
}