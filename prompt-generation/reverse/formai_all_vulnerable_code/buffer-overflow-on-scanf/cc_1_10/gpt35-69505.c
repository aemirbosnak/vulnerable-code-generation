//FormAI DATASET v1.0 Category: Data structures visualization ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure definition
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} Queue;

// Function to initialize queue
void initialize(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to insert value into queue
void insert(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Overflow\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = value;
        printf("Inserted: %d\n", value);
    }
}

// Function to delete value from queue
void delete(Queue* q) {
    if (q->front == -1) {
        printf("Underflow\n");
    } else {
        printf("Deleted: %d\n", q->data[q->front]);
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
}

// Function to display queue
void display(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue contents:\n");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d\n", q->data[i]);
        }
    }
}

// Main function
int main() {
    Queue q;
    initialize(&q);

    printf("WELCOME TO VISUAL QUEUE SIMULATION!\n");
    printf("==================================\n\n");

    while (1) {
        printf("Please select an operation to perform:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n\n");
        printf("Choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("\nEnter value to insert: ");
                int value;
                scanf("%d", &value);
                insert(&q, value);
                printf("\n");
                break;
            }
            case 2: {
                delete(&q);
                printf("\n");
                break;
            }
            case 3: {
                display(&q);
                printf("\n");
                break;
            }
            case 4: {
                printf("Thank you for using Visual Queue Simulation!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
            }
        }
    }

    return 0;
}