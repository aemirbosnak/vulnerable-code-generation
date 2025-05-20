//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 4
#define PAIRS 8

char board[ROW][COL];
int pairCount = 0;
int flag = 0;

void initBoard() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = '*';
        }
    }
}

void printBoard() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffleBoard() {
    int i, j, k;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            k = rand() % PAIRS;
            board[i][j] = k + '0';
        }
    }
}

int checkMatch(int x, int y) {
    if (board[x][y] == board[x][y + 1] && board[x][y + 1] == board[x + 1][y + 1]) {
        return 1;
    } else if (board[x][y] == board[x + 1][y] && board[x + 1][y] == board[x + 1][y + 1]) {
        return 1;
    } else {
        return 0;
    }
}

int playGame() {
    int x, y, i, j;
    while (pairCount < PAIRS) {
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                if (board[i][j] == '*') {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        if (x == -1 || y == -1) {
            break;
        }
        board[x][y] = '*';
        if (checkMatch(x, y)) {
            pairCount++;
            board[x][y] = '0' + pairCount;
            board[x][y + 1] = '0' + pairCount;
            board[x + 1][y] = '0' + pairCount;
            board[x + 1][y + 1] = '0' + pairCount;
        } else {
            board[x][y] = '*';
        }
    }
    return pairCount;
}

int main() {
    srand(time(NULL));
    initBoard();
    shuffleBoard();
    int score = playGame();
    if (score == PAIRS) {
        printf("Congratulations! You won the game!\n");
    } else {
        printf("Sorry, you lost the game.\n");
    }
    return 0;
}