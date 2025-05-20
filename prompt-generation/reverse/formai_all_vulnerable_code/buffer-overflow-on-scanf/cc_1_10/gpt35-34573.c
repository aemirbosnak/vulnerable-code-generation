//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
// C Remote control Vehicle Simulation example program

#include <stdio.h>
#include <stdlib.h>

// define constants
#define NUM_GEARS 5
#define MAX_ACCELERATION 10
#define MAX_SPEED 100
#define MIN_SPEED 0

// define enums for vehicle state and gear
enum VehicleState {
    STOPPED,
    ACCELERATING,
    CRUISING,
    BRAKING
};

enum Gear {
    NEUTRAL = 0,
    FIRST,
    SECOND,
    THIRD,
    FOURTH,
    FIFTH
};

// function to prompt user for input
int get_input() {
    int result = 0;
    printf("Enter a value: ");
    scanf("%d", &result);
    return result;
}

// function to handle accelerating
int accelerate(int current_speed, enum Gear current_gear) {
    int acceleration = get_input();
    if (acceleration < 0 || acceleration > MAX_ACCELERATION) {
        printf("Invalid input. Must be between 0 and %d\n", MAX_ACCELERATION);
        return current_speed;
    }
    int new_speed = current_speed + acceleration;
    if (new_speed > MAX_SPEED) {
        new_speed = MAX_SPEED;
    }
    return new_speed;
}

// function to handle braking
int brake(int current_speed, enum Gear current_gear) {
    int deceleration = get_input();
    if (deceleration < 0 || deceleration > MAX_ACCELERATION) {
        printf("Invalid input. Must be between 0 and %d\n", MAX_ACCELERATION);
        return current_speed;
    }
    int new_speed = current_speed - deceleration;
    if (new_speed < MIN_SPEED) {
        new_speed = MIN_SPEED;
    }
    return new_speed;
}

int main() {
    enum Gear current_gear = NEUTRAL;
    int current_speed = 0;
    enum VehicleState current_state = STOPPED;

    // main loop for user interactions
    while(1) {
        printf("\nVehicle State: ");
        switch(current_state) {
            case STOPPED:
                printf("Stopped\n");
                break;
            case ACCELERATING:
                printf("Accelerating\n");
                break;
            case CRUISING:
                printf("Cruising\n");
                break;
            case BRAKING:
                printf("Braking\n");
                break;
        }

        printf("Current Gear: %d\n", current_gear);
        printf("Current Speed: %d\n", current_speed);

        printf("Enter a command: ");
        char command;
        scanf(" %c", &command);
        switch(command) {
            case 'a':
                if (current_state == CRUISING || current_state == ACCELERATING) {
                    printf("Already accelerating\n");
                } else {
                    current_state = ACCELERATING;
                }
                break;
            case 'b':
                if (current_state == CRUISING || current_state == BRAKING) {
                    printf("Already braking\n");
                } else {
                    current_state = BRAKING;
                }
                break;
            case 'c':
                if (current_gear >= FIFTH) {
                    printf("Already in top gear\n");
                } else {
                    current_gear = (enum Gear)(current_gear + 1);
                }
                break;
            case 'd':
                if (current_gear <= NEUTRAL) {
                    printf("Already in lowest gear\n");
                } else {
                    current_gear = (enum Gear)(current_gear - 1);
                }
                break;
            case 'e':
                if (current_state == STOPPED) {
                    printf("Cannot cruise while stopped\n");
                } else {
                    current_state = CRUISING;
                }
                break;
            case 'q':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid command. Try again.\n");
                continue;
        }

        switch(current_state) {
            case ACCELERATING:
                current_speed = accelerate(current_speed, current_gear);
                break;
            case BRAKING:
                current_speed = brake(current_speed, current_gear);
                break;
            case CRUISING:
                break;
            case STOPPED:
                current_speed = 0;
                break;
        }
    }
}