//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdio.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void drawBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

void playGame() {
    int player = 1;
    int choice;

    while (1) {
        drawBoard();
        printf("\nPlayer %d's turn. Enter a number: ", player);
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        int row = (choice-1)/3;
        int col = (choice-1)%3;

        if (board[row][col]!= 'X' && board[row][col]!= 'O') {
            board[row][col] = (player == 1)? 'X' : 'O';
            player++;
        } else {
            printf("Spot taken. Try again.\n");
        }

        if (checkWin()) {
            drawBoard();
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        if (player > 2) {
            drawBoard();
            printf("\nIt's a tie.\n");
            break;
        }
    }
}

int main() {
    playGame();
    return 0;
}