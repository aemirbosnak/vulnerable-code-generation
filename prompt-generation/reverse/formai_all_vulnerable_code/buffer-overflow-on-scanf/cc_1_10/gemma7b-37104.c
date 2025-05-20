//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 10
#define MAX_HEIGHT 10

typedef struct Cell {
    int x, y, state, visited;
} Cell;

Cell cells[MAX_WIDTH * MAX_HEIGHT];

void init_game() {
    srand(time(NULL));

    for (int i = 0; i < MAX_WIDTH * MAX_HEIGHT; i++) {
        cells[i].x = i % MAX_WIDTH;
        cells[i].y = i / MAX_WIDTH;
        cells[i].state = 0;
        cells[i].visited = 0;
    }

    cells[0].state = 1;
    cells[5].state = 1;
    cells[10].state = 1;
    cells[15].state = 1;
}

void play_game() {
    int move_x, move_y;

    printf("Enter move (x, y): ");
    scanf("%d %d", &move_x, &move_y);

    if (move_x < 0 || move_x >= MAX_WIDTH || move_y < 0 || move_y >= MAX_HEIGHT) {
        printf("Invalid move.\n");
        return;
    }

    if (cells[move_x * MAX_HEIGHT + move_y].visited) {
        printf("Already visited.\n");
        return;
    }

    cells[move_x * MAX_HEIGHT + move_y].visited = 1;

    if (cells[move_x * MAX_HEIGHT + move_y].state == 1) {
        printf("You win!\n");
        return;
    } else {
        printf("No win.\n");
    }
}

int main() {
    init_game();
    play_game();

    return 0;
}