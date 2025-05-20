//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to sleep for n milliseconds
void sleep(unsigned int n) {
    clock_t start_t = clock();
    while (clock() < start_t + n);
}

int main() {
    printf("Welcome to the Brave Bingo Simulator!\n");
    printf("Get ready to play some bingo!\n");

    // Initialize random number generator
    srand(time(NULL));

    // Initialize variables
    int numCalls = 0; // number of number calls
    int numWins = 0; // number of times player wins
    int numCards = 1; // number of cards to play with
    int cards[50][5][5]; // array to hold cards
    int calledNums[75]; // array to hold called numbers
    int currNum; // current called number

    // Initialize cards
    for (int cardIndex = 0; cardIndex < numCards; cardIndex++) {
        printf("Generating Card %d...\n", cardIndex + 1);
        // Initialize each card
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                // Make sure center square is free
                if (i == 2 && j == 2) {
                    cards[cardIndex][i][j] = 0;
                } else {
                    // Generate random number
                    int num;
                    do {
                        num = rand() % 15 + 1 + (15 * j);
                    } while (cards[cardIndex][0][num / 15] == num ||
                            cards[cardIndex][1][num / 15] == num ||
                            cards[cardIndex][2][num / 15] == num ||
                            cards[cardIndex][3][num / 15] == num ||
                            cards[cardIndex][4][num / 15] == num);
                    cards[cardIndex][i][j] = num;
                }
            }
        }
        // Print out each card
        printf("Card %d:\n", cardIndex + 1);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%2d | ", cards[cardIndex][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    // Main game loop
    while (numWins < numCards) {
        // Generate new number
        do {
            currNum = rand() % 75 + 1;
        } while (calledNums[currNum - 1] == 1);
        calledNums[currNum - 1] = 1;

        // Print out called number
        printf("Current Number: %d\n", currNum);
        // Iterate through each card to see if it has the number
        for (int cardIndex = 0; cardIndex < numCards; cardIndex++) {
            // Iterate through each number on the card
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (cards[cardIndex][i][j] == currNum) {
                        cards[cardIndex][i][j] = -1; // mark as found
                        printf("Card %d matched the number!\n", cardIndex + 1);
                    }
                }
            }
            // Check if card has a bingo
            int rowSum, colSum, diagSum, reverseDiagSum;
            for (int i = 0; i < 5; i++) {
                rowSum = 0, colSum = 0;
                for (int j = 0; j < 5; j++) {
                    // Check rows
                    if (cards[cardIndex][i][j] != -1) {
                        break;
                    } else {
                        rowSum++;
                    }
                    if (rowSum == 5) {
                        printf("Congratulations! Card %d has a bingo!\n", cardIndex + 1);
                        numWins++;
                    }
                    // Check columns
                    if (cards[cardIndex][j][i] != -1) {
                        break;
                    } else {
                        colSum++;
                    }
                    if (colSum == 5) {
                        printf("Congratulations! Card %d has a bingo!\n", cardIndex + 1);
                        numWins++;
                    }
                }
                // Check diagonals
                if (cards[cardIndex][i][i] == -1) {
                    diagSum++;
                }
                if (diagSum == 5) {
                    printf("Congratulations! Card %d has a bingo!\n", cardIndex + 1);
                    numWins++;
                }
                if (cards[cardIndex][i][4 - i] == -1) {
                    reverseDiagSum++;
                }
                if (reverseDiagSum == 5) {
                    printf("Congratulations! Card %d has a bingo!\n", cardIndex + 1);
                    numWins++;
                }
            }
        }
        // Sleep for 1 second before calling the next number
        sleep(1000);
    }

    printf("All cards have been won! Thanks for playing!\n");

    return 0;
}