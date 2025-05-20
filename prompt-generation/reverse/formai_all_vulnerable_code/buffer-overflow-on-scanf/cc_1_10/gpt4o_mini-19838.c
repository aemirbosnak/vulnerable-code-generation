//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 100
#define BAG_ID_LENGTH 10

typedef struct {
    char id[BAG_ID_LENGTH];
    int processed;
} Bag;

typedef struct {
    Bag bags[MAX_BAGS];
    int front;
    int rear;
    int count;
} BaggageQueue;

void initializeQueue(BaggageQueue* queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->count = 0;
}

int isFull(BaggageQueue* queue) {
    return queue->count == MAX_BAGS;
}

int isEmpty(BaggageQueue* queue) {
    return queue->count == 0;
}

void enqueue(BaggageQueue* queue, const char* id) {
    if (isFull(queue)) {
        printf("Oh no! The baggage queue is full! Cannot add more bags!\n");
        return;
    }
    strcpy(queue->bags[queue->rear].id, id);
    queue->bags[queue->rear].processed = 0;
    queue->rear = (queue->rear + 1) % MAX_BAGS;
    queue->count++;
    printf("Woohoo! Bag %s has been added to the queue!\n", id);
}

void dequeue(BaggageQueue* queue) {
    if (isEmpty(queue)) {
        printf("Oops! There are no bags to process right now!\n");
        return;
    }
    printf("Processing bag %s...\n", queue->bags[queue->front].id);
    queue->bags[queue->front].processed = 1;
    queue->front = (queue->front + 1) % MAX_BAGS;
    queue->count--;
    sleep(1);  // Simulate processing time
}

void displayQueue(BaggageQueue* queue) {
    if (isEmpty(queue)) {
        printf("The baggage queue is currently empty!\n");
        return;
    }
    printf("Current Baggage Queue:\n");
    for (int i = 0; i < queue->count; i++) {
        int index = (queue->front + i) % MAX_BAGS;
        printf("Bag ID: %s | Status: %s\n", queue->bags[index].id, queue->bags[index].processed ? "Processed" : "Not processed");
    }
}

int main() {
    BaggageQueue queue;
    initializeQueue(&queue);
    char choice;
    char id[BAG_ID_LENGTH];

    printf("Welcome to the Airport Baggage Handling Simulation!\n");
    do {
        printf("\nChoose an option:\n");
        printf("1. Add a bag\n");
        printf("2. Process a bag\n");
        printf("3. Display current bags in queue\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf(" %c", &choice);
        getchar();  // Clear newline character

        switch (choice) {
            case '1':
                if (isFull(&queue)) {
                    printf("Cannot add more bags, the queue is full!\n");
                } else {
                    printf("Enter Bag ID to add: ");
                    fgets(id, BAG_ID_LENGTH, stdin);
                    id[strcspn(id, "\n")] = 0;  // Remove newline character
                    enqueue(&queue, id);
                }
                break;
            case '2':
                dequeue(&queue);
                break;
            case '3':
                displayQueue(&queue);
                break;
            case '4':
                printf("Exiting the simulation. Thank you for using the Airport Baggage Handling System!\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
                break;
        }

    } while (choice != '4');

    return 0;
}