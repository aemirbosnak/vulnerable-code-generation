//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FLOORS 5
#define MAX_REQUESTS 10

typedef struct {
    int requests[MAX_REQUESTS];
    int count;
} RequestQueue;

typedef struct {
    int current_floor;
    RequestQueue queue;
    int direction; // 1 for up, -1 for down, 0 for idle
} Elevator;

void init_elevator(Elevator *e) {
    e->current_floor = 0; // Ground floor
    e->queue.count = 0;
    e->direction = 0; // Idle
}

void add_request(Elevator *e, int floor) {
    if (e->queue.count < MAX_REQUESTS) {
        e->queue.requests[e->queue.count++] = floor;
    }
}

void print_status(Elevator *e) {
    printf("Elevator @ Floor: %d | Direction: %s | Requests: ", 
           e->current_floor, 
           e->direction == 1 ? "Up" : (e->direction == -1 ? "Down" : "Idle"));
    
    for(int i = 0; i < e->queue.count; i++) {
        printf("%d ", e->queue.requests[i]);
    }
    printf("\n");
}

int next_floor(Elevator *e) {
    if (e->queue.count == 0) return -1;
    return e->queue.requests[0];
}

void move_elevator(Elevator *e) {
    if (e->queue.count == 0) {
        e->direction = 0; // Idle
        return;
    }
    int target = next_floor(e);
    if (target > e->current_floor) {
        e->current_floor++;
        e->direction = 1;
    } else if (target < e->current_floor) {
        e->current_floor--;
        e->direction = -1;
    }
    
    // Check if we've reached the requested floor
    if (e->current_floor == target) {
        printf("Arrived at Floor: %d\n", target);
        // Remove the floor from requests
        for (int i = 0; i < e->queue.count - 1; i++) {
            e->queue.requests[i] = e->queue.requests[i + 1];
        }
        e->queue.count--;
    }
}

int main() {
    Elevator e;
    init_elevator(&e);
    int input = 0;

    while (1) {
        print_status(&e);
        printf("Select floor to request (0-%d, -1 to quit): ", FLOORS - 1);
        scanf("%d", &input);
        
        if (input == -1) break;
        if (input >= 0 && input < FLOORS) {
            add_request(&e, input);
        } else {
            printf("Invalid floor!\n");
        }
        
        while (e.queue.count > 0) {
            move_elevator(&e);
            sleep(1); // Simulate time taken to move
        }
    }

    printf("Exiting elevator simulation.\n");
    return 0;
}