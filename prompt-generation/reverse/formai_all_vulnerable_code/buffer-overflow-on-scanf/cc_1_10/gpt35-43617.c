//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#define MAX_FLOOR 10

// Struct representing the elevator status
typedef struct {
    int current_floor;
    bool is_operational;
    bool doors_open;
} Elevator;

// Function to move the elevator to a specific floor
void move_elevator(Elevator *elevator, int target_floor) {
    printf("Moving elevator from floor %d to floor %d\n", elevator->current_floor, target_floor);
    elevator->current_floor = target_floor;
}

// Function to open the elevator doors
void open_doors(Elevator *elevator) {
    printf("Opening doors\n");
    elevator->doors_open = true;
}

// Function to close the elevator doors
void close_doors(Elevator *elevator) {
    printf("Closing doors\n");
    elevator->doors_open = false;
}

// Function to simulate elevator operation
void elevator_simulation(Elevator *elevator) {
    if (!elevator->is_operational) {
        printf("Elevator is out of order\n");
        return;
    }
    
    int target_floor;
    printf("Enter the floor you want to go to (1 to %d): ", MAX_FLOOR);
    scanf("%d", &target_floor);
    
    if (target_floor < 1 || target_floor > MAX_FLOOR) {
        printf("Invalid floor\n");
        return;
    }
    
    printf("Going to floor %d\n", target_floor);
    close_doors(elevator);
    
    while (elevator->current_floor != target_floor) {
        if (elevator->current_floor < target_floor) {
            move_elevator(elevator, elevator->current_floor + 1);
        } else {
            move_elevator(elevator, elevator->current_floor - 1);
        }
    }
    
    open_doors(elevator);
}

int main() {
    Elevator elevator = {1, true, false};
    int choice;
    
    while (true) {
        printf("1. Simulate elevator\n2. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: elevator_simulation(&elevator); break;
            case 2: return 0;
            default: printf("Invalid choice\n"); break;
        }
    }
    
    return 0;
}