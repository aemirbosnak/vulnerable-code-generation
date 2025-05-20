//FormAI DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 500
#define MIN_SPEED 0
#define MAX_POSITION 1000
#define MIN_POSITION 0

typedef struct {
    int position;
    int speed;
} Robot;

int main() {
    Robot robot = {500, 250};
    bool running = true;
    
    printf("Welcome to the robot control system!\n");
    printf("Current position: %d\n", robot.position);
    printf("Current speed: %d\n", robot.speed);

    while (running) {
        char command;
        scanf("%c", &command);
        
        switch(command) {
            case 'f':
                if (robot.speed < MAX_SPEED) {
                    robot.speed += 10;
                }
                break;
            case 's':
                robot.speed = 0;
                break;
            case 'b':
                if (robot.speed > MIN_SPEED) {
                    robot.speed -= 10;
                }
                break;
            case 'u':
                if (robot.position < MAX_POSITION) {
                    robot.position += robot.speed;
                }
                printf("Position updated: %d\n", robot.position);
                break;
            case 'd':
                if (robot.position > MIN_POSITION) {
                    robot.position -= robot.speed;
                }
                printf("Position updated: %d\n", robot.position);
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    printf("Exiting robot control system\n");
    return 0;
}