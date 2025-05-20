//FormAI DATASET v1.0 Category: Queue Implementation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int front=-1,rear=-1;
int queue[MAX];

void enqueue(int x){
    if(rear==MAX-1){
        printf("\nQueue is full");
    }
    else{
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        else{
            rear=rear+1;
        }
        queue[rear]=x;
        printf("\nInserted Element is %d",x);
    }
}

void dequeue(){
    if(front==-1 || front>rear){
        printf("\nQueue is Empty");
    }
    else{
        printf("\nDeleted Element is %d",queue[front]);
        front=front+1;
    }
}

void display(){
    if(front==-1){
        printf("\nQueue is Empty");
    }
    else{
        printf("\nElements in Queue are : ");
        for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    }
}

int main(){
    int ch, val;
    printf("\n\n~~~~~~~~~~~~~ C Queue Implementation ~~~~~~~~~~~~~\n\n");
    do{
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter the value to be inserted : ");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nInvalid choice");
                     break;
        }
    }while(ch!=4);
    return 0;
}