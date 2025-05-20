//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5 // Bingo card size
#define BINGO_NUMBERS 75 // Total numbers in a standard Bingo game

// Function declarations
void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]);
void printCard(int card[BINGO_SIZE][BINGO_SIZE]);
void drawNumber(int drawnNumbers[BINGO_NUMBERS], int *drawCount);
bool checkWin(int card[BINGO_SIZE][BINGO_SIZE]);
void markCard(int card[BINGO_SIZE][BINGO_SIZE], int number);
int randomInt(int lower, int upper);

int main() {
    int bingoCard[BINGO_SIZE][BINGO_SIZE] = {0};
    int drawnNumbers[BINGO_NUMBERS] = {0};
    int drawCount = 0;
    char playAgain;

    srand(time(NULL));

    printf("Welcome to the Bingo Simulator!\n");
    
    do {
        // Initialize the Bingo card
        initializeCard(bingoCard);
        printCard(bingoCard);

        while (true) {
            // Draw a number
            drawNumber(drawnNumbers, &drawCount);
            printf("Number drawn: %d\n", drawnNumbers[drawCount - 1]);

            // Check and mark the Bingo card
            markCard(bingoCard, drawnNumbers[drawCount - 1]);
            printCard(bingoCard);

            // Check if there's a winner
            if (checkWin(bingoCard)) {
                printf("Bingo! You've won!\n");
                break;
            }

            // Ask if the user wants to continue
            printf("Do you want to continue? (y/n): ");
            scanf(" %c", &playAgain);
            if (playAgain == 'n' || playAgain == 'N') {
                printf("Thank you for playing!\n");
                return 0;
            }
        }
    } while (true);

    return 0;
}

// Initialize the Bingo card
void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int columnRanges[5][2] = {
        {1, 15},   // B
        {16, 30},  // I
        {31, 45},  // N
        {46, 60},  // G
        {61, 75}   // O
    };
    
    for (int col = 0; col < BINGO_SIZE; col++) {
        int randNumbers[BINGO_SIZE] = {0};
        for (int row = 0; row < BINGO_SIZE; row++) {
            int number;
            do {
                number = randomInt(columnRanges[col][0], columnRanges[col][1]);
            } while (randNumbers[number - columnRanges[col][0]] != 0);
            randNumbers[number - columnRanges[col][0]] = 1;
            card[row][col] = number;
        }
    }

    // Set the free space in the middle of the card
    card[2][2] = 0; // 0 represents free space
}

// Print the Bingo card
void printCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    printf("B   I   N   G   O\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] == 0)
                printf(" * ");
            else
                printf("%2d ", card[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

// Draw a random number
void drawNumber(int drawnNumbers[BINGO_NUMBERS], int *drawCount) {
    int number;
    do {
        number = randomInt(1, 75);
    } while (drawnNumbers[number - 1] != 0);
    
    drawnNumbers[number - 1] = number;
    (*drawCount)++;
}

// Check if there is a Bingo
bool checkWin(int card[BINGO_SIZE][BINGO_SIZE]) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        bool rowWin = true;
        bool colWin = true;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] != 0) rowWin = false;
            if (card[j][i] != 0) colWin = false;
        }
        if (rowWin || colWin) return true;
    }
    
    // Check diagonals
    bool diag1Win = true;
    bool diag2Win = true;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card[i][i] != 0) diag1Win = false; // Left to right diagonal
        if (card[i][BINGO_SIZE - 1 - i] != 0) diag2Win = false; // Right to left diagonal
    }
    return diag1Win || diag2Win;
}

// Mark the Bingo card
void markCard(int card[BINGO_SIZE][BINGO_SIZE], int number) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] == number) {
                card[row][col] = 0; // Mark the number as drawn
            }
        }
    }
}

// Function to generate a random integer between lower and upper bounds
int randomInt(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}