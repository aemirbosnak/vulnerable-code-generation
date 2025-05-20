//Falcon2-11B DATASET v1.0 Category: Space Invaders Game Clone ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int score;
    int moves;
} Player;

int main() {
    Player playerA = {0, 0, 0, 0};
    Player playerB = {0, 0, 0, 0};

    int board[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int player = 1;
    int moves = 0;

    while (player <= 2) {
        printf("Player %d's turn\n", player);

        printf("Enter your move: ");
        int x, y;
        scanf("%d %d", &x, &y);

        if (x < 0 || x > 2 || y < 0 || y > 2) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (board[x][y]!= 0) {
            printf("Cell already occupied. Try again.\n");
            continue;
        }

        board[x][y] = 1;
        playerA.score += board[x][y];
        playerA.moves++;

        if (playerA.moves == 3) {
            player++;
            moves = 0;
            playerA.score = 0;
            playerA.moves = 0;
            printf("Player %d's score: %d\n", playerA.score, playerA.score);
        } else {
            moves++;
        }

        printf("Board: ");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}