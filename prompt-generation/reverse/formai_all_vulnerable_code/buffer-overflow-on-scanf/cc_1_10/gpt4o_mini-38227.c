//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 5

typedef struct {
    int requestedFloors[MAX_REQUESTS];
    int front;
    int rear;
} RequestQueue;

typedef struct {
    int currentFloor;
    bool movingUp;
    RequestQueue queue;
} Elevator;

void initializeQueue(RequestQueue* queue) {
    queue->front = 0;
    queue->rear = 0;
}

bool isQueueEmpty(RequestQueue* queue) {
    return queue->front == queue->rear;
}

bool enqueue(RequestQueue* queue, int floor) {
    if (queue->rear < MAX_REQUESTS) {
        queue->requestedFloors[queue->rear++] = floor;
        return true;
    }
    return false;
}

int dequeue(RequestQueue* queue) {
    if (!isQueueEmpty(queue)) {
        return queue->requestedFloors[queue->front++];
    }
    return -1; // Queue is empty
}

void initializeElevator(Elevator* elevator) {
    elevator->currentFloor = 0;
    elevator->movingUp = true; // Start by moving up
    initializeQueue(&elevator->queue);
}

void moveElevator(Elevator* elevator) {
    if (!isQueueEmpty(&elevator->queue)) {
        int nextFloor = dequeue(&elevator->queue);
        while (elevator->currentFloor != nextFloor) {
            if (elevator->currentFloor < nextFloor) {
                elevator->currentFloor++;
                elevator->movingUp = true;
            } else {
                elevator->currentFloor--;
                elevator->movingUp = false;
            }
            printf("Elevator moving to floor %d\n", elevator->currentFloor);
            sleep(1);
        }
        printf("Elevator stopping at floor %d\n", elevator->currentFloor);
    }
}

void requestElevator(Elevator* elevator, int floor) {
    if (floor >= 0 && floor < MAX_FLOORS) {
        if (enqueue(&elevator->queue, floor)) {
            printf("Request made for floor %d\n", floor);
        } else {
            printf("Request queue full. Could not request floor %d\n", floor);
        }
    } else {
        printf("Invalid floor: %d\n", floor);
    }
}

void printMenu() {
    printf("Elevator Simulation Menu:\n");
    printf("1: Request elevator to a floor (0-%d)\n", MAX_FLOORS - 1);
    printf("2: Move elevator\n");
    printf("3: Exit\n");
}

int main() {
    Elevator elevator;
    initializeElevator(&elevator);
    int choice, floor;

    while (true) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter floor to request (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                requestElevator(&elevator, floor);
                break;
            case 2:
                moveElevator(&elevator);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}