//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 5
#define BINGO 5
#define ROUNDS 100

void print_card(int card[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

int check_card(int card[SIZE][SIZE], int number) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (card[i][j] == number) {
                card[i][j] = 0;
                return 1;
            }
        }
    }
    return 0;
}

int check_bingo(int card[SIZE][SIZE]) {
    int count;

    // Check rows
    for (int i = 0; i < SIZE; i++) {
        count = 0;
        for (int j = 0; j < SIZE; j++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
        if (count == SIZE) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        count = 0;
        for (int j = 0; j < SIZE; j++) {
            if (card[j][i] == 0) {
                count++;
            }
        }
        if (count == SIZE) {
            return 1;
        }
    }

    // Check diagonals
    count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (card[i][i] == 0) {
            count++;
        }
    }
    if (count == SIZE) {
        return 1;
    }

    count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (card[i][SIZE - i - 1] == 0) {
            count++;
        }
    }
    if (count == SIZE) {
        return 1;
    }

    return 0;
}

int main() {
    int card[SIZE][SIZE];
    int numbers[SIZE * SIZE];
    int drawn_numbers[ROUNDS];
    int round, i, j, number, bingo;

    // Generate a random bingo card
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            card[i][j] = (i * SIZE) + j + 1;
        }
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            number = rand() % (SIZE * SIZE);
            card[i][j] ^= card[number][number];
            card[number][number] ^= card[i][j];
            card[i][j] ^= card[number][number];
        }
    }

    // Generate a list of random numbers
    for (i = 0; i < SIZE * SIZE; i++) {
        numbers[i] = i + 1;
    }
    for (i = 0; i < SIZE * SIZE; i++) {
        number = rand() % (SIZE * SIZE);
        numbers[i] ^= numbers[number];
        numbers[number] ^= numbers[i];
        numbers[i] ^= numbers[number];
    }

    // Play the bingo game
    bingo = 0;
    for (round = 0; round < ROUNDS && !bingo; round++) {
        number = numbers[round];
        drawn_numbers[round] = number;
        //printf("Round %d: Number %d\n", round + 1, number);
        bingo = check_bingo(card);
    }

    // Print the results
    if (bingo) {
        printf("Bingo on round %d with numbers:\n", round);
        for (i = 0; i <= round; i++) {
            printf("%d ", drawn_numbers[i]);
        }
        printf("\n");
        print_card(card);
    } else {
        printf("No bingo after %d rounds\n", ROUNDS);
    }

    return 0;
}