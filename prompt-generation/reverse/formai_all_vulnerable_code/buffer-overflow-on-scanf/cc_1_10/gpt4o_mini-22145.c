//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define QUEUE_SIZE 20

typedef struct {
    int floor_queue[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} FloorQueue;

void initializeQueue(FloorQueue* q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool isFull(FloorQueue* q) {
    return q->count == QUEUE_SIZE;
}

bool isEmpty(FloorQueue* q) {
    return q->count == 0;
}

void enqueue(FloorQueue* q, int floor) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue floor %d.\n", floor);
        return;
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->floor_queue[q->rear] = floor;
    q->count++;
}

int dequeue(FloorQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! No floors to dequeue.\n");
        return -1;
    }
    int floor = q->floor_queue[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return floor;
}

void displayQueue(FloorQueue* q) {
    if (isEmpty(q)) {
        printf("Floor queue is empty.\n");
        return;
    }
    printf("Current floor queue: ");
    for (int i = 0; i < q->count; i++) {
        printf("%d ", q->floor_queue[(q->front + i) % QUEUE_SIZE]);
    }
    printf("\n");
}

void moveToFloor(int floor) {
    printf("Moving to floor %d...\n", floor);
    sleep(1);  // simulate time taken to move
    printf("Arrived at floor %d.\n", floor);
}

void elevatorSystem() {
    FloorQueue floorQueue;
    initializeQueue(&floorQueue);
    int currentFloor = 0;
    int choice;

    do {
        printf("\n--- Elevator System ---\n");
        printf("1. Request Floor\n");
        printf("2. View Current Queue\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the floor you want to go to (0 to %d): ", MAX_FLOORS - 1);
                int requestedFloor;
                scanf("%d", &requestedFloor);
                if (requestedFloor >= 0 && requestedFloor < MAX_FLOORS) {
                    enqueue(&floorQueue, requestedFloor);
                } else {
                    printf("Invalid floor!\n");
                }
                break;
            case 2:
                displayQueue(&floorQueue);
                while (!isEmpty(&floorQueue)) {
                    int nextFloor = dequeue(&floorQueue);
                    moveToFloor(nextFloor);
                }
                break;
            case 3:
                printf("Exiting elevator system. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 3);
}

int main() {
    elevatorSystem();
    return 0;
}