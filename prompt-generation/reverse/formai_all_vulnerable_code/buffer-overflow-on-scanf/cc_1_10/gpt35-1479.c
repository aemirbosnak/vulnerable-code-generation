//FormAI DATASET v1.0 Category: Chess AI ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_DEPTH 3

void evaluateBoard(int board[][8], int *whiteSum, int *blackSum)
{
    *whiteSum = *blackSum = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++) {
            int value = board[i][j];
            if (value == 0) continue;
            int absValue = abs(value);
            if (value > 0) {
                *whiteSum += absValue;
                *whiteSum += (absValue == 1) ? (10 - i) : 0;
            }
            else {
                *blackSum += absValue;
                *blackSum += (absValue == 1) ? (i + 1) : 0;
            }
        }
    }
}
int evaluate(int board[][8])
{
    int w, b;
    evaluateBoard(board, &w, &b);
    return w - b;
}
void copyBoard(int newBoard[][8], int oldBoard[][8])
{
    memcpy(newBoard, oldBoard, sizeof(int) * 64);
}
void inputBoard(int board[][8])
{
    printf("Enter board:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}
void printBoard(int board[][8])
{
    printf("Board:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%2d", board[i][j]);
        }
        printf("\n");
    }
}
void printMove(int *move, int depth)
{
    printf("MOVE(%d): %d%d->%d%d\n", depth, move[0], move[1], move[2], move[3]);
}
void humanInput(int board[][8], int *move)
{
    printf("Enter move (eg. a2a4): ");
    char movestr[5];
    scanf("%s", movestr);
    move[0] = movestr[0] - 'a';
    move[1] = 8 - (movestr[1] - '0');
    move[2] = movestr[2] - 'a';
    move[3] = 8 - (movestr[3] - '0');
}
int alphaBeta(int board[][8], int alpha, int beta, int depth, int maximisingPlayer, int *bestMove, int maxDepth)
{
    if (depth == maxDepth) {
        return evaluate(board);
    }
    int moves[32][4] = { 0 };
    int numMoves = 0;
    int player = maximisingPlayer ? 1 : -1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] * player < 0) continue;
            int piece = abs(board[i][j]);
            int direction = piece == 1 ? 1 : 8;
            int sign = piece > 0 ? 1 : -1;
            if (piece == 1) {
                int row = (player > 0) ? i + 1 : i - 1;
                if (board[row][j] == 0) {
                    moves[numMoves][0] = i;
                    moves[numMoves][1] = j;
                    moves[numMoves][2] = row;
                    moves[numMoves][3] = j;
                    numMoves++;
                    if ((player > 0 && i == 1) || (player < 0 && i == 6)) {
                        if (board[row + direction][j] == 0) {
                            moves[numMoves][0] = i;
                            moves[numMoves][1] = j;
                            moves[numMoves][2] = row + direction;
                            moves[numMoves][3] = j;
                            numMoves++;
                        }
                    }
                }
            }
            if (piece == 2 || piece == 4 || piece == 5 || piece == 6) {
                for (int a = -1; a <= 1; a++) {
                    for (int b = -1; b <= 1; b++) {
                        if (a == 0 && b == 0) continue;
                        if (piece != 2 && abs(a) != abs(b)) continue;
                        for (int k = 1; k <= 8; k++) {
                            int row = i + k * a;
                            int col = j + k * b;
                            if (row < 0 || col < 0 || row >= 8 || col >= 8) {
                                break;
                            }
                            if (board[row][col] == 0) {
                                moves[numMoves][0] = i;
                                moves[numMoves][1] = j;
                                moves[numMoves][2] = row;
                                moves[numMoves][3] = col;
                                numMoves++;
                            }
                            else {
                                if (abs(board[row][col]) * sign < 0) {
                                    moves[numMoves][0] = i;
                                    moves[numMoves][1] = j;
                                    moves[numMoves][2] = row;
                                    moves[numMoves][3] = col;
                                    numMoves++;
                                }
                                break;
                            }
                            if (piece == 2) break;
                        }
                    }
                }
            }
            if (piece == 3 || piece == 6) {
                int kLimit = piece == 3 ? 8 : 1;
                for (int k = 1; k <= kLimit; k++) {
                    for (int a = -1; a <= 1; a++) {
                        for (int b = -1; b <= 1; b++) {
                            if (a == 0 && b == 0) continue;
                            if (abs(a) != abs(b)) continue;
                            int row = i + k * a;
                            int col = j + k * b;
                            if (row < 0 || col < 0 || row >= 8 || col >= 8) continue;
                            if (board[row][col] == 0) {
                                moves[numMoves][0] = i;
                                moves[numMoves][1] = j;
                                moves[numMoves][2] = row;
                                moves[numMoves][3] = col;
                                numMoves++;
                            }
                            else {
                                if (abs(board[row][col]) * sign < 0) {
                                    moves[numMoves][0] = i;
                                    moves[numMoves][1] = j;
                                    moves[numMoves][2] = row;
                                    moves[numMoves][3] = col;
                                    numMoves++;
                                }
                                break;
                            }
                            if (piece == 3) break;
                        }
                    }
                }
            }
        }
    }
    if (numMoves == 0) {
        return maximisingPlayer ? -10000 : 10000;
    }
    int val, bestVal = maximisingPlayer ? -1000000 : 1000000;
    int len = numMoves;
    for (int i = 0; i < len; i++) {
        int move[4];
        memcpy(move, moves[i], 4 * sizeof(int));
        int boardCopy[8][8];
        copyBoard(boardCopy, board);
        boardCopy[move[2]][move[3]] = boardCopy[move[0]][move[1]];
        boardCopy[move[0]][move[1]] = 0;
        val = alphaBeta(boardCopy, alpha, beta, depth + 1, !maximisingPlayer, NULL, maxDepth);
        if (maximisingPlayer) {
            if (val > bestVal) {
                bestVal = val;
                if (bestMove != NULL) memcpy(bestMove, move, 4 * sizeof(int));
            }
            if (bestVal > alpha) alpha = bestVal;
        }
        else {
            if (val < bestVal) {
                bestVal = val;
                if (bestMove != NULL) memcpy(bestMove, move, 4 * sizeof(int));
            }
            if (bestVal < beta) beta = bestVal;
        }
        if (alpha > beta) break;
    }
    if (depth == 0 && bestMove != NULL) {
        printMove(bestMove, maxDepth);
    }
    return bestVal;
}

void playChess(int board[][8])
{
    printBoard(board);
    while (1) {
        int move[4] = { 0 };
        humanInput(board, move);
        int boardCopy[8][8];
        copyBoard(boardCopy, board);
        boardCopy[move[2]][move[3]] = boardCopy[move[0]][move[1]];
        boardCopy[move[0]][move[1]] = 0;
        printBoard(boardCopy);
        alphaBeta(boardCopy, -1000000, 1000000, 0, 0, move, MAX_DEPTH);
        board[move[2]][move[3]] = board[move[0]][move[1]];
        board[move[0]][move[1]] = 0;
        printBoard(board);
    }
}

int main()
{
    int board[8][8];
    inputBoard(board);
    playChess(board);
    return 0;
}