//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BUTTONS 5
#define MIN_FLOOR 0
#define MAX_FLOOR 9
#define STOPPED 0
#define MOVING_UP 1
#define MOVING_DOWN -1

typedef struct {
    int floor;
    int direction;
} elevator;

void simulate_elevator(void) {
    elevator elevator = {.floor = MIN_FLOOR, .direction = STOPPED};
    int button_press;

    for (int i = 0; i < 100; i++) {
        printf("Iteration %d: Current floor: %d\n", i, elevator.floor);

        if (rand() % 10 < 5) { // Simulate random button press
            button_press = rand() % NUM_BUTTONS + 'A';
            printf("Button %c pressed.\n", button_press);
        }

        switch (elevator.direction) {
            case STOPPED:
                if (button_press != '\0') {
                    elevator.floor = button_press - 'A';
                    elevator.direction = MOVING_UP;
                    printf("Moving to floor %d.\n", elevator.floor);
                }
                break;
            case MOVING_UP:
                if (elevator.floor < MAX_FLOOR) {
                    elevator.floor++;
                    printf("Reached floor %d.\n", elevator.floor);
                    elevator.direction = STOPPED;
                }
                break;
            case MOVING_DOWN:
                if (elevator.floor > MIN_FLOOR) {
                    elevator.floor--;
                    printf("Reached floor %d.\n", elevator.floor);
                    elevator.direction = STOPPED;
                }
                break;
        }

        sleep(1); // Simulate elevator travel time
    }
}

void print_button_panel(void) {
    for (int i = 0; i < NUM_BUTTONS; i++) {
        printf("Button %c: ", i + 'A');
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));

    printf("Retro Elevator Simulation\n");
    print_button_panel();

    simulate_elevator();

    return EXIT_SUCCESS;
}