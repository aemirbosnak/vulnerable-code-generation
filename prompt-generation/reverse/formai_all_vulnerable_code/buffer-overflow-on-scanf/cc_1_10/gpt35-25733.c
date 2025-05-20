//FormAI DATASET v1.0 Category: Queue Implementation ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5
int queue[MAX_SIZE], front=-1, rear=-1;

void enqueue(int value){
    if ((front == 0 && rear == MAX_SIZE-1) || rear == front-1){
        printf("\nQueue Overflow!!!");
        return;
    }
    if (front == -1){
        front = rear = 0;
        queue[rear] = value;
    }
    else if(rear == MAX_SIZE-1 && front != 0){
        rear = 0;
        queue[rear] = value;
    }
    else{
        rear++;
        queue[rear] = value;
    }
    printf("%d added to the queue.\n", value);
}

int dequeue(){
    int value;
    if (front == -1){
        printf("\nQueue Underflow!!!");
        return -1;
    }  
    value = queue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else if(front == MAX_SIZE-1)
        front = 0;
    else
        front++;
    printf("%d removed from the queue.\n", value);
    return value;
}

void display(){
    int i;
    if (front == -1)
        printf("\nQueue is empty!!!");
    else{
        printf("\nThe queue is:");
        if (rear >= front){
            for(i=front;i<=rear;i++)
                printf("%d ",queue[i]);
        }
        else{
            for(i=front;i<MAX_SIZE;i++)
                printf("%d ", queue[i]);
            for(i=0;i<=rear;i++)
                printf("%d ",queue[i]);
        }
    }
}

int main(){
    int ch, value;
    printf("-----Queue Implementation using C-----\n");
    do{
        printf("\n\nChoose:\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\nChoice:");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("\nEnter value to be inserted:");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice!!!");
        }
    }while(ch!=0);
    return 0;
}