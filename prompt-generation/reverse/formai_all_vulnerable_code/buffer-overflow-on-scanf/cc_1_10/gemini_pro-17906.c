//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define XMAX 100
#define YMAX 100

struct position {
    int x;
    int y;
};

struct car {
    struct position pos;
    char facing;  // 'N', 'E', 'S', or 'W'
};

void move(struct car *car, char direction) {
    switch (direction) {
        case 'N':
            car->pos.y++;
            break;
        case 'E':
            car->pos.x++;
            break;
        case 'S':
            car->pos.y--;
            break;
        case 'W':
            car->pos.x--;
            break;
    }
}

void turn(struct car *car, char direction) {
    static char directions[] = "NESW";
    int index = strchr(directions, car->facing) - directions;
    if (direction == 'L') {
        index = (index + 3) % 4;
    } else if (direction == 'R') {
        index = (index + 1) % 4;
    }
    car->facing = directions[index];
}

int main() {
    struct car car = { { 0, 0 }, 'N' };
    char command;
    while (scanf(" %c", &command) != EOF) {
        if (command == 'F') {
            move(&car, car.facing);
        } else if (command == 'L' || command == 'R') {
            turn(&car, command);
        }
    }
    printf("%d %d %c\n", car.pos.x, car.pos.y, car.facing);
    return 0;
}