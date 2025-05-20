//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: high level of detail
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

Student* insert_at_tail(Student* head) {
    Student* new_node = (Student*)malloc(sizeof(Student));
    printf("Enter name: ");
    scanf("%s", new_node->name);
    printf("Enter roll no: ");
    scanf("%d", &new_node->roll_no);
    printf("Enter marks: ");
    scanf("%f", &new_node->marks[0]);
    scanf("%f", &new_node->marks[1]);
    scanf("%f", &new_node->marks[2]);

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

void print_students(Student* head) {
    Student* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Roll no: %d\n", current->roll_no);
        printf("Marks: %.1f, %.1f, %.1f\n", current->marks[0], current->marks[1], current->marks[2]);
        printf("\n");
        current = current->next;
    }
}

int main() {
    Student* head = NULL;

    while (1) {
        printf("1. Insert at tail\n");
        printf("2. Print students\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insert_at_tail(head);
                break;
            case 2:
                print_students(head);
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    }

    return 0;
}