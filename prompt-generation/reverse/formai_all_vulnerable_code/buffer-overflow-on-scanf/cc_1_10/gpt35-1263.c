//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

char board[3][3];  // game board

// initialize the board
void init_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// display the board
void display_board() {
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" ");
        for (j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// check if there is a winning condition
char check_win() {
    int i;
    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // no winning condition found
    return '-';
}

// check if the game is a tie
int check_tie() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

// AI player move
int ai_move() {
    int i, j;
    // check if AI can win
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                board[i][j] = 'O';
                if (check_win() == 'O') {
                    return 1;
                } else {
                    board[i][j] = '-';
                }
            }
        }
    }
    // check if player can win and block
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                board[i][j] = 'X';
                if (check_win() == 'X') {
                    board[i][j] = 'O';
                    return 1;
                } else {
                    board[i][j] = '-';
                }
            }
        }
    }
    // take a random spot
    while (1) {
        i = rand() % 3;
        j = rand() % 3;
        if (board[i][j] == '-') {
            board[i][j] = 'O';
            break;
        }
    }
    return 0;
}

// main function
int main() {
    int i, j;
    char turn = 'X';
    int row, col;
    int is_tie = 0;
    init_board();
    printf("Welcome to Tic Tac Toe!\n");
    while (check_win() == '-' && is_tie == 0) {
        display_board();
        if (turn == 'X') {
            printf("Player X turn. Enter row and column: ");
            scanf("%d %d", &row, &col);
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row-1][col-1] == '-') {
                board[row-1][col-1] = 'X';
                turn = 'O';
            } else {
                printf("Invalid move.\n");
            }
        } else {
            printf("Player O turn.\n");
            if (ai_move()) {
                printf("AI moved.\n");
            } else {
                printf("AI could not find a good move, moved randomly.\n");
            }
            turn = 'X';
        }
        if (check_tie()) {
            is_tie = 1;
        }
    }
    display_board();
    if (check_win() != '-') {
        printf("Player %c won!\n", check_win());
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}