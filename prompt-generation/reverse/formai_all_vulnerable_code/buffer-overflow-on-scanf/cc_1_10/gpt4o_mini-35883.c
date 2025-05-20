//GPT-4o-mini DATASET v1.0 Category: Robot movement control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_X 10
#define MAX_Y 10

typedef struct {
    int x;
    int y;
    int speed;
} Robot;

void initializeRobot(Robot* robot) {
    robot->x = 0;
    robot->y = 0;
    robot->speed = 0;
}

void setSpeed(Robot* robot, int speed) {
    if(speed > MAX_SPEED) {
        robot->speed = MAX_SPEED;
    } else if(speed < MIN_SPEED) {
        robot->speed = MIN_SPEED;
    } else {
        robot->speed = speed;
    }
}

void printRobotStatus(Robot* robot) {
    printf("Robot Position: (%d, %d), Speed: %d\n", robot->x, robot->y, robot->speed);
}

void moveRobot(Robot* robot, int dx, int dy) {
    robot->x += dx;
    robot->y += dy;

    // Boundary checking
    if (robot->x < 0) robot->x = 0;
    if (robot->y < 0) robot->y = 0;
    if (robot->x > MAX_X) robot->x = MAX_X;
    if (robot->y > MAX_Y) robot->y = MAX_Y;
}

void displayMenu() {
    printf("Robot Movement Control Menu:\n");
    printf("1. Move Robot\n");
    printf("2. Set Speed\n");
    printf("3. Print Status\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

int main() {
    Robot robot;
    initializeRobot(&robot);
    
    int choice;
    int dx, dy, speed;

    while(1) {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter movement (dx dy): ");
                scanf("%d %d", &dx, &dy);
                moveRobot(&robot, dx, dy);
                break;

            case 2:
                printf("Enter speed (0 to 100): ");
                scanf("%d", &speed);
                setSpeed(&robot, speed);
                break;

            case 3:
                printRobotStatus(&robot);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid option, please try again.\n");
        }

        // Simulating robot speed effect with sleep
        usleep(1000000 - (robot.speed * 10000)); // Speed affects the delay
    }

    return 0;
}