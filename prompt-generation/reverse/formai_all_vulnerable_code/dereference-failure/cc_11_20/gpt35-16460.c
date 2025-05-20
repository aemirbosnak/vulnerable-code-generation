//FormAI DATASET v1.0 Category: Chess AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 4

int evaluate_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    // evaluates the current board state and returns its score
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 'P') {
                score += 1;
            } else if (board[i][j] == 'N') {
                score += 3;
            } else if (board[i][j] == 'B') {
                score += 3;
            } else if (board[i][j] == 'R') {
                score += 5;
            } else if (board[i][j] == 'Q') {
                score += 9;
            } else if (board[i][j] == 'K') {
                score += 100;
            } else if (board[i][j] == 'p') {
                score -= 1;
            } else if (board[i][j] == 'n') {
                score -= 3;
            } else if (board[i][j] == 'b') {
                score -= 3;
            } else if (board[i][j] == 'r') {
                score -= 5;
            } else if (board[i][j] == 'q') {
                score -= 9;
            } else if (board[i][j] == 'k') {
                score -= 100;
            }
        }
    }
    return score;
}

int min_max(char board[BOARD_SIZE][BOARD_SIZE], int depth, bool is_maximizing_player) {
    // minimax recursive function to find best move
    if (depth == 0) {
        return evaluate_board(board);
    }
    if (is_maximizing_player) {
        int max_score = -10000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    continue;
                }
                // simulate move
                char piece = board[i][j];
                board[i][j] = ' ';
                board[i+1][j] = piece;
                // evaluate move recursively
                int score = min_max(board, depth - 1, !is_maximizing_player);
                // undo move
                board[i][j] = piece;
                board[i+1][j] = ' ';
                max_score = (score > max_score) ? score : max_score;
            }
        }
        return max_score;
    } else {
        int min_score = 10000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    continue;
                }
                // simulate move
                char piece = board[i][j];
                board[i][j] = ' ';
                board[i-1][j] = piece;
                // evaluate move recursively
                int score = min_max(board, depth - 1, !is_maximizing_player);
                // undo move
                board[i][j] = piece;
                board[i-1][j] = ' ';
                min_score = (score < min_score) ? score : min_score;
            }
        }
        return min_score;
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    int best_score = -10000;
    int move_i = 0;
    int move_j = 0;
    // evaluate all possible legal moves up to a certain depth
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                continue;
            }
            if (board[i][j] == 'P' || board[i][j] == 'p') {
                if (i == 1 || i == 6) { // double pawn move
                    if (board[i][j] == 'P') {
                        board[i][j] = ' ';
                        board[i+1][j] = 'P';
                        int score = min_max(board, MAX_DEPTH, false);
                        if (score > best_score) {
                            best_score = score;
                            move_i = i;
                            move_j = j;
                        }
                        board[i][j] = 'P';
                        board[i+1][j] = ' ';
                    } else {
                        board[i][j] = ' ';
                        board[i-1][j] = 'p';
                        int score = min_max(board, MAX_DEPTH, false);
                        if (score > best_score) {
                            best_score = score;
                            move_i = i;
                            move_j = j;
                        }
                        board[i][j] = 'p';
                        board[i-1][j] = ' ';
                    }
                }
            }
            // simulate move
            char piece = board[i][j];
            board[i][j] = ' ';
            board[i+1][j] = piece;
            // evaluate move recursively
            int score = min_max(board, MAX_DEPTH, false);
            // undo move
            board[i][j] = piece;
            board[i+1][j] = ' ';
            if (score > best_score) {
                best_score = score;
                move_i = i;
                move_j = j;
            }
        }
    }
    // make the best move
    printf("Best move: %c%d to %c%d\n", 'a'+move_j, 8-move_i, 'a'+move_j, 6-move_i);
    board[move_i][move_j] = ' ';
    board[move_i+1][move_j] = 'P';
    return 0;
}