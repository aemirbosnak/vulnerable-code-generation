//FormAI DATASET v1.0 Category: Queue Implementation ; Style: active
/* A unique C queue implementation example program */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // MAX_SIZE of the queue

// Queue data structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
void initQueue(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmpty(Queue* q);
void display(Queue* q);

// Function to initialize a queue
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if(q->rear == MAX_SIZE-1)
        printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
        printf("\nInserted -> %d", value);
    }
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    int item;
    if(isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    }
    else {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear) {
            printf("\nResetting queue ");
            q->front = q->rear = -1;
        }
        printf("\nDeleted -> %d", item);
    }
    return item;
}

// Function to display the queue
void display(Queue* q) {
    int i;
    if(isEmpty(q))
        printf("Queue is empty");
    else {
        printf("\n\nQueue elements are:\n");
        for(i=q->front; i<=q->rear; i++)
            printf("%d  ", q->items[i]);
    }   
}

int main() {
    Queue q;
    int choice, value;
    initQueue(&q);
    printf("Queue using array");
    do {
        printf("\n\nQueue MENU:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("\nEnter the value to be inserted/Enqueued : ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("\n\nExiting from the program\n");
                exit(0);
                break;
            default:
                printf("\nWrong choice\n");
                break;
        }
    } while(choice != 4);
    return 0;
}