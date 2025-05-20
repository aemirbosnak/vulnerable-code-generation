//FormAI DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front=-1;
int rear=-1;

void enqueue(int element){
    if (rear==SIZE-1){
        printf("Queue Overflow!");
    }
    else{
        if (front==-1){
            front=0;
        }
        rear++;
        queue[rear]=element;
        printf("Added element %d to the Queue\n",element);
    }
}

void dequeue(){
    if (front==-1 || front>rear){
        printf("Queue Underflow!");
    }
    else{
        printf("Removed element %d from the Queue\n",queue[front]);
        front++;
    }
}

void display(){
    if (front==-1 || front>rear){
        printf("Queue is Empty!");
    }
    else{
        printf("Elements in the Queue are: ");
        for (int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice;
    int element;
    printf("Queue Implementation in C\n");
    printf("------------------------\n");
    do{
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element: ");
                scanf("%d",&element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the Program!\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice! Please select 1-4.\n");
                break;
        }
        printf("\n");
    }while(1);
    return 0;
}