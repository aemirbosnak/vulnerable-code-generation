//FormAI DATASET v1.0 Category: Queue ; Style: calm
#include <stdio.h>
#define QUEUE_SIZE 5 // define the size of the queue

int queue[QUEUE_SIZE], front = -1, rear = -1; // create an integer queue, front and rear initialized to -1

void enqueue(int element); // declare the enqueue function
void dequeue(); // declare the dequeue function
void display(); // declare the display function

int main() {
    int choice, element; // declare variables for user choice and an element to be added to or removed from the queue

    while(1) {
        printf("\nQueue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // read user choice

        switch(choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &element);
                enqueue(element); // call the enqueue function
                break;
            case 2:
                dequeue(); // call the dequeue function
                break;
            case 3:
                display(); // call the display function
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void enqueue(int element) {
    if(rear == QUEUE_SIZE - 1) { // if the queue is full
        printf("Queue is full! Cannot enqueue.\n");
    }
    else {
        if(front == -1) { // if the queue is empty
            front = 0;
        }
        rear++;
        queue[rear] = element; // add the element to the queue
        printf("%d enqueued successfully!\n", element);
    }
}

void dequeue() {
    if(front == -1 || front > rear) { // if the queue is empty
        printf("Queue is empty! Cannot dequeue.\n");
    }
    else {
        printf("%d dequeued successfully!\n", queue[front]); // remove the element at the front of the queue
        front++;
    }
}

void display() {
    if(front == -1 || front > rear) { // if the queue is empty
        printf("Queue is empty!\n");
    }
    else {
        printf("The elements in the queue are: ");
        for(int i = front; i <= rear; i++) { // loop through the queue and print the elements
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}