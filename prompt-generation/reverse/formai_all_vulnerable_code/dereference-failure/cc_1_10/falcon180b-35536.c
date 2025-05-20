//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define structure for Queue
typedef struct {
    int data;
    struct node *next;
} node;

// Define structure for Queue
typedef struct {
    node *front;
    node *rear;
    int size;
} Queue;

// Function to create an empty Queue
Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to check if Queue is empty
bool isEmpty(Queue *q) {
    return (q->front == NULL);
}

// Function to check if Queue is full
bool isFull(Queue *q) {
    return (q->size == MAX_SIZE);
}

// Function to add element to Queue
void enqueue(Queue *q, int data) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

// Function to remove element from Queue
int dequeue(Queue *q) {
    int data;
    node *temp = q->front;
    data = temp->data;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return data;
}

// Function to display elements in Queue
void display(Queue *q) {
    node *temp = q->front;
    printf("Queue elements: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Queue *q = createQueue();
    int choice, data;
    while (true) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                data = dequeue(q);
                printf("Dequeued data: %d\n", data);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}