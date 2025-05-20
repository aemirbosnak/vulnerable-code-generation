//FormAI DATASET v1.0 Category: Queue Implementation ; Style: active
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5 

//declaring a global queue.
int queue[SIZE];
int rear = -1, front = -1;

//function to check if the queue is full.
int isFull(){
    if(rear == SIZE-1){
        return 1; //returns true.
    } else {
        return 0; //returns false.
    }
}

//function to check if the queue is empty.
int isEmpty(){
    if(front == -1 || front == rear+1){
        return 1; //returns true.
    } else {
        return 0; //returns false.
    }
}

//function to add element to the queue.
void enqueue(int element){
    if(isFull()){
        printf("Queue is full.\n");
    } else {
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("%d inserted in queue.\n", element);
    }
}

//function to remove element from the queue.
void dequeue(){
    int element;
    if(isEmpty()){
        printf("Queue is empty.\n");
    } else {
        element = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        printf("%d removed from queue.\n", element);
    }
}

//function to display all elements in the queue.
void display(){
    int i;
    if(isEmpty()){
        printf("Queue is empty.\n");
    } else {
        printf("Elements in queue are:\n");

        for(i = front; i <= rear; i++){
            printf("%d\n", queue[i]);
        }
    }
}

int main(){
    int choice, element;

    while(1){
        printf("Enter your choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element to insert:\n");
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
                exit(0); //exits the program.
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}