//FormAI DATASET v1.0 Category: Queue Implementation ; Style: happy
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue(int data) {
    if(rear == SIZE-1) {
        printf("Queue is full! Cannot add new elements.");
    } else {
        if(front == -1) front = 0;
        rear++;
        queue[rear] = data;
        printf("%d has been added to the queue!\n", data);
    }
}

void dequeue() {
    if(front == -1) {
        printf("Queue is empty! Nothing to remove.");
    } else {
        printf("%d has been removed from the queue!\n", queue[front]);
        front++;
        if(front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if(front == -1) {
        printf("Queue is empty!");
    } else {
        printf("The elements in the queue are: ");
        for(int i=front; i<=rear; i++) {
            printf("%d ", queue[i]);
        }
    }
}

int main() {
    int choice, data;
    
    printf("Welcome to my unique C Queue implementation!\n");
    
    do {
        printf("\n\nWhat would you like to do?\n1. Add element to the queue\n2. Remove element from the queue\n3. Display elements in the queue\n4. Exit\nYour choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter the element you want to add: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank you for using my queue implementation!");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please choose again.");
        }
    } while(choice != 4);
    
    return 0;
}