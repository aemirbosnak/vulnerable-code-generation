//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLOORS 10
#define MIN_STOP_TIME 5
#define MAX_STOP_TIME 15
#define ELEVATOR_SPEED 1

typedef struct {
    int current_floor;
    int direction;
} Elevator;

void simulate_elevator(Elevator *elevator) {
    int user_input;

    while (1) {
        printf("Current floor: %d\n", elevator->current_floor);
        printf("Enter the floor number you wish to go to: ");
        scanf("%d", &user_input);

        if (user_input == elevator->current_floor) {
            printf("You are already on floor %d.\n", elevator->current_floor);
            continue;
        }

        if (user_input < elevator->current_floor) {
            elevator->direction = 1;
        } else {
            elevator->direction = -1;
        }

        printf("Moving to floor %d...\n", user_input);

        int stop_time = MIN_STOP_TIME + rand() % (MAX_STOP_TIME - MIN_STOP_TIME + 1);

        printf("Stopping at floor %d for %d seconds...\n", user_input, stop_time);
        sleep(stop_time);

        int new_floor = elevator->current_floor + elevator->direction;

        if (new_floor >= 0 && new_floor < NUM_FLOORS) {
            elevator->current_floor = new_floor;
        } else {
            printf("Error: Elevator overshot the floor.\n");
            continue;
        }

        printf("Arrived at floor %d.\n", elevator->current_floor);
    }
}

int main() {
    Elevator elevator = {0};
    srand(time(NULL));

    printf("Simulating elevator...\n");
    simulate_elevator(&elevator);

    return 0;
}