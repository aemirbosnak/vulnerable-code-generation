//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define FORWARD 1
#define BACKWARD 2
#define STOP 0

typedef struct {
    int x;
    int y;
    int dir;
    int speed;
} Vehicle;

void move(Vehicle *v) {
    if (v->speed == FORWARD) {
        printf("The vehicle moves forward.\n");
    } else if (v->speed == BACKWARD) {
        printf("The vehicle moves backward.\n");
    } else {
        printf("The vehicle is stopped.\n");
    }
}

void turn(Vehicle *v, int turn) {
    switch(turn) {
        case UP:
            printf("The vehicle turns up.\n");
            break;
        case DOWN:
            printf("The vehicle turns down.\n");
            break;
        case LEFT:
            printf("The vehicle turns left.\n");
            break;
        case RIGHT:
            printf("The vehicle turns right.\n");
            break;
    }
}

int main() {
    Vehicle v;
    int choice;

    v.x = 0;
    v.y = 0;
    v.dir = 0;
    v.speed = STOP;

    while(1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Stop\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                v.speed = FORWARD;
                break;
            case 2:
                v.speed = BACKWARD;
                break;
            case 3:
                turn(&v, LEFT);
                break;
            case 4:
                turn(&v, RIGHT);
                break;
            case 5:
                v.speed = STOP;
                break;
            default:
                printf("Invalid choice.\n");
        }

        move(&v);
    }

    return 0;
}