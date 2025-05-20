//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define VELOCITY 0.1
#define RADIUS 5
#define X_AXIS 0
#define Y_AXIS 1

typedef struct {
    double x;
    double y;
} Vector;

void move(Vector* v, int direction) {
    switch(direction) {
        case 0: // Forward
            v->x += cos(v->y) * VELOCITY;
            v->y += sin(v->y) * VELOCITY;
            break;
        case 1: // Backward
            v->x -= cos(v->y) * VELOCITY;
            v->y -= sin(v->y) * VELOCITY;
            break;
        case 2: // Left
            v->y -= sin(v->x) * VELOCITY;
            v->x += cos(v->x) * VELOCITY;
            break;
        case 3: // Right
            v->y += sin(v->x) * VELOCITY;
            v->x -= cos(v->x) * VELOCITY;
            break;
    }
}

int main() {
    srand(time(NULL));

    Vector robot;
    robot.x = 0;
    robot.y = 0;

    int choice;
    printf("Enter your choice:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            move(&robot, 0);
            break;
        case 2:
            move(&robot, 1);
            break;
        case 3:
            move(&robot, 2);
            break;
        case 4:
            move(&robot, 3);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    double distance = sqrt(pow(robot.x - 0, 2) + pow(robot.y - 0, 2));
    printf("The robot has moved %.2f units away from the origin.\n", distance);

    return 0;
}