//FormAI DATASET v1.0 Category: Queue Implementation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10

int front = -1, rear = -1, queue[MAX_QUEUE_SIZE];

void enqueue(int value){
    if(rear == MAX_QUEUE_SIZE - 1)
        printf("Sorry, the queue is full!\n");
    else{
        rear++;
        queue[rear] = value;
        printf("%d has been added to the queue!\n",value);
    }
    if(front == -1)
        front++;
}

void dequeue(){
    if(front == -1)
        printf("Sorry, the queue is empty!\n");
    else{
        printf("%d has been removed from the queue!\n",queue[front]);
        front++;
    }
    if(front>rear){
        front=-1;
        rear=-1;
    }
}

void display(){
    if(front == -1)
        printf("Queue is empty!\n");
    else{
        printf("Queue Contents: ");
        for(int i=front;i<=rear;i++)
            printf("%d ",queue[i]);
        printf("\n");
    }
}

int main(){
    int choice, value;
    printf("---QUEUE MENU---\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter a value to enqueue: ");
                    scanf("%d",&value);
                    enqueue(value);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: printf("Goodbye!\n");
                    exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}