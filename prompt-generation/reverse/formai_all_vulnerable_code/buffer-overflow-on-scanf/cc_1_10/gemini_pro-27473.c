//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: innovative
// *** Include Section ***
//------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// *** Preprocessor Section ***
//------------------------------------------------
#define DRONE_MAX_SPEED 100
#define DRONE_MIN_SPEED 0
#define DRONE_MAX_ALTITUDE 1000
#define DRONE_MIN_ALTITUDE 0
#define DRONE_MAX_TILT_ANGLE 45
#define DRONE_MIN_TILT_ANGLE -45

// *** Type Section ***
//------------------------------------------------
typedef struct {
    int speed;
    int altitude;
    int tilt_angle;
} drone_state_t;

// *** Function Section ***
//------------------------------------------------
void print_drone_state(drone_state_t *drone_state) {
    printf("Speed: %d\n", drone_state->speed);
    printf("Altitude: %d\n", drone_state->altitude);
    printf("Tilt Angle: %d\n", drone_state->tilt_angle);
}

void set_drone_speed(drone_state_t *drone_state, int speed) {
    if (speed >= DRONE_MIN_SPEED && speed <= DRONE_MAX_SPEED) {
        drone_state->speed = speed;
    }
}

void set_drone_altitude(drone_state_t *drone_state, int altitude) {
    if (altitude >= DRONE_MIN_ALTITUDE && altitude <= DRONE_MAX_ALTITUDE) {
        drone_state->altitude = altitude;
    }
}

void set_drone_tilt_angle(drone_state_t *drone_state, int tilt_angle) {
    if (tilt_angle >= DRONE_MIN_TILT_ANGLE && tilt_angle <= DRONE_MAX_TILT_ANGLE) {
        drone_state->tilt_angle = tilt_angle;
    }
}

int main(void) {
    // Create a drone state variable
    drone_state_t drone_state;

    // Set the initial drone state
    drone_state.speed = 0;
    drone_state.altitude = 0;
    drone_state.tilt_angle = 0;

    // Print the initial drone state
    print_drone_state(&drone_state);

    // Get input from the user
    int input;
    printf("Enter a command (1 = increase speed, 2 = decrease speed, 3 = increase altitude, 4 = decrease altitude, 5 = increase tilt angle, 6 = decrease tilt angle, 7 = print drone state, 8 = quit): ");
    scanf("%d", &input);

    // Process the input
    while (input != 8) {
        switch (input) {
            case 1:
                set_drone_speed(&drone_state, drone_state.speed + 10);
                break;
            case 2:
                set_drone_speed(&drone_state, drone_state.speed - 10);
                break;
            case 3:
                set_drone_altitude(&drone_state, drone_state.altitude + 10);
                break;
            case 4:
                set_drone_altitude(&drone_state, drone_state.altitude - 10);
                break;
            case 5:
                set_drone_tilt_angle(&drone_state, drone_state.tilt_angle + 10);
                break;
            case 6:
                set_drone_tilt_angle(&drone_state, drone_state.tilt_angle - 10);
                break;
            case 7:
                print_drone_state(&drone_state);
                break;
            default:
                printf("Invalid input\n");
        }

        // Get input from the user
        printf("Enter a command (1 = increase speed, 2 = decrease speed, 3 = increase altitude, 4 = decrease altitude, 5 = increase tilt angle, 6 = decrease tilt angle, 7 = print drone state, 8 = quit): ");
        scanf("%d", &input);
    }

    // Quit the program
    return 0;
}