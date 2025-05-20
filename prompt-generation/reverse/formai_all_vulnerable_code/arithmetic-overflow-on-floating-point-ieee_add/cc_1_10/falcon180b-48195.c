//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} robot_t;

void robot_move(robot_t* robot, double dx, double dy, double dtheta) {
    robot->x += dx * cos(robot->theta) - dy * sin(robot->theta);
    robot->y += dx * sin(robot->theta) + dy * cos(robot->theta);
    robot->theta += dtheta;
}

void robot_turn(robot_t* robot, double dtheta) {
    robot->theta += dtheta;
}

void robot_set_position(robot_t* robot, double x, double y, double theta) {
    robot->x = x;
    robot->y = y;
    robot->theta = theta;
}

void robot_print(robot_t* robot) {
    printf("Position: (%lf, %lf)\n", robot->x, robot->y);
    printf("Orientation: %lf\n", robot->theta);
}

int main(int argc, char** argv) {
    robot_t robot;
    int choice;
    double dx, dy, dtheta;

    do {
        printf("Enter 1 to move the robot\n");
        printf("Enter 2 to turn the robot\n");
        printf("Enter 3 to set the robot's position\n");
        printf("Enter 4 to print the robot's current position\n");
        printf("Enter 5 to exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the distance to move (in meters): ");
                scanf("%lf", &dx);
                printf("Enter the distance to move (in meters): ");
                scanf("%lf", &dy);
                printf("Enter the angle to turn (in radians): ");
                scanf("%lf", &dtheta);
                robot_move(&robot, dx, dy, dtheta);
                break;
            case 2:
                printf("Enter the angle to turn (in radians): ");
                scanf("%lf", &dtheta);
                robot_turn(&robot, dtheta);
                break;
            case 3:
                printf("Enter the x coordinate: ");
                scanf("%lf", &dx);
                printf("Enter the y coordinate: ");
                scanf("%lf", &dy);
                printf("Enter the orientation (in radians): ");
                scanf("%lf", &dtheta);
                robot_set_position(&robot, dx, dy, dtheta);
                break;
            case 4:
                robot_print(&robot);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 5);

    return 0;
}