//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_REQUESTS 100

typedef struct {
    int requests[MAX_REQUESTS];
    int count;
} RequestQueue;

typedef struct {
    int current_floor;
    bool is_moving_up;
} Elevator;

void init_request_queue(RequestQueue* queue) {
    queue->count = 0;
}

void add_request(RequestQueue* queue, int floor) {
    if (queue->count < MAX_REQUESTS) {
        queue->requests[queue->count++] = floor;
    } else {
        printf("Request queue is full!\n");
    }
}

void process_requests(Elevator* elevator, RequestQueue* queue) {
    while (queue->count > 0) {
        int target_floor = queue->requests[0];

        // Remove the request from queue
        for (int i = 1; i < queue->count; i++) {
            queue->requests[i - 1] = queue->requests[i];
        }
        queue->count--;

        // Move the elevator to the requested floor
        while (elevator->current_floor != target_floor) {
            if (elevator->current_floor < target_floor) {
                elevator->is_moving_up = true;
                elevator->current_floor++;
            } else {
                elevator->is_moving_up = false;
                elevator->current_floor--;
            }

            printf("Elevator moving to floor %d.\n", elevator->current_floor);
            sleep(1); // Simulate the time taken to move to the floor
        }
      
        printf("Elevator has arrived at floor %d.\n", target_floor);
        sleep(1); // Pause to indicate arrival
    }
}

void display_requests(RequestQueue* queue) {
    printf("Current Requests: ");
    for (int i = 0; i < queue->count; i++) {
        printf("%d ", queue->requests[i]);
    }
    printf("\n");
}

int main() {
    Elevator elevator = { .current_floor = 0, .is_moving_up = true };
    RequestQueue requestQueue;

    init_request_queue(&requestQueue);

    int choice;
    do {
        printf("\n=== Elevator Simulation ===\n");
        printf("1. Add Request\n");
        printf("2. Show Current Requests\n");
        printf("3. Process Requests\n");
        printf("4. Exit\n");
        printf("===========================\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);

        if (choice == 1) {
            int floor;
            printf("Enter floor number (0-%d): ", MAX_FLOORS-1);
            scanf("%d", &floor);
            if (floor >= 0 && floor < MAX_FLOORS) {
                add_request(&requestQueue, floor);
            } else {
                printf("Invalid floor!\n");
            }
        } else if (choice == 2) {
            display_requests(&requestQueue);
        } else if (choice == 3) {
            process_requests(&elevator, &requestQueue);
        } else if (choice == 4) {
            printf("Exiting the simulation...\n");
        } else {
            printf("Invalid choice, please try again.\n");
        }

    } while (choice != 4);

    return 0;
}