//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define NUM_BAG_TYPES 3
#define MIN_BAG_WEIGHT 10
#define MAX_BAG_WEIGHT 30
#define BAG_WEIGHT_INCREMENT 5
#define NUM_BAGS_PER_TYPE 10
#define MAX_BAG_DELAY 10

// Define bag types
enum bag_types {
    SMALL_BAG,
    MEDIUM_BAG,
    LARGE_BAG
};

// Define baggage struct
struct baggage {
    enum bag_types type;
    int weight;
    int delay;
};

// Define queue struct
struct queue {
    struct baggage *baggage;
    int size;
    int capacity;
};

// Define airport struct
struct airport {
    struct queue *queues;
    int num_queues;
    int capacity;
};

// Initialize airport
void init_airport(struct airport *airport) {
    airport->num_queues = NUM_BAG_TYPES;
    airport->capacity = NUM_BAG_TYPES * NUM_BAGS_PER_TYPE;
    airport->queues = (struct queue *)malloc(airport->num_queues * sizeof(struct queue));
    for (int i = 0; i < airport->num_queues; i++) {
        airport->queues[i].baggage = (struct baggage *)malloc(NUM_BAGS_PER_TYPE * sizeof(struct baggage));
        airport->queues[i].size = 0;
        airport->queues[i].capacity = NUM_BAGS_PER_TYPE;
    }
}

// Initialize baggage
void init_baggage(struct baggage *baggage) {
    baggage->type = (enum bag_types)rand() % NUM_BAG_TYPES;
    baggage->weight = MIN_BAG_WEIGHT + (rand() % (MAX_BAG_WEIGHT - MIN_BAG_WEIGHT + 1)) * BAG_WEIGHT_INCREMENT;
    baggage->delay = 0;
}

// Enqueue baggage
void enqueue_baggage(struct airport *airport, struct baggage *baggage) {
    struct queue *queue = &airport->queues[baggage->type];
    if (queue->size < queue->capacity) {
        queue->baggage[queue->size] = *baggage;
        queue->size++;
    } else {
        printf("Queue is full!\n");
    }
}

// Dequeue baggage
void dequeue_baggage(struct airport *airport, struct baggage *baggage) {
    struct queue *queue = &airport->queues[baggage->type];
    if (queue->size > 0) {
        *baggage = queue->baggage[queue->size - 1];
        queue->size--;
    } else {
        printf("Queue is empty!\n");
    }
}

// Simulate bag handling
void simulate_baggage_handling(struct airport *airport) {
    struct baggage baggage;
    for (int i = 0; i < airport->num_queues; i++) {
        for (int j = 0; j < airport->queues[i].size; j++) {
            init_baggage(&baggage);
            enqueue_baggage(airport, &baggage);
            printf("Baggage %d of type %d weighs %d and is delayed by %d minutes\n", j + 1, baggage.type, baggage.weight, baggage.delay);
            dequeue_baggage(airport, &baggage);
            printf("Baggage %d of type %d weighs %d and is delayed by %d minutes\n", j + 1, baggage.type, baggage.weight, baggage.delay);
        }
    }
}

int main() {
    struct airport airport;
    init_airport(&airport);
    simulate_baggage_handling(&airport);
    return 0;
}