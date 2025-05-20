//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

int main() {
    char board[ROWS][COLUMNS];
    int i, j, x, y, treasure_x, treasure_y, steps, prev_x, prev_y;
    srand(time(NULL));
    treasure_x = rand() % ROWS;
    treasure_y = rand() % COLUMNS;
    steps = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board[i][j] = '-';
        }
    }
    board[treasure_x][treasure_y] = 'T';
    x = rand() % ROWS;
    y = rand() % COLUMNS;
    board[x][y] = '@';
    while (1) {
        prev_x = x;
        prev_y = y;
        printf("Enter move (N/S/E/W): ");
        fflush(stdout);
        char move;
        scanf(" %c", &move);  // space before %c to consume newline from previous scanf
        switch (move) {
            case 'N':
                x--;
                break;
            case 'S':
                x++;
                break;
            case 'E':
                y++;
                break;
            case 'W':
                y--;
                break;
            default:
                printf("Invalid move!\n");
                continue;
        }
        steps++;
        if (x < 0 || x >= ROWS || y < 0 || y >= COLUMNS) {
            printf("Out of bounds!\n");
            x = prev_x;
            y = prev_y;
            continue;
        }
        if (board[x][y] == 'T') {
            printf("Congratulations! You found the treasure in %d steps!\n", steps);
            break;
        }
        board[prev_x][prev_y] = '-';
        board[x][y] = '@';
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLUMNS; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}