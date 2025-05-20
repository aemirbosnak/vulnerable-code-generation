//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    position pos;
    int speed;
    int direction;
} vehicle;

void drive_forward(vehicle *v) {
    if (v->speed < MAX_SPEED) {
        v->speed++;
    }
    switch (v->direction) {
        case 0:
            v->pos.y++;
            break;
        case 1:
            v->pos.x++;
            break;
        case 2:
            v->pos.y--;
            break;
        case 3:
            v->pos.x--;
            break;
    }
}

void drive_backward(vehicle *v) {
    if (v->speed > MIN_SPEED) {
        v->speed--;
    }
    switch (v->direction) {
        case 0:
            v->pos.y--;
            break;
        case 1:
            v->pos.x--;
            break;
        case 2:
            v->pos.y++;
            break;
        case 3:
            v->pos.x++;
            break;
    }
}

void turn_left(vehicle *v) {
    if (v->direction == 0) {
        v->direction = 3;
    } else {
        v->direction--;
    }
}

void turn_right(vehicle *v) {
    if (v->direction == 3) {
        v->direction = 0;
    } else {
        v->direction++;
    }
}

void print_status(vehicle *v) {
    char direction[6];
    switch (v->direction) {
        case 0:
            strcpy(direction, "NORTH");
            break;
        case 1:
            strcpy(direction, "EAST");
            break;
        case 2:
            strcpy(direction, "SOUTH");
            break;
        case 3:
            strcpy(direction, "WEST");
            break;
    }
    printf("Current position: (%d, %d)\n", v->pos.x, v->pos.y);
    printf("Current speed: %d\n", v->speed);
    printf("Current direction: %s\n", direction);
    printf("\n");
}

int main() {
    vehicle v;
    v.pos.x = 0;
    v.pos.y = 0;
    v.speed = 0;
    v.direction = 0;
    bool running = true;
    while (running) {
        int input;
        printf("Enter 1 to drive forward, 2 to drive backward, 3 to turn left, 4 to turn right,\n5 to print current status, or 6 to quit: ");
        scanf("%d", &input);
        printf("\n");
        switch (input) {
            case 1:
                drive_forward(&v);
                break;
            case 2:
                drive_backward(&v);
                break;
            case 3:
                turn_left(&v);
                break;
            case 4:
                turn_right(&v);
                break;
            case 5:
                print_status(&v);
                break;
            case 6:
                running = false;
                break;
            default:
                printf("Invalid input.\n\n");
        }
    }
    return 0;
}