//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdbool.h>

#define NUM_FLOORS 10

enum status {IDLE, MOVING_UP, MOVING_DOWN};

struct Elevator {
    int current_floor;
    bool destinations[NUM_FLOORS];
    enum status current_status;
};

void move_elevator(struct Elevator *elevator, int target_floor) {
    if (target_floor > elevator->current_floor) {
        elevator->current_status = MOVING_UP;
    } else if (target_floor < elevator->current_floor) {
        elevator->current_status = MOVING_DOWN;
    }
    
    while (elevator->current_floor != target_floor) {
        if (elevator->current_status == MOVING_UP) {
            elevator->current_floor++;
        } else {
            elevator->current_floor--;
        }
        printf("Elevator is now on floor %d\n", elevator->current_floor);
    }
    
    elevator->current_status = IDLE;
    elevator->destinations[target_floor] = false;
    printf("Elevator has arrived at floor %d\n", target_floor);
}

int main() {
    struct Elevator elevator = {0};
    int target_floor = 0;
    
    while (true) {
        printf("Which floor do you want to go to? (0-%d, -1 to exit)\n", NUM_FLOORS-1);
        scanf("%d", &target_floor);
        
        if (target_floor == -1) {
            break;
        }
        
        if (target_floor < 0 || target_floor >= NUM_FLOORS) {
            printf("Invalid floor\n");
            continue;
        }
        
        elevator.destinations[target_floor] = true;
        
        if (elevator.current_status == IDLE) {
            int next_floor = -1;
            
            for (int i = 0; i < NUM_FLOORS; i++) {
                if (elevator.destinations[i]) {
                    next_floor = i;
                    break;
                }
            }
            
            if (next_floor == -1) {
                printf("Error: elevator in IDLE status but no destinations found\n");
                break;
            }
            
            move_elevator(&elevator, next_floor);
        }
    }
    
    return 0;
}