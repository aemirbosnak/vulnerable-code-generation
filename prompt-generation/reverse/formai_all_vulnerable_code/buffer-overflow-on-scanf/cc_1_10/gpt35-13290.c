//FormAI DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head, int val) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = *head;
    *head = new_node;
}

void delete(struct node **head, int val) {
    if (*head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    struct node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->data == val) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Data not found in linked list.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void display(struct node *head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice, val;
    do {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insert(&head, val);
                printf("%d inserted to linked list.\n", val);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                delete(&head, val);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    return 0;
}