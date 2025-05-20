//FormAI DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue(int value){
    if((front == 0 && rear == MAX_QUEUE_SIZE-1) || (front == rear+1)){
        printf("Queue is full!\n");
        return;
    }
    else if (front == -1 && rear == -1){
        front = rear = 0;
    }
    else if(rear == MAX_QUEUE_SIZE-1){
        rear = 0;
    }
    else{
        rear++;
    }
    queue[rear] = value;
    printf("%d has been enqueued.\n", value);
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
        return;
    }
    printf("%d has been dequeued.\n", queue[front]);
    if (front == rear){
        front = rear = -1;
    }
    else if(front == MAX_QUEUE_SIZE-1){
        front = 0;
    }
    else{
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    if (front <= rear){
        while(i <= rear){
            printf("%d ", queue[i]);
            i++;
        }
    }
    else{
        while(i <= MAX_QUEUE_SIZE-1){
            printf("%d ", queue[i]);
            i++;
        }
        i = 0;
        while(i <= rear){
            printf("%d ", queue[i]);
            i++;
        }
    }
    printf("\n");
}

int main(){
    int choice, value;
    printf("Queue Operations:\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    do{
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
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
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }while(1);
    return 0;
}