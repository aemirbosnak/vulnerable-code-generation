//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_COMMANDS 100
#define PI 3.14159265358979323846

struct Command {
    char *name;
    void (*func)(void);
};

void init(void) {
    printf("Initializing drone...\n");
}

void takeoff(void) {
    printf("Taking off...\n");
}

void land(void) {
    printf("Landing...\n");
}

void forward(int distance) {
    printf("Moving forward %d meters...\n", distance);
}

void backward(int distance) {
    printf("Moving backward %d meters...\n", distance);
}

void left(int distance) {
    printf("Moving left %d meters...\n", distance);
}

void right(int distance) {
    printf("Moving right %d meters...\n", distance);
}

void up(int distance) {
    printf("Moving up %d meters...\n", distance);
}

void down(int distance) {
    printf("Moving down %d meters...\n", distance);
}

void rotate(int angle) {
    printf("Rotating %d degrees...\n", angle);
}

int main(int argc, char *argv[]) {
    int i, j;
    char input[100];
    struct Command commands[MAX_COMMANDS];

    init();

    strcpy(commands[0].name, "takeoff");
    commands[0].func = takeoff;

    strcpy(commands[1].name, "land");
    commands[1].func = land;

    strcpy(commands[2].name, "forward");
    commands[2].func = forward;

    strcpy(commands[3].name, "backward");
    commands[3].func = backward;

    strcpy(commands[4].name, "left");
    commands[4].func = left;

    strcpy(commands[5].name, "right");
    commands[5].func = right;

    strcpy(commands[6].name, "up");
    commands[6].func = up;

    strcpy(commands[7].name, "down");
    commands[7].func = down;

    strcpy(commands[8].name, "rotate");
    commands[8].func = rotate;

    while (1) {
        printf("Enter command: ");
        scanf("%s", input);

        for (i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(commands[i].name, input) == 0) {
                commands[i].func();
            }
        }

        if (strcmp(input, "exit") == 0) {
            break;
        }
    }

    return 0;
}