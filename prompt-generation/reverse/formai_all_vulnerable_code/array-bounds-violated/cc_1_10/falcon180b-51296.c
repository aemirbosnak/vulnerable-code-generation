//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    char board[ROWS][COLS];
    initBoard(board);

    int x = 0, y = 0, dir = 0;
    while (1) {
        system("clear");
        printBoard(board);

        int ch = rand() % 4;
        switch (ch) {
            case 0:
                if (dir!= 1)
                    dir = 0;
                break;
            case 1:
                if (dir!= 2)
                    dir = 1;
                break;
            case 2:
                if (dir!= 0)
                    dir = 2;
                break;
            case 3:
                if (dir!= 3)
                    dir = 3;
                break;
        }

        switch (dir) {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
        }

        if (board[y][x] == '.') {
            board[y][x] = 'O';
        } else {
            board[y][x] = '.';
        }

        usleep(100000);
    }

    return 0;
}