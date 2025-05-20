//FormAI DATASET v1.0 Category: Queue Implementation ; Style: authentic
#include<stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(front==-1 && rear==-1){
        front = rear = 0;
        queue[rear] = x;
    }else if(rear == MAX_SIZE-1){
        printf("Queue is full\n");
    }else{
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front==-1 && rear ==-1){
        printf("Queue is empty\n");
    }else if(front == rear){
        printf("Dequeued element is %d\n", queue[front]);
        front = rear = -1;
    }else{
        printf("Dequeued element is %d\n", queue[front]);
        front++;
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }else{
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
    }
}

int main(){
    int choice, x;
    
    printf("************C Queue Implementation************\n");
    printf("1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Exit\n");
    
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nThank you for using the program!\n\n");
                return 0;
            default:
                printf("Invalid input\n");
        }
    }
    
    return 0;
}