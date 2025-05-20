//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

#define BINGO_PATTERN_1 "B I N G O\n"
#define BINGO_PATTERN_2 "B I N G O\n"
#define BINGO_PATTERN_3 "B I N G O\n"
#define BINGO_PATTERN_4 "B I N G O\n"
#define BINGO_PATTERN_5 "B I N G O\n"
#define BINGO_PATTERN_6 "B I N G O\n"
#define BINGO_PATTERN_7 "B I N G O\n"
#define BINGO_PATTERN_8 "B I N G O\n"
#define BINGO_PATTERN_9 "B I N G O\n"
#define BINGO_PATTERN_10 "B I N G O\n"
#define BINGO_PATTERN_11 "B I N G O\n"
#define BINGO_PATTERN_12 "B I N G O\n"
#define BINGO_PATTERN_13 "B I N G O\n"
#define BINGO_PATTERN_14 "B I N G O\n"
#define BINGO_PATTERN_15 "B I N G O\n"
#define BINGO_PATTERN_16 "B I N G O\n"
#define BINGO_PATTERN_17 "B I N G O\n"
#define BINGO_PATTERN_18 "B I N G O\n"
#define BINGO_PATTERN_19 "B I N G O\n"
#define BINGO_PATTERN_20 "B I N G O\n"

// Function to print the bingo pattern
void print_bingo_pattern(int row, int col) {
    int i, j;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            if (row == i && col == j) {
                printf("%s", BINGO_PATTERN_1);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to generate a random bingo card
void generate_bingo_card() {
    int i, j;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%d ", rand() % 25 + 1);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    int row, col;
    printf("Enter the row number: ");
    scanf("%d", &row);
    printf("Enter the column number: ");
    scanf("%d", &col);

    printf("Your bingo card is: \n");
    generate_bingo_card();

    print_bingo_pattern(row, col);

    return 0;
}