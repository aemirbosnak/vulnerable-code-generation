//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

void enqueue(struct node** front_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); // Allocate memory for new node
    new_node->data = new_data;
    new_node->next = NULL;
    if (*front_ref == NULL) {
        new_node->next = new_node; // If the queue is empty, set the next pointer of the new node to itself
        *front_ref = new_node; // Set the front pointer to the new node
    }
    else {
        struct node* last = *front_ref;
        while (last->next!= *front_ref) {
            last = last->next;
        }
        last->next = new_node; // Set the next pointer of the last node to the new node
        new_node->next = *front_ref; // Set the next pointer of the new node to the front node
    }
}

void dequeue(struct node** front_ref) {
    if (*front_ref == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct node* temp = *front_ref;
    *front_ref = (*front_ref)->next; // Set the front pointer to the next node
    free(temp); // Free the memory allocated to the old front node
}

void display(struct node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct node* last = front;
    do {
        printf("%d ", last->data);
        last = last->next;
    } while (last!= front);
    printf("\n");
}

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;
    int choice, data;

    do {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(&front, data);
                break;
            case 2:
                dequeue(&front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}