//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SPEED 5
#define LEFT 1
#define RIGHT 2
#define FORWARD 3
#define BACKWARD 4

typedef struct {
    int x;
    int y;
} position;

position vehicle = {0, 0};

void move(int direction) {
    switch (direction) {
        case FORWARD:
            vehicle.y++;
            break;
        case BACKWARD:
            vehicle.y--;
            break;
        case LEFT:
            vehicle.x--;
            break;
        case RIGHT:
            vehicle.x++;
            break;
    }
}

void print_position() {
    printf("Position: (%d, %d)\n", vehicle.x, vehicle.y);
}

void get_command() {
    char command[5];
    fgets(command, 5, stdin);
    command[strlen(command) - 1] = '\0';

    if (strcmp(command, "f") == 0) {
        move(FORWARD);
    } else if (strcmp(command, "b") == 0) {
        move(BACKWARD);
    } else if (strcmp(command, "l") == 0) {
        move(LEFT);
    } else if (strcmp(command, "r") == 0) {
        move(RIGHT);
    } else {
        printf("Invalid command\n");
        get_command();
    }
}

int main() {
    srand(time(NULL));

    printf("Remote control vehicle simulation started\n");
    print_position();

    while (1) {
        get_command();
        print_position();
        usleep(SPEED * 1000000);
    }

    return 0;
}