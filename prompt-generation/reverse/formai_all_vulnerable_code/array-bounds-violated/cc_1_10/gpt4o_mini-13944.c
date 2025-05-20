//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5

// Structure to represent a Bingo card
typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    int marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

// Function to initialize the card with random numbers
void initializeCard(BingoCard *bingoCard) {
    int nums[BINGO_SIZE * BINGO_SIZE] = {0};
    int numCount = 0;

    // Fill card with random unique numbers between 1 and 75
    while (numCount < BINGO_SIZE * BINGO_SIZE) {
        int num = (rand() % 75) + 1;
        if (!nums[num - 1]) { // Avoid duplicates
            nums[num - 1] = 1;
            bingoCard->card[numCount / BINGO_SIZE][numCount % BINGO_SIZE] = num;
            numCount++;
        }
    }

    // Initialize marked array
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            bingoCard->marked[i][j] = 0;
        }
    }
}

// Function to print the Bingo card
void printCard(BingoCard *bingoCard) {
    printf("B   I   N   G   O\n");
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (bingoCard->marked[i][j]) {
                printf("[*] ");
            } else {
                printf("[%d] ", bingoCard->card[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to mark a number on the card
void markNumber(BingoCard *bingoCard, int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (bingoCard->card[i][j] == number) {
                bingoCard->marked[i][j] = 1; // Mark the number
            }
        }
    }
}

// Function to check for Bingo
int checkBingo(BingoCard *bingoCard) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (bingoCard->marked[i][0] && bingoCard->marked[i][1] && bingoCard->marked[i][2] &&
            bingoCard->marked[i][3] && bingoCard->marked[i][4]) {
            return 1; // Row Bingo
        }
        if (bingoCard->marked[0][i] && bingoCard->marked[1][i] && bingoCard->marked[2][i] &&
            bingoCard->marked[3][i] && bingoCard->marked[4][i]) {
            return 1; // Column Bingo
        }
    }

    // Check diagonals
    if (bingoCard->marked[0][0] && bingoCard->marked[1][1] && bingoCard->marked[2][2] &&
        bingoCard->marked[3][3] && bingoCard->marked[4][4]) {
        return 1; // Diagonal Bingo
    }
    if (bingoCard->marked[0][4] && bingoCard->marked[1][3] && bingoCard->marked[2][2] &&
        bingoCard->marked[3][1] && bingoCard->marked[4][0]) {
        return 1; // Anti-Diagonal Bingo
    }

    return 0; // No Bingo
}

// Function to play the game
void playBingo() {
    BingoCard bingoCard;
    int numberDrawn;

    initializeCard(&bingoCard);
    srand(time(NULL));

    while (1) {
        printf("\nCurrent Bingo Card:\n");
        printCard(&bingoCard);

        // Draw a number
        numberDrawn = (rand() % 75) + 1;
        printf("Number Drawn: %d\n", numberDrawn);
        
        markNumber(&bingoCard, numberDrawn);

        if (checkBingo(&bingoCard)) {
            printf("BINGO! You won!\n");
            break;
        }

        // Pause for a moment before the next draw
        printf("Press Enter to continue...\n");
        getchar();
    }
}

int main() {
    printf("Welcome to the Bingo Simulator!\n");
    playBingo();
    return 0;
}