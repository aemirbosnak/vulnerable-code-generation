//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLACK 1
#define WHITE 2

typedef struct {
    int row;
    int col;
    int player;
    int score;
} Piece;

int main() {
    srand(time(NULL));

    Piece board[8][8];

    int gameOver = 0;
    while (!gameOver) {
        printf("--------------------\n");
        printf("| %c %c %c %c | %c %c %c %c |\n", "12345678");
        printf("| %c %c %c %c | %c %c %c %c |\n", "12345678");
        printf("| %c %c %c %c | %c %c %c %c |\n", "12345678");
        printf("| %c %c %c %c | %c %c %c %c |\n", "12345678");
        printf("| %c %c %c %c | %c %c %c %c |\n", "12345678");
        printf("| %c %c %c %c | %c %c %c %c |\n", "12345678");
        printf("| %c %c %c %c | %c %c %c %c |\n", "12345678");
        printf("| %c %c %c %c | %c %c %c %c |\n", "12345678");
        printf("--------------------\n");
        printf("  0  1  2  3  4  5  6  7 \n");
        printf("  8  9 10 11 12 13 14 15 \n");
        printf("  16 17 18 19 20 21 22 23 \n");
        printf("  24 25 26 27 28 29 30 31 \n");
        printf("  32 33 34 35 36 37 38 39 \n");
        printf("  40 41 42 43 44 45 46 47 \n");
        printf("  48 49 50 51 52 53 54 55 \n");
        printf("  56 57 58 59 60 61 62 63 \n");
        printf("  64 65 66 67 68 69 70 71 \n");
        printf("  72 73 74 75 76 77 78 79 \n");
        printf("  80 81 82 83 84 85 86 87 \n");
        printf("  88 89 90 91 92 93 94 95 \n");
        printf("  96 97 98 99 A B C D \n");
        printf("--------------------\n");

        printf("Enter your move (row, column): ");
        int row, col;
        scanf("%d %d", &row, &col);

        if (row > 7 || col > 7) {
            printf("Invalid move, try again.\n");
            continue;
        }

        if (board[row][col].player!= 0) {
            printf("That piece is already in play, try again.\n");
            continue;
        }

        if (board[row][col].player == WHITE) {
            board[row][col].player = BLACK;
            board[row][col].score += 1;
            printf("Player %d made a move at (%d, %d), their score is now %d.\n", BLACK, row, col, board[row][col].score);
        } else {
            board[row][col].player = WHITE;
            board[row][col].score += 1;
            printf("Player %d made a move at (%d, %d), their score is now %d.\n", WHITE, row, col, board[row][col].score);
        }

        if (board[row][col].score == 64) {
            gameOver = 1;
            printf("Game over! Player %d wins!\n", board[row][col].player);
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                printf("%c ", (board[i][j].player == WHITE? 'W' : 'B'));
            }
            printf("\n");
        }
    }

    return 0;
}