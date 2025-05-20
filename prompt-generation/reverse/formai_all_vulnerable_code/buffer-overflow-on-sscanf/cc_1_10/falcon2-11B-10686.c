//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int speed;
} Coord;

typedef struct {
    int rx;
    int ry;
} Direction;

Coord current_position;
Direction current_direction;

void update_position() {
    Coord next_position;
    next_position.x = current_position.x + current_direction.rx;
    next_position.y = current_position.y + current_direction.ry;
    current_position.x = next_position.x;
    current_position.y = next_position.y;
}

void update_direction(Direction new_direction) {
    current_direction.rx = new_direction.rx;
    current_direction.ry = new_direction.ry;
}

void display_status() {
    printf("Current position: %d, %d\n", current_position.x, current_position.y);
    printf("Current direction: %d, %d\n", current_direction.rx, current_direction.ry);
}

int main() {
    Coord initial_position = {0, 0};
    Direction initial_direction = {1, 0};

    while (1) {
        printf("Enter direction (rx, ry):\n");
        char direction_input[10];
        fgets(direction_input, sizeof(direction_input), stdin);

        Direction new_direction;
        sscanf(direction_input, "%d,%d", &new_direction.rx, &new_direction.ry);

        update_direction(new_direction);
        display_status();
        sleep(1);
    }
    return 0;
}