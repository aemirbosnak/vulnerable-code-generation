//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

// Define possible robot movements
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP
} Movement;

// Define the Robot struct
typedef struct {
    int x_position;
    int y_position;
    Movement current_movement;
} Robot;

// Function prototypes
void initialize_robot(Robot *robot);
void move_robot(Robot *robot, Movement direction);
void print_robot_status(Robot *robot);
void signal_handler(int signum);
void print_usage();

// Global variable to control the robot's operation
volatile bool running = true;

int main() {
    // Set up signal handler for graceful exit
    signal(SIGINT, signal_handler);

    Robot my_robot;
    initialize_robot(&my_robot);

    print_usage();
    
    while (running) {
        char command;
        printf("Enter command (W/A/S/D for movement, Q to quit): ");
        scanf(" %c", &command); // The space before %c allows whitespace skipping
        
        switch (command) {
            case 'W':
            case 'w':
                move_robot(&my_robot, FORWARD);
                break;
            case 'A':
            case 'a':
                move_robot(&my_robot, LEFT);
                break;
            case 'S':
            case 's':
                move_robot(&my_robot, BACKWARD);
                break;
            case 'D':
            case 'd':
                move_robot(&my_robot, RIGHT);
                break;
            case 'Q':
            case 'q':
                running = false;
                break;
            default:
                printf("Invalid command! Please try again.\n");
                break;
        }
        print_robot_status(&my_robot);
    }

    printf("\nExiting program. Final robot position: (%d, %d)\n", 
           my_robot.x_position, my_robot.y_position);
    return 0;
}

// Initialize robot's starting position and state
void initialize_robot(Robot *robot) {
    robot->x_position = 0;
    robot->y_position = 0;
    robot->current_movement = STOP;
}

// Move the robot in the specified direction
void move_robot(Robot *robot, Movement direction) {
    robot->current_movement = direction;
    switch (direction) {
        case FORWARD:
            robot->y_position += 1;
            break;
        case BACKWARD:
            robot->y_position -= 1;
            break;
        case LEFT:
            robot->x_position -= 1;
            break;
        case RIGHT:
            robot->x_position += 1;
            break;
        case STOP:
            // Do nothing, the robot is stopped
            break;
    }
}

// Print the robot's current status
void print_robot_status(Robot *robot) {
    printf("Robot is currently at (%d, %d) facing ", 
           robot->x_position, robot->y_position);
    switch (robot->current_movement) {
        case FORWARD:
            printf("FORWARD\n");
            break;
        case BACKWARD:
            printf("BACKWARD\n");
            break;
        case LEFT:
            printf("LEFT\n");
            break;
        case RIGHT:
            printf("RIGHT\n");
            break;
        case STOP:
            printf("STOP\n");
            break;
    }
}

// Signal handler for graceful exit
void signal_handler(int signum) {
    running = false;
}

// Print usage instructions
void print_usage() {
    printf("----- Robot Control -----\n");
    printf("Commands:\n");
    printf("W - Move Forward\n");
    printf("A - Turn Left\n");
    printf("S - Move Backward\n");
    printf("D - Turn Right\n");
    printf("Q - Quit\n");
    printf("-------------------------\n");
}