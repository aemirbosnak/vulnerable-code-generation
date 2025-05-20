//Code Llama-13B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define the vehicle structure
struct vehicle {
    int speed;
    int direction;
};

// Define the commands structure
struct commands {
    char command;
    void (*function)(struct vehicle *);
};

// Define the vehicle commands
void accelerate(struct vehicle *v) {
    v->speed += 5;
}

void brake(struct vehicle *v) {
    v->speed -= 5;
}

void left(struct vehicle *v) {
    v->direction -= 1;
}

void right(struct vehicle *v) {
    v->direction += 1;
}

// Define the command table
struct commands commands[] = {
    { 'a', accelerate },
    { 'b', brake },
    { 'l', left },
    { 'r', right }
};

// Define the vehicle
struct vehicle vehicle;

// Define the main function
int main() {
    // Initialize the vehicle
    vehicle.speed = 0;
    vehicle.direction = 0;

    // Define the command
    char command;

    // Loop until the user enters 'q'
    while (command != 'q') {
        // Get the user input
        scanf("%c", &command);

        // Find the corresponding function
        for (int i = 0; i < sizeof(commands) / sizeof(struct commands); i++) {
            if (commands[i].command == command) {
                // Execute the function
                commands[i].function(&vehicle);
                break;
            }
        }

        // Print the current speed and direction
        printf("Speed: %d, Direction: %d\n", vehicle.speed, vehicle.direction);
    }

    return 0;
}