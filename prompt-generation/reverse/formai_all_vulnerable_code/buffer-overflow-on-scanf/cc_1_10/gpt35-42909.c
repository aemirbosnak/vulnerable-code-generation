//FormAI DATASET v1.0 Category: Queue ; Style: curious
#include<stdio.h>
#include<stdlib.h>

// Defining the capacity of Queue
#define CAPACITY 5

int rear = -1; // Initializing the last index as -1
int front = -1; // Initializing the first index as -1
int queue[CAPACITY]; // Declaring an array for Queue

// Function to add an element into Queue
void enqueue(int data){

    if((front == 0 && rear == CAPACITY-1) || (rear == front-1)){
        printf("\nOverflow"); // If Queue is full
        return;
    }

    else if(front == -1 && rear == -1){
        front = rear = 0; // If Queue is empty
        queue[rear] = data;
    }

    else if(rear == CAPACITY-1 && front != 0){
        rear = 0;
        queue[rear] = data; // If rear has reached the end of Queue
    }

    else{
        rear++;
        queue[rear] = data; // Adding element to Queue
    }
}

// Function to remove an element from Queue
void dequeue(){
    if(front == -1){
        printf("\nUnderflow"); // If Queue is empty
        return;
    }

    printf("\nRemoved Element : %d",queue[front]);
    if(front == rear){
        front = rear = -1; // If only one element is there
    }

    else if(front == CAPACITY-1){
        front = 0; // If front has reached the end of Queue
    }

    else{
        front++; // Removing element from Queue
    }
}

// Function to display the elements of Queue
void display(){
    if(front == -1){
        printf("\nQueue is empty"); // If Queue is empty
        return;
    }

    printf("\nElements in queue: ");

    if(rear >= front){
        for(int i = front; i <= rear; i++){
            printf("%d ",queue[i]); // If rear is greater than or equal to front, elements from front to rear are printed
        }
    }

    else{
        for(int i = front; i < CAPACITY; i++){
            printf("%d ",queue[i]);
        }

        for(int i = 0; i <= rear; i++){
            printf("%d ",queue[i]); // If rear is less than front, elements from front to end and from 0 to rear are printed
        }
    }
}

// Main function
int main(){

    // Welcome message
    printf("\nWelcome to Curious Queue Program");

    // Menu for User prompt
    while(1){

        printf("\n\n================================");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n================================");

        // User input
        int choice,data;
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch(choice){

            case 1:
                printf("\nEnter the data to be enqueued : ");
                scanf("%d",&data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nThanks for using the program. Bye!");
                exit(0); // Exiting the program
                
            default:
                printf("\nInvalid Choice!");
        }
    }
    return 0;
}