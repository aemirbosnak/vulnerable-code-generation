//Falcon-180B DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initBoard(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

int checkWin(char board[][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

int main() {
    srand(time(NULL));
    int player = rand() % 2 + 1;
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    initBoard(board);
    int moves = 0;
    while (moves < 9) {
        int row, col;
        printf("Player %d's turn\n", player);
        printf("Enter row and column: ");
        scanf("%d%d", &row, &col);
        if (board[row - 1][col - 1]!= '-') {
            printf("Invalid move\n");
            continue;
        }
        board[row - 1][col - 1] = player == 1? 'X' : 'O';
        printf("Board:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        if (checkWin(board)) {
            printf("Player %d wins!\n", player);
            break;
        }
        player = player == 1? 2 : 1;
        moves++;
    }
    if (moves == 9)
        printf("It's a draw\n");
    return 0;
}