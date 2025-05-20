//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define BINGO_SIZE 5
#define MAX_PLAYERS 10

// Structure to represent a Bingo card
typedef struct {
    int card[BINGO_SIZE][BINGO_SIZE];
    bool marked[BINGO_SIZE][BINGO_SIZE];
} BingoCard;

// Function prototypes
void generateBingoCard(BingoCard* card);
void printBingoCard(BingoCard* card);
void callNumber(int* calledNumbers, int* count);
bool checkWinner(BingoCard* card);
void printWinners(int winners[], int numWinners);

int main() {
    int numPlayers, calledNumbers[75] = {0}, calledCount = 0;
    BingoCard players[MAX_PLAYERS];
    bool gameActive = true, winners[MAX_PLAYERS] = {false};
    
    srand(time(NULL)); // Seed for random number generation

    printf("Welcome to the C Bingo Simulator!\n");
    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    
    if(numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting game...\n");
        return 1;
    }

    // Generate Bingo cards for each player
    for (int i = 0; i < numPlayers; ++i) {
        generateBingoCard(&players[i]);
    }

    while (gameActive) {
        callNumber(calledNumbers, &calledCount);

        // Check if anyone has won
        for (int i = 0; i < numPlayers; ++i) {
            if (checkWinner(&players[i])) {
                winners[i] = true;
            }
        }

        // Check if there are any winners and print results
        int numWinners = 0;
        for (int i = 0; i < numPlayers; ++i) {
            if (winners[i]) {
                numWinners++;
            }
        }
        
        if (numWinners > 0) {
            printWinners(winners, numPlayers);
            gameActive = false; // End the game if there are winners
        }
    }

    return 0;
}

// Function to generate a Bingo card
void generateBingoCard(BingoCard* card) {
    int colStart[5] = {1, 16, 31, 46, 61}; // Start of each Bingo column
    int num;
    
    for (int col = 0; col < BINGO_SIZE; ++col) {
        int nums[15] = {0}; // Store unique numbers for the column
        // Generate column numbers ensuring uniqueness
        for (int j = 0; j < BINGO_SIZE; j++) {
            do {
                num = rand() % 15 + colStart[col];
            } while (nums[num - colStart[col]] != 0);

            nums[num - colStart[col]] = num; // Mark this number as used
            card->card[j][col] = num; // Assign to the Bingo card
            card->marked[j][col] = false; // Initialize marked status
        }
    }

    // Place a free space in the center
    card->card[2][2] = 0; // 0 represents free space
    card->marked[2][2] = true;
}

// Function to print the Bingo card
void printBingoCard(BingoCard* card) {
    printf(" B   I   N   G   O\n");
    for (int row = 0; row < BINGO_SIZE; ++row) {
        for (int col = 0; col < BINGO_SIZE; ++col) {
            if (card->marked[row][col]) {
                printf("[*] "); // Marked numbers
            } else {
                if (card->card[row][col] == 0) {
                    printf("[ ] "); // Free space
                } else {
                    printf("[%2d] ", card->card[row][col]);
                }
            }
        }
        printf("\n");
    }
}

// Function to call a random number and mark the Bingo cards
void callNumber(int* calledNumbers, int* count) {
    int number;
    do {
        number = rand() % 75 + 1; // Random number from 1 to 75
    } while (calledNumbers[number - 1] != 0); // Ensure not already called

    calledNumbers[number - 1] = number; // Mark this number as called
    *count += 1;

    printf("Number Called: %d\n", number);
}

// Function to check if the player has won
bool checkWinner(BingoCard* card) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        // Check rows and columns
        if ((card->marked[i][0] && card->marked[i][1] && card->marked[i][2] && card->marked[i][3] && card->marked[i][4]) ||
            (card->marked[0][i] && card->marked[1][i] && card->marked[2][i] && card->marked[3][i] && card->marked[4][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((card->marked[0][0] && card->marked[1][1] && card->marked[2][2] && card->marked[3][3] && card->marked[4][4]) ||
        (card->marked[0][4] && card->marked[1][3] && card->marked[2][2] && card->marked[3][1] && card->marked[4][0])) {
        return true;
    }

    return false;
}

// Function to print all winners
void printWinners(int winners[], int numWinners) {
    printf("Congratulations to the following winners:\n");
    for (int i = 0; i < numWinners; i++) {
        if (winners[i]) {
            printf("Player %d\n", i + 1);
        }
    }
}