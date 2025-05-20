//Falcon-180B DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 50
#define MAX_COLS 50
#define ALIVE 1
#define DEAD 0

int board[MAX_ROWS][MAX_COLS];
int num_alive_neighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int row = y + i;
            int col = x + j;
            if (row >= 0 && row < MAX_ROWS && col >= 0 && col < MAX_COLS) {
                if (board[row][col] == ALIVE) {
                    count++;
                }
            }
        }
    }
    return count;
}

void next_generation() {
    int new_board[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            int alive_neighbors = num_alive_neighbors(i, j);
            if (board[i][j] == ALIVE && alive_neighbors < 2) {
                new_board[i][j] = DEAD;
            } else if (board[i][j] == ALIVE && alive_neighbors == 2 || alive_neighbors == 3) {
                new_board[i][j] = ALIVE;
            } else if (board[i][j] == DEAD && alive_neighbors == 3) {
                new_board[i][j] = ALIVE;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

void print_board() {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (board[i][j] == ALIVE) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int x, y, alive_cells = 0;
    printf("Enter the number of alive cells: ");
    scanf("%d", &alive_cells);
    srand(time(NULL));
    for (int i = 0; i < alive_cells; i++) {
        x = rand() % MAX_ROWS;
        y = rand() % MAX_COLS;
        board[x][y] = ALIVE;
    }
    while (1) {
        print_board();
        next_generation();
        usleep(100000);
    }
    return 0;
}