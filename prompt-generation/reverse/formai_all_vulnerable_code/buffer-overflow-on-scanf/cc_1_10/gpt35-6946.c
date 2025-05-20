//FormAI DATASET v1.0 Category: Database simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[20];
    int roll;
    float marks;
} Student;

typedef struct Node {
    Student data;
    struct Node * next;
} Node;

void printList(Node *head) {
    Node *curr = head;
    printf("\n\nName\t\tRoll No.\tMarks\n");
    while (curr != NULL) {
        printf("%s\t\t%d\t\t%.2f\n", curr->data.name, curr->data.roll, curr->data.marks);
        curr = curr->next;
    }
}

void insert(Node **head, Student data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void delete(Node **head, char name[]) {
    Node *curr = *head, *prev = NULL;
    while (curr != NULL) {
        if (strcmp(curr->data.name, name) == 0) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("\nStudent not found.");
        return;
    }
    if (prev == NULL) {
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    printf("\nStudent deleted successfully.");
}

void update(Node **head, char name[], int roll, float marks) {
    Node *curr = *head;
    while (curr != NULL) {
        if (strcmp(curr->data.name, name) == 0) {
            break;
        }
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("\nStudent not found.");
        return;
    }
    strcpy(curr->data.name, name);
    curr->data.roll = roll;
    curr->data.marks = marks;
    printf("\nStudent details updated successfully.");
}

int main() {
    Node* head = NULL;
    int choice, roll;
    float marks;
    char name[20];
    do {
        printf("\n\n\n*************** C DATABASE SIMULATION ******************");
        printf("\n\n1. Add student\n2. Delete student\n3. Update student\n4. Print student details\n5. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("\nEnter roll no: ");
                scanf("%d", &roll);
                printf("\nEnter marks: ");
                scanf("%f", &marks);
                Student newStudent = { .name = name, .roll = roll, .marks = marks };
                insert(&head, newStudent);
                printf("\nStudent added successfully.");
                break;
            case 2:
                printf("\nEnter name of student to be deleted: ");
                scanf("%s", name);
                delete(&head, name);
                break;
            case 3:
                printf("\nEnter name of student to be updated: ");
                scanf("%s", name);
                printf("\nEnter new name: ");
                scanf("%s", name);
                printf("\nEnter new roll no: ");
                scanf("%d", &roll);
                printf("\nEnter new marks: ");
                scanf("%f", &marks);
                update(&head, name, roll, marks);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice.");
        }
    } while (1);
    return 0;
}