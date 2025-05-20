//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define MAX_NUMBER 75

typedef struct {
    int numbers[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

// Function to generate a Bingo card
void generateBingoCard(BingoCard *card) {
    int colRanges[5][2] = {
        {1, 15}, {16, 30}, {31, 45}, {46, 60}, {61, 75}
    };
    int number;
    for (int col = 0; col < BINGO_SIZE; col++) {
        int count = 0;
        while (count < BINGO_SIZE) {
            number = rand() % (colRanges[col][1] - colRanges[col][0] + 1) + colRanges[col][0];
            bool found = false;
            // Check if the number is already present in the column
            for (int row = 0; row < count; row++) {
                if (card->numbers[row][col] == number) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                card->numbers[count][col] = number;
                count++;
            }
        }
    }
    card->marked[2][2] = true; // Free space in the center
}

// Function to print Bingo card
void printBingoCard(const BingoCard *card) {
    printf(" B   I   N   G   O\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card->marked[row][col]) {
                printf(" *  ");
            } else {
                printf("%2d  ", card->numbers[row][col]);
            }
        }
        printf("\n");
    }
}

// Function to mark a number on the Bingo card
void markNumber(BingoCard *card, int number) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card->numbers[row][col] == number) {
                card->marked[row][col] = true;
                return;
            }
        }
    }
}

// Function to check for Bingo
bool checkBingo(const BingoCard *card) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        if ((card->marked[i][0] && card->marked[i][1] && card->marked[i][2] && 
             card->marked[i][3] && card->marked[i][4]) || 
            (card->marked[0][i] && card->marked[1][i] && card->marked[2][i] && 
             card->marked[3][i] && card->marked[4][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((card->marked[0][0] && card->marked[1][1] && 
         card->marked[2][2] && card->marked[3][3] && 
         card->marked[4][4]) ||
        (card->marked[0][4] && card->marked[1][3] && 
         card->marked[2][2] && card->marked[3][1] && 
         card->marked[4][0])) {
        return true;
    }
    return false;
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    BingoCard card;
    generateBingoCard(&card);
    printBingoCard(&card);

    while (1) {
        int drawnNumber;
        printf("\nEnter a number between 1 and 75 to mark it (-1 to exit): ");
        scanf("%d", &drawnNumber);
        if (drawnNumber == -1) {
            printf("Exiting the game.\n");
            break;
        }
        if (drawnNumber < 1 || drawnNumber > MAX_NUMBER) {
            printf("Invalid number, try again.\n");
            continue;
        }
        markNumber(&card, drawnNumber);
        printBingoCard(&card);

        if (checkBingo(&card)) {
            printf("Bingo! You won!\n");
            break;
        }
    }
    return 0;
}