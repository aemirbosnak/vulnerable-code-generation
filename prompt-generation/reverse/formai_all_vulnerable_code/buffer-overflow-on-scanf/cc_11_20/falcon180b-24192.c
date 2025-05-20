//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 15

int main() {
    int bingo_cards[MAX_ROWS][MAX_COLS];
    int numbers[MAX_NUMBERS];
    int i, j, k, flag = 0, player_input;
    char choice;

    srand(time(NULL));

    printf("Welcome to Bingo!\n");
    printf("How many players? ");
    scanf("%d", &player_input);

    for (i = 0; i < player_input; i++) {
        for (j = 0; j < MAX_ROWS; j++) {
            for (k = 0; k < MAX_COLS; k++) {
                bingo_cards[j][k] = rand() % 100;
            }
        }
        printf("\nPlayer %d's card:\n", i + 1);
        for (j = 0; j < MAX_ROWS; j++) {
            for (k = 0; k < MAX_COLS; k++) {
                printf("%d ", bingo_cards[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("Enter your choice of numbers (1-99): ");
    scanf("%d", &choice);

    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % 100;
    }

    printf("The numbers are: ");
    for (i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    while (flag == 0) {
        for (i = 0; i < player_input; i++) {
            for (j = 0; j < MAX_ROWS; j++) {
                for (k = 0; k < MAX_COLS; k++) {
                    if (bingo_cards[j][k] == numbers[i]) {
                        bingo_cards[j][k] = -1;
                    }
                }
            }
        }
        flag = 1;
        for (j = 0; j < MAX_ROWS; j++) {
            for (k = 0; k < MAX_COLS; k++) {
                if (bingo_cards[j][k]!= -1) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
    }

    printf("\nBingo! Player %d wins!\n", i + 1);

    return 0;
}