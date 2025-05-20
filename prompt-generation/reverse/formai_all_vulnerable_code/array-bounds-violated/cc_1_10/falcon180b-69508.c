//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS 8

void init_deck(char deck[][ROWS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            deck[i][j] = 'X';
        }
    }
}

void shuffle_deck(char deck[][ROWS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int rand_row = rand() % ROWS;
            int rand_col = rand() % COLS;
            char temp = deck[i][j];
            deck[i][j] = deck[rand_row][rand_col];
            deck[rand_row][rand_col] = temp;
        }
    }
}

void print_deck(char deck[][ROWS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", deck[i][j]);
        }
        printf("\n");
    }
}

void flip_card(char deck[][ROWS], int row, int col) {
    if (deck[row][col] == 'X') {
        deck[row][col] = 'O';
    } else if (deck[row][col] == 'O') {
        deck[row][col] = 'X';
    }
}

int main() {
    char deck[ROWS][COLS];
    init_deck(deck);
    shuffle_deck(deck);

    int player_score = 0;
    int computer_score = 0;

    while (player_score < TOTAL_CARDS || computer_score < TOTAL_CARDS) {
        print_deck(deck);
        int row, col;
        printf("Player's turn. Enter row and column: ");
        scanf("%d %d", &row, &col);
        flip_card(deck, row, col);
        if (deck[row][col] == 'O') {
            player_score++;
        } else {
            computer_score++;
        }
    }

    if (player_score > computer_score) {
        printf("Player wins!\n");
    } else if (computer_score > player_score) {
        printf("Computer wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}