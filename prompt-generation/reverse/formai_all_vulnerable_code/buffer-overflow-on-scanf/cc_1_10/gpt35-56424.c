//FormAI DATASET v1.0 Category: Queue Implementation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 10 //define maximum size of queue

int q[MAX_QUEUE_SIZE], front=-1, rear=-1; //queue declaration

void enqueue(int x); //function to enqueue an element
int dequeue(); //function to dequeue an element
void display(); //function to display the queue elements


int main(){

    int n, x, option;

    printf("C Implementation of Queue Data Structure\n\n");

    do{

        printf("Enter an option (1-4):\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch(option){

            case 1: //enqueue option
                printf("Enter element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                printf("\n");
                break;

            case 2: //dequeue option
                x = dequeue();
                if(x != -1){
                    printf("Dequeued element: %d\n", x);
                }
                printf("\n");
                break;

            case 3: //display option
                display();
                printf("\n");
                break;

            case 4: //exit option
                printf("Exiting Program...\n");
                break;

            default: //invalid option
                printf("Invalid option. Please enter a valid option (1-4).\n");

        }

    }while(option != 4);

    return 0;

}

void enqueue(int x){
    //check if queue is full
    if(rear == MAX_QUEUE_SIZE-1){
        printf("Queue is full. Cannot enqueue further elements.\n");
        return;
    }
    //if queue is empty, set front and rear to 0
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        q[rear] = x;
        printf("%d enqueued.\n", x);
        return;
    }
    //if queue is not empty, add element to rear and increment rear
    else{
        rear++;
        q[rear] = x;
        printf("%d enqueued.\n", x);
        return;
    }
}

int dequeue(){
    int x;
    //check if queue is empty
    if(front == -1 && rear == -1){
        printf("Queue is empty. Cannot dequeue any elements.\n");
        return -1;
    }
    //if there is only one element in queue, set front and rear to -1
    else if(front == rear){
        x = q[front];
        front = -1;
        rear = -1;
        return x;
    }
    //if there are more than one elements in queue, remove element from front and increment front
    else{
        x = q[front];
        front++;
        return x;
    }
}

void display(){
    int i;
    //check if queue is empty
    if(front == -1 && rear == -1){
        printf("Queue is empty. Cannot display any elements.\n");
        return;
    }
    //display elements in queue
    printf("Queue elements are: ");
    for(i=front; i<=rear; i++){
        printf("%d ", q[i]);
    }
    printf("\n");
}