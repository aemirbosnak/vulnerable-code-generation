//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int board[8][8] = {
        /* initialize board with black and red pieces */
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };

    int player = 1; // 1 for black, -1 for red
    int turn = 1;
    int numMoves = 0;
    int redScore = 0;
    int blackScore = 0;

    while (turn <= 32) {
        printf("Turn %d\n", turn);
        printf("Black Score: %d\n", blackScore);
        printf("Red Score: %d\n", redScore);

        printf("Select a move (1-8): ");
        int move;
        scanf("%d", &move);

        if (board[move / 8][move % 8] == 1) {
            board[move / 8][move % 8] = -player;
            numMoves++;
        } else if (board[move / 8][move % 8] == -1) {
            board[move / 8][move % 8] = player;
            numMoves++;
        } else {
            printf("Invalid move. Try again.\n");
        }

        if (numMoves == 32) {
            if (player == 1) {
                blackScore += (numMoves / 8) + 1;
                printf("Black wins!\n");
            } else {
                redScore += (numMoves / 8) + 1;
                printf("Red wins!\n");
            }
            break;
        }

        if (player == 1) {
            player *= -1;
        } else {
            player *= -1;
        }
        turn++;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}