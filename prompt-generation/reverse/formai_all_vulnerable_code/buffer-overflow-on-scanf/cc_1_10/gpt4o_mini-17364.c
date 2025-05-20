//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 10
#define BAG_DESC_LEN 50

typedef struct Bag {
    char description[BAG_DESC_LEN];
    int bagId;
} Bag;

typedef struct Queue {
    Bag bags[MAX_BAGS];
    int front;
    int rear;
} Queue;

void initializeQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX_BAGS == q->front;
}

int isEmpty(Queue* q) {
    return q->front == (q->rear + 1) % MAX_BAGS;
}

void enqueue(Queue* q, Bag bag) {
    if (isFull(q)) {
        printf("Queue is full! Unable to add bag.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_BAGS;
    q->bags[q->rear] = bag;
}

Bag dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No bags to remove.\n");
        Bag empty = {"", -1};
        return empty;
    }
    Bag bag = q->bags[q->front];
    q->front = (q->front + 1) % MAX_BAGS;
    return bag;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("No bags in the queue.\n");
        return;
    }
    printf("Bags in the queue:\n");
    int i = q->front;
    while (i != (q->rear + 1) % MAX_BAGS) {
        printf("Bag ID %d: %s\n", q->bags[i].bagId, q->bags[i].description);
        i = (i + 1) % MAX_BAGS;
    }
}

void displayMenu() {
    printf("\n--- Baggage Handling Simulation ---\n");
    printf("1. Add Bag\n");
    printf("2. Remove Bag\n");
    printf("3. Display Bags\n");
    printf("4. Exit\n");
}

int main() {
    Queue baggageQueue;
    initializeQueue(&baggageQueue);
    
    int choice;
    int bagCount = 0;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (bagCount >= MAX_BAGS) {
                    printf("Max bag limit reached!\n");
                    break;
                }
                Bag newBag;
                newBag.bagId = ++bagCount;
                printf("Enter bag description: ");
                getchar(); // to consume the newline character
                fgets(newBag.description, BAG_DESC_LEN, stdin);
                newBag.description[strcspn(newBag.description, "\n")] = 0; // Remove newline
                enqueue(&baggageQueue, newBag);
                printf("Bag added successfully!\n");
                break;

            case 2:
                {
                    Bag removedBag = dequeue(&baggageQueue);
                    if (removedBag.bagId != -1) {
                        printf("Removed Bag ID %d: %s\n", removedBag.bagId, removedBag.description);
                    }
                }
                break;
            
            case 3:
                printQueue(&baggageQueue);
                break;

            case 4:
                printf("Exiting the program. Thank you!\n");
                exit(0);
                break;
            
            default:
                printf("Invalid choice! Please try again.\n");
        }
        sleep(1); // Sleep for 1 second for better interaction
    }
    
    return 0;
}