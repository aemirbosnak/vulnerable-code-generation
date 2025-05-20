//FormAI DATASET v1.0 Category: Robot movement control ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// define movement directions
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// define map size and initial starting point
#define MAP_SIZE 5
#define INITIAL_X 2
#define INITIAL_Y 2

// define robot object
struct Robot {
    int x;
    int y;
    char name[20];
};

// function to move robot
void move_robot(struct Robot* robot, int direction) {
    switch (direction) {
        case FORWARD:
            // check if robot is at the map boundaries
            if (robot->x < MAP_SIZE - 1) {
                robot->x++;
                printf("%s moved forward to (%d,%d)\n", robot->name, robot->x, robot->y);
            } else {
                printf("%s cannot move forward, reached map boundary.\n", robot->name);
            }
            break;
        case BACKWARD:
            // check if robot is at the map boundaries
            if (robot->x > 0) {
                robot->x--;
                printf("%s moved backward to (%d,%d)\n", robot->name, robot->x, robot->y);
            } else {
                printf("%s cannot move backward, reached map boundary.\n", robot->name);
            }
            break;
        case LEFT:
            // check if robot is at the map boundaries
            if (robot->y > 0) {
                robot->y--;
                printf("%s moved left to (%d,%d)\n", robot->name, robot->x, robot->y);
            } else {
                printf("%s cannot move left, reached map boundary.\n", robot->name);
            }
            break;
        case RIGHT:
            // check if robot is at the map boundaries
            if (robot->y < MAP_SIZE - 1) {
                robot->y++;
                printf("%s moved right to (%d,%d)\n", robot->name, robot->x, robot->y);
            } else {
                printf("%s cannot move right, reached map boundary.\n", robot->name);
            }
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }
}

int main() {
    // create robot object
    struct Robot r1;
    r1.x = INITIAL_X;
    r1.y = INITIAL_Y;
    strcpy(r1.name,"Robot 1");
    
    // initial prompt
    printf("Welcome to Robot Movement Control Program!\n");
    printf("Current Map: (%d x %d)\n", MAP_SIZE, MAP_SIZE);
    printf("%s starting at (%d,%d)\n\n", r1.name, r1.x, r1.y);
    
    // keep prompting user for movement until they exit
    int choice = 0;
    do {
        printf("Which direction should %s move?\n", r1.name);
        printf("1. Forward\n2. Backward\n3. Left\n4. Right\n0. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 0:
                printf("Exiting program.\n");
                break;
            case FORWARD:
                move_robot(&r1, FORWARD);
                break;
            case BACKWARD:
                move_robot(&r1, BACKWARD);
                break;
            case LEFT:
                move_robot(&r1, LEFT);
                break;
            case RIGHT:
                move_robot(&r1, RIGHT);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);  // keep prompting until user exits
    
    return 0;
}