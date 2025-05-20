//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define ACCELERATION 1
#define DECELERATION 1

// Struct to hold the current state of the vehicle
typedef struct {
    int speed;
    int direction;
    int position;
} VehicleState;

// Function to initialize the state of the vehicle
void init_state(VehicleState *state) {
    state->speed = 0;
    state->direction = 1;
    state->position = 0;
}

// Function to update the state of the vehicle based on user input
void update_state(VehicleState *state, int input) {
    switch(input) {
        case 1: // Accelerate
            if(state->speed < MAX_SPEED) {
                state->speed += ACCELERATION;
            }
            break;
        case 2: // Decelerate
            if(state->speed > MIN_SPEED) {
                state->speed -= DECELERATION;
            }
            break;
        case 3: // Turn left
            state->direction = -1;
            break;
        case 4: // Turn right
            state->direction = 1;
            break;
        default:
            break;
    }
}

// Function to move the vehicle based on its current state
void move_vehicle(VehicleState *state) {
    int distance = state->speed * state->direction;
    state->position += distance;
    if(state->position < 0) {
        state->position = 0;
    }
}

// Function to display the current state of the vehicle
void display_state(VehicleState *state) {
    printf("Speed: %d\n", state->speed);
    printf("Direction: %d\n", state->direction);
    printf("Position: %d\n", state->position);
}

// Main function to simulate the remote control vehicle
int main() {
    srand(time(NULL));
    VehicleState state;
    init_state(&state);

    int choice;
    while(1) {
        printf("Enter your choice:\n");
        printf("1. Accelerate\n");
        printf("2. Decelerate\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Display state\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Accelerate
                update_state(&state, 1);
                break;
            case 2: // Decelerate
                update_state(&state, 2);
                break;
            case 3: // Turn left
                update_state(&state, 3);
                break;
            case 4: // Turn right
                update_state(&state, 4);
                break;
            case 5: // Display state
                display_state(&state);
                break;
            case 6: // Exit
                exit(0);
            default:
                printf("Invalid choice!\n");
        }

        move_vehicle(&state);
        printf("\n");
    }

    return 0;
}