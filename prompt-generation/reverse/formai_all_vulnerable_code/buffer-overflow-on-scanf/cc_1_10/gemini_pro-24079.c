//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the car's attributes
typedef struct {
    int speed;
    int direction;
    int x;
    int y;
} car;

// Define the remote control commands
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP
} command;

// Initialize the car
car init_car() {
    car c;
    c.speed = 0;
    c.direction = 0;
    c.x = 0;
    c.y = 0;
    return c;
}

// Print the car's status
void print_car(car c) {
    printf("Speed: %d\n", c.speed);
    printf("Direction: %d\n", c.direction);
    printf("X: %d\n", c.x);
    printf("Y: %d\n", c.y);
}

// Execute a remote control command
void execute_command(car *c, command cmd) {
    switch (cmd) {
        case FORWARD:
            c->speed++;
            break;
        case BACKWARD:
            c->speed--;
            break;
        case LEFT:
            c->direction--;
            break;
        case RIGHT:
            c->direction++;
            break;
        case STOP:
            c->speed = 0;
            break;
    }
}

// Update the car's position
void update_car(car *c) {
    c->x += c->speed * cos(c->direction);
    c->y += c->speed * sin(c->direction);
}

// Main function
int main() {
    // Initialize the car
    car c = init_car();

    // Get the user's commands
    while (1) {
        char cmd;
        printf("Enter a command (f/b/l/r/s): ");
        scanf(" %c", &cmd);

        // Execute the command
        switch (cmd) {
            case 'f':
                execute_command(&c, FORWARD);
                break;
            case 'b':
                execute_command(&c, BACKWARD);
                break;
            case 'l':
                execute_command(&c, LEFT);
                break;
            case 'r':
                execute_command(&c, RIGHT);
                break;
            case 's':
                execute_command(&c, STOP);
                break;
            default:
                printf("Invalid command\n");
                break;
        }

        // Update the car's position
        update_car(&c);

        // Print the car's status
        print_car(c);
    }

    return 0;
}