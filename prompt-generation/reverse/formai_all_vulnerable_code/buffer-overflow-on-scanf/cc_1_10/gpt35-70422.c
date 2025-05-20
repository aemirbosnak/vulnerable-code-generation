//FormAI DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
/* Welcome to my exciting C Queue Implementation Program! */

#include<stdio.h>
#define MAX_SIZE 10 // Size of the queue

int queue[MAX_SIZE], front=-1, rear=-1; // Initializing Front and Rear as -1

// Enqueue Function
void enqueue(int value){
    if(rear == MAX_SIZE-1){ // If Queue is full
        printf("\nOops! The Queue is already full. Can't store any more values.\n");
    }
    else{
        if(front == -1){ // If Queue is empty
            front = 0; // Move Front to first position
        }
        rear++; // Increase Rear position
        queue[rear] = value; // Add Value to Queue
        printf("\n%d has been added to the Queue.\n", value);
    }
}

// Dequeue Function
void dequeue(){
    if(front == -1){ // If Queue is empty
        printf("\nOops! The Queue is already empty. Can't remove any more values.\n");
    }
    else{
        printf("\n%d has been removed from the Queue.\n", queue[front]); // Print Removed Value
        front++; // Move Front position to Next
        if(front > rear){ // If All Values are Removed
            front = rear = -1; // Re-Initialize Front and Rear as -1
        }
    }
}

// Get Front Function
int get_front(){
    if(front == -1){ // If Queue is empty
        printf("\nOops! The Queue is empty. No value to display.\n");
        return -1;
    }
    else{
        return queue[front]; // Return Front Value
    }
}

// Get Rear Function
int get_rear(){
    if(rear == -1){ // If Queue is empty
        printf("\nOops! The Queue is empty. No value to display.\n");
        return -1;
    }
    else{
        return queue[rear]; // Return Rear Value
    }
}

int main(){
    int choice, value;
    
    printf("Welcome to my Unique C Queue Implementation Program!\n");
    
    do{
        printf("\nWhat would you like to do?\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Front Value\n");
        printf("4. Get Rear Value\n");
        printf("5. Exit\n");
        
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice); // Get User Choice
        
        switch(choice){
            case 1: // Enqueue
                printf("\nEnter the value to Enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            
            case 2: // Dequeue
                dequeue();
                break;
            
            case 3: // Get Front Value
                printf("\nThe Front Value is: %d\n", get_front());
                break;
            
            case 4: // Get Rear Value
                printf("\nThe Rear Value is: %d\n", get_rear());
                break;
            
            case 5: // Exit
                printf("\nThank you for using my Unique C Queue Implementation Program! Have a nice day!\n");
                break;
            
            default: // Invalid Choice
                printf("\nOops! The choice is invalid. Please try again.\n");
                break;
        }
    } while(choice != 5); // Repeat until User chooses to Exit
    
    return 0;
}