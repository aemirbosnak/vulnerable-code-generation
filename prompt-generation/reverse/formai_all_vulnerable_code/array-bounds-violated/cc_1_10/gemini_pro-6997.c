//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY   0
#define PLAYER1 1
#define PLAYER2 2
#define DRAW    3

#define SIZE 3

char board[SIZE][SIZE];
int player;
bool game_over;

void init_game() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
    player = PLAYER1;
    game_over = false;
}

void print_board() {
    printf("   1 2 3\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case PLAYER1:
                    printf("X");
                    break;
                case PLAYER2:
                    printf("O");
                    break;
            }
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("  ---+---+---\n");
        }
    }
}

int check_winner() {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return EMPTY;
}

int minimax(int depth, bool maximizing_player) {
    int winner = check_winner();
    if (winner != EMPTY) {
        if (winner == DRAW) {
            return 0;
        } else if (winner == player) {
            return 1;
        } else {
            return -1;
        }
    }

    int best_score;
    if (maximizing_player) {
        best_score = -100;
    } else {
        best_score = 100;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = player;
                int score = minimax(depth + 1, !maximizing_player);
                board[i][j] = EMPTY;
                if (maximizing_player) {
                    best_score = fmax(best_score, score);
                } else {
                    best_score = fmin(best_score, score);
                }
            }
        }
    }

    return best_score;
}

void make_move() {
    int best_score = -100;
    int best_move_i = -1;
    int best_move_j = -1;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = player;
                int score = minimax(0, false);
                board[i][j] = EMPTY;
                if (score > best_score) {
                    best_score = score;
                    best_move_i = i;
                    best_move_j = j;
                }
            }
        }
    }

    board[best_move_i][best_move_j] = player;
}

void play_game() {
    init_game();
    while (!game_over) {
        print_board();
        if (player == PLAYER1) {
            printf("Player 1's turn (X): ");
        } else {
            printf("Player 2's turn (O): ");
        }

        int row, col;
        scanf("%d %d", &row, &col);

        if (board[row - 1][col - 1] == EMPTY) {
            board[row - 1][col - 1] = player;
            int winner = check_winner();
            if (winner != EMPTY) {
                game_over = true;
                print_board();
                if (winner == DRAW) {
                    printf("Draw!\n");
                } else {
                    printf("Player %d wins!\n", winner);
                }
            } else {
                player = (player == PLAYER1) ? PLAYER2 : PLAYER1;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

int main() {
    play_game();
    return 0;
}