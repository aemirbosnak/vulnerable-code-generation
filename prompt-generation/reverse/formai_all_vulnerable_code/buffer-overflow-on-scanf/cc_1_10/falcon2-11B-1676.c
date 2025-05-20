//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265359

typedef struct {
    int x;
    int y;
    int angle;
} Point;

typedef struct {
    Point shape[4];
} Shape;

typedef struct {
    Shape robot;
} Robot;

int main() {
    Robot robot;
    robot.robot.shape[0].x = 0;
    robot.robot.shape[0].y = 0;
    robot.robot.shape[0].angle = 0;
    robot.robot.shape[1].x = 0;
    robot.robot.shape[1].y = 0;
    robot.robot.shape[1].angle = 0;
    robot.robot.shape[2].x = 0;
    robot.robot.shape[2].y = 0;
    robot.robot.shape[2].angle = 0;
    robot.robot.shape[3].x = 0;
    robot.robot.shape[3].y = 0;
    robot.robot.shape[3].angle = 0;

    while (1) {
        printf("Enter the robot's position (x,y,angle):\n");
        int x, y, angle;
        scanf("%d %d %d", &x, &y, &angle);

        robot.robot.shape[0].x = x;
        robot.robot.shape[0].y = y;
        robot.robot.shape[0].angle = angle;
        robot.robot.shape[1].x = x;
        robot.robot.shape[1].y = y;
        robot.robot.shape[1].angle = angle + PI / 4;
        robot.robot.shape[2].x = x;
        robot.robot.shape[2].y = y;
        robot.robot.shape[2].angle = angle + PI / 2;
        robot.robot.shape[3].x = x;
        robot.robot.shape[3].y = y;
        robot.robot.shape[3].angle = angle + 3 * PI / 4;

        printf("Robot's position: (%d,%d,%d)\n", robot.robot.shape[0].x, robot.robot.shape[0].y, robot.robot.shape[0].angle);
        printf("Robot's position: (%d,%d,%d)\n", robot.robot.shape[1].x, robot.robot.shape[1].y, robot.robot.shape[1].angle);
        printf("Robot's position: (%d,%d,%d)\n", robot.robot.shape[2].x, robot.robot.shape[2].y, robot.robot.shape[2].angle);
        printf("Robot's position: (%d,%d,%d)\n", robot.robot.shape[3].x, robot.robot.shape[3].y, robot.robot.shape[3].angle);
    }

    return 0;
}