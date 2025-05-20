//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_FLOORS 10
#define QUEUE_SIZE 100

typedef struct {
    int requests[QUEUE_SIZE];
    int front;
    int rear;
} RequestQueue;

typedef struct {
    int current_floor;
    RequestQueue queue;
    bool is_moving;
} Elevator;

void init_elevator(Elevator *elevator) {
    elevator->current_floor = 0;
    elevator->is_moving = false;
    elevator->queue.front = 0;
    elevator->queue.rear = 0;
}

void enqueue(RequestQueue *queue, int floor) {
    if (queue->rear < QUEUE_SIZE) {
        queue->requests[queue->rear++] = floor;
    } else {
        printf("Queue is full, cannot enqueue floor %d\n", floor);
    }
}

int dequeue(RequestQueue *queue) {
    if (queue->front < queue->rear) {
        return queue->requests[queue->front++];
    }
    return -1; // Queue is empty
}

bool is_queue_empty(RequestQueue *queue) {
    return queue->front >= queue->rear;
}

void move_elevator(Elevator *elevator) {
    if (is_queue_empty(&elevator->queue)) {
        elevator->is_moving = false;
        printf("Elevator is idle at floor %d\n", elevator->current_floor);
        return;
    }

    elevator->is_moving = true;
    int next_floor = dequeue(&elevator->queue);
    
    while (elevator->current_floor != next_floor) {
        if (elevator->current_floor < next_floor) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        printf("Elevator moving... Current floor: %d\n", elevator->current_floor);
        sleep(1); // Simulating time taken to move
    }

    printf("Elevator has arrived at floor %d\n", next_floor);
}

void request_floor(Elevator *elevator, int floor) {
    if (floor < 0 || floor >= MAX_FLOORS) {
        printf("Invalid floor request: %d. Please choose a floor between 0 and %d.\n", floor, MAX_FLOORS - 1);
        return;
    }
    enqueue(&elevator->queue, floor);
    printf("Floor %d requested.\n", floor);
}

void show_menu() {
    printf("Elevator Simulation Menu:\n");
    printf("1. Request floor\n");
    printf("2. Move elevator\n");
    printf("3. Exit\n");
}

int main() {
    Elevator elevator;
    int choice, floor;

    init_elevator(&elevator);

    while (true) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter floor number (0-%d): ", MAX_FLOORS - 1);
                scanf("%d", &floor);
                request_floor(&elevator, floor);
                break;

            case 2:
                move_elevator(&elevator);
                break;

            case 3:
                printf("Exiting the elevator simulation.\n");
                return 0;

            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    }

    return 0;
}