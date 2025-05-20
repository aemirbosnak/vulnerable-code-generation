//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node* next;
} node;

node* create_node(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void enqueue(node** head, int data) {
    node* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
    printf("Element %d enqueued.\n", data);
}

void dequeue(node** head) {
    if (*head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Element dequeued.\n");
}

void display(node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int choice, data;
    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(&head, data);
                break;
            case 2:
                dequeue(&head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);
    return 0;
}