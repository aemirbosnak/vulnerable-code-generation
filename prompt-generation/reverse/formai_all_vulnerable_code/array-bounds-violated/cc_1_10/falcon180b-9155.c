//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void drawBoard(char board[3][3]) {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
        printf("-------------\n");
    }
}

int main() {
    srand(time(NULL));
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int playerTurn = 1;
    int choice;
    int flag = 0;

    initBoard(board);
    while (!flag) {
        drawBoard(board);
        printf("Player %d's turn\n", playerTurn);
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 9 || board[choice / 3 - 1][choice % 3 - 1]!= '-') {
            printf("Invalid choice. Try again.\n");
        } else {
            board[choice / 3 - 1][choice % 3 - 1] = (playerTurn % 2 == 0)? 'X' : 'O';
            playerTurn++;
            flag = checkWin(board);
        }
    }

    if (playerTurn % 2 == 0) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}

int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0]!= '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i]!= '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    if (board[0][0]!= '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2]!= '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}