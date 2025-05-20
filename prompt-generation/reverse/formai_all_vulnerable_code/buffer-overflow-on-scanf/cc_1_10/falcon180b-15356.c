//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159

struct Vector {
    double x;
    double y;
};

struct Robot {
    struct Vector position;
    struct Vector velocity;
    double radius;
};

void move(struct Robot* robot, double dx, double dy) {
    double distance = sqrt(dx*dx + dy*dy);
    if (distance > robot->radius) {
        dx = dx / distance * robot->radius;
        dy = dy / distance * robot->radius;
    }
    robot->position.x += dx;
    robot->position.y += dy;
}

void turn(struct Robot* robot, double angle) {
    double dx = cos(angle) * robot->radius;
    double dy = sin(angle) * robot->radius;
    move(robot, dx, dy);
}

int main() {
    srand(time(NULL));

    struct Robot romeo = {
       .position = {0, 0},
       .velocity = {0, 0},
       .radius = 10
    };

    struct Robot juliet = {
       .position = {20, 0},
       .velocity = {0, 0},
       .radius = 10
    };

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move Romeo\n");
        printf("2. Turn Romeo\n");
        printf("3. Move Juliet\n");
        printf("4. Turn Juliet\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the distance Romeo should move (in cm): ");
                double distance = rand() % 101;
                move(&romeo, distance, 0);
                printf("Romeo moved %.2f cm.\n", distance);
                break;
            case 2:
                printf("Enter the angle Romeo should turn (in degrees): ");
                double angle = rand() % 361;
                turn(&romeo, angle);
                printf("Romeo turned %.2f degrees.\n", angle);
                break;
            case 3:
                printf("Enter the distance Juliet should move (in cm): ");
                distance = rand() % 101;
                move(&juliet, distance, 0);
                printf("Juliet moved %.2f cm.\n", distance);
                break;
            case 4:
                printf("Enter the angle Juliet should turn (in degrees): ");
                angle = rand() % 361;
                turn(&juliet, angle);
                printf("Juliet turned %.2f degrees.\n", angle);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}