//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 15

int main() {
    srand(time(NULL));
    int bingo_cards[MAX_ROWS][MAX_COLS];
    int numbers[MAX_NUMBERS];
    int num_cards, num_numbers;
    int i, j, k, count;
    char choice;

    printf("Welcome to the Bingo Simulator!\n");
    printf("How many Bingo cards would you like to generate? ");
    scanf("%d", &num_cards);

    for (i = 0; i < num_cards; i++) {
        printf("Bingo Card %d:\n", i+1);
        for (j = 0; j < MAX_ROWS; j++) {
            for (k = 0; k < MAX_COLS; k++) {
                bingo_cards[j][k] = rand() % 100;
                printf("%d ", bingo_cards[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    printf("How many Bingo numbers would you like to call? ");
    scanf("%d", &num_numbers);

    for (i = 0; i < num_numbers; i++) {
        numbers[i] = rand() % 100;
        printf("Bingo number %d: %d\n", i+1, numbers[i]);
    }

    printf("Bingo game begins...\n");

    for (i = 0; i < num_numbers; i++) {
        for (j = 0; j < num_cards; j++) {
            for (k = 0; k < MAX_ROWS; k++) {
                if (bingo_cards[k][j] == numbers[i]) {
                    bingo_cards[k][j] = -1;
                }
            }
        }
    }

    printf("Bingo game ends...\n");

    for (i = 0; i < num_cards; i++) {
        count = 0;
        for (j = 0; j < MAX_ROWS; j++) {
            for (k = 0; k < MAX_COLS; k++) {
                if (bingo_cards[j][k]!= -1) {
                    count++;
                }
            }
        }
        if (count == 0) {
            printf("Bingo Card %d wins!\n", i+1);
        }
    }

    return 0;
}