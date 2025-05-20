//FormAI DATASET v1.0 Category: Queue Implementation ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10 //define maximum size of the queue

int queue[MAX_SIZE]; //queue declaration
int front = -1, rear = -1; //front and rear variables declaration

//function to check if queue is full
int isFull(){
    if(rear == MAX_SIZE - 1){
        return 1;
    }
    else{
        return 0;
    }
}

//function to check if queue is empty
int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

//function to add element to the queue
void enqueue(int x){
    if(isFull()){
        printf("Queue is Full, cannot add element!\n");
        return;
    }
    else if(isEmpty()){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

//function to remove element from queue
void dequeue(){
    if(isEmpty()){
        printf("Queue is Empty, cannot remove element!\n");
        return;
    }
    else if(front == rear){
        printf("Element %d removed from queue.\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("Element %d removed from queue.\n", queue[front]);
        front++;
    }
}

//function to display the elements in queue
void display(){
    if(isEmpty()){
        printf("Queue is Empty, nothing to display!\n");
        return;
    }
    else{
        printf("Elements in Queue are:\n");
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

//main function to test the queue
int main(){
    int choice, element;
    printf("=====Welcome to the C Queue Implementation program!=====\n");
    while(1){
        printf("\nChoose one of the following options:\n");
        printf("1. Enqueue an element.\n");
        printf("2. Dequeue an element.\n");
        printf("3. Display the Queue.\n");
        printf("4. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice, please choose again!\n");
        }
    }
    return 0;
}