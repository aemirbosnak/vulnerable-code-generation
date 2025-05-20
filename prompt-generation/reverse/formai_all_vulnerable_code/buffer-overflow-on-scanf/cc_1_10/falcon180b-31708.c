//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5
#define MAX_NUM 75

void print_bingo_card(int card[NUM_ROWS][NUM_COLS]) {
    int i, j;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void generate_bingo_card(int card[NUM_ROWS][NUM_COLS]) {
    int i, j;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            card[i][j] = rand() % MAX_NUM + 1;
        }
    }
}

int check_win(int card[NUM_ROWS][NUM_COLS]) {
    int i, j;
    int win = 0;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            if (card[i][j] == 0) {
                win = 1;
            }
        }
    }
    return win;
}

int main() {
    srand(time(NULL));
    int bingo_card[NUM_ROWS][NUM_COLS] = {{0}};
    generate_bingo_card(bingo_card);

    while (!check_win(bingo_card)) {
        int num;
        printf("Enter a number between 1 and %d: ", MAX_NUM);
        scanf("%d", &num);
        int row = rand() % NUM_ROWS;
        int col = rand() % NUM_COLS;
        if (bingo_card[row][col] == 0) {
            bingo_card[row][col] = num;
        } else {
            printf("That spot is already taken!\n");
        }
        print_bingo_card(bingo_card);
    }

    printf("Congratulations! You've won!\n");
    return 0;
}