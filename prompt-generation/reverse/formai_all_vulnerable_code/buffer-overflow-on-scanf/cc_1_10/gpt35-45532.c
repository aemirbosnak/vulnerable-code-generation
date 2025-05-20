//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: detailed
#include <stdio.h>

// Define the struct for the remote control vehicle
struct rc_vehicle {
    float speed;
    int direction;
};

// Function to move the vehicle forward
void move_forward(struct rc_vehicle *vehicle) {
    vehicle->speed = 1.0;
    vehicle->direction = 0;
    printf("The vehicle is now moving forward at %.2f mph\n", vehicle->speed);
}

// Function to move the vehicle backward
void move_backward(struct rc_vehicle *vehicle) {
    vehicle->speed = 0.5;
    vehicle->direction = 180;
    printf("The vehicle is now moving backward at %.2f mph\n", vehicle->speed);
}

// Function to turn the vehicle left
void turn_left(struct rc_vehicle *vehicle) {
    vehicle->direction -= 15;
    printf("The vehicle is now turning left. Direction: %d degrees\n", vehicle->direction);
}

// Function to turn the vehicle right
void turn_right(struct rc_vehicle *vehicle) {
    vehicle->direction += 15;
    printf("The vehicle is now turning right. Direction: %d degrees\n", vehicle->direction);
}

// Function to stop the vehicle
void stop(struct rc_vehicle *vehicle) {
    vehicle->speed = 0.0;
    printf("The vehicle has come to a stop\n");
}

int main() {
    struct rc_vehicle my_vehicle = {0.0, 0};
    char command;

    printf("Remote Control Vehicle Simulation Program\n");
    printf("Please enter a command (f-forward, b-backward, l-left, r-right, s-stop): ");

    // Loop to receive commands from user
    while (1) {
        scanf(" %c", &command);

        switch (command) {
            case 'f':
                move_forward(&my_vehicle);
                break;
            case 'b':
                move_backward(&my_vehicle);
                break;
            case 'l':
                turn_left(&my_vehicle);
                break;
            case 'r':
                turn_right(&my_vehicle);
                break;
            case 's':
                stop(&my_vehicle);
                break;
            default:
                printf("Invalid command\n");
        }

        printf("Please enter a command (f-forward, b-backward, l-left, r-right, s-stop): ");
    }

    return 0;
}