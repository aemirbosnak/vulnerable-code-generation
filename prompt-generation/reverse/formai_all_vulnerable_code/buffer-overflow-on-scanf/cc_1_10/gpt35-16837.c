//FormAI DATASET v1.0 Category: Queue ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

struct Queue{
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue *q){
    q->front = -1;
    q->rear = -1;
}

int isFull(struct Queue *q){
    return ((q->rear+1)%MAX_QUEUE_SIZE == q->front);
}

int isEmpty(struct Queue *q){
    return (q->front == -1 && q->rear == -1);
}

void enqueue(struct Queue *q, int value){
    if(isFull(q)){
        printf("Queue is full. Cannot add new element.\n");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    }
    else{
	    q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
    }
    q->data[q->rear] = value;
}

void dequeue(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty. Cannot remove element.\n");
        return;
    }
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }
    else{
        q->front = (q->front+1)%MAX_QUEUE_SIZE;
    }
}

void display(struct Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    printf("Elements of queue are: ");
    while(i != q->rear){
        printf("%d ", q->data[i]);
        i = (i+1)%MAX_QUEUE_SIZE;
    }
    printf("%d", q->data[i]);
    printf("\n");
}

int menu(){
    int choice;
    printf("\nEnter 1 to enqueue element\n");
    printf("Enter 2 to dequeue element\n");
    printf("Enter 3 to display queue\n");
    printf("Enter 4 to exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main(){
    struct Queue q;
    initQueue(&q);
    printf("Welcome to Queue Program!\n");
    int choice, value;
    do{
        choice = menu();
        switch(choice){
            case 1:
                printf("Enter element to enqueue: ");
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
                printf("Exiting program. Thank you for using!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 4);
    return 0;
}