//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <signal.h>

// Define constants for robot movements
#define MAX_SPEED 100
#define MIN_SPEED 0
#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

// Robot structure
typedef struct {
    int x;          // Current X position
    int y;          // Current Y position
    int speed;      // Speed of robot
    int direction;  // Current direction
} Robot;

// Function to initialize the robot
void initializeRobot(Robot *r) {
    r->x = 0;
    r->y = 0;
    r->speed = 50; // Set initial speed to 50
    r->direction = FORWARD; // Set initial direction to forward
}

// Function to set robot speed
void setSpeed(Robot *r, int speed) {
    if (speed > MAX_SPEED) {
        r->speed = MAX_SPEED;
    } else if (speed < MIN_SPEED) {
        r->speed = MIN_SPEED;
    } else {
        r->speed = speed;
    }
}

// Function to move the robot
void moveRobot(Robot *r) {
    switch (r->direction) {
        case FORWARD:
            r->y += r->speed;
            break;
        case BACKWARD:
            r->y -= r->speed;
            break;
        case LEFT:
            r->x -= r->speed;
            break;
        case RIGHT:
            r->x += r->speed;
            break;
        default:
            printf("Invalid direction\n");
    }
    printf("Robot moved to position (%d, %d) with speed %d\n", r->x, r->y, r->speed);
}

// Function to change direction
void changeDirection(Robot *r, int newDirection) {
    r->direction = newDirection;
    printf("Robot changed direction to %d\n", newDirection);
}

// Signal handler to gracefully shutdown the robot movement
void signalHandler(int signum) {
    printf("Shutting down robot movement...\n");
    exit(signum);
}

// Main function to control the robot
int main() {
    Robot robot;
    initializeRobot(&robot);

    // Catching SIGINT to allow graceful exit
    signal(SIGINT, signalHandler);

    // Movement control loop
    while (1) {
        char command;
        printf("Enter command (W: Forward, S: Backward, A: Left, D: Right, +: Increase Speed, -: Decrease Speed, Q: Quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'W':
            case 'w':
                changeDirection(&robot, FORWARD);
                moveRobot(&robot);
                break;
            case 'S':
            case 's':
                changeDirection(&robot, BACKWARD);
                moveRobot(&robot);
                break;
            case 'A':
            case 'a':
                changeDirection(&robot, LEFT);
                moveRobot(&robot);
                break;
            case 'D':
            case 'd':
                changeDirection(&robot, RIGHT);
                moveRobot(&robot);
                break;
            case '+':
                setSpeed(&robot, robot.speed + 10);
                printf("Speed increased: %d\n", robot.speed);
                break;
            case '-':
                setSpeed(&robot, robot.speed - 10);
                printf("Speed decreased: %d\n", robot.speed);
                break;
            case 'Q':
            case 'q':
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid command\n");
                break;
        }

        usleep(500000); // Sleep for 500 milliseconds to simulate movement delay
    }

    return 0;
}