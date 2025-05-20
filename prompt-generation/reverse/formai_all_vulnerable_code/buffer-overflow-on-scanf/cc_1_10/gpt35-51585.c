//FormAI DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

struct queue{
    int data[MAX_SIZE];
    int front,rear;       
};

void enqueue(struct queue *q, int value) {
    if(q->rear == MAX_SIZE - 1) {
        printf("Queue is full!");
    } else {
        if(q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = value;
        printf("Enqueue element: %d\n",value);
    }
}

void dequeue(struct queue *q) {
    if(q->front == -1 || q->front > q->rear) {
        printf("Queue is empty!");
    } else {
        printf("Dequeued element: %d\n",q->data[q->front]);
        q->front++;
    }
}

void display(struct queue *q) {
    if(q->front == -1 || q->front > q->rear) {
        printf("Queue is empty!");
    } else {
        printf("Elements in Queue:\n");
        for(int i=q->front;i<=q->rear;i++) {
            printf("%d ",q->data[i]);
        }
    }
}

int main(){
    struct queue q;
    q.front = -1;
    q.rear = -1;
    int choice, value;
    while(1) {
        printf("\nQueue Operations\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: 
                printf("Enter value to Enqueue: ");
                scanf("%d",&value);
                enqueue(&q, value);
                break;
            case 2: 
                dequeue(&q);
                break;
            case 3: 
                display(&q);
                break;
            case 4: 
                exit(0);
            default: 
                printf("Invalid choice!");
        }
    }
    return 0;
}