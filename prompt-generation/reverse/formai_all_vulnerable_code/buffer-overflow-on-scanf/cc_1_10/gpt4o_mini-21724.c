//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define MAX_NUM 75

void initializeBingoCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int numbers[MAX_NUM + 1] = {0}; // Track used numbers
    srand(time(0));

    for (int col = 0; col < BINGO_SIZE; col++) {
        int min = col * 15 + 1;
        int max = min + 14;
        int count = 0;

        while (count < BINGO_SIZE) {
            int num = rand() % (max - min + 1) + min;
            if (numbers[num] == 0) { // Unique number
                card[count][col] = num;
                numbers[num] = 1;
                count++;
            }
        }
    }
    card[2][2] = 0; // Free space in the middle
}

void printBingoCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    printf("\n B   I   N   G   O\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] == 0) // Free space
                printf(" *  ");
            else
                printf("%2d  ", card[row][col]);
        }
        printf("\n");
    }
}

bool markNumber(int card[BINGO_SIZE][BINGO_SIZE], int num) {
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] == num) {
                card[row][col] = 0; // Mark it as called (0 for free space)
                return true;
            }
        }
    }
    return false;
}

bool checkWinner(int card[BINGO_SIZE][BINGO_SIZE]) {
    // Check rows and columns
    for (int i = 0; i < BINGO_SIZE; i++) {
        if ((card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 &&
             card[i][3] == 0 && card[i][4] == 0) ||
            (card[0][i] == 0 && card[1][i] == 0 && card[2][i] == 0 &&
             card[3][i] == 0 && card[4][i] == 0)) {
            return true;
        }
    }

    // Check diagonals
    if ((card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 &&
         card[3][3] == 0 && card[4][4] == 0) ||
        (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 &&
         card[3][1] == 0 && card[4][0] == 0)) {
        return true;
    }

    return false;
}

int main() {
    int bingoCard[BINGO_SIZE][BINGO_SIZE] = {0};
    int calledNumbers[MAX_NUM + 1] = {0};
    int randomNum;
    
    initializeBingoCard(bingoCard);
    printBingoCard(bingoCard);

    printf("\n----- Let the game begin! -----\n");

    while (true) {
        printf("\nCalling a number... ");
        do {
            randomNum = rand() % MAX_NUM + 1;
        } while (calledNumbers[randomNum]); // Choose unique numbers

        calledNumbers[randomNum] = 1;
        printf("Number called: %d\n", randomNum);
        
        if (markNumber(bingoCard, randomNum)) {
            printf("Marked on the card:\n");
            printBingoCard(bingoCard);
        } else {
            printf("Number %d is not on the card.\n", randomNum);
        }

        if (checkWinner(bingoCard)) {
            printf("\nCongratulations! You have a Bingo!\n");
            break;
        }

        char choice;
        printf("Continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y') {
            printf("Game Over!\n");
            break;
        }
    }
    return 0;
}