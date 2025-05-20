//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta;
} Vector;

void move(Vector* v, double speed, double turn) {
    double turn_rad = turn * PI / 180.0;
    v->x += speed * cos(v->theta) - speed * sin(v->theta + turn_rad);
    v->y += speed * sin(v->theta) + speed * cos(v->theta + turn_rad);
    v->theta += turn_rad;
}

void turn(Vector* v, double turn) {
    double turn_rad = turn * PI / 180.0;
    v->theta += turn_rad;
}

int main() {
    srand(time(NULL));
    int width, height;
    printf("Enter the size of the arena (width and height): ");
    scanf("%d %d", &width, &height);
    Vector car = {0, 0, 0};
    Vector target = {rand() % width, rand() % height};
    while (1) {
        system("clear");
        printf("Arena:\n");
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == target.y && j == target.x)
                    printf("T");
                else
                    printf(" ");
            }
            printf("\n");
        }
        printf("Car: (%d, %d, %d)\n", car.x, car.y, car.theta);
        printf("Target: (%d, %d)\n", target.x, target.y);
        char command;
        printf("Enter command (f, b, l, r, t): ");
        scanf(" %c", &command);
        switch (command) {
        case 'f':
            move(&car, 5.0, 0.0);
            break;
        case 'b':
            move(&car, -5.0, 0.0);
            break;
        case 'l':
            turn(&car, -10.0);
            break;
        case 'r':
            turn(&car, 10.0);
            break;
        case 't':
            printf("Turn complete.\n");
            break;
        default:
            printf("Invalid command.\n");
        }
        if (car.x == target.x && car.y == target.y) {
            printf("Mission accomplished.\n");
            break;
        }
    }
    return 0;
}