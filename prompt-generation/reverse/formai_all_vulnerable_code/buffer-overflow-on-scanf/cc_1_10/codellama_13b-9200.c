//Code Llama-13B DATASET v1.0 Category: Robot movement control ; Style: expert-level
/*
 * robot_movement.c
 *
 *  Created on: 01-Dec-2020
 *      Author: Aditya
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROBOT_SIZE 100

typedef struct {
    int x;
    int y;
    int z;
} Coordinate;

void move_forward(Coordinate* coordinate) {
    coordinate->x++;
}

void move_backward(Coordinate* coordinate) {
    coordinate->x--;
}

void move_left(Coordinate* coordinate) {
    coordinate->y++;
}

void move_right(Coordinate* coordinate) {
    coordinate->y--;
}

void move_up(Coordinate* coordinate) {
    coordinate->z++;
}

void move_down(Coordinate* coordinate) {
    coordinate->z--;
}

void rotate_left(Coordinate* coordinate) {
    coordinate->x++;
}

void rotate_right(Coordinate* coordinate) {
    coordinate->x--;
}

int main() {
    Coordinate coordinate = {0, 0, 0};
    char command;

    while (1) {
        printf("Enter a command: ");
        scanf("%c", &command);

        switch (command) {
            case 'F':
                move_forward(&coordinate);
                break;
            case 'B':
                move_backward(&coordinate);
                break;
            case 'L':
                move_left(&coordinate);
                break;
            case 'R':
                move_right(&coordinate);
                break;
            case 'U':
                move_up(&coordinate);
                break;
            case 'D':
                move_down(&coordinate);
                break;
            case 'H':
                rotate_left(&coordinate);
                break;
            case 'J':
                rotate_right(&coordinate);
                break;
            default:
                printf("Invalid command!\n");
                break;
        }

        printf("Coordinate: (%d, %d, %d)\n", coordinate.x, coordinate.y, coordinate.z);
    }

    return 0;
}