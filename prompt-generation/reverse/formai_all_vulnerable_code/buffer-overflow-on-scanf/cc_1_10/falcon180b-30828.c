//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

char grid[ROWS][COLS];
bool game_over = false;

void init_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = '.';
        }
    }
}

void draw_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void place_ship(int length) {
    int x, y;
    do {
        x = rand() % ROWS;
        y = rand() % COLS;
    } while (grid[x][y]!= '.');

    grid[x][y] = 'S';
    for (int i = 1; i < length; i++) {
        if (x + i >= ROWS) {
            break;
        }
        grid[x + i][y] = 'S';
    }
}

void place_ships() {
    int ship_lengths[] = {2, 3, 3, 4, 4};
    for (int i = 0; i < 5; i++) {
        place_ship(ship_lengths[i]);
    }
}

bool check_hit(int x, int y) {
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y]!= '.') {
        return true;
    }
    return false;
}

void fire(int x, int y) {
    if (check_hit(x, y)) {
        grid[x][y] = 'X';
        if (grid[x][y] == 'S') {
            printf("Hit!\n");
        } else {
            printf("Miss.\n");
        }
    } else {
        printf("Miss.\n");
    }
}

int main() {
    srand(time(NULL));
    init_grid();
    place_ships();

    int player_x, player_y;
    do {
        draw_grid();
        printf("Enter your coordinates: ");
        scanf("%d %d", &player_x, &player_y);
        if (check_hit(player_x, player_y)) {
            fire(player_x, player_y);
        } else {
            printf("Miss.\n");
        }
        if (game_over) {
            printf("Game Over!\n");
            break;
        }
    } while (!game_over);

    return 0;
}