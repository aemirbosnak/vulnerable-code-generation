//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include <stdio.h>
#define NO_OF_FLOORS 10

enum DIRECTION {
    UP = 0,
    DOWN = 1
};

typedef struct elevator {
    int current_floor;
    enum DIRECTION direction;
    int stops[NO_OF_FLOORS];
} Elevator;

int main() {
    Elevator elevator = { 0, UP, {0} };
    int floor;
    printf("Welcome to Elevator Simulation\n");
    printf("Current Floor: %d\n", elevator.current_floor);
    printf("Please enter the floor you'd like to go to: ");
    scanf("%d", &floor);
    while (floor > NO_OF_FLOORS || floor < 1) {
        printf("Invalid floor, try again: ");
        scanf("%d", &floor);
    }
    elevator.stops[floor-1] = 1; // mark the desired floor as a stop
    printf("Press 1 to call elevator or 0 to exit: ");
    int call;
    scanf("%d", &call);
    while (call != 0) {
        // simulate elevator movement
        if (elevator.direction == UP) {
            for (int i = elevator.current_floor+1; i <= NO_OF_FLOORS; i++) {
                if (elevator.stops[i-1] == 1) {
                    printf("Stopping at Floor %d\n", i);
                    elevator.current_floor = i;
                    elevator.stops[i-1] = 0; // remove this floor from stops
                }
            }
            elevator.direction = DOWN;
        } else if (elevator.direction == DOWN) {
            for (int i = elevator.current_floor-1; i >= 1; i--) {
                if (elevator.stops[i-1] == 1) {
                    printf("Stopping at Floor %d\n", i);
                    elevator.current_floor = i;
                    elevator.stops[i-1] = 0; // remove this floor from stops
                }
            }
            elevator.direction = UP;
        }
        if (elevator.current_floor == floor) {
            printf("You have arrived at your floor.\n");
            printf("Press 0 to exit.\n");
            scanf("%d", &call);
        }
    }
    return 0;
}