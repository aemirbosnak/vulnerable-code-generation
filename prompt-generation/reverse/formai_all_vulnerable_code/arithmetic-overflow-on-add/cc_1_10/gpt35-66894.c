//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CAPACITY 100 // Maximum capacity of baggage conveyor belt
#define MAX_BAGGAGE 20 // Maximum number of baggage that can be processed at once
#define MIN_WEIGHT 5 // Minimum weight of a baggage
#define MAX_WEIGHT 30 // Maximum weight of a baggage

typedef struct {
    int weight;
    int destination;
} Baggage;

typedef struct {
    Baggage items[MAX_BAGGAGE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isFull(Queue *q) {
    return (q->rear == MAX_BAGGAGE - 1);
}

int isEmpty(Queue *q) {
    return (q->rear < q->front);
}

void enqueue(Queue *q, Baggage item) {
    if (isFull(q)) {
        printf("Error: Queue is full\n");
        return;
    }
    q->rear++;
    q->items[q->rear] = item;
}

Baggage dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: Queue is empty\n");
        Baggage null;
        null.weight = -1;
        null.destination = -1;
        return null;
    }
    Baggage item = q->items[q->front];
    q->front++;
    return item;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Baggage in conveyor belt:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("Weight: %d, Destination: %d\n", q->items[i].weight, q->items[i].destination);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generator
    Queue conveyorBelt; // Queue to represent conveyor belt

    int totalBaggage = 1 + rand() % MAX_CAPACITY; // Total number of baggage
    int remainingBaggage = totalBaggage; // Remaining unprocessed baggage
    printf("Total baggage: %d\n", totalBaggage);

    // Enqueue all baggage into the conveyor belt
    for (int i = 0; i < totalBaggage; i++) {
        Baggage baggage;
        baggage.weight = MIN_WEIGHT + rand() % (MAX_WEIGHT - MIN_WEIGHT + 1);
        baggage.destination = rand() % 5; // 0 to 4 representing the 5 destinations

        enqueue(&conveyorBelt, baggage);
    }

    // Process baggage while conveyor belt is not empty
    while (!isEmpty(&conveyorBelt)) {
        int numBaggage = 1 + rand() % MAX_BAGGAGE;
        printf("\nProcessing %d baggage...\n", numBaggage);

        // Dequeue baggage from conveyor belt and load onto the airplane
        for (int i = 0; i < numBaggage && !isEmpty(&conveyorBelt); i++) {
            Baggage baggage = dequeue(&conveyorBelt);
            printf("Loading baggage: weight = %d, destination = %d\n", baggage.weight, baggage.destination);
            remainingBaggage--;
        }

        display(&conveyorBelt);
        printf("Remaining unprocessed baggage: %d\n", remainingBaggage);
    }

    printf("\nAll baggage loaded onto the airplane.\n");
    printf("Total baggage processed: %d\n", totalBaggage);

    return 0;
}