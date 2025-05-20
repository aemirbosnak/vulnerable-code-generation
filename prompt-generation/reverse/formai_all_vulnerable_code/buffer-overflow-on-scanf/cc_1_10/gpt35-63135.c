//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CAPACITY 100

// Define baggage struct
typedef struct Baggage {
    int number;
    char flight[10];
} Baggage;

// Define baggage queue struct
typedef struct BaggageQueue {
    Baggage baggageList[MAX_CAPACITY];
    int front;
    int rear;
} BaggageQueue;

// Initialize baggage queue
void initialize(BaggageQueue* q) {
    q->front = q->rear = -1;
}

// Check if queue is empty
bool isQueueEmpty(BaggageQueue* q) {
    return q->front == -1;
}

// Check if queue is full
bool isQueueFull(BaggageQueue* q) {
    return (q->front == 0 && q->rear == MAX_CAPACITY - 1) || q->rear == (q->front - 1) % (MAX_CAPACITY - 1);
}

// Add new baggage to queue
void enqueue(BaggageQueue* q, Baggage newBaggage) {
    if (isQueueFull(q)) {
        printf("Baggage queue is full!\n");
        return;
    }

    if (q->front == -1) {
        q->front = q->rear = 0;
        q->baggageList[q->rear] = newBaggage;
    } else if (q->rear == MAX_CAPACITY - 1 && q->front != 0) {
        q->rear = 0;
        q->baggageList[q->rear] = newBaggage;
    } else {
        q->rear++;
        q->baggageList[q->rear] = newBaggage;
    }
}

// Remove baggage from queue
Baggage dequeue(BaggageQueue* q) {
    if (isQueueEmpty(q)) {
        printf("Baggage queue is empty!\n");
        Baggage emptyBaggage;
        emptyBaggage.number = -1;
        return emptyBaggage;
    }

    Baggage removedBaggage = q->baggageList[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else if (q->front == MAX_CAPACITY - 1) {
        q->front = 0;
    } else {
        q->front++;
    }

    return removedBaggage;
}

// Display all baggage in queue
void displayBaggageQueue(BaggageQueue* q) {
    if (isQueueEmpty(q)) {
        printf("Baggage queue is empty!\n");
        return;
    }

    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_CAPACITY) {
        printf("Baggage Number: %d | Flight Number: %s\n", q->baggageList[i].number, q->baggageList[i].flight);
    }

    printf("Baggage Number: %d | Flight Number: %s\n", q->baggageList[i].number, q->baggageList[i].flight);
}

int main() {
    int choice;
    BaggageQueue queue;
    initialize(&queue);

    do {
        printf("\n=====Airport Baggage Handling Simulation=====\n");
        printf("1. Add new baggage to queue\n");
        printf("2. Remove baggage from queue\n");
        printf("3. Display all baggage in queue\n");
        printf("4. Quit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Baggage newBaggage;
                printf("\nEnter Baggage Number: ");
                scanf("%d", &newBaggage.number);
                printf("Enter Flight Number: ");
                scanf("%s", newBaggage.flight);
                enqueue(&queue, newBaggage);
                printf("\nAdded Baggage Number %d for Flight %s to the queue.\n", newBaggage.number, newBaggage.flight);
                break;
            }

            case 2: {
                Baggage removedBaggage = dequeue(&queue);
                if (removedBaggage.number != -1) {
                    printf("\nRemoved Baggage Number %d for Flight %s from the queue.\n", removedBaggage.number, removedBaggage.flight);
                }
                break;
            }

            case 3: {
                printf("\n===== All Baggage in Queue =====\n\n");
                displayBaggageQueue(&queue);
                break;
            }

            case 4: {
                printf("\nExiting Airport Baggage Handling Simulation...\n");
                exit(0);
            }

            default:
                printf("Invalid choice!\n");
        }
    } while (true);

    return 0;
}