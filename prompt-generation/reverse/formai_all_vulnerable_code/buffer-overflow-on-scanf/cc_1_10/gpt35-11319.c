//FormAI DATASET v1.0 Category: Queue Implementation ; Style: scientific
#include<stdio.h> 
  
#define MAX_SIZE 5 // Maximum size of the queue 
  
int queue[MAX_SIZE], front = -1, rear = -1; 
  
// Function to check if the queue is empty 
int is_empty() {
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}
  
// Function to insert an element in the queue 
void enqueue(int value) { 
    if((rear+1)%MAX_SIZE == front) {
        printf("\nQueue overflow!"); 
    }
    else if(is_empty()) {
        front = rear = 0;
        queue[rear] = value;
    }
    else {
        rear = (rear+1)%MAX_SIZE;
        queue[rear] = value;
    }
} 
  
// Function to delete an element from the queue 
void dequeue() { 
    if(is_empty()) {
        printf("\nQueue underflow!"); 
    }
    else if(front == rear) {
        printf("\nDeleted element is %d", queue[front]);
        front = rear = -1;
    }
    else {
        printf("\nDeleted element is %d", queue[front]);
        front = (front+1)%MAX_SIZE;
    }
} 
  
// Function to display the elements in the queue 
void display() { 
    if(is_empty()) {
        printf("\nQueue is empty!"); 
    }
    else {
        printf("\nElements in queue are:\n");
        int i;
        for(i=front; i!=rear; i=(i+1)%MAX_SIZE)
            printf("%d\n", queue[i]);
        printf("%d\n", queue[i]);
    }
} 
  
int main() { 
    int choice, value; 
    while(1) { 
        printf("\n----------------------"); 
        printf("\nOperations on Queue"); 
        printf("\n----------------------"); 
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d",&choice); 
        switch(choice) { 
            case 1: 
                printf("\nEnter the value to be inserted: "); 
                scanf("%d",&value); 
                enqueue(value); 
                break; 
            case 2: 
                dequeue(); 
                break; 
            case 3: 
                display(); 
                break;
            case 4:
                printf("\nExiting...");
                return 0; 
            default: 
                printf("\nInvalid choice!"); 
                break; 
        } 
    } 
    return 0; 
}