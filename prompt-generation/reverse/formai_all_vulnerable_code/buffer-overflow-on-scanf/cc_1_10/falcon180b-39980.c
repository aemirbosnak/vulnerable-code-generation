//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define TOTAL_NUMBERS 24

void print_bingo_card(char card[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void generate_bingo_card(char card[ROWS][COLS]) {
    int i, j, num;
    srand(time(NULL));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            num = rand() % TOTAL_NUMBERS + 1;
            card[i][j] = num;
        }
    }
}

int main() {
    char bingo_card[ROWS][COLS];
    int i, j, user_input, found_bingo;

    generate_bingo_card(bingo_card);
    print_bingo_card(bingo_card);

    found_bingo = 0;
    while (!found_bingo) {
        printf("Enter a number: ");
        scanf("%d", &user_input);

        int row = user_input / COLS;
        int col = user_input % COLS;

        if (bingo_card[row][col] == user_input) {
            printf("Bingo!\n");
            found_bingo = 1;
        } else {
            printf("Sorry, that number is not on your card.\n");
        }
    }

    return 0;
}