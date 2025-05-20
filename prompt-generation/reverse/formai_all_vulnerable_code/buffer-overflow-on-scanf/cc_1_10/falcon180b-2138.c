//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // Maximum size of the queue

// Node structure definition
typedef struct node {
    int data;
    struct node *next;
} Node;

// Queue structure definition
typedef struct {
    Node *front;
    Node *rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    if (q->front == NULL)
        return 1;
    else
        return 0;
}

// Function to check if the queue is full
int isFull(Queue *q) {
    Node *temp = q->rear;
    while (temp!= NULL) {
        temp = temp->next;
        if (temp == q->front)
            return 1;
    }
    return 0;
}

// Function to enqueue an element into the queue
void enqueue(Queue *q, int value) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newnode->data = value;
    newnode->next = NULL;
    if (isEmpty(q)) {
        q->front = newnode;
        q->rear = newnode;
    }
    else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue *q) {
    int value;
    Node *temp = q->front;
    if (isEmpty(q))
        return -1;
    else {
        value = temp->data;
        q->front = temp->next;
        free(temp);
        return value;
    }
}

// Function to display the elements in the queue
void display(Queue *q) {
    Node *temp = q->front;
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    Queue *q = createQueue();
    int choice, value;

    do {
        printf("\n\nMENU\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if (value!= -1)
                    printf("Dequeued value is: %d\n", value);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}