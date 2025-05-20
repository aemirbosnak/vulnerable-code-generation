//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BOARD_SIZE 8
#define MAX_PLY 1000
#define INF 999999

// Chess piece data structure
struct piece {
    int row;
    int col;
    char type;
};

int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE] = {0};
int ply = 0;
int alpha = -INF;
int beta = INF;

void printBoard(void) {
    printf("   a b c d e f g h\n");
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

void movePiece(int r, int c, char type) {
    board[r][c] = type;
}

int getPiece(int r, int c) {
    return board[r][c];
}

void generatePossibleMoves(int r, int c) {
    // Generate possible moves for this piece
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newR = r + i;
            int newC = c + j;

            // Check if the new position is valid
            if (newR >= 0 && newR < MAX_BOARD_SIZE && newC >= 0 && newC < MAX_BOARD_SIZE) {
                int pieceType = getPiece(newR, newC);

                // Check if the new position is empty
                if (pieceType == 0) {
                    movePiece(newR, newC, getPiece(r, c));
                    ply++;
                    generatePossibleMoves(newR, newC);
                    movePiece(newR, newC, 0);
                    ply--;
                }
            }
        }
    }
}

int evaluate(int r, int c) {
    int score = 0;

    // Evaluate the position of the piece
    if (getPiece(r, c) == 'P') {
        score = 1;
    } else if (getPiece(r, c) == 'N') {
        score = 3;
    } else if (getPiece(r, c) == 'B') {
        score = 3.5;
    } else if (getPiece(r, c) == 'R') {
        score = 5;
    } else if (getPiece(r, c) == 'Q') {
        score = 9;
    } else if (getPiece(r, c) == 'K') {
        score = 32;
    }

    // Check for potential checkmates
    if (getPiece(r, c) == 'K') {
        if (isCheckmate()) {
            score *= 100;
        } else if (isStalemate()) {
            score *= -100;
        }
    }

    return score;
}

int maxValue(int r, int c) {
    int value = evaluate(r, c);

    // Check if this move leads to a checkmate or stalemate
    if (isCheckmate()) {
        value *= 100;
    } else if (isStalemate()) {
        value *= -100;
    }

    // Alpha-beta pruning
    if (value > alpha) {
        alpha = value;
    }
    if (alpha >= beta) {
        return alpha;
    }

    return value;
}

int minValue(int r, int c) {
    int value = evaluate(r, c);

    // Check if this move leads to a checkmate or stalemate
    if (isCheckmate()) {
        value *= 100;
    } else if (isStalemate()) {
        value *= -100;
    }

    // Alpha-beta pruning
    if (value < beta) {
        beta = value;
    }
    if (alpha >= beta) {
        return beta;
    }

    return value;
}

int isCheckmate(void) {
    // Check for checkmate
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (getPiece(i, j) == 'K' && getPiece(i - 1, j) == 'K' && getPiece(i + 1, j) == 'K' && getPiece(i, j - 1) == 'K' && getPiece(i, j + 1) == 'K') {
                return true;
            }
        }
    }

    return false;
}

int isStalemate(void) {
    // Check for stalemate
    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (getPiece(i, j) == 'K' && getPiece(i - 1, j) == 'K' && getPiece(i + 1, j) == 'K' && getPiece(i, j - 1) == 'K' && getPiece(i, j + 1) == 'K') {
                return true;
            }
        }
    }

    return false;
}

int main(void) {
    int r = 0;
    int c = 0;
    char type;

    printf("Welcome to Chess AI!\n");
    printf("Select a move (a1-h8): ");
    scanf("%d %d %c", &r, &c, &type);
    movePiece(r, c, type);

    printBoard();

    int maxScore = -INF;
    int maxR = -1;
    int maxC = -1;

    int minScore = INF;
    int minR = -1;
    int minC = -1;

    for (int i = 0; i < MAX_BOARD_SIZE; i++) {
        for (int j = 0; j < MAX_BOARD_SIZE; j++) {
            if (getPiece(i, j) == 0) {
                ply = 0;
                generatePossibleMoves(i, j);
                ply--;

                int value = maxValue(i, j);
                if (value > maxScore) {
                    maxScore = value;
                    maxR = i;
                    maxC = j;
                }

                value = minValue(i, j);
                if (value < minScore) {
                    minScore = value;
                    minR = i;
                    minC = j;
                }
            }
        }
    }

    printf("AI's best move: (%d, %d) -> ", maxR, maxC);
    switch (getPiece(maxR, maxC)) {
        case 'P':
            printf("Pawn ");
            break;
        case 'N':
            printf("Knight ");
            break;
        case 'B':
            printf("Bishop ");
            break;
        case 'R':
            printf("Rook ");
            break;
        case 'Q':
            printf("Queen ");
            break;
        case 'K':
            printf("King ");
            break;
        default:
            printf("Invalid move ");
            break;
    }

    printf("\nAI's best move: (%d, %d)\n", minR, minC);
    switch (getPiece(minR, minC)) {
        case 'P':
            printf("Pawn ");
            break;
        case 'N':
            printf("Knight ");
            break;
        case 'B':
            printf("Bishop ");
            break;
        case 'R':
            printf("Rook ");
            break;
        case 'Q':
            printf("Queen ");
            break;
        case 'K':
            printf("King ");
            break;
        default:
            printf("Invalid move ");
            break;
    }

    printf("\n");
    return 0;
}