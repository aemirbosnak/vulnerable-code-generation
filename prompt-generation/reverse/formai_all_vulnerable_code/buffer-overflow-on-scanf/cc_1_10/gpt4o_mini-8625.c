//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_BAGGAGE_TIME 10 // Max time a baggage can take
#define MAX_CONVEYOR_TIME 5  // Max time for conveyor to process a bag

typedef struct Baggage {
    int id;
    int arrival_time;
    int processing_time; // Time taken for handling
} Baggage;

Baggage baggage_queue[MAX_BAGS];
int front = -1, rear = -1, total_baggage = 0;

// Enqueue function for adding a baggage to the queue
void enqueue(Baggage baggage) {
    if ((rear + 1) % MAX_BAGS == front) {
        printf("Baggage queue is full!\n");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX_BAGS;
    baggage_queue[rear] = baggage;
    total_baggage++;
}

// Dequeue function for processing a baggage from the queue
Baggage dequeue() {
    if (front == -1) {
        printf("Baggage queue is empty!\n");
        exit(1);
    }
    Baggage baggage = baggage_queue[front];
    if (front == rear) {
        front = rear = -1; // Reset queue after last element is dequeued
    } else {
        front = (front + 1) % MAX_BAGS;
    }
    total_baggage--;
    return baggage;
}

// Function to simulate baggage handling
void handleBaggage() {
    int handled_baggage = 0;
    int total_handling_time = 0;
    while (total_baggage > 0) {
        Baggage baggage = dequeue();
        sleep(baggage.processing_time); // Simulate handling time
        printf("Processed baggage ID: %d, Handling Time: %d seconds\n", baggage.id, baggage.processing_time);
        total_handling_time += baggage.processing_time;
        handled_baggage++;
    }
    
    // Statistical Outputs
    printf("\nTotal Baggage Processed: %d\n", handled_baggage);
    printf("Total Handling Time: %d seconds\n", total_handling_time);
    printf("Average Handling Time: %.2f seconds\n", (float)total_handling_time / handled_baggage);
}

// Random baggage generation
void generateBaggage(int n) {
    srand(time(NULL)); // Seed for random number generator
    for (int i = 0; i < n; i++) {
        Baggage baggage;
        baggage.id = i + 1;
        baggage.arrival_time = rand() % 10; // Arrival time
        baggage.processing_time = (rand() % MAX_BAGGAGE_TIME) + 1; // Processing time between 1 and MAX_BAGGAGE_TIME
        printf("Generated baggage ID: %d, Arrival Time: %d, Processing Time: %d\n",
               baggage.id, baggage.arrival_time, baggage.processing_time);
        enqueue(baggage);
    }
}

int main() {
    int n;

    printf("Enter the number of baggage to be processed: ");
    scanf("%d", &n);
    
    generateBaggage(n);
    
    printf("\nHandling baggage...\n");
    handleBaggage();
    
    return 0;
}