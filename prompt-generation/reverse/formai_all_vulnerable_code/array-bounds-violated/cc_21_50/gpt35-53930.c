//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>

int main() {
    char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int player = 1, row, column, moves = 0;

    while (1) {
        printf("Player %d's turn! \n", player);
        printf("Enter row number (1-3): ");
        scanf("%d", &row);
        printf("Enter column number (1-3): ");
        scanf("%d", &column);
        row--;
        column--;

        if (board[row][column] == ' ') {
            board[row][column] = (player == 1) ? 'X' : 'O';
            moves++;
        } else {
            printf("Position already taken! Try again!\n");
            continue;
        }

        // Print the board
        printf("\n\n");
        printf("  1 2 3\n");
        printf(" -------\n");
        for (int i = 0; i < 3; i++) {
            printf("%d|", i + 1);
            for (int j = 0; j < 3; j++) {
                printf("%c|", board[i][j]);
            }
            printf("\n");
            printf(" -------\n");
        }

        // Check whether any player has won
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                printf("Player %d Wins!\n", player);
                return 0;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                printf("Player %d Wins!\n", player);
                return 0;
            }
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
            printf("Player %d Wins!\n", player);
            return 0;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
            printf("Player %d Wins!\n", player);
            return 0;
        }

        // Check if the game is a tie
        if (moves == 9) {
            printf("It's a tie! Nobody wins!\n");
            return 0;
        }

        // Switch to the other player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}