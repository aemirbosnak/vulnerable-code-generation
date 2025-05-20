//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

// Function to initialize the bingo card
void init_card(int card[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            card[i][j] = rand() % MAX_NUM + 1;
        }
    }
}

// Function to print the bingo card
void print_card(int card[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a line is complete
int check_line(int card[ROWS][COLS], int row, int col) {
    int i;
    for (i = 0; i < COLS; i++) {
        if (card[row][i]!= card[row][col] && card[row][i]!= 0) {
            return 0;
        }
    }
    return 1;
}

// Function to check if the bingo is complete
int check_bingo(int card[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (card[i][j]!= 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));
    int card[ROWS][COLS];
    init_card(card);
    print_card(card);
    int row, col;
    while (1) {
        printf("Enter row and column to mark: ");
        scanf("%d %d", &row, &col);
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Invalid input.\n");
            continue;
        }
        if (card[row][col] == 0) {
            printf("This spot is already marked.\n");
            continue;
        }
        card[row][col] = 0;
        print_card(card);
        if (check_line(card, row, col)) {
            printf("Line complete!\n");
        }
        if (check_bingo(card)) {
            printf("Bingo!\n");
            break;
        }
    }
    return 0;
}