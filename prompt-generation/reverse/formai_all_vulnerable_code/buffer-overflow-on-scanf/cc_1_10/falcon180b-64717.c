//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 75

void print_bingo_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void generate_bingo_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            card[i][j] = generate_random_number(1, MAX_NUMBERS);
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
    return count;
}

int main() {
    int bingo_card[MAX_ROWS][MAX_COLS];
    int player_input;
    srand(time(NULL));

    generate_bingo_card(bingo_card);
    print_bingo_card(bingo_card);

    while (1) {
        printf("Enter a number between 1 and %d: ", MAX_NUMBERS);
        scanf("%d", &player_input);

        int row = player_input / MAX_COLS;
        int col = player_input % MAX_COLS;

        if (bingo_card[row][col] == 0) {
            bingo_card[row][col] = player_input;
        } else {
            printf("Sorry, that number has already been called.\n");
        }

        if (check_bingo(bingo_card) == 0) {
            printf("Bingo!\n");
            break;
        }
    }

    return 0;
}