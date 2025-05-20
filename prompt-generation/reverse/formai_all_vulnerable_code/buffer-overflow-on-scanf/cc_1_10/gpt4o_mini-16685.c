//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 100
#define BAG_NAME_LENGTH 30

typedef struct {
    int id;
    char name[BAG_NAME_LENGTH];
    int weight;
} Bag;

typedef struct {
    Bag* bags[MAX_BAGS];
    int front;
    int rear;
    int size;
} BaggageQueue;

BaggageQueue* createQueue() {
    BaggageQueue* queue = (BaggageQueue*)malloc(sizeof(BaggageQueue));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isFull(BaggageQueue* queue) {
    return queue->size == MAX_BAGS; 
}

int isEmpty(BaggageQueue* queue) {
    return queue->size == 0; 
}

void enqueue(BaggageQueue* queue, Bag* bag) {
    if (!isFull(queue)) {
        queue->rear = (queue->rear + 1) % MAX_BAGS;
        queue->bags[queue->rear] = bag;
        queue->size++;
        printf("Bag %s (ID: %d, Weight: %dkg) has been added to the queue.\n", bag->name, bag->id, bag->weight);
    } else {
        printf("Queue is full! Cannot add more bags.\n");
    }
}

Bag* dequeue(BaggageQueue* queue) {
    if (!isEmpty(queue)) {
        Bag* bag = queue->bags[queue->front];
        queue->front = (queue->front + 1) % MAX_BAGS;
        queue->size--;
        return bag;
    } else {
        printf("Queue is empty! No bags to process.\n");
        return NULL;
    }
}

void processBag(Bag* bag) {
    if (bag != NULL) {
        printf("Processing bag %s (ID: %d, Weight: %dkg)...\n", bag->name, bag->id, bag->weight);
        sleep(1); // Simulating processing time
        printf("Bag %s successfully processed and ready for loading!\n\n", bag->name);
        free(bag);
    }
}

void cleanupQueue(BaggageQueue* queue) {
    free(queue);
}

int main() {
    BaggageQueue* queue = createQueue();
    char command;
    int bagCount = 0;

    printf("Welcome to the Airport Baggage Handling Simulation!\n\n");

    while (1) {
        printf("Choose an action:\n");
        printf("1. Add a new bag (press 'A')\n");
        printf("2. Process the next bag (press 'P')\n");
        printf("3. Exit the simulation (press 'E')\n");
        printf("Your choice: ");
        scanf(" %c", &command);

        if (command == 'A' || command == 'a') {
            if (!isFull(queue)) {
                Bag* newBag = (Bag*)malloc(sizeof(Bag));
                newBag->id = ++bagCount;
                printf("Enter the name of the bag: ");
                scanf("%s", newBag->name);
                printf("Enter the weight of the bag (kg): ");
                scanf("%d", &newBag->weight);
                enqueue(queue, newBag);
            } else {
                printf("The baggage handling queue is full! Cannot add more bags.\n");
            }
        } else if (command == 'P' || command == 'p') {
            Bag* bagToProcess = dequeue(queue);
            processBag(bagToProcess);
        } else if (command == 'E' || command == 'e') {
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }

        printf("\n");
    }

    printf("Exiting simulation. Thank you for using the Airport Baggage Handling System!\n");
    cleanupQueue(queue);
    return 0;
}