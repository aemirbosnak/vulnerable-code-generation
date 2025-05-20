//Falcon-180B DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    int **table;
    int *p;
    int i, j;
    int count = 0;
    int player;
    int pos;
    int flag = 0;
    int choice;
    int value;
    int r, c;
    int k = 0;
    int l;
    int posr, posc;
    int r1, c1, r2, c2;
    int x, y;
    int posx, posy;
    int score;

    srand(time(NULL));
    n = rand() % 5 + 3; // generates a random number between 3 and 7
    table = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        table[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            table[i][j] = 0;
        }
    }

    player = 1;
    do {
        printf("Player %d's turn\n", player);
        pos = 0;
        flag = 0;
        while (!flag) {
            printf("Enter your move: ");
            scanf("%d %d", &r, &c);
            if (table[r - 1][c - 1] == 0) {
                table[r - 1][c - 1] = player;
                flag = 1;
                pos = r * n + c;
            }
        }
        if (pos == 8 || pos == 9 || pos == 10 || pos == 11) {
            score = 10;
        } else if (pos == 12 || pos == 13 || pos == 14 || pos == 15) {
            score = 20;
        } else {
            score = 5;
        }
        printf("You scored %d points\n", score);
        count++;
        if (count % 2 == 0) {
            player = 2;
        } else {
            player = 1;
        }
    } while (count < 25);

    printf("Game over!\n");
    printf("Final score: Player 1: %d, Player 2: %d\n", count / 2, 25 - count / 2);

    for (i = 0; i < n; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}