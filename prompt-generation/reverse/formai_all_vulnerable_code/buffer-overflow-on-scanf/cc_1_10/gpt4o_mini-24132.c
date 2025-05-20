//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX_SPEED 10
#define MIN_SPEED 0
#define MOVE_DELAY 100000 // in microseconds

typedef struct {
    int x;
    int y;
    int speed;
    char direction; // 'N', 'E', 'S', 'W'
} Robot;

void initializeRobot(Robot *robot, int startX, int startY, int startSpeed) {
    robot->x = startX;
    robot->y = startY;
    robot->speed = startSpeed > MAX_SPEED ? MAX_SPEED : (startSpeed < MIN_SPEED ? MIN_SPEED : startSpeed);
    robot->direction = 'N'; // Initial direction North
}

void moveRobot(Robot *robot) {
    switch (robot->direction) {
        case 'N':
            robot->y += robot->speed;
            break;
        case 'S':
            robot->y -= robot->speed;
            break;
        case 'E':
            robot->x += robot->speed;
            break;
        case 'W':
            robot->x -= robot->speed;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
}

void changeDirection(Robot *robot, char newDirection) {
    if (newDirection == 'N' || newDirection == 'E' || newDirection == 'S' || newDirection == 'W') {
        robot->direction = newDirection;
    } else {
        printf("Invalid direction!\n");
    }
}

void changeSpeed(Robot *robot, int newSpeed) {
    if (newSpeed >= MIN_SPEED && newSpeed <= MAX_SPEED) {
        robot->speed = newSpeed;
    } else {
        printf("Speed must be between %d and %d.\n", MIN_SPEED, MAX_SPEED);
    }
}

void reportPosition(Robot *robot) {
    printf("Robot Position: (%d, %d), Direction: %c, Speed: %d\n", robot->x, robot->y, robot->direction, robot->speed);
}

void signalHandler(int sig) {
    if (sig == SIGINT) {
        printf("Stopping robot...\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, signalHandler); // Capture Ctrl+C to stop the robot

    Robot myRobot;
    initializeRobot(&myRobot, 0, 0, 5);

    char command;
    int speedChange;

    while (1) {
        reportPosition(&myRobot);
        printf("Enter command (m:Move, d:Direction, s:Speed, q:Quit): ");
        command = getchar();
        while (getchar() != '\n'); // Clear the buffer

        switch (command) {
            case 'm':
                moveRobot(&myRobot);
                usleep(MOVE_DELAY);
                break;
            case 'd':
                printf("Enter new direction (N/E/S/W): ");
                char direction;
                scanf(" %c", &direction);
                changeDirection(&myRobot, direction);
                while (getchar() != '\n'); // Clear the buffer
                break;
            case 's':
                printf("Enter new speed (0-%d): ", MAX_SPEED);
                scanf("%d", &speedChange);
                changeSpeed(&myRobot, speedChange);
                while (getchar() != '\n'); // Clear the buffer
                break;
            case 'q':
                printf("Quitting the program...\n");
                exit(0);
                break;
            default:
                printf("Unknown command!\n");
                break;
        }
    }

    return 0;
}