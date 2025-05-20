//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define MAX_NUMBER 75

void initializeBingoCard(int card[BINGO_SIZE][BINGO_SIZE]);
void printBingoCard(int card[BINGO_SIZE][BINGO_SIZE]);
bool checkBingo(int card[BINGO_SIZE][BINGO_SIZE]);
void drawNumber(int* drawnNumbers, int* numberCount);
void displayDrawnNumbers(int* drawnNumbers, int numberCount);

int main() {
    srand(time(NULL)); // Seed for random number generation

    int bingoCard[BINGO_SIZE][BINGO_SIZE] = {0};
    int drawnNumbers[MAX_NUMBER] = {0};
    int numberCount = 0;
    char choice;

    // Initialize bingo card
    initializeBingoCard(bingoCard);

    // Main game loop
    do {
        printf("\n--- Your Bingo Card ---\n");
        printBingoCard(bingoCard);
        
        printf("\nWould you like to draw a number? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            drawNumber(drawnNumbers, &numberCount);
            displayDrawnNumbers(drawnNumbers, numberCount);
        }

        // Check for Bingo
        if (checkBingo(bingoCard)) {
            printf("BINGO! You've won!\n");
            break;
        }

    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}

void initializeBingoCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int columnRanges[5][2] = {
        {1, 15},  // B
        {16, 30}, // I
        {31, 45}, // N
        {46, 60}, // G
        {61, 75}  // O
    };

    for (int col = 0; col < BINGO_SIZE; col++) {
        int numbers[BINGO_SIZE] = {0};
        int index = 0;

        // Generate unique numbers for each column
        while (index < BINGO_SIZE) {
            int num = rand() % (columnRanges[col][1] - columnRanges[col][0] + 1) + columnRanges[col][0];
            bool unique = true;

            // Check for uniqueness
            for (int j = 0; j < index; j++) {
                if (numbers[j] == num) {
                    unique = false;
                    break;
                }
            }

            if (unique) {
                numbers[index++] = num;
            }
        }

        // Populating the card
        for (int row = 0; row < BINGO_SIZE; row++) {
            card[row][col] = numbers[row];
        }
    }

    // Set the free space in the center
    card[2][2] = 0; // Free space
}

void printBingoCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    printf(" B   I   N   G   O\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] == 0) { // Free space is marked as 'X'
                printf("[ X ] ");
            } else {
                printf("[%2d]  ", card[row][col]);
            }
        }
        printf("\n");
    }
}

bool checkBingo(int card[BINGO_SIZE][BINGO_SIZE]) {
    // Check rows
    for (int r = 0; r < BINGO_SIZE; r++) {
        if (card[r][0] == 0 && card[r][1] == 0 && card[r][2] == 0 && card[r][3] == 0 && card[r][4] == 0) {
            return true;
        }
    }

    // Check columns
    for (int c = 0; c < BINGO_SIZE; c++) {
        if (card[0][c] == 0 && card[1][c] == 0 && card[2][c] == 0 && card[3][c] == 0 && card[4][c] == 0) {
            return true;
        }
    }

    // Check diagonals
    if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0) {
        return true;
    }
    if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0) {
        return true;
    }

    return false;
}

void drawNumber(int* drawnNumbers, int* numberCount) {
    int number;

    while (true) {
        number = rand() % MAX_NUMBER + 1;
        // Ensure unique drawn number
        bool isUnique = true;
        for (int i = 0; i < *numberCount; i++) {
            if (drawnNumbers[i] == number) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            drawnNumbers[*numberCount] = number;
            (*numberCount)++;
            printf("Drawn Number: %d\n", number);
            break;
        }
    }
}

void displayDrawnNumbers(int* drawnNumbers, int numberCount) {
    printf("Drawn Numbers: ");
    for (int i = 0; i < numberCount; i++) {
        printf("%d ", drawnNumbers[i]);
    }
    printf("\n");
}