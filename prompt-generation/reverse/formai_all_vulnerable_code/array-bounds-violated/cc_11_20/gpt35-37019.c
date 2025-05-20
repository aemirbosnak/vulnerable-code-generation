//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void print_board() {
    printf("\n");
    printf("\t%c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("\t--|---|--\n");
    printf("\t%c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("\t--|---|--\n");
    printf("\t%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int winner() {
    int i;
    for (i = 0; i < 3; i++) {
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
    int i, j, k, row, col, n=0, choice[9];
    print_board();
    while (n <= 9) {
        if (n % 2 == 0) {
            printf("Player 1, please enter a row (0-2) and column (0-2) to place an X: ");
            scanf("%d %d", &row, &col);
            if (board[row][col] == 'O' || board[row][col] == 'X') {
                printf("That space is already taken!\n");
                continue;
            }
            board[row][col] = 'X';
        } else {
            // AI turn
            int move_found = 0;
            // Check for winning move
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        board[i][j] = 'O';
                        if (winner()) {
                            move_found = 1;
                            break;
                        }
                        board[i][j] = ' ';
                    }
                }
                if (move_found) break;
            }
            // Check for blocking move
            if (!move_found) {
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        if (board[i][j] == ' ') {
                            board[i][j] = 'X';
                            if (winner()) {
                                board[i][j] = 'O';
                                move_found = 1;
                                break;
                            }
                            board[i][j] = ' ';
                        }
                    }
                    if (move_found) break;
                }
            }
            // Otherwise, make any available move
            if (!move_found) {
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        if (board[i][j] == ' ') {
                            board[i][j] = 'O';
                            move_found = 1;
                            break;
                        }
                    }
                    if (move_found) break;
                }
            }
            printf("AI selects row %d and column %d.\n", i, j);
        }
        n++;
        print_board();
        if (winner()) {
            printf("Congratulations! Player %d wins!\n", (n % 2) + 1);
            break;
        }
        if (n == 9) {
            printf("The game is a tie!\n");
            break;
        }
    }
    return 0;
}