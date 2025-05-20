//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: Unable to create new node.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void enqueue(node** head, int data) {
    node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

int dequeue(node** head) {
    int data = 0;
    if (*head == NULL) {
        printf("Error: Queue is empty.\n");
        exit(1);
    }
    node* temp = *head;
    data = temp->data;
    *head = temp->next;
    free(temp);
    return data;
}

void display(node* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node* head = NULL;
    int choice, data;
    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&head, data);
                break;
            case 2:
                data = dequeue(&head);
                if (data!= 0) {
                    printf("Dequeued element is: %d\n", data);
                }
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}