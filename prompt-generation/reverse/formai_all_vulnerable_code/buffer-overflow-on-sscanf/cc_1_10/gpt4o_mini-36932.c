//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

typedef struct {
    int x;
    int y;
} Robot;

void initializeRobot(Robot *robot) {
    robot->x = 0;
    robot->y = 0;
}

void moveForward(Robot *robot, int distance) {
    robot->y += distance;
    printf("Robot moved forward by %d units. Current position: (%d, %d)\n", distance, robot->x, robot->y);
}

void moveBackward(Robot *robot, int distance) {
    robot->y -= distance;
    printf("Robot moved backward by %d units. Current position: (%d, %d)\n", distance, robot->x, robot->y);
}

void moveLeft(Robot *robot, int distance) {
    robot->x -= distance;
    printf("Robot moved left by %d units. Current position: (%d, %d)\n", distance, robot->x, robot->y);
}

void moveRight(Robot *robot, int distance) {
    robot->x += distance;
    printf("Robot moved right by %d units. Current position: (%d, %d)\n", distance, robot->x, robot->y);
}

void simulateError() {
    printf("!!! ERROR: SYSTEM MALFUNCTION DETECTED !!!\n");
    usleep(500000); // Simulating delay
    printf("Robot is attempting to reboot...\n");
    usleep(2000000); // Simulating reboot time
    printf("Reboot successful! Please resume commands.\n");
}

void processCommand(char *command, Robot *robot) {
    char action[10];
    int distance;

    int result = sscanf(command, "%s %d", action, &distance);

    if (result == 2) {
        if (distance < 0) {
            printf("Distance cannot be negative! Please enter a positive value.\n");
            return;
        }
    } else if (result == 1) {
        if (strcmp(action, "error") == 0) {
            simulateError();
            return;
        } else {
            printf("Invalid command format! Use '<action> <distance>'.\n");
            return;
        }
    } else {
        printf("Please provide a command and distance! (e.g., move forward 5)\n");
        return;
    }

    if (strcmp(action, "move") == 0) {
        printf("Please specify 'forward', 'backward', 'left', or 'right'.\n");
    } else if (strcmp(action, "forward") == 0) {
        moveForward(robot, distance);
    } else if (strcmp(action, "backward") == 0) {
        moveBackward(robot, distance);
    } else if (strcmp(action, "left") == 0) {
        moveLeft(robot, distance);
    } else if (strcmp(action, "right") == 0) {
        moveRight(robot, distance);
    } else {
        printf("Unknown action: %s! Please use one of the following: forward, backward, left, right.\n", action);
    }
}

int main() {
    Robot robot;
    initializeRobot(&robot);

    char command[MAX_COMMAND_LENGTH];

    printf("Robot movement control system initiated...\n");
    printf("Commands: 'move <direction> <distance>', 'error' to simulate malfunction. Type 'exit' to quit.\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        
        if (strncmp(command, "exit", 4) == 0) {
            printf("Exiting the robot control system. Goodbye!\n");
            break;
        }

        command[strcspn(command, "\n")] = 0; // Remove newline character
        processCommand(command, &robot);
    }

    return 0;
}