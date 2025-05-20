//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 3
#define NUM_COLS 3
#define NUM_DIRECTIONS 4

enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

void move(int *row, int *col, enum direction dir) {
    switch (dir) {
        case UP:
            (*row)--;
            break;
        case DOWN:
            (*row)++;
            break;
        case LEFT:
            (*col)--;
            break;
        case RIGHT:
            (*col)++;
            break;
    }
}

int main() {
    int row = 0;
    int col = 0;
    enum direction dir = RIGHT;

    printf("Starting position: (%d, %d)\n", row, col);

    while (1) {
        printf("Current position: (%d, %d)\n", row, col);
        printf("Enter a direction (up, down, left, right): ");
        scanf("%s", &dir);

        move(&row, &col, dir);

        if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
            printf("Robot has fallen off the grid.\n");
            exit(0);
        }
    }

    return 0;
}