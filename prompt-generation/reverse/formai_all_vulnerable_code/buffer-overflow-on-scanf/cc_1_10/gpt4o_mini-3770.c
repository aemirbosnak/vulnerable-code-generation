//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define QUEUE_SIZE 10

typedef enum {
    AWAITING_LOADING,
    LOADED,
    DELIVERED
} BaggageStatus;

typedef struct {
    int id;
    BaggageStatus status;
} Baggage;

typedef struct {
    Baggage queue[QUEUE_SIZE];
    int front;
    int rear;
    int size;
} BaggageQueue;

// Function to initialize the baggage queue
void initializeQueue(BaggageQueue *bq) {
    bq->front = 0;
    bq->rear = -1;
    bq->size = 0;
}

// Function to check if the queue is full
int isFull(BaggageQueue *bq) {
    return bq->size == QUEUE_SIZE;
}

// Function to check if the queue is empty
int isEmpty(BaggageQueue *bq) {
    return bq->size == 0;
}

// Function to add baggage to the queue
void enqueue(BaggageQueue *bq, int id) {
    if (isFull(bq)) {
        printf("Baggage queue is full! Cannot enqueue baggage ID: %d\n", id);
        return;
    }
    bq->rear = (bq->rear + 1) % QUEUE_SIZE;
    bq->queue[bq->rear].id = id;
    bq->queue[bq->rear].status = AWAITING_LOADING;
    bq->size++;
    printf("Baggage ID: %d added to the queue.\n", id);
}

// Function to load baggage
void loadBag(BaggageQueue *bq) {
    if (isEmpty(bq)) {
        printf("No baggage to load.\n");
        return;
    }
    Baggage *bag = &bq->queue[bq->front];
    if (bag->status == AWAITING_LOADING) {
        bag->status = LOADED;
        printf("Baggage ID: %d has been loaded.\n", bag->id);
        bq->front = (bq->front + 1) % QUEUE_SIZE;
        bq->size--;
    } else {
        printf("Baggage ID: %d cannot be loaded. Current status: %d\n", bag->id, bag->status);
    }
}

// Function to deliver baggage
void deliverBag(BaggageQueue *bq) {
    if (isEmpty(bq)) {
        printf("No baggage to deliver.\n");
        return;
    }
    int idx = bq->front == 0 ? QUEUE_SIZE - 1 : bq->front - 1;
    Baggage *bag = &bq->queue[idx];
    if (bag->status == LOADED) {
        bag->status = DELIVERED;
        printf("Baggage ID: %d has been delivered.\n", bag->id);
    } else {
        printf("Baggage ID: %d cannot be delivered. Current status: %d\n", bag->id, bag->status);
    }
}

// Function to print the status of all baggage in the queue
void printBaggageStatus(BaggageQueue *bq) {
    if (isEmpty(bq)) {
        printf("No baggage in the queue.\n");
        return;
    }
    printf("Current baggage status:\n");
    for (int i = 0; i < bq->size; i++) {
        int idx = (bq->front + i) % QUEUE_SIZE;
        printf("Baggage ID: %d, Status: %d\n", bq->queue[idx].id, bq->queue[idx].status);
    }
}

int main() {
    BaggageQueue bq;
    initializeQueue(&bq);
    
    int choice, id;
    while (1) {
        printf("\nAirport Baggage Handling System:\n");
        printf("1. Add Baggage\n");
        printf("2. Load Baggage\n");
        printf("3. Deliver Baggage\n");
        printf("4. Check Baggage Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter baggage ID to add: ");
                scanf("%d", &id);
                enqueue(&bq, id);
                break;
            case 2:
                loadBag(&bq);
                break;
            case 3:
                deliverBag(&bq);
                break;
            case 4:
                printBaggageStatus(&bq);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        sleep(1);
    }

    return 0;
}