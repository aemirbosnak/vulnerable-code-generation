//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5

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
            card[i][j] = rand() % 15 + 1;
        }
    }
}

int check_winning_condition(int card[NUM_ROWS][NUM_COLS]) {
    int i, j, count = 0;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
    }
    return count == 0;
}

int main() {
    int player_cards[NUM_ROWS][NUM_COLS];
    int bingo_card[NUM_ROWS][NUM_COLS];
    int i, j, player_count = 0;

    srand(time(NULL));

    printf("Welcome to Bingo!\n");

    while (player_count < 2) {
        printf("Enter your name: ");
        scanf("%s", &player_cards[player_count][0]);
        player_count++;
    }

    generate_bingo_card(bingo_card);

    while (1) {
        printf("Current Bingo card:\n");
        print_bingo_card(bingo_card);

        int choice;
        printf("\nChoose a number between 1 and 15: ");
        scanf("%d", &choice);

        int row = (choice - 1) / NUM_COLS;
        int col = (choice - 1) % NUM_COLS;

        if (bingo_card[row][col] == 0) {
            bingo_card[row][col] = choice;
        } else {
            printf("Sorry, that number has already been called.\n");
        }

        if (check_winning_condition(bingo_card)) {
            printf("\nWe have a winner! %s has won!\n", &player_cards[0][0]);
            break;
        }
    }

    return 0;
}