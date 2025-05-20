//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5
#define MAX_NUMBERS 75

void generate_bingo_card(int card[NUM_ROWS][NUM_COLS], int num) {
    int row = 0, col = 0;
    for (int i = 1; i <= num; i++) {
        srand(time(NULL));
        int rand_row = rand() % NUM_ROWS;
        int rand_col = rand() % NUM_COLS;
        while (card[rand_row][rand_col]!= 0) {
            rand_row = rand() % NUM_ROWS;
            rand_col = rand() % NUM_COLS;
        }
        card[rand_row][rand_col] = i;
        if (row == NUM_ROWS - 1) {
            row = 0;
            col++;
        } else {
            row++;
        }
    }
}

void print_bingo_card(int card[NUM_ROWS][NUM_COLS]) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int check_win(int card[NUM_ROWS][NUM_COLS], int num) {
    int win = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (card[i][j] == num) {
                win = 1;
                break;
            }
        }
        if (win) {
            break;
        }
    }
    if (win) {
        printf("BINGO! ");
    }
    return win;
}

int main() {
    int num, card[NUM_ROWS][NUM_COLS];
    printf("Enter the number of numbers to generate: ");
    scanf("%d", &num);
    generate_bingo_card(card, num);
    printf("Your bingo card:\n");
    print_bingo_card(card);
    int win = 0;
    while (!win) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        win = check_win(card, num);
    }
    return 0;
}