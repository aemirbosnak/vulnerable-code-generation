//Falcon-180B DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int player = 1;
    int choice;
    int flag = 0;
    int i, j;

    printf("Player 1: X and Player 2: O\n");
    printf("Player 1, choose your symbol:\n1. X\n2. O\n");
    scanf("%d", &choice);

    if (choice == 1) {
        player = 1;
    } else if (choice == 2) {
        player = 2;
    }

    while (flag == 0) {
        system("clear");
        printf("Player %d's Turn\n", player);
        printf("1. %d\n", board[0][0]);
        printf("2. %d\n", board[0][1]);
        printf("3. %d\n", board[0][2]);
        printf("\n");
        printf("4. %d\n", board[1][0]);
        printf("5. %d\n", board[1][1]);
        printf("6. %d\n", board[1][2]);
        printf("\n");
        printf("7. %d\n", board[2][0]);
        printf("8. %d\n", board[2][1]);
        printf("9. %d\n", board[2][2]);
        printf("\n");

        scanf("%d", &choice);
        i = choice / 3;
        j = choice % 3;

        if (board[i][j]!= 0) {
            printf("Sorry, the cell %d is already occupied.\n", choice);
        } else {
            board[i][j] = player;
            flag = 1;
        }

        system("clear");
        printf("Current board:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        if (flag == 1) {
            player++;
            if (player > 2) {
                player = 1;
            }
            flag = 0;
        }
    }

    if (player == 1) {
        printf("Player 2 wins!\n");
    } else {
        printf("Player 1 wins!\n");
    }

    return 0;
}