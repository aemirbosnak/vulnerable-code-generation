//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 // Maximum size of the Candy Queue
#define NAME_SIZE 30 // Maximum size for the candy name

typedef struct {
    char candy[NAME_SIZE];
} CandyOrder;

typedef struct {
    CandyOrder orders[MAX];
    int front, rear;
} CandyQueue;

// Function to initialize the Queue
void initializeQueue(CandyQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is full
int isFull(CandyQueue* queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Function to check if the queue is empty
int isEmpty(CandyQueue* queue) {
    return queue->front == -1;
}

// Function to add an order to the queue
void enqueue(CandyQueue* queue, const char* candy) {
    if (isFull(queue)) {
        printf("Oh no! The candy shop is too busy right now! Can't take more orders.\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    strncpy(queue->orders[queue->rear].candy, candy, NAME_SIZE - 1);
    queue->orders[queue->rear].candy[NAME_SIZE - 1] = '\0'; // Null-terminate the string
    printf("Yay! Added '%s' to the candy order queue.\n", candy);
}

// Function to remove an order from the queue
void dequeue(CandyQueue* queue) {
    if (isEmpty(queue)) {
        printf("Uh-oh! No more candy orders to process!\n");
        return;
    }
    printf("Processing '%s' order! Here you go, sweet customer!\n", queue->orders[queue->front].candy);
    if (queue->front == queue->rear) {
        // The queue is now empty
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX;
    }
}

// Function to display current orders in the queue
void displayQueue(CandyQueue* queue) {
    if (isEmpty(queue)) {
        printf("The candy order queue is empty! We'll have to wait for new orders!\n");
        return;
    }
    printf("Current Candy Orders in Queue:\n");
    int i = queue->front;
    while (1) {
        printf("- %s\n", queue->orders[i].candy);
        if (i == queue->rear) break;
        i = (i + 1) % MAX;
    }
}

// Main function to run the candy order program
int main() {
    CandyQueue myCandyQueue;
    initializeQueue(&myCandyQueue);
    
    int choice;
    char candy[NAME_SIZE];

    do {
        printf("\nWelcome to the Magical Candy Shop! What would you like to do?\n");
        printf("1. Place a Candy Order (Enqueue)\n");
        printf("2. Process a Candy Order (Dequeue)\n");
        printf("3. View Current Candy Orders\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the name of the candy you want to order: ");
                scanf("%s", candy);
                enqueue(&myCandyQueue, candy);
                break;
            case 2:
                dequeue(&myCandyQueue);
                break;
            case 3:
                displayQueue(&myCandyQueue);
                break;
            case 4:
                printf("Thank you for visiting the Magical Candy Shop! Come back soon for more sugary treats!\n");
                break;
            default:
                printf("Oops! That's not a valid option. Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}