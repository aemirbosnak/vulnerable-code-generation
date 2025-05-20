//FormAI DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void create_board(int board[][BOARD_SIZE]) {
    int nums[BOARD_SIZE * BOARD_SIZE / 2];
    int index = 0;

    // Can only have half the number of spaces filled with values
    for (int i = 1; i <= BOARD_SIZE * BOARD_SIZE / 2; i++) {
        nums[index] = i;
        nums[index + 1] = i;
        index += 2;
    }

    srand(time(NULL));

    // Shuffle the nums array
    for (int i = BOARD_SIZE * BOARD_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Fill the board with values from nums array
    index = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = nums[index];
            index++;
        }
    }
}

void print_board(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void play_game(int board[][BOARD_SIZE]) {
    // Create a second board to keep track of which spots have been revealed
    int revealed[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            revealed[i][j] = 0;
        }
    }

    int num_revealed = 0;
    int first_row, first_col, second_row, second_col;

    while (num_revealed < BOARD_SIZE * BOARD_SIZE) {
        printf("Enter row and column of first card: ");
        scanf("%d %d", &first_row, &first_col);

        // If the card has already been revealed, ask user for input again
        while (revealed[first_row][first_col] == 1) {
            printf("That card has already been revealed. Enter row and column of first card: ");
            scanf("%d %d", &first_row, &first_col);
        }

        // Reveal the first card
        printf("First card: %d\n", board[first_row][first_col]);
        revealed[first_row][first_col] = 1;
        num_revealed++;

        printf("Enter row and column of second card: ");
        scanf("%d %d", &second_row, &second_col);

        // If the second card has already been revealed or is the same as the first card, ask user for input again
        while (revealed[second_row][second_col] == 1 || (first_row == second_row && first_col == second_col)) {
            printf("Invalid card. Enter row and column of second card: ");
            scanf("%d %d", &second_row, &second_col);
        }

        // Reveal the second card
        printf("Second card: %d\n", board[second_row][second_col]);
        revealed[second_row][second_col] = 1;
        num_revealed++;

        // Check if the two revealed cards match
        if (board[first_row][first_col] == board[second_row][second_col]) {
            printf("MATCH!\n");
        } else {
            printf("NO MATCH.\n");
            revealed[first_row][first_col] = 0;
            revealed[second_row][second_col] = 0;
        }
    }

    printf("Congratulations! You have uncovered all the cards.\n");
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    create_board(board);
    printf("Welcome to the Memory Game!\n");
    printf("Match all the pairs of numbers on the board.\n");
    print_board(board);
    play_game(board);

    return 0;
}