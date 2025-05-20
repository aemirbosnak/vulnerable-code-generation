//FormAI DATASET v1.0 Category: Chess AI ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_DEPTH 4

const int pawn_table[64] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    10, 10, 0, -10, -10, 0, 10, 10,
    5, 0, 0, 5, 5, 0, 0, 5,
    0, 0, 10, 20, 20, 10, 0, 0,
    5, 5, 5, 10, 10, 5, 5, 5,
    10, 10, 10, 20, 20, 10, 10, 10,
    20, 20, 20, 30, 30, 20, 20, 20,
    0, 0, 0, 0, 0, 0, 0, 0
};

const int knight_table[64] = {
    0, -10, 0, 0, 0, 0, -10, 0,
    0, 0, 0, 5, 5, 0, 0, 0,
    0, 0, 10, 10, 10, 10, 0, 0,
    0, 0, 10, 20, 20, 10, 5, 0,
    5, 10, 15, 20, 20, 15, 10, 5,
    5, 10, 10, 20, 20, 10, 10, 5,
    0, 0, 5, 10, 10, 5, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

const int bishop_table[64] = {
    0, 0, -10, 0, 0, -10, 0, 0,
    0, 0, 0, 10, 10, 0, 0, 0,
    0, 0, 10, 15, 15, 10, 0, 0,
    0, 10, 15, 20, 20, 15, 10, 0,
    0, 10, 15, 20, 20, 15, 10, 0,
    0, 0, 10, 15, 15, 10, 0, 0,
    0, 0, 0, 10, 10, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

const int rook_table[64] = {
    0, 0, 5, 10, 10, 5, 0, 0,
    0, 0, 5, 10, 10, 5, 0, 0,
    0, 0, 5, 10, 10, 5, 0, 0,
    0, 0, 5, 10, 10, 5, 0, 0,
    0, 0, 5, 10, 10, 5, 0, 0,
    0, 0, 5, 10, 10, 5, 0, 0,
    25, 25, 25, 25, 25, 25, 25, 25,
    0, 0, 5, 10, 10, 5, 0, 0
};

const int queen_table[64] = {
    0, 0, 0, 5, 5, 0, 0, 0,
    0, 0, 5, 5, 5, 5, 0, 0,
    0, 0, 5, 10, 10, 5, 0, 0,
    0, 0, 5, 10, 10, 5, 0, 0,
    0, 0, 5, 5, 5, 5, 0, 0,
    0, 0, 0, 5, 5, 0, 0, 0,
    0, 0, 0, 5, 5, 0, 0, 0,
    0, 0, 0, 5, 5, 0, 0, 0
};

int evaluate_board(int board[8][8]) {
    int score = 0;
    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == 1) {
                score += 100 + pawn_table[i * 8 + j];
            } else if (board[i][j] == 2) {
                score -= 320 + knight_table[i * 8 + j];
            } else if (board[i][j] == 3) {
                score += 330 + bishop_table[i * 8 + j];
            } else if (board[i][j] == 4) {
                score += 500 + rook_table[i * 8 + j];
            } else if (board[i][j] == 5) {
                score += 900 + queen_table[i * 8 + j];
            } else if (board[i][j] == -1) {
                score -= 100 + pawn_table[(7-i) * 8 + (7-j)];
            } else if (board[i][j] == -2) {
                score += 320 + knight_table[(7-i) * 8 + (7-j)];
            } else if (board[i][j] == -3) {
                score -= 330 + bishop_table[(7-i) * 8 + (7-j)];
            } else if (board[i][j] == -4) {
                score -= 500 + rook_table[(7-i) * 8 + (7-j)];
            } else if (board[i][j] == -5) {
                score -= 900 + queen_table[(7-i) * 8 + (7-j)];
            }
        }
    }

    return score;
}

int minmax(int board[8][8], int depth, int alpha, int beta, int color) {
    if (depth == 0) {
        return evaluate_board(board);
    }

    int i, j, n, m, score, best_score;
    int new_board[8][8];

    best_score = color == 1 ? INT_MIN : INT_MAX;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((color == 1 && board[i][j] > 0) || (color == -1 && board[i][j] < 0)) {
                for (n = 0; n < 8; n++) {
                    for (m = 0; m < 8; m++) {
                        int piece = board[i][j];
                        if ((piece == 1 && n == 7) || (piece == -1 && n == 0)) {
                            continue;
                        }
                        if (piece == 1 && ((n - i == 2 && i == 1 && board[2][j] == 0 && board[3][j] == 0) || (n - i == 1 && board[n][j] == 0))) {
                            piece = 0;
                            new_board[n][j] = 1;
                        } else if (piece == -1 && ((i - n == 2 && i == 6 && board[5][j] == 0 && board[4][j] == 0) || (i - n == 1 && board[n][j] == 0))) {
                            piece = 0;
                            new_board[n][j] = -1;
                        } else {
                            new_board[n][j] = board[i][j];
                            new_board[i][j] = 0;
                        }

                        if (new_board[n][j] == 5 && color == -1 && depth == MAX_DEPTH) {
                            printf("Computer moved %c%d %c%d\n", 'a'+j, 8-i, 'a'+m, 8-n);
                        }

                        if (new_board[n][j] == -5 && color == 1 && depth == MAX_DEPTH) {
                            printf("Computer moved %c%d %c%d\n", 'a'+j, 8-i, 'a'+m, 8-n);
                        }

                        score = minmax(new_board, depth - 1, alpha, beta, color * -1);
                        if (color == 1 && score > best_score) {
                            best_score = score;
                            if (depth == MAX_DEPTH) {
                                printf("Computer moved %c%d %c%d\n", 'a'+j, 8-i, 'a'+m, 8-n);
                            }
                        } else if (color == -1 && score < best_score) {
                            best_score = score;
                        }

                        if (color == 1 && best_score > alpha) {
                            alpha = best_score;
                        } else if (color == -1 && best_score < beta) {
                            beta = best_score;
                        }

                        if (beta <= alpha) {
                            return best_score;
                        }

                        new_board[i][j] = piece;
                        new_board[n][j] = 0;
                    }
                }
            }
        }
    }

    return best_score;
}

int main(void) {
    int board[8][8] = {
        {-4, -2, -3, -5, -6, -3, -2, -4},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 0,  0,  0,  0,  0,  0,  0,  0},
        { 1,  1,  1,  1,  1,  1,  1,  1},
        { 4,  2,  3,  5,  6,  3,  2,  4}
    };

    int human_move = 0;
    int computer_move = 0;
    int score;

    printf("Welcome to Chess AI!\n\n");

    while (1) {
        printf("Enter your move (e.g. e2e4): ");
        scanf("%c%d%c%d", &human_move, &human_move, &computer_move, &computer_move);
        getchar();

        human_move = 8 - human_move;

        board[human_move][(int)(computer_move - 'a')] = 0;
        board[8 - computer_move][human_move] = 1;

        score = minmax(board, MAX_DEPTH, INT_MIN, INT_MAX, -1);
        printf("\nScore after computer move: %d\n", score);
    }

    return 0;
}