//FormAI DATASET v1.0 Category: Queue ; Style: bold
// Bold Queue Program in C

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50 // Maximum size of queue

// Structure definition for Queue
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototype declarations for Queue operations
void insert(Queue *, int);
int delete(Queue *);
void display(Queue *);

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    int choice, x;
    while (1) { // Loop to keep the program running until user chooses to exit
        printf("\nChoose an option:\n");
        printf("1. Insert element into queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display elements in queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &x);
                insert(&q, x); // Address of queue passed as argument to update its values
                break;
            case 2:
                x = delete(&q); // Address of queue passed as argument to update its values
                if (x != -1) { // -1 returned when queue is empty
                    printf("Deleted element: %d\n", x);
                }
                break;
            case 3:
                display(&q); // Address of queue passed as argument to display its elements
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Function to insert element into queue
void insert(Queue *q, int x) {
    if (q->rear == MAX_SIZE - 1) { // Check if queue is full
        printf("Queue Overflow\n");
    } else {
        if (q->front == -1) {
            q->front = 0; // Set front to 0 if inserting the first element
        }
        q->rear++;
        q->data[q->rear] = x; // Insert element at rear
        printf("Inserted element: %d\n", x);
    }
}

// Function to delete element from queue
int delete(Queue *q) {
    int x;
    if (q->front == -1 || q->front > q->rear) { // Check if queue is empty
        printf("Queue Underflow\n");
        return -1;
    } else {
        x = q->data[q->front]; // Get the element at front
        q->front++;
    }
    return x;
}

// Function to display elements in queue
void display(Queue *q) {
    int i;
    if (q->front == -1 || q->front > q->rear) { // Check if queue is empty
        printf("Queue is empty\n");
    } else {
        printf("Elements in Queue: ");
        for (i = q->front; i <= q->rear; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}