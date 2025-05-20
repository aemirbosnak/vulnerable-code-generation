//Falcon-180B DATASET v1.0 Category: Sorting ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *create_node(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node **head, int data) {
    Node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display_list(Node *head) {
    if (head == NULL) {
        printf("Empty list\n");
        return;
    }
    Node *temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void merge_sort(Node **head) {
    Node *curr = *head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr!= NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    Node *head = NULL;
    int choice, data;
    do {
        printf("1. Insert element\n");
        printf("2. Display list\n");
        printf("3. Sort list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insert_node(&head, data);
                break;
            case 2:
                display_list(head);
                break;
            case 3:
                merge_sort(&head);
                printf("List sorted\n");
                display_list(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}