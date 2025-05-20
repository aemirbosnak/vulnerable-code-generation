//Falcon-180B DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void initBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[SIZE][SIZE], char symbol) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1;
        }
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1;
        }
    }
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1;
    }
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    char board[SIZE][SIZE];
    initBoard(board);
    int player = 1;
    int choice;
    while (1) {
        system("clear");
        printBoard(board);
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move (row col): ");
        scanf("%d %d", &choice, &choice);
        if (choice < 1 || choice > SIZE) {
            printf("Invalid move\n");
            continue;
        }
        if (board[choice - 1][0]!= '.' && board[choice - 1][1]!= '.' && board[choice - 1][2]!= '.') {
            printf("Row full\n");
            continue;
        }
        board[choice - 1][0] = (player % 2 == 0)? 'X' : 'O';
        if (checkWin(board, board[choice - 1][0])) {
            printf("%c wins!\n", board[choice - 1][0]);
            break;
        }
        player++;
    }
    return 0;
}