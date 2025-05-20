//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100 //defining maximum queue size

//function to insert element into Queue
void enqueue(int queue[], int *rear, int element){
    if(*rear == MAX_QUEUE_SIZE-1){ //queue is full
        printf("Queue is Full!\n");
        return;
    }
    queue[++(*rear)] = element;//insert element at the rear end
}

//function to delete element from Queue
int dequeue(int queue[], int *front, int rear){
    if(*front == rear+1){ //queue is empty
        printf("Queue is Empty!\n");
        return -1;
    }
    return queue[(*front)++]; //delete element from the front end
}

//function to display the Queue
void display(int queue[], int front, int rear){
    if(front == rear+1){ //queue is empty
        printf("Queue is Empty!\n");
        return;
    }
    printf("\nThe elements in the Queue are:\n");
    for(int i=front; i<=rear; i++){
        printf("%d ", queue[i]); //displaying elements
    }
}

int main(){
    int front = 0, rear = -1; //initializing front and rear
    int queue[MAX_QUEUE_SIZE]; //declaring Queue of MAX_QUEUE_SIZE
    int choice, element;
    //menu driven program
    do{
        printf("\n-----------------------\n");
        printf("Mathematical Queue Program\n");
        printf("-----------------------\n\n");
        printf("1. Insert Element into Queue\n");
        printf("2. Delete Element from Queue\n");
        printf("3. Display Elements in Queue\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf("%d", &element);
                enqueue(queue, &rear, element); //calling enqueue function
                break;
            case 2:
                element = dequeue(queue, &front, rear); //calling dequeue function and assigning to variable element
                if(element != -1)
                    printf("\nThe deleted element is %d.", element);
                break;
            case 3:
                display(queue, front, rear); //calling display function
                break;
            case 4:
                printf("\nExiting Program..."); //exit message
                break;
            default:
                printf("\nInvalid Choice!"); //invalid choice message
        }
    }while(choice != 4); //program will run until user chooses to exit
    
    return 0;
}