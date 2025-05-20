//FormAI DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

// Struct defining the C Queue
typedef struct {
    int front, rear;
    int arr[MAX_SIZE];
} cQueue;

// C Queue operations
void init(cQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(cQueue *q) {
    return ((q->front == 0 && q->rear == MAX_SIZE - 1) || q->front == q->rear + 1);
}

int isEmpty(cQueue *q) {
    return (q->front == -1);
}

void enqueue(cQueue *q, int element) {
    if (isFull(q)) {
        printf("Error: Queue is full!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->arr[q->rear] = element;
        printf("Enqueued element %d.\n", element);
    }
}

int dequeue(cQueue *q) {
    int element;
    if (isEmpty(q)) {
        printf("Error: Queue is empty!\n");
        return (-1);
    } else {
        element = q->arr[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX_SIZE;
        }
        printf("Dequeued element %d.\n", element);
        return (element);
    }
}

void display(cQueue *q) {
    int i;
    if (isEmpty(q)) {
        printf("Error: Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (i = q->front; i != q->rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", q->arr[i]);
        }
        printf("%d\n", q->arr[i]);
    }
}

// Main function
int main() {
    cQueue q;
    int choice, element;

    init(&q);

    do {
        // Display menu
        printf("\n\n Queue Operations \n\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch cases based on user's choice
        switch (choice) {

            case 1:
                printf("Enter element to be enqueued: ");
                scanf("%d", &element);
                enqueue(&q, element);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("\n\nExiting program...Thank you for using our C Queue Implementation example !");
                break;

            default:
                printf("\n\nInvalid choice! Please choose a valid operation.(1/2/3/4)\n");
        }

    } while (choice != 4);

    return 0;
}