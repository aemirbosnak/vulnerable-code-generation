//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define ELEVATOR_CAPACITY 10
#define NUM_FLOORS 5

typedef enum {IDLE, UP, DOWN} Elevator_State;
typedef struct {
    int current_floor;
    int num_passengers;
    Elevator_State state;
} Elevator;

int getInput() {
    int input;
    printf("Enter a floor number (0-%d) or -1 to exit: ", NUM_FLOORS - 1);
    scanf("%d", &input);
    return input;
}

void updateElevator(Elevator *elevator) {
    if (elevator->state == UP) {
        elevator->current_floor++;
        if (elevator->current_floor == NUM_FLOORS - 1) {
            elevator->state = DOWN;
        }
    } else if (elevator->state == DOWN) {
        elevator->current_floor--;
        if (elevator->current_floor == 0) {
            elevator->state = UP;
        }
    }
}

int main() {
    Elevator elevator = {0, 0, IDLE};
    int floors_queue[ELEVATOR_CAPACITY];
    int queue_front = 0, queue_back = 0;

    while (1) {
        int input = getInput();
        if (input == -1) {
            printf("Exiting.\n");
            break;
        } else if (input < 0 || input >= NUM_FLOORS) {
            printf("Invalid floor number. Try again.\n");
            continue;
        }

        printf("Request [Floor %d]\n", input);

        if (elevator.num_passengers == ELEVATOR_CAPACITY) {
            printf("Elevator is full.\n");
            continue;
        }

        floors_queue[queue_back] = input;
        queue_back++;
        elevator.num_passengers++;

        if (elevator.num_passengers == 1) {
            if (input > elevator.current_floor) {
                elevator.state = UP;
            } else {
                elevator.state = DOWN;
            }
        }
    }

    printf("Simulation complete.\n");
    return 0;
}