//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void enqueue(node** front, node** rear, int data) {
    node* new_node = create_node(data);
    if (*front == NULL) {
        *front = new_node;
        *rear = new_node;
    } else {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

int dequeue(node** front, node** rear) {
    if (*front == NULL) {
        return -1;
    }
    node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}

int peek(node* front) {
    if (front == NULL) {
        return -1;
    }
    return front->data;
}

int is_empty(node* front) {
    return front == NULL;
}

int main() {
    srand(time(NULL));
    node* front = NULL;
    node* rear = NULL;
    int choice;
    int data;

    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Is Empty\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                data = dequeue(&front, &rear);
                if (data!= -1) {
                    printf("Dequeued data: %d\n", data);
                }
                break;
            case 3:
                data = peek(front);
                if (data!= -1) {
                    printf("Front data: %d\n", data);
                }
                break;
            case 4:
                if (is_empty(front)) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);

    return 0;
}