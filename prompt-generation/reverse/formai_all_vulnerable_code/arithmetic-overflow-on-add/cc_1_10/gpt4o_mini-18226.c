//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define MAX_NUM 75

// Function to initialize the Bingo card
void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int num, i, j;
    bool found;
    int colRange[BINGO_SIZE][2] = {
        {1, 15}, {16, 30}, {31, 45}, {46, 60}, {61, 75}
    };

    for (j = 0; j < BINGO_SIZE; j++) {
        found = true;
        int count = 0;

        // Generate unique numbers for each column
        while (count < BINGO_SIZE) {
            num = rand() % (colRange[j][1] - colRange[j][0] + 1) + colRange[j][0];
            found = true;

            // Check for duplicates
            for (i = 0; i < count; i++) {
                if (card[i][j] == num) {
                    found = false;
                    break;
                }
            }

            if (found) {
                card[count][j] = num;
                count++;
            }
        }
    }

    // Set the center space to a free space
    card[2][2] = 0; // Free space represented by 0
}

// Function to print the Bingo card
void printCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    printf("\nB   I   N   G   O\n");
    printf("---------------------\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] == 0)
                printf(" *  ");
            else
                printf("%2d  ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check for Bingo
bool checkBingo(int card[BINGO_SIZE][BINGO_SIZE], int marked[BINGO_SIZE][BINGO_SIZE]) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        if ((marked[i][0] && marked[i][1] && marked[i][2] && marked[i][3] && marked[i][4]) ||
            (marked[0][i] && marked[1][i] && marked[2][i] && marked[3][i] && marked[4][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((marked[0][0] && marked[1][1] && marked[2][2] && marked[3][3] && marked[4][4]) ||
        (marked[0][4] && marked[1][3] && marked[2][2] && marked[3][1] && marked[4][0])) {
        return true;
    }

    return false;
}

// Function to mark the called number on the card
void markNumber(int card[BINGO_SIZE][BINGO_SIZE], int marked[BINGO_SIZE][BINGO_SIZE], int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] == number) {
                marked[i][j] = 1;
            }
        }
    }
}

// Function to simulate a Bingo game
void playBingo() {
    int card[BINGO_SIZE][BINGO_SIZE] = {0};
    int marked[BINGO_SIZE][BINGO_SIZE] = {0};
    int calls[MAX_NUM] = {0};
    int np, number;

    initializeCard(card);
    printCard(card);

    // Initialize random number generator
    srand(time(NULL));

    printf("Let's start calling Bingo numbers!\n");
    while (1) {
        number = rand() % MAX_NUM + 1;

        // Check if the number has already been called
        if (calls[number - 1] == 0) {
            calls[number - 1] = 1; // Mark the number as called
            printf("Number called: %2d\n", number);
            markNumber(card, marked, number);
            printCard(card);

            // Check for Bingo
            if (checkBingo(card, marked)) {
                printf("Bingo! You've won!\n");
                break;
            } else {
                printf("No Bingo yet. Keep playing!\n");
            }

            // Avoid too many calls
            if (++np >= MAX_NUM) {
                printf("All numbers have been called without a Bingo!\n");
                break;
            }
        }
    }
}

// Main function to run the Bingo simulator
int main() {
    printf("Welcome to the Bingo Game!\n");
    playBingo();
    return 0;
}