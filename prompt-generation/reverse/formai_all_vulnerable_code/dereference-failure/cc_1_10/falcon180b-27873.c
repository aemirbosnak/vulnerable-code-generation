//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Initialize an empty queue
void initQueue(struct Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    if (q->front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Check if the queue is full
int isFull(struct Queue* q) {
    if ((q->rear!= NULL) && (q->rear->next == NULL)) {
        return 1;
    } else {
        return 0;
    }
}

// Enqueue an element in the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Dequeue an element from the queue
int dequeue(struct Queue* q) {
    int data = 0;
    struct Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue Underflow\n");
    } else {
        data = temp->data;
        q->front = temp->next;
        free(temp);
    }

    return data;
}

// Display the elements of the queue
void display(struct Queue* q) {
    struct Node* temp = q->front;

    if (isEmpty(q)) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    int choice, data;

    initQueue(&q);

    while (1) {
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
                enqueue(&q, data);
                break;
            case 2:
                data = dequeue(&q);
                printf("Dequeued element is: %d\n", data);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}