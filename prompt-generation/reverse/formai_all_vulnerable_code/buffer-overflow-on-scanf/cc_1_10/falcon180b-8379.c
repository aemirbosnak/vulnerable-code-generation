//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MINE_COUNT 5

char board[ROWS][COLS];
int mines[ROWS][COLS];
int mine_count = 0;

void init_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
            mines[i][j] = 0;
        }
    }
}

void plant_mines() {
    srand(time(NULL));
    int x, y;
    for (int i = 0; i < MINE_COUNT; i++) {
        do {
            x = rand() % ROWS;
            y = rand() % COLS;
        } while (mines[x][y] == 1);
        mines[x][y] = 1;
        mine_count++;
    }
}

void print_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mines[i][j] == 1) {
                printf("*");
            } else {
                printf("%d", mines[i][j]);
            }
        }
        printf("\n");
    }
}

int reveal_tile(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return 0;
    }

    if (mines[x][y] == 1) {
        printf("You hit a mine! Game over.\n");
        return 1;
    } else {
        printf("Revealed tile: %d\n", mines[x][y]);
        return 0;
    }
}

int main() {
    init_board();
    plant_mines();
    int x, y;
    while (1) {
        print_board();
        printf("Enter the coordinates of the tile you want to reveal (x y): ");
        scanf("%d %d", &x, &y);
        if (reveal_tile(x, y)) {
            break;
        }
    }
    return 0;
}