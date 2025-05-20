//Falcon-180B DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;
    int choice;
    int flag = 0;

    srand(time(0));

    while (flag == 0) {
        system("clear");
        printf("Player 1: X and Player 2: O\n");
        printf("Player %d's Turn\n", player);

        if (player % 2 == 0) {
            printf("Player 2's Turn\n");
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf(" %d ", board[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        choice = rand() % 9 + 1;

        if (board[choice / 3][choice % 3]!= 0) {
            flag = 1;
        } else {
            if (player % 2 == 0) {
                board[choice / 3][choice % 3] = 2;
            } else {
                board[choice / 3][choice % 3] = 1;
            }

            player++;

            if (player % 2 == 0) {
                player++;
            }
        }
    }

    if (player % 2 == 0) {
        printf("Player 2 Wins!\n");
    } else {
        printf("Player 1 Wins!\n");
    }

    return 0;
}