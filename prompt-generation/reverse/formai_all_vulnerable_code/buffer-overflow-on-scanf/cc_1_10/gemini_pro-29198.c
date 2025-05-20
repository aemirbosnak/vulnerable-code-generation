//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define NUM_PAIRS 8

char board[BOARD_SIZE][BOARD_SIZE];
int pairs_found;


void print_board() {
    printf("  | 1 | 2 | 3 | 4 |\n");
    printf("---+---+---+---+---\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d | ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c | ", board[row][col]);
        }
        printf("\n");
    }
    printf("---+---+---+---+---\n");
}

int get_input() {
    int input;
    printf("Enter the coordinates of the card you want to flip (row, column): ");
    scanf("%d, %d", &input, &input);
    return input;
}

void flip_card(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = 'X';
    } else {
        board[row][col] = ' ';
    }
}

int check_for_pair(int row1, int col1, int row2, int col2) {
    if (board[row1][col1] == board[row2][col2]) {
        pairs_found++;
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(0));

    // Initialize the board
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = ' ';
        }
    }

    // Generate the random pairs
    for (int i = 0; i < NUM_PAIRS; i++) {
        int row1 = rand() % BOARD_SIZE;
        int col1 = rand() % BOARD_SIZE;
        int row2 = rand() % BOARD_SIZE;
        int col2 = rand() % BOARD_SIZE;
        while (row1 == row2 && col1 == col2) {
            row2 = rand() % BOARD_SIZE;
            col2 = rand() % BOARD_SIZE;
        }
        board[row1][col1] = 'A' + i;
        board[row2][col2] = 'A' + i;
    }

    // Game loop
    while (pairs_found < NUM_PAIRS) {
        print_board();
        int input1 = get_input();
        int row1 = input1 / 10 - 1;
        int col1 = input1 % 10 - 1;
        flip_card(row1, col1);
        print_board();
        int input2 = get_input();
        int row2 = input2 / 10 - 1;
        int col2 = input2 % 10 - 1;
        flip_card(row2, col2);
        if (check_for_pair(row1, col1, row2, col2)) {
            printf("You found a pair!\n");
        } else {
            printf("No match. Try again.\n");
        }
    }

    printf("Congratulations! You found all the pairs.\n");

    return 0;
}