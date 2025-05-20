//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the car's possible directions
enum direction { NORTH, EAST, SOUTH, WEST };

// Define the car's possible commands
enum command { FORWARD, LEFT, RIGHT, QUIT };

// Define the car's position
struct position {
    int x;
    int y;
    enum direction direction;
};

// Define the car's state
struct state {
    struct position position;
    enum command command;
};

// Print the car's position
void print_position(struct position position) {
    printf("The car is at position (%d, %d) and is facing %s.\n", position.x, position.y, position.direction == NORTH ? "North" : position.direction == EAST ? "East" : position.direction == SOUTH ? "South" : "West");
}

// Update the car's position based on the given command
struct position update_position(struct position position, enum command command) {
    switch (command) {
        case FORWARD:
            switch (position.direction) {
                case NORTH:
                    position.y++;
                    break;
                case EAST:
                    position.x++;
                    break;
                case SOUTH:
                    position.y--;
                    break;
                case WEST:
                    position.x--;
                    break;
            }
            break;
        case LEFT:
            position.direction = (position.direction + 3) % 4;
            break;
        case RIGHT:
            position.direction = (position.direction + 1) % 4;
            break;
        default:
            break;
    }
    return position;
}

// Get the next command from the user
enum command get_command() {
    char command;
    printf("Enter a command (f/l/r/q): ");
    scanf(" %c", &command);
    switch (command) {
        case 'f':
            return FORWARD;
        case 'l':
            return LEFT;
        case 'r':
            return RIGHT;
        case 'q':
            return QUIT;
        default:
            printf("Invalid command. Please enter one of f/l/r/q.\n");
            return get_command();
    }
}

// Run the car simulation
void run_simulation(struct state state) {
    // Print the initial position of the car
    print_position(state.position);

    // Get the next command from the user
    state.command = get_command();

    // Update the car's position based on the given command
    state.position = update_position(state.position, state.command);

    // If the user entered the quit command, exit the simulation
    if (state.command == QUIT) {
        printf("Exiting simulation.\n");
        return;
    }

    // Otherwise, run the simulation again
    run_simulation(state);
}

// Main function
int main() {
    // Initialize the car's state
    struct state state = {
        .position = {
            .x = 0,
            .y = 0,
            .direction = NORTH,
        },
        .command = FORWARD,
    };

    // Run the car simulation
    run_simulation(state);

    return 0;
}