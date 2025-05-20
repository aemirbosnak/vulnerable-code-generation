//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 10

// Struct to represent an elevator
typedef struct {
    int current_floor;
    int destination_floor;
    int capacity;
    int max_capacity;
} Elevator;

// Array to represent floors
int floors[MAX_FLOORS];

// Function to initialize floors with random values
void initialize_floors() {
    for(int i=0; i<MAX_FLOORS; i++) {
        floors[i] = rand() % 11;
    }
}

// Function to print the state of the elevator
void print_elevator(Elevator elevator) {
    printf("Current floor: %d\n", elevator.current_floor);
    printf("Destination floor: %d\n", elevator.destination_floor);
    printf("Capacity: %d/%d\n", elevator.capacity, elevator.max_capacity);
}

// Function to simulate elevator movement
void move_elevator(Elevator *elevator) {
    // Check if elevator is at the destination floor
    if(elevator->current_floor == elevator->destination_floor) {
        // Let passengers exit
        printf("Passengers are exiting the elevator...\n");
        elevator->capacity = 0;
        return;
    }
    
    // Move elevator up or down
    if(elevator->current_floor < elevator->destination_floor) {
        printf("Moving up...\n");
        elevator->current_floor++;
    } else {
        printf("Moving down...\n");
        elevator->current_floor--;
    }
    
    // Let passengers enter
    if(elevator->capacity < elevator->max_capacity && elevator->current_floor < MAX_FLOORS) {
        int passengers_to_enter = rand() % (elevator->max_capacity - elevator->capacity + 1);
        printf("Passengers are entering the elevator (%d)...\n", passengers_to_enter);
        elevator->capacity += passengers_to_enter;
    }
}

int main() {
    initialize_floors();
    printf("Floors: ");
    for(int i=0; i<MAX_FLOORS; i++) {
        printf("%d ", floors[i]);
    }
    printf("\n");
    
    Elevator elevator = {0};
    int destination_floor;
    printf("Enter destination floor (0-%d): ", MAX_FLOORS-1);
    scanf("%d", &destination_floor);
    elevator.destination_floor = destination_floor;
    elevator.max_capacity = MAX_CAPACITY;
    printf("\n");
    
    while(elevator.capacity > 0 || elevator.current_floor != elevator.destination_floor) {
        print_elevator(elevator);
        move_elevator(&elevator);
        printf("\n");
    }
    
    printf("Elevator has arrived at the destination floor.\n");

    return 0;
}