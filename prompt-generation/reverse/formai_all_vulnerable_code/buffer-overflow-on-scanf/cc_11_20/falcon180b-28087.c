//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_players, i, j, k;
    char name[100];
    int bingo[5][5];
    int player_bingo[100][5][5];
    int flag = 0;
    int count = 0;

    printf("Enter number of players: ");
    scanf("%d", &num_players);

    printf("Enter your name: ");
    scanf("%s", name);

    srand(time(0));

    for (i = 0; i < num_players; i++) {
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                bingo[j][k] = rand() % 15 + 1;
            }
        }
        printf("\n%s's Bingo Card:\n", name);
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                printf("%d ", bingo[j][k]);
            }
            printf("\n");
        }
    }

    int num_called = 0;
    while (flag == 0 && num_called < 25) {
        int row, col;
        printf("\nEnter row and column to call: ");
        scanf("%d%d", &row, &col);
        if (row >= 0 && row < 5 && col >= 0 && col < 5) {
            for (i = 0; i < num_players; i++) {
                for (j = 0; j < 5; j++) {
                    for (k = 0; k < 5; k++) {
                        if (player_bingo[i][j][k] == bingo[row][col]) {
                            player_bingo[i][j][k] = -1;
                            count++;
                        }
                    }
                }
            }
            if (count == num_players) {
                flag = 1;
            }
            num_called++;
        } else {
            printf("Invalid input.\n");
        }
    }

    if (flag == 1) {
        printf("\n%s wins!\n", name);
    } else {
        printf("\nNo winner.\n");
    }

    return 0;
}