//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8

void init_deck(char deck[][ROWS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            deck[i][j] = '*';
        }
    }
}

void shuffle_deck(char deck[][ROWS]) {
    int i, j, k;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            k = rand() % TOTAL_CARDS;
            deck[i][j] = deck[k/COLS][k%COLS];
            deck[k/COLS][k%COLS] = '*';
        }
    }
}

int check_match(char card1, char card2) {
    return (card1 == card2);
}

int main() {
    srand(time(0));
    char deck[ROWS][COLS];
    init_deck(deck);
    shuffle_deck(deck);

    int player_score = 0;
    int computer_score = 0;
    int current_player = 1;

    while (player_score < TOTAL_CARDS || computer_score < TOTAL_CARDS) {
        int row, col;
        printf("Player %d's turn\n", current_player);
        printf("Enter the row and column of the card you want to flip: ");
        scanf("%d%d", &row, &col);
        if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
            char card = deck[row][col];
            if (card == '*') {
                printf("You flipped over a blank card.\n");
            } else {
                printf("You flipped over the %c card.\n", card);
                if (current_player == 1) {
                    player_score++;
                } else {
                    computer_score++;
                }
                if (player_score == TOTAL_CARDS) {
                    printf("Player 1 wins!\n");
                    break;
                } else if (computer_score == TOTAL_CARDS) {
                    printf("Computer wins!\n");
                    break;
                }
            }
        } else {
            printf("Invalid input. Try again.\n");
        }
        if (current_player == 1) {
            current_player = 2;
        } else {
            current_player = 1;
        }
    }

    return 0;
}