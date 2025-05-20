//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 10
#define BAG_NAME_LENGTH 20

typedef struct {
    char name[BAG_NAME_LENGTH];
} Bag;

typedef struct {
    Bag bags[MAX_BAGS];
    int front;
    int rear;
    int count;
} BaggageQueue;

// Function prototypes
void initializeQueue(BaggageQueue* queue);
int isFull(BaggageQueue* queue);
int isEmpty(BaggageQueue* queue);
void addBag(BaggageQueue* queue, const char* bagName);
void processBag(BaggageQueue* queue);
void displayBags(BaggageQueue* queue);
void menu();

int main() {
    BaggageQueue queue;
    initializeQueue(&queue);
    menu();

    return 0;
}

void initializeQueue(BaggageQueue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

// Check if the queue is full
int isFull(BaggageQueue* queue) {
    return queue->count == MAX_BAGS;
}

// Check if the queue is empty
int isEmpty(BaggageQueue* queue) {
    return queue->count == 0;
}

// Add a bag to the queue
void addBag(BaggageQueue* queue, const char* bagName) {
    if (isFull(queue)) {
        printf("The baggage handling system is currently full. Please try again later.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_BAGS;
    strcpy(queue->bags[queue->rear].name, bagName);
    queue->count++;
    printf("Bag '%s' has been added to the queue.\n", bagName);
}

// Process a bag from the queue
void processBag(BaggageQueue* queue) {
    if (isEmpty(queue)) {
        printf("There are no bags to process.\n");
        return;
    }
    printf("Processing bag: '%s'\n", queue->bags[queue->front].name);
    queue->front = (queue->front + 1) % MAX_BAGS;
    queue->count--;
}

// Display all bags in the queue
void displayBags(BaggageQueue* queue) {
    if (isEmpty(queue)) {
        printf("No bags in the queue.\n");
        return;
    }
    printf("Current bags in the queue:\n");
    for (int i = 0; i < queue->count; i++) {
        int index = (queue->front + i) % MAX_BAGS;
        printf(" - %s\n", queue->bags[index].name);
    }
}

// Display menu options
void menu() {
    BaggageQueue queue;
    initializeQueue(&queue);
    int choice;
    char bagName[BAG_NAME_LENGTH];

    while (1) {
        printf("\n--- Airport Baggage Handling System ---\n");
        printf("1. Add Bag\n");
        printf("2. Process Bag\n");
        printf("3. Display Bags\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline after integer input

        switch (choice) {
            case 1:
                printf("Enter bag name: ");
                fgets(bagName, BAG_NAME_LENGTH, stdin);
                bagName[strcspn(bagName, "\n")] = 0; // Remove newline character
                addBag(&queue, bagName);
                break;
            case 2:
                processBag(&queue);
                break;
            case 3:
                displayBags(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}