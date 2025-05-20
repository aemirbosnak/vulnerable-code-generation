//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

// Constants for robot movement
#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4
#define STOP 0

// Structure to hold command data
typedef struct {
    int command;
    int duration; // duration to move in seconds
} RobotCommand;

// Robot state structure
typedef struct {
    int isMoving;
    int direction; // Current direction
} RobotState;

RobotState robotState = {0, STOP};

// Control the robot movement
void* controlRobot(void* arg) {
    RobotCommand* command = (RobotCommand*)arg;

    printf("Executing Command: %d for %d seconds\n", command->command, command->duration);

    robotState.isMoving = 1;
    robotState.direction = command->command;

    // Simulating movement
    sleep(command->duration);

    robotState.isMoving = 0;
    robotState.direction = STOP;
    printf("Stopped moving.\n");
    return NULL;
}

// Function to process user inputs and issue commands to the robot
void processInput() {
    char input[10];
    int duration;

    while (1) {
        printf("Enter a command (f: forward, b: backward, l: left, r: right, s: stop) and duration (in seconds): ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        if (input[0] == 's') {
            printf("Stopping the robot.\n");
            RobotCommand stopCommand = {STOP, 0};
            controlRobot(&stopCommand);
            continue;
        }

        printf("Enter duration: ");
        scanf("%d", &duration);
        getchar(); // clear newline after scanf
        
        RobotCommand command;

        switch (input[0]) {
            case 'f':
                command.command = MOVE_FORWARD;
                break;
            case 'b':
                command.command = MOVE_BACKWARD;
                break;
            case 'l':
                command.command = TURN_LEFT;
                break;
            case 'r':
                command.command = TURN_RIGHT;
                break;
            default:
                printf("Invalid command. Please try again.\n");
                continue;
        }

        command.duration = duration;

        pthread_t robotThread;
        if (pthread_create(&robotThread, NULL, controlRobot, (void*)&command) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
        pthread_detach(robotThread);
    }
}

// Signal handling to gracefully shut down the program
void signalHandler(int signo) {
    if (signo == SIGINT) {
        printf("Shutting down the robot control program...\n");
        exit(EXIT_SUCCESS);
    }
}

int main() {
    // Set up signal handling
    signal(SIGINT, signalHandler);
    
    printf("Welcome to the Robot Movement Control Interface!\n");
    printf("You can control the robot using the following commands:\n");
    printf("f - Move Forward\n");
    printf("b - Move Backward\n");
    printf("l - Turn Left\n");
    printf("r - Turn Right\n");
    printf("s - Stop\n");

    processInput();

    return 0;
}