//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 200
#define MAX_LUGGAGE_WEIGHT 100
#define MAX_WAIT_TIME 10

typedef struct {
    int bags[MAX_BAGS];
    int front, rear;
    int count;
} BaggageQueue;

int total_bags_loaded = 0;
int total_weight_loaded = 0;

bool isQueueFull(BaggageQueue *queue) {
    return queue->count == MAX_BAGS;
}

bool isQueueEmpty(BaggageQueue *queue) {
    return queue->count == 0;
}

void enqueue(BaggageQueue *queue, int bags) {
    if (isQueueFull(queue)) {
        printf("Baggage Queue is full. Cannot add any more luggage!\n");
        return;
    }
    queue->bags[queue->rear] = bags;
    queue->rear = (queue->rear + 1) % MAX_BAGS;
    queue->count++;
}

int dequeue(BaggageQueue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Baggage Queue is empty. No luggage to unload!\n");
        return -1;
    }
    int bags = queue->bags[queue->front];
    queue->front = (queue->front + 1) % MAX_BAGS;
    queue->count--;
    return bags;
}

void loadLuggage(BaggageQueue *queue, int flight_no, int luggage_count, int luggage_weight) {
    if (luggage_count > MAX_BAGS) {
        printf("Unable to load all luggage. Max luggage allowed on a flight is %d\n", MAX_BAGS);
        return;
    }
    printf("\nLoading luggage for Flight No: %d\n", flight_no);
    srand(time(0)); // seed for random number generator
    for (int i = 0; i < luggage_count; i++) {
        int weight = rand() % MAX_LUGGAGE_WEIGHT + 1;
        if (total_weight_loaded + weight > luggage_weight) {
            printf("Total weight of luggage exceeds the weight limit. Cannot load more luggage.\n");
            break;
        }
        enqueue(queue, weight);
        total_bags_loaded++;
        total_weight_loaded += weight;
        printf("Loaded luggage piece with weight: %d\n", weight);
    }
}

void unloadLuggage(BaggageQueue *queue, int flight_no) {
    printf("\nUnloading luggage for Flight No: %d\n", flight_no);
    while (!isQueueEmpty(queue)) {
        int bags = dequeue(queue);
        total_bags_loaded--;
        total_weight_loaded -= bags;
        printf("Unloaded luggage piece with weight: %d\n", bags);
    }
}

int main() {
    BaggageQueue queue;
    queue.front = 0;
    queue.rear = 0;
    queue.count = 0;
    int num_flights, max_luggage_count, max_luggage_weight;
    printf("Enter the number of flights: ");
    scanf("%d", &num_flights);
    printf("Enter the maximum number of luggage pieces allowed per flight: ");
    scanf("%d", &max_luggage_count);
    printf("Enter the maximum luggage weight allowed per flight: ");
    scanf("%d", &max_luggage_weight);
    for (int i = 1; i <= num_flights; i++) {
        int num_luggage = rand() % max_luggage_count + 1;
        int luggage_weight = rand() % max_luggage_weight + 1;
        loadLuggage(&queue, i, num_luggage, luggage_weight);
        int wait_time = rand() % MAX_WAIT_TIME + 1;
        printf("\nWaiting for %d seconds before unloading luggage...\n", wait_time);
        sleep(wait_time);
        unloadLuggage(&queue, i);
    }
    printf("\nTotal luggage pieces loaded: %d\n", total_bags_loaded);
    printf("Total luggage weight loaded: %d\n", total_weight_loaded);
    return 0;
}