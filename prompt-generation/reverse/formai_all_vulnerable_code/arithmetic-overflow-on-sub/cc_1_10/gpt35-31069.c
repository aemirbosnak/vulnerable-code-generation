//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: ultraprecise
#include <stdio.h>

// Prototype functions
void show_board(char board[3][3]);
int check_win(char board[3][3], char player);
int alphabeta(char board[3][3], int depth, int alpha, int beta, int maximizing_player);
int minimax(char board[3][3]);

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int choice = 0, turn = 0, winner = 0;

    do {
        // Display the board
        printf("--------------\n");
        printf("     Tic Tac Toe    \n");
        printf("--------------\n");
        show_board(board);
        printf("--------------\n");

        // Ask player for input
        if (turn == 0) {
            do {
                printf("Please enter the cell number to place X (1-9): ");
                scanf("%d", &choice);
            } while (board[(choice-1) / 3][(choice-1) % 3] != ' ');
            board[(choice-1) / 3][(choice-1) % 3] = 'X';
        } else {
            choice = minimax(board);
            board[(choice-1) / 3][(choice-1) % 3] = 'O';
        }

        // Check if there is a winner
        winner = check_win(board, turn == 0 ? 'X' : 'O');
        turn = (turn + 1) % 2;
    } while (winner == 0);

    // Show the final board and winner
    show_board(board);
    printf("--------------\n");
    printf("      %c is the winner!\n", winner == 1 ? 'X' : 'O');

    return 0;
}

// Display the board
void show_board(char board[3][3]) {
    printf("   1   2   3\n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---|---|---\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---|---|---\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Check if a player has won
int check_win(char board[3][3], char player) {
    int i, j, count;

    // Check rows
    for (i = 0; i < 3; i++) {
        count = 0;
        for (j = 0; j < 3; j++) {
            if (board[i][j] == player) {
                count++;
            }
        }
        if (count == 3) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < 3; i++) {
        count = 0;
        for (j = 0; j < 3; j++) {
            if (board[j][i] == player) {
                count++;
            }
        }
        if (count == 3) {
            return 1;
        }
    }

    // Check diagonals
    count = 0;
    for (i = 0; i < 3; i++) {
        if (board[i][i] == player) {
            count++;
        }
    }
    if (count == 3) {
        return 1;
    }

    count = 0;
    for (i = 0; i < 3; i++) {
        if (board[i][2-i] == player) {
            count++;
        }
    }
    if (count == 3) {
        return 1;
    }

    // Check for tie
    count = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                count++;
            }
        }
    }
    if (count == 0) {
        return -1;
    }

    return 0;
}

// Alpha-beta pruning algorithm
int alphabeta(char board[3][3], int depth, int alpha, int beta, int maximizing_player) {
    int i, j, value, best_val;

    // Check if this is a leaf node
    int result = check_win(board, maximizing_player ? 'O' : 'X');
    if (result != 0) {
        if (result == 1) {
            return 10 - depth;
        } else if (result == -1) {
            return 0;
        } else {
            return depth - 10;
        }
    }

    // Recursive search for the best move
    best_val = maximizing_player ? -100 : 100;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = maximizing_player ? 'O' : 'X';
                value = alphabeta(board, depth+1, alpha, beta, !maximizing_player);
                board[i][j] = ' ';

                if (maximizing_player) {
                    if (value > best_val) {
                        best_val = value;
                        alpha = value;
                    }
                } else {
                    if (value < best_val) {
                        best_val = value;
                        beta = value;
                    }
                }
                if (alpha >= beta) {
                    return best_val;
                }
            }
        }
    }

    return best_val;
}

// Minimax algorithm
int minimax(char board[3][3]) {
    int i, j, value, best_val, best_move;

    best_val = -100;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                value = alphabeta(board, 1, -100, 100, 0);
                board[i][j] = ' ';
                if (value > best_val) {
                    best_val = value;
                    best_move = i*3 + j + 1;
                }
            }
        }
    }

    return best_move;
}