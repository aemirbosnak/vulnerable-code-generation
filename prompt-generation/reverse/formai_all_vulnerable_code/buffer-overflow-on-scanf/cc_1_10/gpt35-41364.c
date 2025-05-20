//FormAI DATASET v1.0 Category: Queue ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

typedef struct queue{
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *q){
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q){
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

int isEmpty(Queue *q){
    return (q->front == -1 && q->rear == -1);
}

void enqueue(Queue *q, int item){
    if(isFull(q)){
        printf("Queue is full! Cannot add element\n");
        return;
    }
    else if(isEmpty(q)){
        q->front++;
        q->rear++;
    }
    else{
        q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    }
    q->data[q->rear] = item;
    printf("%d is successfully enqueued.\n", item);
}

int dequeue(Queue *q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty! Cannot delete element\n");
        return -1;
    }
    else if(q->front == q->rear){
        item = q->data[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else{
        item = q->data[q->front];
        q->front = (q->front+1)%MAX_QUEUE_SIZE;
    }
    printf("%d is successfully dequeued.\n", item);
    return item;
}

int main(){
    Queue q;
    init(&q);
    int choice, item;
    printf("------- Queue Operations -------\n");
    do{
        printf("Choose:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if(item != -1) printf("%d is dequeued from the queue.\n", item); 
                break;
            case 3:
                printf("Exiting..");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(choice != 3);

    return 0;
}