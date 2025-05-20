//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define robot states
typedef enum {
    IDLE,
    MOVING_FORWARD,
    BACKWARD,
    TURNING_LEFT,
    TURNING_RIGHT,
    STOPPED
} RobotState;

// Define the Robot structure
typedef struct {
    RobotState state;
    int speed; // Speed of the robot from 0 to 100
} Robot;

// Function prototypes
void displayStatus(Robot *robot);
void moveForward(Robot *robot);
void moveBackward(Robot *robot);
void turnLeft(Robot *robot);
void turnRight(Robot *robot);
void stop(Robot *robot);
void initializeRobot(Robot *robot);

int main() {
    Robot myRobot;
    initializeRobot(&myRobot);

    displayStatus(&myRobot);

    // Energy boost object
    char option;
    while (1) {
        printf("\nChoose an action for your robot!\n");
        printf("f: Move Forward\n");
        printf("b: Move Backward\n");
        printf("l: Turn Left\n");
        printf("r: Turn Right\n");
        printf("s: Stop\n");
        printf("q: Quit\n");
        printf("Your choice: ");
        scanf(" %c", &option);

        switch (option) {
            case 'f':
                moveForward(&myRobot);
                break;
            case 'b':
                moveBackward(&myRobot);
                break;
            case 'l':
                turnLeft(&myRobot);
                break;
            case 'r':
                turnRight(&myRobot);
                break;
            case 's':
                stop(&myRobot);
                break;
            case 'q':
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option! Please choose again.\n");
        }
        
        displayStatus(&myRobot);
    }

    return 0;
}

void initializeRobot(Robot *robot) {
    robot->state = IDLE;
    robot->speed = 0;
    printf("Robot initialized and ready for action!\n");
}

void displayStatus(Robot *robot) {
    printf("\n--- Current Robot Status ---\n");
    switch (robot->state) {
        case IDLE:
            printf("Robot is currently idle.\n");
            break;
        case MOVING_FORWARD:
            printf("Robot is moving forward with speed %d.\n", robot->speed);
            break;
        case BACKWARD:
            printf("Robot is moving backward with speed %d.\n", robot->speed);
            break;
        case TURNING_LEFT:
            printf("Robot is turning left with speed %d.\n", robot->speed);
            break;
        case TURNING_RIGHT:
            printf("Robot is turning right with speed %d.\n", robot->speed);
            break;
        case STOPPED:
            printf("Robot has stopped.\n");
            break;
    }
}

void moveForward(Robot *robot) {
    robot->speed = 50; // Setting a default speed
    robot->state = MOVING_FORWARD;
    printf("The robot zooms forward like a lightning bolt!\n");
    usleep(1000000); // Simulating movement for a moment
    robot->speed = 0; // Resetting speed
}

void moveBackward(Robot *robot) {
    robot->speed = 50; // Setting a default speed
    robot->state = BACKWARD;
    printf("The robot reverses with the finesse of a dancer! Watch out! \n");
    usleep(1000000); // Simulating movement for a moment
    robot->speed = 0; // Resetting speed
}

void turnLeft(Robot *robot) {
    robot->speed = 30; // Setting a default speed for turning
    robot->state = TURNING_LEFT;
    printf("The robot is elegantly turning left like a graceful swan!\n");
    usleep(500000); // Simulating turning for a moment
    robot->speed = 0; // Resetting speed
}

void turnRight(Robot *robot) {
    robot->speed = 30; // Setting a default speed for turning
    robot->state = TURNING_RIGHT;
    printf("The robot whirls right with the energy of a whirlwind!\n");
    usleep(500000); // Simulating turning for a moment
    robot->speed = 0; // Resetting speed
}

void stop(Robot *robot) {
    robot->state = STOPPED;
    robot->speed = 0;
    printf("The robot has come to a complete stop. Time for a breather!\n");
}