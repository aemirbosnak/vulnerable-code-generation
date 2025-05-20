//FormAI DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h> 
#define MAX_QUEUE_SIZE 100 

int queue[MAX_QUEUE_SIZE], front = -1, rear = -1; 

int isFull(){ //to check if queue is full
    return (rear == MAX_QUEUE_SIZE - 1); 
} 

int isEmpty(){ //to check if queue is empty
    return (front == -1 && rear == -1); 
} 

void enqueue(int data){ //to insert elements into queue
    if(isFull()){ 
        printf("\nError: Queue is full\n"); 
        return; 
    } 
    else if(isEmpty()){ 
        front = rear = 0; 
    } 
    else{ 
        rear++; 
    } 
    queue[rear] = data; 
    printf("\nInserted %d into queue", data); 
} 

void dequeue(){ //to remove elements from queue
    if(isEmpty()){ 
        printf("\nError: Queue is empty\n"); 
        return; 
    } 
    else if(front == rear){ 
        front = rear = -1; 
    } 
    else{ 
        front++; 
    } 
    printf("\nRemoved %d from queue", queue[front-1]); 
} 

void display(){ //to display the elements in the queue
    if(isEmpty()){ 
        printf("\nQueue is empty\n"); 
        return; 
    } 
    for(int i=front; i<=rear; i++){ 
        printf("%d ",queue[i]); 
    } 
} 

int main(){ 
    int choice, data; 

    do{ //loop to keep the program running until the user chooses to exit
        printf("\n\nQUEUE IMPLEMENTATION IN C\n"); 
        printf("\n1. Insert element into queue"); 
        printf("\n2. Remove element from queue"); 
        printf("\n3. Display elements in queue"); 
        printf("\n4. Exit"); 
        printf("\nEnter your choice: "); 

        scanf("%d", &choice); 

        switch(choice){ //switch statement to perform corresponding operation based on user choice
            case 1: printf("\nEnter data to insert: ");
                    scanf("%d", &data);
                    enqueue(data); 
                    break; 

            case 2: dequeue();
                    break; 

            case 3: display();
                    break; 

            case 4: printf("\nExiting program");
                    break; 

            default: printf("\nInvalid choice"); 
        } 
    }while(choice != 4); 

    return 0; 
}