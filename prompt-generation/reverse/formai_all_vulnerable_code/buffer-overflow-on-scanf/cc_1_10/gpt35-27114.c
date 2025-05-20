//FormAI DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#define MAX 10 // Maximum size of the queue

// Structure of Queue
typedef struct queue{
    int data[MAX];
    int front;
    int rear;
}Queue;

// Function prototypes
void initQueue(Queue *q); // Initialized the queue
int isFull(Queue *q); // Checks if the queue is full
int isEmpty(Queue *q); // Checks if the queue is empty
void enqueue(Queue *q, int value); // Enqueues an element in the queue
void dequeue(Queue *q); // Dequeues an element from the queue
void display(Queue *q); // Displays the elements of the queue

// Function to initialize the queue
void initQueue(Queue *q){
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue *q){
    if(q->rear == MAX-1)
        return 1;
    else
        return 0;
}

// Function to check if the queue is empty
int isEmpty(Queue *q){
    if(q->front == -1)
        return 1;
    else
        return 0;
}

// Function to enqueue an element in the queue
void enqueue(Queue *q, int value){
    if(isFull(q)){
        printf("Queue is full!\n");
        return;
    }
    else{
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->data[q->rear] = value;
        printf("%d enqueued successfully!\n", value);
    }
}

// Function to dequeue an element from the queue
void dequeue(Queue *q){
    int element;
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    else{
        element = q->data[q->front];
        if(q->front >= q->rear){
            q->front = -1;
            q->rear = -1;
        }
        else{
            q->front++;
        }
        printf("%d dequeued successfully!\n", element);
    }
}

// Function to display the elements in the queue
void display(Queue *q){
    int i;
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return;
    }
    else{
        printf("Elements of the queue are: ");
        for(i=q->front; i<=q->rear; i++){
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

int main(){
    Queue q;
    int ch, value;

    initQueue(&q);

    do{
        printf("**** MENU ****\n");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: printf("Enter the value to be enqueued: ");
                    scanf("%d", &value);
                    enqueue(&q, value);
                    break;

            case 2: dequeue(&q);
                    break;

            case 3: display(&q);
                    break;

            case 4: exit(0);

            default: printf("Invalid choice!\n");
        }
    }while(ch != 4);

    return 0;
}