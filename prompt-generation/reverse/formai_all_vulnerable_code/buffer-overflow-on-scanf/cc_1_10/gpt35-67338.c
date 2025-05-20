//FormAI DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 10 // maximum size of queue

int queue[MAXSIZE]; // declaring queue
int front = -1, rear = -1; // initializing front and rear of queue

int isFull(){
    if(rear == MAXSIZE-1){
        return 1; // queue is full
    }
    else{
        return 0; // queue is not full
    }
}

int isEmpty(){
    if(front == -1 || front > rear){
        return 1; // queue is empty
    }
    else{
        return 0; // queue is not empty
    }
}

void enqueue(int x){
    if(isFull()){
        printf("Queue is full. Cannot insert %d!\n", x);
    }
    else{
        if(front == -1){ // first element of queue
            front = 0;
        }
        rear++;
        queue[rear] = x;
        printf("%d is inserted into the queue.\n", x);
    }
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty. Cannot dequeue!\n");
    }
    else{
        printf("%d is dequeued from the queue.\n", queue[front]);
        front++;
    }
}

void display(){
    if(isEmpty()){
        printf("Queue is empty.\n");
    }
    else{
        printf("Current queue: ");
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    srand(time(0)); // seeding the random function
    int randomNum;

    printf("Welcome to the post-apocalyptic queue system!\n");

    while(1){
        printf("\n1. Add person to the queue\n2. Remove person from the queue\n3. Display queue\n4. Exit\n"); // presenting menu
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice){
            case 1:
                randomNum = rand() % 100 + 1;
                printf("Person with ID %d has arrived at the queue.\n", randomNum);
                enqueue(randomNum);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting post-apocalyptic queue system. Stay safe!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}