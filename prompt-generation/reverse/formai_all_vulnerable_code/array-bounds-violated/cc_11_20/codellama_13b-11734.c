//Code Llama-13B DATASET v1.0 Category: Bingo Simulator ; Style: Ada Lovelace
/*
* C Bingo Simulator Example Program
*
* This program simulates a Bingo game. It generates a random 5x5 matrix with
* numbers 1-25 and checks if any of the rows, columns, or diagonals have a
* matching pattern of numbers. If a match is found, the program prints the
* winning numbers and the winning pattern.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define BINGO_RANGE 25

int main() {
    int i, j, k;
    int matrix[BINGO_SIZE][BINGO_SIZE];
    int winning_numbers[BINGO_SIZE];
    int winning_pattern[BINGO_SIZE];

    // Initialize matrix with random numbers
    srand(time(NULL));
    for (i = 0; i < BINGO_SIZE; i++) {
        for (j = 0; j < BINGO_SIZE; j++) {
            matrix[i][j] = rand() % BINGO_RANGE + 1;
        }
    }

    // Check rows
    for (i = 0; i < BINGO_SIZE; i++) {
        for (j = 0; j < BINGO_SIZE; j++) {
            winning_numbers[j] = matrix[i][j];
        }
        if (check_pattern(winning_numbers, BINGO_SIZE)) {
            winning_pattern[0] = i + 1;
            for (j = 0; j < BINGO_SIZE; j++) {
                winning_pattern[j + 1] = winning_numbers[j];
            }
            break;
        }
    }

    // Check columns
    for (j = 0; j < BINGO_SIZE; j++) {
        for (i = 0; i < BINGO_SIZE; i++) {
            winning_numbers[i] = matrix[i][j];
        }
        if (check_pattern(winning_numbers, BINGO_SIZE)) {
            winning_pattern[0] = j + 1;
            for (i = 0; i < BINGO_SIZE; i++) {
                winning_pattern[i + 1] = winning_numbers[i];
            }
            break;
        }
    }

    // Check diagonals
    for (k = 0; k < 2; k++) {
        for (i = 0; i < BINGO_SIZE; i++) {
            winning_numbers[i] = matrix[i][i + k];
        }
        if (check_pattern(winning_numbers, BINGO_SIZE)) {
            winning_pattern[0] = i + 1;
            for (i = 0; i < BINGO_SIZE; i++) {
                winning_pattern[i + 1] = winning_numbers[i];
            }
            break;
        }
    }

    // Print winning pattern
    if (winning_pattern[0] > 0) {
        printf("Bingo! You have won the game!\n");
        printf("Winning pattern: ");
        for (i = 0; i < BINGO_SIZE; i++) {
            printf("%d ", winning_pattern[i]);
        }
        printf("\n");
    } else {
        printf("Sorry, no winning pattern was found.\n");
    }

    return 0;
}

// Function to check if a pattern is present in a given set of numbers
int check_pattern(int *numbers, int size) {
    int i, j;
    int pattern[BINGO_SIZE] = { 1, 2, 3, 4, 5 };

    for (i = 0; i < size - BINGO_SIZE; i++) {
        for (j = 0; j < BINGO_SIZE; j++) {
            if (numbers[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == BINGO_SIZE) {
            return 1;
        }
    }
    return 0;
}