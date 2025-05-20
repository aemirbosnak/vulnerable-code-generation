//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 24

void print_bingo_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void generate_bingo_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            card[i][j] = rand() % 15 + 1;
        }
    }
}

int check_bingo(int card[MAX_ROWS][MAX_COLS]) {
    int i, j, count = 0;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
    }
    return count == 0;
}

int main() {
    int bingo_cards[100][MAX_ROWS][MAX_COLS];
    int num_cards, i, j, k;
    srand(time(NULL));

    printf("Enter the number of bingo cards to generate: ");
    scanf("%d", &num_cards);

    for (i = 0; i < num_cards; i++) {
        generate_bingo_card(bingo_cards[i][0]);
    }

    int num_called = 0;
    while (num_called < MAX_NUMBERS) {
        int num = rand() % 15 + 1;
        if (num == 0) {
            num = 15;
        }
        printf("Number %d called\n", num);
        num_called++;
    }

    for (i = 0; i < num_cards; i++) {
        for (j = 0; j < MAX_ROWS; j++) {
            for (k = 0; k < MAX_COLS; k++) {
                if (bingo_cards[i][j][k] == num_called) {
                    bingo_cards[i][j][k] = 0;
                }
            }
        }
    }

    for (i = 0; i < num_cards; i++) {
        if (check_bingo(bingo_cards[i][0])) {
            printf("Bingo on card %d!\n", i + 1);
        }
    }

    return 0;
}