//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int q[MAX];
int front = -1, rear = -1;

void enqueue(int x){
    if(rear >= MAX-1){
        printf("Queue Overflow\n");
        return;
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        q[rear] = x;
    }
    else{
        rear++;
        q[rear] = x;
    }
    printf("%d Enqueued into Queue\n",x);
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow\n");
        return;
    }
    else if(front == rear){
        printf("%d Dequeued from the Queue\n",q[front]);
        front = rear = -1;
    }
    else{
        printf("%d Dequeued from the Queue\n",q[front]);
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty\n");
        return;
    }
    else{
        printf("Queue Elements are: ");
        for(int i=front; i<=rear; i++){
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, data;
    while(1){
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the Data to Enqueue: ");
                    scanf("%d",&data);
                    enqueue(data);
                    break;

            case 2: dequeue();
                    break;

            case 3: display();
                    break;

            case 4: printf("Exiting...\n");
                    exit(0);

            default: printf("Invalid Choice, Please Try Again\n");
        }
    }
    return 0;
}