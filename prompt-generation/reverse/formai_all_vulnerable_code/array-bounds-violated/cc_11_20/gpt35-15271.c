//FormAI DATASET v1.0 Category: Chess engine ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDEPTH 3
#define INFINITY 1000000

char board[8][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

int posValue[12] = {0, 100, 300, 317, 500, 900, 13000, -100, -300, -317, -500, -900};

int evaluate() {
    int whiteValue = 0;
    int blackValue = 0;

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            switch(board[i][j]) {
                case 'P': whiteValue += posValue[1] + (10 * (8 - i));
                          break;
                case 'N': whiteValue += posValue[2] + (10 * (8 - i));
                          break;
                case 'B': whiteValue += posValue[3] + (10 * (8 - i));
                          break;
                case 'R': whiteValue += posValue[4] + (10 * (8 - i));
                          break;
                case 'Q': whiteValue += posValue[5] + (10 * (8 - i));
                          break;
                case 'K': whiteValue += posValue[6] + (10 * (8 - i));
                          break;
                case 'p': blackValue -= posValue[1] + (10 * i);
                          break;
                case 'n': blackValue -= posValue[2] + (10 * i);
                          break;
                case 'b': blackValue -= posValue[3] + (10 * i);
                          break;
                case 'r': blackValue -= posValue[4] + (10 * i);
                          break;
                case 'q': blackValue -= posValue[5] + (10 * i);
                          break;
                case 'k': blackValue -= posValue[6] + (10 * i);
                          break;
            }
        }
    }

    return whiteValue + blackValue;
}

int negamax(int depth, int alpha, int beta) {
    if(depth == 0) {
        return evaluate();
    }

    int maxVal = -INFINITY;
    char temp[8][8];
    int val;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] != ' ') {
                for(int k = 0; k < 8; k++) {
                    for(int l = 0; l < 8; l++) {
                        if(board[i][j] == 'P') {
                            if(k == (i - 1) && (l == (j - 1) || l == (j + 1))) {
                                if(board[k][l] != ' ') {
                                    char taken = board[k][l];
                                    board[k][l] = board[i][j];
                                    board[i][j] = ' ';
                                    val = -negamax(depth - 1, -beta, -alpha);
                                    maxVal = (val > maxVal) ? val : maxVal;
                                    if(maxVal >= beta) {
                                        board[i][j] = board[k][l];
                                        board[k][l] = taken;
                                        return maxVal;
                                    }
                                    if(maxVal > alpha) {
                                        alpha = maxVal;
                                    }
                                    board[i][j] = board[k][l];
                                    board[k][l] = taken;
                                }
                            } else if(k == (i - 2) && j == l && i == 6) {
                                if(board[5][j] == ' ' && board[4][j] == ' ') {
                                    board[5][j] = board[i][j];
                                    board[i][j] = ' ';
                                    val = -negamax(depth - 1, -beta, -alpha);
                                    maxVal = (val > maxVal) ? val : maxVal;
                                    if(maxVal >= beta) {
                                        board[i][j] = board[5][j];
                                        board[5][j] = ' ';
                                        return maxVal;
                                    }
                                    if(maxVal > alpha) {
                                        alpha = maxVal;
                                    }
                                    board[i][j] = board[5][j];
                                    board[5][j] = ' ';
                                }
                            } else if(k == (i - 1) && j == l && board[k][l] == ' ') {
                                board[k][l] = board[i][j];
                                board[i][j] = ' ';
                                val = -negamax(depth - 1, -beta, -alpha);
                                maxVal = (val > maxVal) ? val : maxVal;
                                if(maxVal >= beta) {
                                    board[i][j] = board[k][l];
                                    board[k][l] = ' ';
                                    return maxVal;
                                }
                                if(maxVal > alpha) {
                                    alpha = maxVal;
                                }
                                board[i][j] = board[k][l];
                                board[k][l] = ' ';
                            }
                        }
                    }
                }
            }
        }
    }
    return maxVal;
}

void makeMove(char move[]) {
    int srcI = 8 - (move[1] - '0');
    int srcJ = move[0] - 'a';
    int destI = 8 - (move[3] - '0');
    int destJ = move[2] - 'a';
    board[destI][destJ] = board[srcI][srcJ];
    board[srcI][srcJ] = ' ';
}

void paranoidChess(int player) {
    char move[5];
    printf("Enter your move: ");
    scanf("%s", move);
    makeMove(move);
    int maxVal = -INFINITY;
    int val;
    char bestMove[5];
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] != ' ' && board[i][j] > 'a' == player) {
                for(int k = 0; k < 8; k++) {
                    for(int l = 0; l < 8; l++) {
                        if(board[i][j] == 'P') {
                            if(k == (i - 1) && (l == (j - 1) || l == (j + 1))) {
                                if(board[k][l] != ' ') {
                                    char taken = board[k][l];
                                    board[k][l] = board[i][j];
                                    board[i][j] = ' ';
                                    val = -negamax(MAXDEPTH - 1, -INFINITY, INFINITY);
                                    if(val > maxVal) {
                                        maxVal = val;
                                        bestMove[0] = j + 'a';
                                        bestMove[1] = '0' + (8 - i);
                                        bestMove[2] = l + 'a';
                                        bestMove[3] = '0' + (8 - k);
                                        bestMove[4] = '\0';
                                    }
                                    board[i][j] = board[k][l];
                                    board[k][l] = taken;
                                }
                            } else if(k == (i - 2) && j == l && i == 6) {
                                if(board[5][j] == ' ' && board[4][j] == ' ') {
                                    board[5][j] = board[i][j];
                                    board[i][j] = ' ';
                                    val = -negamax(MAXDEPTH - 1, -INFINITY, INFINITY);
                                    if(val > maxVal) {
                                        maxVal = val;
                                        bestMove[0] = j + 'a';
                                        bestMove[1] = '0' + (8 - i);
                                        bestMove[2] = l + 'a';
                                        bestMove[3] = '0' + (8 - k);
                                        bestMove[4] = '\0';
                                    }
                                    board[i][j] = board[5][j];
                                    board[5][j] = ' ';
                                }
                            } else if(k == (i - 1) && j == l && board[k][l] == ' ') {
                                board[k][l] = board[i][j];
                                board[i][j] = ' ';
                                val = -negamax(MAXDEPTH - 1, -INFINITY, INFINITY);
                                if(val > maxVal) {
                                    maxVal = val;
                                    bestMove[0] = j + 'a';
                                    bestMove[1] = '0' + (8 - i);
                                    bestMove[2] = l + 'a';
                                    bestMove[3] = '0' + (8 - k);
                                    bestMove[4] = '\0';
                                }
                                board[i][j] = board[k][l];
                                board[k][l] = ' ';
                            }
                        }
                    }
                }
            }
        }
    }
    makeMove(bestMove);
    printf("Computer moved %s\n", bestMove);
}

int main() {
    int player = 0;
    while(1) {
        if(player == 0) {
            paranoidChess(player);
            player = 1;
        } else {
            paranoidChess(player);
            player = 0;
        }
    }
    return 0;
}