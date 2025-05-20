//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 50

typedef struct student {
    char name[50];
    int roll_no;
    float marks[5];
    struct student* next;
} student;

void insert_at_tail(student** head) {
    student* new_node = (student*)malloc(sizeof(student));
    printf("Enter name: ");
    scanf("%s", new_node->name);
    printf("Enter roll no: ");
    scanf("%d", &new_node->roll_no);
    printf("Enter marks: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &new_node->marks[i]);
    }

    if (*head == NULL) {
        *head = new_node;
    } else {
        (*head)->next = new_node;
    }
    (*head)->next = NULL;
}

void print_students(student* head) {
    while (head) {
        printf("Name: %s\n", head->name);
        printf("Roll no: %d\n", head->roll_no);
        printf("Marks: ");
        for (int i = 0; i < 5; i++) {
            printf("%f ", head->marks[i]);
        }
        printf("\n");
        head = head->next;
    }
}

int main() {
    student* head = NULL;
    insert_at_tail(&head);
    insert_at_tail(&head);
    insert_at_tail(&head);
    print_students(head);
    return 0;
}