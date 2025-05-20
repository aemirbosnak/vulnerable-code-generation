//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_bingo_card(int card[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void generate_bingo_card(int card[ROWS][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            card[i][j] = rand() % 15 + 1;
        }
    }
}

int check_win(int card[ROWS][COLS]) {
    int i, j, k;
    int win = 0;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS - 4; j++) {
            for (k = 0; k < 5; k++) {
                if (card[i][j + k]!= card[i][j + k + 1] ||
                    card[i][j + k]!= card[i][j + k + 2] ||
                    card[i][j + k]!= card[i][j + k + 3] ||
                    card[i][j + k]!= card[i][j + k + 4]) {
                    win = 1;
                    break;
                }
            }
            if (win) break;
        }
        if (win) break;
    }

    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS - 4; j++) {
            for (k = 0; k < 5; k++) {
                if (card[j + k][i]!= card[j + k + 1][i] ||
                    card[j + k][i]!= card[j + k + 2][i] ||
                    card[j + k][i]!= card[j + k + 3][i] ||
                    card[j + k][i]!= card[j + k + 4][i]) {
                    win = 1;
                    break;
                }
            }
            if (win) break;
        }
        if (win) break;
    }

    return win;
}

int main() {
    int card[ROWS][COLS];
    int i, j;
    int win = 0;

    srand(time(NULL));

    generate_bingo_card(card);
    print_bingo_card(card);

    while (!win) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);

        int row = num / 5;
        int col = num % 5;

        if (card[row][col] == num) {
            card[row][col] = 0;
        } else {
            printf("Invalid number!\n");
        }

        win = check_win(card);
        if (win) {
            printf("Bingo! You win!\n");
        }
    }

    return 0;
}