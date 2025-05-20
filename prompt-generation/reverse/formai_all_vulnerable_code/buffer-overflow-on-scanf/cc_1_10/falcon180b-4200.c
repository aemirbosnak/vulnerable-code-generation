//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_CARDS 25

void print_card(int card) {
    int row = card / COLS;
    int col = card % COLS;

    printf("  %d", row * 5 + col + 1);
}

void print_bingo_card(int card[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            print_card(i * COLS + j);
        }
        printf("\n");
    }
}

void generate_card(int card[ROWS][COLS]) {
    srand(time(0));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card[i][j] = rand() % MAX_CARDS + 1;
        }
    }
}

int check_win(int card[ROWS][COLS], int win_pattern[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j]!= win_pattern[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int card[ROWS][COLS];
    int win_pattern[ROWS][COLS] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};

    printf("Welcome to Cyberpunk Bingo!\n");
    printf("Generating your bingo card...\n");

    generate_card(card);
    print_bingo_card(card);

    int won = 0;

    while (!won) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);

        if (num >= 1 && num <= 25) {
            won = check_win(card, win_pattern);

            if (won) {
                printf("Congratulations! You won Cyberpunk Bingo!\n");
            }
        } else {
            printf("Invalid number.\n");
        }
    }

    return 0;
}