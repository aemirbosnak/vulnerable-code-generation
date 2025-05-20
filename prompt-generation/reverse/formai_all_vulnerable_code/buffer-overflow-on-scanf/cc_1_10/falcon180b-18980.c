//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Vector;

typedef struct {
    double angle;
    double speed;
    Vector position;
} Vehicle;

void move(Vehicle* v) {
    Vector dir = {cos(v->angle), sin(v->angle)};
    v->position.x += dir.x * v->speed;
    v->position.y += dir.y * v->speed;
}

void turn(Vehicle* v, double angle) {
    v->angle += angle;
    if (v->angle > 2 * PI) {
        v->angle -= 2 * PI;
    } else if (v->angle < 0) {
        v->angle += 2 * PI;
    }
}

int main() {
    srand(time(NULL));

    Vehicle v = {0, 1, {0, 0}};
    double maxSpeed = 1;
    double maxTurn = PI / 4;

    while (1) {
        printf("Current position: (%g, %g)\n", v.position.x, v.position.y);
        printf("Speed: %g\n", v.speed);
        printf("Angle: %g\n", v.angle);

        char command;
        scanf("%c", &command);

        switch (command) {
            case 'f':
                move(&v);
                break;
            case 'b':
                move(&v);
                turn(&v, -maxTurn);
                break;
            case 'l':
                turn(&v, maxTurn);
                break;
            case 'r':
                turn(&v, -maxTurn);
                break;
            case's':
                v.speed = 0;
                break;
            case 'a':
                v.speed = maxSpeed;
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command\n");
        }
    }

    return 0;
}