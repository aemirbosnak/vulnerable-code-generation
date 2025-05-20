//FormAI DATASET v1.0 Category: Queue Implementation ; Style: paranoid
//Paranoid C Queue Implementation
#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 10

int front = 0, rear = -1;
int queue[MAX_QUEUE_SIZE];

void enqueue(int data){
    if(rear < MAX_QUEUE_SIZE - 1){
        queue[++rear] = data; //insert the element
    }
    else{
        printf("Queue Overflow\n");
        exit(1);
    }
}

int dequeue(){
    if(front <= rear){
        return queue[front++]; //remove the element
    }
    else{
        printf("Queue Underflow\n");
        exit(1);
    }
}

void display(){
    if(front <= rear){
        printf("Queue: ");
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]); //display the elements
        }
        printf("\n");
    }
    else{
        printf("Queue is Empty\n");
    }
}

int main(){
    int choice, data;

    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the data: ");
                scanf("%d",&data);
                enqueue(data);
                printf("Data Inserted Successfully\n");
                break;

            case 2:
                data = dequeue();
                printf("Data Removed from Queue: %d\n",data);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");               
        }
    }
    return 0;
}