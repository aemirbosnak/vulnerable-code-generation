#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 5
#define TREASURE_X 3
#define TREASURE_Y 4

char grid[ROWS][COLS];

void print_grid() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void move_player(char *direction) {
    int player_x = 2, player_y = 2;

    if (strcmp(direction, "w") == 0) --player_y;
    else if (strcmp(direction, "s") == 0) ++player_y;
    else if (strcmp(direction, "a") == 0) --player_x;
    else if (strcmp(direction, "d") == 0) ++player_x;

    if (player_x >= 0 && player_x < ROWS && player_y >= 0 && player_y < COLS)
        grid[player_y][player_x] = 'P';

    print_grid();
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = i < TREASURE_Y && j < TREASURE_X ? '$' : '.';
        }
    }
    grid[TREASURE_Y][TREASURE_X] = 'T';

    char input[1];
    while (1) {
        printf("Enter direction (w, a, s, d): ");
        fgets(input, sizeof(input), stdin);
        move_player(input);
    }

    return 0;
}
