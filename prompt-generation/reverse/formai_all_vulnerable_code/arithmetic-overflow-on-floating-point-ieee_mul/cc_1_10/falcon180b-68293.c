//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} robot;

void move(robot *r, double v, double w) {
    double delta_x = v * cos(r->theta) * 0.01;
    double delta_y = v * sin(r->theta) * 0.01;
    double delta_theta = w * 0.01;
    r->x += delta_x;
    r->y += delta_y;
    r->theta += delta_theta;
}

void turn(robot *r, double a) {
    double delta_theta = a * 0.01;
    r->theta += delta_theta;
}

void read_input(robot *r) {
    printf("Enter the current position of the robot (x, y): ");
    scanf("%lf %lf", &r->x, &r->y);
    printf("Enter the current orientation of the robot (theta): ");
    scanf("%lf", &r->theta);
}

void print_output(robot *r) {
    printf("The current position of the robot is (%lf, %lf)\n", r->x, r->y);
    printf("The current orientation of the robot is %lf\n", r->theta);
}

int main() {
    robot r;
    read_input(&r);
    double v = 0.1, w = 0.1;
    int i = 0;
    while(i < 1000) {
        move(&r, v, w);
        print_output(&r);
        i++;
        if(i == 500) {
            turn(&r, 0.5);
        }
        if(i == 750) {
            v = 0.2;
            w = 0.2;
        }
    }
    return 0;
}