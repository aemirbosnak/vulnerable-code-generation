//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for the remote control vehicle
typedef struct {
    int x;
    int y;
    int heading;
    int speed;
} Vehicle;

// Function to move the vehicle
void move(Vehicle *v) {
    if (v->speed > 0) {
        v->x += v->speed;
        v->y += v->heading;
    } else if (v->speed < 0) {
        v->x -= v->speed;
        v->y += v->heading;
    } else {
        v->y += v->heading;
    }
}

// Function to read input from the user
void read_input() {
    char c;
    printf("Enter command: ");
    scanf(" %c", &c);
    if (c == 'N') {
        printf("North\n");
    } else if (c == 'S') {
        printf("South\n");
    } else if (c == 'E') {
        printf("East\n");
    } else if (c == 'W') {
        printf("West\n");
    } else if (c == 'L') {
        printf("Left\n");
    } else if (c == 'R') {
        printf("Right\n");
    } else if (c == 'F') {
        printf("Forward\n");
    } else if (c == 'B') {
        printf("Backward\n");
    } else if (c == 'Q') {
        printf("Quit\n");
        exit(0);
    }
}

// Function to simulate the vehicle's motion
void simulate(Vehicle *v) {
    char command;
    while (1) {
        read_input();
        switch (command) {
            case 'N':
                v->heading = 90;
                break;
            case 'S':
                v->heading = 270;
                break;
            case 'E':
                v->heading = 0;
                break;
            case 'W':
                v->heading = 180;
                break;
            case 'L':
                v->heading -= 15;
                break;
            case 'R':
                v->heading += 15;
                break;
            case 'F':
                v->speed = 5;
                break;
            case 'B':
                v->speed = -5;
                break;
            default:
                printf("Invalid command\n");
        }
        move(v);
    }
}

int main() {
    Vehicle v;
    v.x = 0;
    v.y = 0;
    v.heading = 0;
    v.speed = 0;
    simulate(&v);
    return 0;
}