//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define QUEUE_SIZE MAX_FLOORS

typedef struct {
    int requestQueue[QUEUE_SIZE];
    int front;
    int rear;
} ElevatorQueue;

typedef struct {
    int currentFloor;
    ElevatorQueue queue;
    int direction; // 1 for up, -1 for down
} Elevator;

void initQueue(ElevatorQueue *q) {
    q->front = 0;
    q->rear = 0;
    memset(q->requestQueue, 0, sizeof(q->requestQueue));
}

int isQueueEmpty(ElevatorQueue *q) {
    return q->front == q->rear;
}

int enqueue(ElevatorQueue *q, int floor) {
    if ((q->rear + 1) % QUEUE_SIZE == q->front) {
        printf("Queue full! Cannot add more requests.\n");
        return -1;
    }
    q->requestQueue[q->rear] = floor;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    return 0;
}

int dequeue(ElevatorQueue *q) {
    if (isQueueEmpty(q)) {
        return -1;
    }
    int floor = q->requestQueue[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    return floor;
}

void addRequest(Elevator *elevator, int floor) {
    if (floor < 1 || floor > MAX_FLOORS) {
        printf("Invalid floor request: %d\n", floor);
        return;
    }
    
    enqueue(&elevator->queue, floor);
    printf("Request added for floor %d\n", floor);
}

void moveElevator(Elevator *elevator) {
    while (!isQueueEmpty(&elevator->queue)) {
        int nextFloor = dequeue(&elevator->queue);
        printf("Elevator moving from floor %d to floor %d\n", elevator->currentFloor, nextFloor);
        
        // Simulating the movement
        sleep(abs(elevator->currentFloor - nextFloor));
        
        elevator->currentFloor = nextFloor;
        printf("Elevator arrived at floor %d\n", elevator->currentFloor);
    }
}

int main() {
    Elevator elevator;
    elevator.currentFloor = 1; // Start on the first floor
    elevator.direction = 0; // No direction initially
    initQueue(&elevator.queue);
    
    int choice;
    do {
        printf("\nElevator Simulation Menu:\n");
        printf("1. Request Floor\n");
        printf("2. Move Elevator\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int floor;
                printf("Enter the floor you want to go to (1-%d): ", MAX_FLOORS);
                scanf("%d", &floor);
                addRequest(&elevator, floor);
                break;
            }
            case 2:
                moveElevator(&elevator);
                break;
            case 3:
                printf("Exiting the simulation.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}