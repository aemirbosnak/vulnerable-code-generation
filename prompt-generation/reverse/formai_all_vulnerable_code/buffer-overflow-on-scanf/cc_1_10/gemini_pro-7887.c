//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

char grid[NUM_ROWS][NUM_COLS];
int player_row, player_col;

void print_grid() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void init_grid() {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            grid[i][j] = '.';
        }
    }
}

void place_player() {
    player_row = rand() % NUM_ROWS;
    player_col = rand() % NUM_COLS;
    grid[player_row][player_col] = 'P';
}

void move_player(char direction) {
    int new_row = player_row;
    int new_col = player_col;

    switch (direction) {
        case 'w':
            new_row--;
            break;
        case 's':
            new_row++;
            break;
        case 'a':
            new_col--;
            break;
        case 'd':
            new_col++;
            break;
    }

    if (new_row >= 0 && new_row < NUM_ROWS && new_col >= 0 && new_col < NUM_COLS) {
        grid[player_row][player_col] = '.';
        grid[new_row][new_col] = 'P';
        player_row = new_row;
        player_col = new_col;
    }
}

int main() {
    srand(time(NULL));

    init_grid();
    place_player();

    while (1) {
        print_grid();

        char direction;
        printf("Enter a direction (w, s, a, d): ");
        scanf(" %c", &direction);

        move_player(direction);
    }

    return 0;
}