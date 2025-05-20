//FormAI DATASET v1.0 Category: Queue Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int data[MAX];
    int front, rear;
}Queue;

void initQueue(Queue *q){
    q->front = q->rear = -1;
}

int isEmpty(Queue *q){
    if(q->rear == -1) return 1;
    return 0;
}

int isFull(Queue *q){
    if(q->rear == MAX-1) return 1;
    return 0;
}

void enqueue(Queue *q, int x){
    if(isFull(q)){
        printf("Queue is full. Cannot enqueue %d\n", x);
        return;
    }
    if(isEmpty(q)){
        q->front = q->rear = 0;
        q->data[q->rear] = x;
        return;
    }
    q->rear++;
    q->data[q->rear] = x;
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int x = q->data[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
        return x;
    }
    q->front++;
    return x;
}

void printQueue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue:\n");
    for(int i=q->front; i<=q->rear; i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main(){
    Queue q;
    initQueue(&q);

    printf("--- Welcome to the futuristic queue implementation program! ---\n");

    while(1){
        printf("\nWhat would you like to do?\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the number you would like to enqueue: ");
                int x;
                scanf("%d", &x);
                enqueue(&q, x);
                break;
            case 2:
                x = dequeue(&q);
                if(x != -1) printf("%d dequeued.\n", x);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("--- Thank you for using the futuristic queue implementation program! ---\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}