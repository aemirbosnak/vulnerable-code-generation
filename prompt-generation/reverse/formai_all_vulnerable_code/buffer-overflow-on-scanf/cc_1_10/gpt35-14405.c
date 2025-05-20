//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include<stdlib.h>
#include<stdio.h>

#define SIZE 5 //maximum size of queue

typedef struct {
    int data[SIZE];
    int front;
    int rear;
} Queue;

Queue* createQueue(); //function to create an empty queue
void enqueue(Queue *q, int x); //function to add an element to the queue
int dequeue(Queue *q); //function to remove and return an element from the queue
int peek(Queue *q); //function to return the element at the front of the queue
int isFull(Queue *q); //function to check if the queue is full
int isEmpty(Queue *q); //function to check if the queue is empty
void display(Queue *q); //function to display the elements of the queue

int main() {
    Queue *q = createQueue(); //create a new queue
    int choice, x;

    while(1) {
        //display menu
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(isFull(q)) {
                    printf("Queue is full!\n");
                }
                else{
                    printf("Enter element to be enqueued: ");
                    scanf("%d", &x);
                    enqueue(q, x);
                }
                break;
            case 2:
                if(isEmpty(q)) {
                    printf("Queue is empty!\n");
                }
                else{
                    x = dequeue(q);
                    printf("Dequeued element: %d\n", x);
                }
                break;
            case 3:
                if(isEmpty(q)) {
                    printf("Queue is empty!\n");
                }
                else{
                    x = peek(q);
                    printf("Element at the front of queue: %d\n", x);
                }
                break;
            case 4:
                display(q);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue *q, int x) {
    if(q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = x;
    printf("Enqueued element: %d\n", x);
}

int dequeue(Queue *q) {
    int x = q->data[q->front];
    if(q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front++;
    }
    return x;
}

int peek(Queue *q) {
    return q->data[q->front];
}

int isFull(Queue *q) {
    if(q->rear == SIZE-1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isEmpty(Queue *q) {
    if(q->front == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void display(Queue *q) {
    if(isEmpty(q)) {
        printf("Queue is empty!\n");
    }
    else {
        int i;
        printf("Elements of the queue: ");
        for(i=q->front; i<=q->rear; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}