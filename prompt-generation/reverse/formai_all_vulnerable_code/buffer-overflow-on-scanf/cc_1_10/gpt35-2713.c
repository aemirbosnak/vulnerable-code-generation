//FormAI DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

#define MAXQUEUE 5 // maximum size of queue

// defining structure for queue
typedef struct queue {
    int front;
    int rear;
    int items[MAXQUEUE];
}queue;

// function to initialize queue
void initqueue(queue *q) {
    q->front = -1;
    q->rear = -1;
}

// function to check if queue is full
int isfull(queue *q) {
    return q->rear == MAXQUEUE-1;
}

// function to check if queue is empty
int isempty(queue *q) {
    return q->front == -1;
}

// function to add an element to the rear of queue
void enqueue(queue *q, int val) {
    if(isfull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = val;
    if(q->front == -1) {
        q->front++;
    }
}

// function to remove an element from the front of queue
int dequeue(queue *q) {
    int val;
    if(isempty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    val = q->items[q->front];
    q->front++;
    if(q->front > q->rear) {
        initqueue(q);
    }
    return val;
}

// function to display the contents of the queue
void display(queue *q) {
    int i;
    if(isempty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue contents:\n");
    for(i=q->front; i<=q->rear; i++) {
        printf("%d\n", q->items[i]);
    }
}

// main function
int main() {
    int choice, val;
    queue q;
    initqueue(&q);
    while(1) {
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                val = dequeue(&q);
                if(val != -1){
                    printf("Dequeued value: %d\n", val);
                }
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}