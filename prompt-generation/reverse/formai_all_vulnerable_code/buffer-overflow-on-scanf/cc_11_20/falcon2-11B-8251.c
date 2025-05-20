//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int board[8][8] = {0};
    int player = 1;
    int turn = 0;
    int red = 0, black = 0;
    int i, j;

    printf("Welcome to Checkers!\n");
    printf("This is a two-player game with the following rules:\n");
    printf("1. Players alternate turns moving one piece per turn.\n");
    printf("2. A player may move one of their pieces one space in any direction, provided it is unoccupied.\n");
    printf("3. A player may capture an enemy piece by moving into a space immediately adjacent to it.\n");
    printf("4. A player may not move a piece onto a square occupied by an enemy piece.\n");
    printf("5. A player may not move a piece to a square occupied by one of their own pieces.\n");
    printf("6. A player wins the game by capturing all of the opponent's pieces.\n");
    printf("7. If a player cannot make a legal move, it is their opponent's turn.\n");
    printf("8. The game ends when a player has no legal moves remaining.\n");

    while (1) {
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move: ");
        scanf("%d %d", &i, &j);

        if (i < 0 || j < 0 || i > 7 || j > 7) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        if (board[i][j] == -1 || board[i][j] == 0) {
            board[i][j] = player;
            printf("Move accepted.\n");
            if (player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        } else {
            printf("Move not accepted. Try again.\n");
        }

        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                printf("%d", board[i][j]);
            }
            printf("\n");
        }

        if (red == black) {
            break;
        }

        red++;
        black++;
        if (red >= 100) {
            red = 0;
        }
        if (black >= 100) {
            black = 0;
        }
    }

    printf("\nGame over. Player %d wins!\n", red > black? red : black);

    return 0;
}