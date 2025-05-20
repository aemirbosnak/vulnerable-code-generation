//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 5
#define MAX_NUMBER 75
#define BINGO_CARD_COLUMNS 5

void initializeCard(int card[SIZE][SIZE]) {
    int columnBuffer[SIZE] = {0};
    for (int col = 0; col < BINGO_CARD_COLUMNS; col++) {
        int start = col * 15 + 1; // Column range start
        for (int row = 0; row < SIZE; row++) {
            int number;
            do {
                number = (rand() % 15) + start;
            } while (columnBuffer[number - start] != 0);
            columnBuffer[number - start] = 1; // Mark as used
            card[row][col] = number;
        }
        // Reset the buffer for the next column
        for (int i = 0; i < SIZE; i++) {
            columnBuffer[i] = 0;
        }
    }
    card[2][2] = 0; // Free space in the center
}

void printCard(int card[SIZE][SIZE]) {
    printf(" B   I   N   G   O\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (card[row][col] == 0) {
                printf(" *  ");
            } else {
                printf("%2d  ", card[row][col]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool checkWin(int card[SIZE][SIZE]) {
    // Check for horizontal and vertical wins
    for (int i = 0; i < SIZE; i++) {
        if (card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 && card[i][3] == 0 && card[i][4] == 0) {
            return true; // Horizontal Win
        }
        if (card[0][i] == 0 && card[1][i] == 0 && card[2][i] == 0 && card[3][i] == 0 && card[4][i] == 0) {
            return true; // Vertical Win
        }
    }
    // Check for diagonal wins
    if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0) {
        return true; // From top left to bottom right
    }
    if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0) {
        return true; // From top right to bottom left
    }
    return false;
}

void markNumber(int card[SIZE][SIZE], int number) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (card[row][col] == number) {
                card[row][col] = 0; // Mark the number as called
                return;
            }
        }
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    int bingoCard[SIZE][SIZE] = {0};
    initializeCard(bingoCard);
    
    printf("Welcome to Bingo Game!\n");
    printCard(bingoCard);
    
    int calledNumber;
    bool hasWon = false;

    while (!hasWon) {
        printf("Enter a number called (1-75) or -1 to quit: ");
        scanf("%d", &calledNumber);

        if (calledNumber == -1) {
            printf("Thanks for playing!\n");
            break;
        }

        if (calledNumber < 1 || calledNumber > MAX_NUMBER) {
            printf("Please enter a valid number between 1 and 75.\n");
            continue;
        }

        markNumber(bingoCard, calledNumber);
        printCard(bingoCard);

        hasWon = checkWin(bingoCard);
        if (hasWon) {
            printf("Congratulations! You have won Bingo!\n");
            break;
        }
    }

    return 0;
}