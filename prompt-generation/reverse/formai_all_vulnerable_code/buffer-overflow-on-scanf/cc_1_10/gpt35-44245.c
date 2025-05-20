//FormAI DATASET v1.0 Category: Queue Implementation ; Style: protected
#include<stdio.h>
#define SIZE 5

int queue[SIZE], front=-1, rear=-1;

void enqueue(int value){
    if((front==0 && rear==SIZE-1) || (rear==front-1)){
        printf("Queue is full\n");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=value;
    }
    else if(rear==SIZE-1 && front!=0){
        rear=0;
        queue[rear]=value;
    }
    else{
        rear++;
        queue[rear]=value;
    }
}

int dequeue(){
    int value;
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
        return -1;
    }
    else if(front==rear){
        value=queue[front];
        front=rear=-1;
    }
    else if(front==SIZE-1){
        value=queue[front];
        front=0;
    }
    else{
        value=queue[front];
        front++;
    }
    return value;
}

void display(){
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else{
        int i;
        printf("Queue elements are:\n");
        if(front<=rear){
            for(i=front;i<=rear;i++){
                printf("%d ",queue[i]);
            }
        }
        else{
            for(i=front;i<SIZE;i++){
                printf("%d ",queue[i]);
            }
            for(i=0;i<=rear;i++){
                printf("%d ",queue[i]);
            }
        }
        printf("\n");
    }
}

int main(){
    int choice, value;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d",&value);
                enqueue(value);
                break;
            case 2:
                value=dequeue();
                if(value!=-1){
                    printf("Dequeued element is %d\n",value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting..\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}