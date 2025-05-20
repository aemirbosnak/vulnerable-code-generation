//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define PI 3.14159

// Function to calculate distance between two points
double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Function to calculate angle between two points
double angle(int x1, int y1, int x2, int y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    return atan2(dy, dx);
}

// Function to calculate new position of robot
void new_position(int *x, int *y, int dx, int dy, double angle)
{
    double radian = angle * PI / 180;
    int new_x = *x + (int)(dx * cos(radian) - dy * sin(radian));
    int new_y = *y + (int)(dx * sin(radian) + dy * cos(radian));
    *x = new_x;
    *y = new_y;
}

// Function to move robot
void move_robot(int *x, int *y, int dx, int dy, int speed)
{
    double distance_to_move = distance(*x, *y, *x + dx, *y + dy);
    int steps = ceil(distance_to_move / speed);
    for(int i = 0; i < steps; i++)
    {
        double step_distance = distance_to_move / steps;
        int step_x = *x + (int)(dx * step_distance);
        int step_y = *y + (int)(dy * step_distance);
        new_position(x, y, dx, dy, angle(*x, *y, step_x, step_y));
        printf("Robot moved to (%d, %d)\n", *x, *y);
        sleep(1);
    }
}

int main()
{
    int x = 0, y = 0;
    int dx = 10, dy = 5;
    int speed = 1;

    printf("Robot starting position: (%d, %d)\n", x, y);
    move_robot(&x, &y, dx, dy, speed);

    return 0;
}