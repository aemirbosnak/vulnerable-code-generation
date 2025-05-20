//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>

// drone state constants
#define STATE_OFF 0
#define STATE_ON 1
#define STATE_FLIGHT 2

// remote control button constants
#define BUTTON_POWER 1
#define BUTTON_FLIGHT 2
#define BUTTON_ROTATE_LEFT 3
#define BUTTON_ROTATE_RIGHT 4
#define BUTTON_FORWARD 5
#define BUTTON_BACKWARD 6
#define BUTTON_UP 7
#define BUTTON_DOWN 8

// initial state of drone
int drone_state = STATE_OFF;

// function to handle turning on the drone
void turn_on_drone() {
    if (drone_state != STATE_OFF) {
        printf("Drone is already on!\n");
        return;
    }
    drone_state = STATE_ON;
    printf("Drone powered on.\n");
}

// function to handle turning off the drone
void turn_off_drone() {
    if (drone_state == STATE_FLIGHT) {
        printf("Cannot turn off drone during flight!\n");
        return;
    }
    drone_state = STATE_OFF;
    printf("Drone powered off.\n");
}

// function to handle starting a flight
void start_flight() {
    if (drone_state != STATE_ON) {
        printf("Drone must be powered on first!\n");
        return;
    }
    drone_state = STATE_FLIGHT;
    printf("Flight started.\n");
}

// function to handle landing the drone
void land_drone() {
    if (drone_state != STATE_FLIGHT) {
        printf("Drone is not in flight!\n");
        return;
    }
    drone_state = STATE_ON;
    printf("Drone landed.\n");
}

// function to handle rotating the drone left
void rotate_left() {
    if (drone_state != STATE_FLIGHT) {
        printf("Drone is not in flight!\n");
        return;
    }
    printf("Drone is rotating left.\n");
}

// function to handle rotating the drone right
void rotate_right() {
    if (drone_state != STATE_FLIGHT) {
        printf("Drone is not in flight!\n");
        return;
    }
    printf("Drone is rotating right.\n");
}

// function to handle moving the drone forward
void move_forward() {
    if (drone_state != STATE_FLIGHT) {
        printf("Drone is not in flight!\n");
        return;
    }
    printf("Drone is moving forward.\n");
}

// function to handle moving the drone backward
void move_backward() {
    if (drone_state != STATE_FLIGHT) {
        printf("Drone is not in flight!\n");
        return;
    }
    printf("Drone is moving backward.\n");
}

// function to handle moving the drone up
void move_up() {
    if (drone_state != STATE_FLIGHT) {
        printf("Drone is not in flight!\n");
        return;
    }
    printf("Drone is moving up.\n");
}

// function to handle moving the drone down
void move_down() {
    if (drone_state != STATE_FLIGHT) {
        printf("Drone is not in flight!\n");
        return;
    }
    printf("Drone is moving down.\n");
}

// function to handle user input
void handle_input(int button) {
    switch (button) {
        case BUTTON_POWER:
            turn_on_drone();
            break;
        case BUTTON_FLIGHT:
            start_flight();
            break;
        case BUTTON_ROTATE_LEFT:
            rotate_left();
            break;
        case BUTTON_ROTATE_RIGHT:
            rotate_right();
            break;
        case BUTTON_FORWARD:
            move_forward();
            break;
        case BUTTON_BACKWARD:
            move_backward();
            break;
        case BUTTON_UP:
            move_up();
            break;
        case BUTTON_DOWN:
            move_down();
            break;
        default:
            printf("Invalid button press.\n");
    }
}

int main() {
    int button;
    char input;
    printf("--- Drone remote control ---\n");
    while (1) {
        // get user input
        printf("Press a button (p=power, f=flight, l=left, r=right, w=forward, b=backward, u=up, d=down): ");
        scanf("%c", &input);
        switch (input) {
            case 'p':
                button = BUTTON_POWER;
                break;
            case 'f':
                button = BUTTON_FLIGHT;
                break;
            case 'l':
                button = BUTTON_ROTATE_LEFT;
                break;
            case 'r':
                button = BUTTON_ROTATE_RIGHT;
                break;
            case 'w':
                button = BUTTON_FORWARD;
                break;
            case 'b':
                button = BUTTON_BACKWARD;
                break;
            case 'u':
                button = BUTTON_UP;
                break;
            case 'd':
                button = BUTTON_DOWN;
                break;
            default:
                printf("Invalid input.\n");
                continue;
        }
        // handle user input
        handle_input(button);
        // clear input buffer
        while ((input = getchar()) != '\n' && input != EOF);
    }
    return 0;
}