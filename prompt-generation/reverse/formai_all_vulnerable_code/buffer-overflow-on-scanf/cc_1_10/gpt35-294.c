//FormAI DATASET v1.0 Category: Queue Implementation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int queue[MAX]; //Queue declaration
int front=-1, rear=-1; //front and rear pointers initialized to -1

//Function to insert element into queue
void enqueue(int element){
    if(rear == MAX-1){
        printf("\nQueue overflow! Cannot add element.\n");
        return;
    }
    else if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = element;
    }
    else{
        rear++;
        queue[rear] = element;
    }
    printf("\n%d added to the queue.\n", element);
}

//Function to delete element from queue
void dequeue(){
    if(front == -1){
        printf("\nQueue underflow! Cannot delete element.\n");
        return;
    }
    else if(front == rear){
        printf("\n%d removed from the queue.\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else{
        printf("\n%d removed from the queue.\n", queue[front]);
        front++;
    }
}

//Function to display elements in queue
void display(){
    if(front == -1){
        printf("\nQueue is empty.\n");
        return;
    }
    else{
        printf("\nElements in queue are: ");
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, element;
    while(1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter the element to be added to the queue: ");
                    scanf("%d", &element);
                    enqueue(element);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}