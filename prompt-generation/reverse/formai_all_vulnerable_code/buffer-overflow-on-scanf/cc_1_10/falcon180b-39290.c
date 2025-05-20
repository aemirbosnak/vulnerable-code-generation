//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define BINGO 5

// Function to print the Bingo card
void print_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random number between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if a card has won
int check_win(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (card[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to mark a number on the card
void mark_number(int card[MAX_ROWS][MAX_COLS], int row, int col) {
    card[row][col] = 0;
}

// Function to generate a new Bingo card
void generate_card(int card[MAX_ROWS][MAX_COLS]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            card[i][j] = rand_int(1, 75);
        }
    }
}

int main() {
    srand(time(NULL));
    int card[MAX_ROWS][MAX_COLS];
    generate_card(card);
    print_card(card);
    int row, col, choice;
    while (1) {
        printf("\nEnter row and column to mark: ");
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= MAX_ROWS || col < 0 || col >= MAX_COLS) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        if (card[row][col] == 0) {
            printf("Number already marked. Try again.\n");
            continue;
        }
        mark_number(card, row, col);
        print_card(card);
        if (check_win(card)) {
            printf("\nCongratulations! You won!\n");
            break;
        }
    }
    return 0;
}