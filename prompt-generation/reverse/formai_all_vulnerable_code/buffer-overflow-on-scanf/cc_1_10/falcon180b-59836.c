//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define EMPTY '.'
#define PLAYER '@'
#define ENEMY 'X'

void print_grid(char grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void generate_grid(char grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = EMPTY;
        }
    }
    grid[0][0] = PLAYER;
}

void move_player(char grid[SIZE][SIZE], int *x, int *y, char direction) {
    int new_x = *x;
    int new_y = *y;

    switch (direction) {
        case 'w':
            new_y--;
            break;
        case 'a':
            new_x--;
            break;
        case's':
            new_y++;
            break;
        case 'd':
            new_x++;
            break;
    }

    if (new_x >= 0 && new_x < SIZE && new_y >= 0 && new_y < SIZE && grid[new_x][new_y] == EMPTY) {
        *x = new_x;
        *y = new_y;
    }
}

int main() {
    srand(time(NULL));

    char grid[SIZE][SIZE];
    generate_grid(grid);

    int player_x = 0;
    int player_y = 0;

    while (1) {
        system("clear");
        print_grid(grid);

        char input[2];
        scanf("%s", input);

        move_player(grid, &player_x, &player_y, input[0]);

        if (grid[player_x][player_y] == ENEMY) {
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}