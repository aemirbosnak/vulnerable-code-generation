//FormAI DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 5

int front = -1, rear = -1;
int queue[MAX_QUEUE_SIZE];

void enqueue(int value){
    if(rear == MAX_QUEUE_SIZE-1){
        printf("Queue overflow\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = value;
    }
    else{
        rear++;
        queue[rear] = value;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue underflow\n");
    }
    else if(front == rear){
        printf("Dequeued %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("Dequeued %d\n", queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue elements are:\n");
        for(int i=front;i<=rear;i++){
            printf("%d\n", queue[i]);
        }
    }
}

int main(){
    int choice, value;
    while(1){
        printf("Enter 1 to enqueue, 2 to dequeue, 3 to display, 4 to exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be enqueued\n");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}