//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double theta;
} Vector;

Vector robot_position;

void initialize_robot() {
    srand(time(NULL));
    robot_position.x = rand() % 100;
    robot_position.y = rand() % 100;
    robot_position.theta = rand() % 360;
}

void move_robot(double distance, double angle) {
    double dx = distance * cos(robot_position.theta);
    double dy = distance * sin(robot_position.theta);
    robot_position.x += dx;
    robot_position.y += dy;
    robot_position.theta += angle;
}

void turn_robot(double angle) {
    robot_position.theta += angle;
}

void print_robot_position() {
    printf("Robot position: (%lf, %lf) with orientation %lf degrees\n", robot_position.x, robot_position.y, robot_position.theta);
}

int main() {
    initialize_robot();
    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move robot\n");
        printf("2. Turn robot\n");
        printf("3. Print robot position\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter distance to move (in units): ");
                double distance = rand() % 10;
                move_robot(distance, 0);
                break;
            case 2:
                printf("Enter angle to turn (in degrees): ");
                double angle = rand() % 360;
                turn_robot(angle);
                break;
            case 3:
                print_robot_position();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
    return 0;
}