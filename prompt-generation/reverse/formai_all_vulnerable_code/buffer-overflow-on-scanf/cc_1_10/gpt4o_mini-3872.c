//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 10

typedef struct {
    int requests[MAX_REQUESTS];
    int front;
    int rear;
} Queue;

typedef struct {
    int current_floor;
    int direction; // 1 for up, -1 for down, 0 for idle
    Queue request_queue;
} Elevator;

void init_queue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
}

bool is_queue_empty(Queue *queue) {
    return queue->front == queue->rear;
}

bool add_request(Queue *queue, int floor) {
    if ((queue->rear + 1) % MAX_REQUESTS == queue->front) {
        printf("Request queue is full!\n");
        return false;
    }
    queue->requests[queue->rear] = floor;
    queue->rear = (queue->rear + 1) % MAX_REQUESTS;
    return true;
}

int remove_request(Queue *queue) {
    if (is_queue_empty(queue)) {
        return -1; // Empty queue
    }
    int floor = queue->requests[queue->front];
    queue->front = (queue->front + 1) % MAX_REQUESTS;
    return floor;
}

void move_elevator(Elevator *elevator) {
    int target_floor = remove_request(&elevator->request_queue);
    if (target_floor == -1) {
        elevator->direction = 0; // No request, idle
        return;
    }

    printf("Moving from floor %d to floor %d\n", elevator->current_floor, target_floor);
    while (elevator->current_floor != target_floor) {
        if (elevator->current_floor < target_floor) {
            elevator->current_floor++;
            elevator->direction = 1;
        } else {
            elevator->current_floor--;
            elevator->direction = -1;
        }
        printf("Elevator at floor %d\n", elevator->current_floor);
        sleep(1);
    }
    printf("Arrived at floor %d\n", elevator->current_floor);
    elevator->direction = 0; // Stop after reaching the target
}

int main() {
    Elevator elevator;
    elevator.current_floor = 1;
    elevator.direction = 0;
    init_queue(&elevator.request_queue);

    int choice, floor_request;
    while (true) {
        printf("\n====== Elevator Simulation ======\n");
        printf("Current Floor: %d\n", elevator.current_floor);
        printf("1. Request Floor\n");
        printf("2. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter floor number (1-%d): ", MAX_FLOORS);
            scanf("%d", &floor_request);
            if (floor_request >= 1 && floor_request <= MAX_FLOORS) {
                add_request(&elevator.request_queue, floor_request);
                printf("Request added for floor %d\n", floor_request);
                move_elevator(&elevator);
            } else {
                printf("Invalid floor number!\n");
            }
        } else if (choice == 2) {
            printf("Exiting the simulation.\n");
            break;
        } else {
            printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}