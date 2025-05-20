//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: intelligent
#include<stdio.h>

#define MAX_FLOOR 10
#define MIN_FLOOR 0
#define MAX_PASS 10

// Structure for the elevator
struct Elevator {
    int current_floor;
    int current_passengers;
    int max_passengers;
    int direction; // 1 for up and 0 for down
};

int main() {
    // Setting up the initial elevator state
    struct Elevator elevator;
    elevator.current_floor = 0;
    elevator.current_passengers = 0;
    elevator.max_passengers = MAX_PASS;
    elevator.direction = 1;

    // Initializing the floors array
    int floors[MAX_FLOOR];
    for(int i=0; i<MAX_FLOOR; i++) {
        floors[i] = 0;
    }

    // Starting the simulation loop
    while(1) {
        // Taking input from user for passengers
        int new_passengers;
        printf("Enter number of passengers waiting on floor %d: ", elevator.current_floor);
        scanf("%d", &new_passengers);

        // Adding passengers to the elevator
        int passengers_added = 0;
        for(int i=0; i<new_passengers; i++) {
            if(elevator.current_passengers < elevator.max_passengers) {
                elevator.current_passengers++;
                passengers_added++;
            }
            else {
                break;
            }
        }
        printf("%d passengers added to elevator\n", passengers_added);

        // Taking input from user for elevator movement
        int new_floor;
        printf("Enter new floor number (between 0 and 10): ");
        scanf("%d", &new_floor);

        // Checking validity of floor input
        if(new_floor > MAX_FLOOR || new_floor < MIN_FLOOR) {
            printf("Invalid floor number\n");
            continue;
        }

        // Moving the elevator to the new floor
        if(new_floor > elevator.current_floor) {
            printf("Elevator moving up\n");
            elevator.direction = 1;
        }
        else if(new_floor < elevator.current_floor) {
            printf("Elevator moving down\n");
            elevator.direction = 0;
        }
        else {
            printf("Elevator already on this floor\n");
        }

        // Dropping off passengers
        int passengers_dropped = floors[elevator.current_floor];
        if(elevator.current_passengers > passengers_dropped) {
            elevator.current_passengers -= passengers_dropped;
            floors[elevator.current_floor] = 0;
            printf("%d passengers dropped off on floor %d\n", passengers_dropped, elevator.current_floor);
        }
        else {
            floors[elevator.current_floor] -= elevator.current_passengers;
            printf("%d passengers dropped off on floor %d\n", elevator.current_passengers, elevator.current_floor);
            elevator.current_passengers = 0;
        }

        // Updating current floor
        elevator.current_floor = new_floor;

        // Checking if simulation is over
        if(elevator.current_floor == MAX_FLOOR && elevator.current_passengers == 0) {
            printf("Simulation over\n");
            break;
        }
    }

    return 0;
}