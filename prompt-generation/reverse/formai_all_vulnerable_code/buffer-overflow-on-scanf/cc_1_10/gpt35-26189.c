//FormAI DATASET v1.0 Category: Queue Implementation ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int q[MAX];
int front=-1, rear=-1;

void enqueue(int data){
    if(rear==MAX-1){
        printf("Queue overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    q[++rear]=data;
}

int dequeue(){
    if(front==-1 || front>rear){
        printf("Queue underflow\n");
        return -1;
    }
    return q[front++];
}

void display(){
    int i;
    if(front==-1 || front>rear){
        printf("Queue is empty\n");
        return;
    }
    printf("The queue is: ");
    for(i=front; i<=rear; i++){
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main(){
    int choice, data;

    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                printf("The dequeued element is %d\n", dequeue());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}