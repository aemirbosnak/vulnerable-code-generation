//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define BALL_COUNT 75
#define BOARD_SIZE 5

typedef struct {
    int values[BOARD_SIZE][BOARD_SIZE];
    int marked[BOARD_SIZE][BOARD_SIZE];
} board;

void print_board(board* b) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%2d ", b->values[i][j]);
        }
        printf("\n");
    }
}

int check_win(board* b) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (b->marked[i][j]) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (b->marked[i][j]) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (b->marked[i][i]) {
            count1++;
        }
        if (b->marked[i][BOARD_SIZE - i - 1]) {
            count2++;
        }
    }
    if (count1 == BOARD_SIZE || count2 == BOARD_SIZE) {
        return 1;
    }

    return 0;
}

int main() {
    // Create the bingo board
    board b;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            b.values[i][j] = (i * BOARD_SIZE) + j + 1;
            b.marked[i][j] = 0;
        }
    }

    // Shuffle the bingo board
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        int r1 = rand() % BOARD_SIZE;
        int r2 = rand() % BOARD_SIZE;
        int temp = b.values[r1][r2];
        b.values[r1][r2] = b.values[i][i];
        b.values[i][i] = temp;
    }

    // Print the bingo board
    printf("Bingo board:\n");
    print_board(&b);

    // Draw the numbers
    int drawn_numbers[BALL_COUNT];
    for (int i = 0; i < BALL_COUNT; i++) {
        drawn_numbers[i] = 0;
    }

    int num_drawn = 0;
    while (num_drawn < BALL_COUNT) {
        int n = rand() % BALL_COUNT + 1;
        if (drawn_numbers[n] == 0) {
            drawn_numbers[n] = 1;
            printf("Number drawn: %d\n", n);

            // Mark the number on the board
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (b.values[i][j] == n) {
                        b.marked[i][j] = 1;
                    }
                }
            }

            // Check for a winner
            if (check_win(&b)) {
                printf("Bingo!\n");
                break;
            }

            num_drawn++;
        }
    }

    return 0;
}