//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 20

typedef struct {
    int requests[MAX_REQUESTS];
    int front;
    int rear;
    int size;
} Queue;

typedef struct {
    int currentFloor;
    int direction; // 1 for up, -1 for down, 0 for idle
    Queue requestQueue;
} Elevator;

void initializeQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool isQueueFull(Queue *q) {
    return q->size >= MAX_REQUESTS;
}

bool isQueueEmpty(Queue *q) {
    return q->size <= 0;
}

void enqueue(Queue *q, int floor) {
    if (!isQueueFull(q)) {
        q->rear = (q->rear + 1) % MAX_REQUESTS;
        q->requests[q->rear] = floor;
        q->size++;
    } else {
        printf("Request queue is full!\n");
    }
}

int dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {
        int floor = q->requests[q->front];
        q->front = (q->front + 1) % MAX_REQUESTS;
        q->size--;
        return floor;
    }
    return -1; // Indicates an empty queue
}

void requestElevator(Elevator *elevator, int floor) {
    printf("Requesting elevator to floor %d...\n", floor);
    enqueue(&elevator->requestQueue, floor);
}

void moveElevator(Elevator *elevator) {
    while (!isQueueEmpty(&elevator->requestQueue)) {
        int nextFloor = dequeue(&elevator->requestQueue);
        printf("Moving to floor %d...\n", nextFloor);
        elevator->direction = (nextFloor > elevator->currentFloor) ? 1 : -1;

        while (elevator->currentFloor != nextFloor) {
            printf("Current floor: %d\n", elevator->currentFloor);
            elevator->currentFloor += elevator->direction;
            sleep(1); // Simulating time taken to move
        }

        printf("Arrived at floor %d\n", elevator->currentFloor);
        elevator->direction = 0; // Idle after reaching the floor
    }
}

int main() {
    Elevator elevator = {0, 0, {0}};
    initializeQueue(&elevator.requestQueue);

    int choice;
    int floor;

    while (true) {
        printf("\nElevator Simulation\n");
        printf("Current Floor: %d\n", elevator.currentFloor);
        printf("1. Request Elevator\n");
        printf("2. Move Elevator\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter floor number (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                if (floor < 0 || floor >= MAX_FLOORS) {
                    printf("Invalid floor. Please try again.\n");
                } else {
                    requestElevator(&elevator, floor);
                }
                break;
            case 2:
                moveElevator(&elevator);
                break;
            case 3:
                printf("Exiting simulation...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}