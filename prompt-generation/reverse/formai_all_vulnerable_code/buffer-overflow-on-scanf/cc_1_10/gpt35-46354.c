//FormAI DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5 //Size of the queue

int queue[SIZE], front = -1, rear = -1; //A global integer array for queue and front and rear will be -1 initially

void enqueue(int value){  //function to insert element into queue
    if(rear == SIZE-1){ //check if queue is full
        printf("\nQueue is full!\n");
        return;
    }
    else if(front == -1 && rear == -1){ //Check if queue is empty
        front = rear = 0;
        queue[rear] = value;
    }
    else{
        rear ++;
        queue[rear] = value;
    }
}

void dequeue(){ //function to delete element from the queue
    if(front == -1 && rear == -1){ //check if queue is empty
        printf("\nQueue is empty!\n");
        return;
    }
    else if(front == rear){
        printf("\nDeleted element is: %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("\nDeleted element is: %d\n", queue[front]);
        front ++;
    }
}

void display(){ //function to display queue elements
    if(front == -1 && rear == -1){
        printf("\nQueue is empty!\n");
    }
    else{
        int i = front;
        printf("\nQueue elements are: ");
        for(i = front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){ //Main function
    int choice, value;
    printf("\n\t::Queue Implementation Program::\n\n");
    while(1){ //Continuous loop for menu driven program
        printf("Choose an operation to perform:\n");
        printf("1.Insert element into the queue\n");
        printf("2.Delete element from the queue\n");
        printf("3.Display queue elements\n");
        printf("4.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("\nEnter a value to insert into queue: ");
                    scanf("%d", &value);
                    enqueue(value);
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