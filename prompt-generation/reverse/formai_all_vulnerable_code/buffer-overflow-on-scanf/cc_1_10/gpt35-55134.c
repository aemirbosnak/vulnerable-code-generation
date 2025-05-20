//FormAI DATASET v1.0 Category: Queue Implementation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front=-1, rear=-1;

void enqueue(int data){
    if(rear==MAX_SIZE-1){
        printf("Queue Overflow\n");
        return;
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        queue[rear]=data;
        printf("%d inserted in queue.\n", data);
    }
}

void dequeue(){
    if(front==-1 || front>rear){
        printf("Queue Underflow\n");
        return;
    }
    else{
        printf("%d deleted from queue.\n",queue[front]);
        front++;
    }
}

void display(){
    if(front==-1 || front>rear){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue Elements are :\n");
    int i;
    for(i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main(){
    int choice, data;
    while(1){
        printf("Enter 1 to Enqueue element.\n");
        printf("Enter 2 to Dequeue element.\n");
        printf("Enter 3 to display the queue.\n");
        printf("Enter 4 to exit.\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to be inserted : ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}