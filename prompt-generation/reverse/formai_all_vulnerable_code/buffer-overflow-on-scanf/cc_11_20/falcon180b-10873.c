//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define TOTAL_NUMBERS 25
#define WILD_NUMBER -1

int main() {
    int bingo_cards[ROWS][COLS];
    int winning_card[ROWS][COLS];
    int i, j, k;
    int player_num, num;
    char choice;
    int flag = 0;

    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            num = rand() % TOTAL_NUMBERS + 1;
            while (num == WILD_NUMBER) {
                num = rand() % TOTAL_NUMBERS + 1;
            }
            bingo_cards[i][j] = num;
        }
    }

    printf("Welcome to Bingo!\n");
    printf("You have %d cards.\n", ROWS * COLS);

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", bingo_cards[i][j]);
        }
        printf("\n");
    }

    while (flag == 0) {
        printf("Press Y to play again or N to quit: ");
        scanf("%c", &choice);

        if (choice == 'Y' || choice == 'y') {
            int num_called = 0;

            while (num_called < TOTAL_NUMBERS) {
                num = rand() % TOTAL_NUMBERS + 1;
                while (num == WILD_NUMBER) {
                    num = rand() % TOTAL_NUMBERS + 1;
                }
                printf("%d ", num);
                for (i = 0; i < ROWS; i++) {
                    for (j = 0; j < COLS; j++) {
                        if (bingo_cards[i][j] == num) {
                            winning_card[i][j] = -1;
                        }
                    }
                }
                num_called++;
            }

            flag = 1;

            for (i = 0; i < ROWS; i++) {
                for (j = 0; j < COLS; j++) {
                    if (winning_card[i][j]!= -1) {
                        printf("%d ", winning_card[i][j]);
                    } else {
                        printf("- ");
                    }
                }
                printf("\n");
            }

            printf("You won!\n");
        } else {
            flag = 1;
        }
    }

    return 0;
}