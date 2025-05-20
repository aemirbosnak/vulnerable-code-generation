//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct queue{
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
};

struct queue* createQueue(){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isFull(struct queue* q){
    return (q->size == MAX_QUEUE_SIZE);
}

int isEmpty(struct queue* q){
    return (q->size == 0);
}

void enqueue(struct queue* q, int item){
    if(isFull(q)){
        printf("Queue is full!\n");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear = (q->rear+1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
    q->size++;
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        exit(0);
    }
    item = q->data[q->front];
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front = (q->front+1) % MAX_QUEUE_SIZE;
    }
    q->size--;
    return item;
}

int main(){
    struct queue* q = createQueue();
    int choice, item;
    
    do{
        printf("Choose from the following options:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter item to insert:\n");
                scanf("%d", &item);
                enqueue(q, item);
                break;
            case 2:
                printf("Dequeueing item %d\n", dequeue(q));
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice!=3);
    
    return 0;
}