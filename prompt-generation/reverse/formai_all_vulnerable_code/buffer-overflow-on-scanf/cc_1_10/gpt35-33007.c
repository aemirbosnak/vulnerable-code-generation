//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

void draw_board(char board[][3]) {
    printf("\n\n");
    printf("\t\t  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t -----------\n");
    printf("\t\t  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t -----------\n");
    printf("\t\t  %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int make_move(char board[][3], char mark, int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid move. Please enter valid row and column numbers.\n");
        return 0;
    } else if (board[row][col] != ' ') {
        printf("Invalid move. That position is already taken.\n");
        return 0;
    } else {
        board[row][col] = mark;
        return 1;
    }
}

int check_win(char board[][3]) {
    int i, j;
    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    } else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player1_mark = 'X';
    char player2_mark = 'O';
    int turn = 1;
    int row, col;
    int winner;

    printf("==========================\n");
    printf(" Welcome to Tic Tac Toe!\n");
    printf("==========================\n");

    while (1) {
        draw_board(board);
        if (turn % 2 == 1) {
            printf("Player 1's turn (X):\n");
        } else {
            printf("Player 2's turn (O):\n");
        }
        printf("Enter row number (0-2): ");
        scanf("%d", &row);
        printf("Enter column number (0-2): ");
        scanf("%d", &col);
        if (turn % 2 == 1) {
            if (make_move(board, player1_mark, row, col)) {
                turn++;
            }
        } else {
            if (make_move(board, player2_mark, row, col)) {
                turn++;
            }
        }
        winner = check_win(board);
        if (winner) {
            draw_board(board);
            if (turn % 2 == 1) {
                printf("Player 2 (O) wins!\n");
            } else {
                printf("Player 1 (X) wins!\n");
            }
            break;
        }
        if (turn > 9) {
            draw_board(board);
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}