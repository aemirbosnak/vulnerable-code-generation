//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

void drawBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));
    char board[3][3];
    int playerScore = 0;
    int computerScore = 0;
    int currentPlayer = 1; // 1 for player, 2 for computer
    Point selectedTile;
    initializeBoard(board);
    while (playerScore < 5 && computerScore < 5) {
        drawBoard(board);
        printf("Player %d's turn.\n", currentPlayer);
        if (currentPlayer == 1) {
            printf("Enter row and column (e.g. 1 2): ");
            scanf("%d %d", &selectedTile.x, &selectedTile.y);
            if (board[selectedTile.x][selectedTile.y] == '-') {
                board[selectedTile.x][selectedTile.y] = 'X';
                playerScore++;
            } else {
                printf("Tile already selected.\n");
            }
        } else {
            int attempts = 0;
            while (attempts < 10) {
                int row = randomNumber(0, 2);
                int col = randomNumber(0, 2);
                if (board[row][col] == '-') {
                    board[row][col] = 'O';
                    computerScore++;
                    break;
                }
                attempts++;
            }
        }
        currentPlayer = (currentPlayer == 1)? 2 : 1;
    }
    drawBoard(board);
    if (playerScore == 5) {
        printf("Player %d wins!\n", currentPlayer);
    } else {
        printf("Computer %d wins!\n", currentPlayer);
    }
    return 0;
}