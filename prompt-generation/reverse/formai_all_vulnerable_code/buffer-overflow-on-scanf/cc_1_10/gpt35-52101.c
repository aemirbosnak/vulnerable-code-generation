//FormAI DATASET v1.0 Category: Queue ; Style: statistical
#include <stdio.h>
#include <stdlib.h> 
#define MAX 5

// Define structure for Queue
struct queue {
    int data[MAX];
    int rear, front;
};

// Function prototypes
void enqueue(struct queue *, int);
int dequeue(struct queue *);
int display(struct queue *);

// Main function
int main() {
    struct queue q;
    q.rear = -1;
    q.front = -1;

    int choice, value;

    do {
        printf("\n\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1)
                    printf("The value dequeued is %d.\n", value);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

// Function to enqueue values
void enqueue(struct queue *q, int value) {
    if (q->rear == MAX-1) {
        printf("Queue Overflow. Cannot insert value.\n");
        return;
    }

    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->data[q->rear] = value;
    } else {
        q->rear++;
        q->data[q->rear] = value;
    }

    printf("%d is successfully inserted in queue.\n", value);
}

// Function to dequeue values
int dequeue(struct queue *q) {
    if (q->front == -1) {
        printf("Queue Underflow. Cannot delete value.\n");
        return -1;
    }

    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }

    return value;
}

// Function to display queue contents
int display(struct queue *q) {
    if (q->front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }

    printf("Queue contents are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }

    printf("\n");

    return 0;
}