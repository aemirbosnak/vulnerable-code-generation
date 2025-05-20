//FormAI DATASET v1.0 Category: Queue Implementation ; Style: irregular
#include<stdio.h>
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;

int isFull(){
    if(rear == MAX-1) return 1;
    else return 0;
}

int isEmpty(){
    if(front==-1 || front>rear) return 1;
    else return 0;
}

void enqueue(int x){
    if(isFull())
        printf("\nQueue is full.");
    else{
        if(front == -1) front = 0;
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){
    if(isEmpty())
        printf("\nQueue is empty.");
    else{
        printf("\nElement %d is dequeued from the queue.", queue[front]);
        front++;
    }
}

void peek(){
    if(isEmpty())
        printf("\nQueue is empty.");
    else
        printf("\nElement at the front of the queue is %d", queue[front]);
}

void display(){
    if(isEmpty())
        printf("\nQueue is empty.");
    else{
        printf("\n****QUEUE****\n");
        int i;
        for(i=front; i<=rear; i++){
            printf("%d\t", queue[i]);
        }
        printf("\n*************");
    }
}

int main(){
    int choice, x;
    printf("\n********QUEUE IMPLEMENTATION USING ARRAY********\n");
    printf("\n\n\n");
    while(1){
        printf("\n==================Queue Menu====================");
        printf("\n1. Enqueue.");
        printf("\n2. Dequeue.");
        printf("\n3. Peek.");
        printf("\n4. Display.");
        printf("\n5. Exit.");
        printf("\n=================================================");
        printf("\nEnter choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter element to be enqueued:");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\n****THANK YOU*****");
                return 0;
                break;
            default:
                printf("\nInvalid choice..!!!");
        }
    }
    return 0;
}