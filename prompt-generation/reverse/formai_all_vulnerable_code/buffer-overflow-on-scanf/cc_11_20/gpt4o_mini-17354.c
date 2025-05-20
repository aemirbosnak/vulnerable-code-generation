//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PLAYERS 5
#define BINGO_SIZE 5
#define TOTAL_NUMBERS 75

void printCard(int card[BINGO_SIZE][BINGO_SIZE]);
bool checkBingo(int card[BINGO_SIZE][BINGO_SIZE]);

int main() {
    int players, bingoCards[MAX_PLAYERS][BINGO_SIZE][BINGO_SIZE] = {0};
    bool playerBingo[MAX_PLAYERS] = {false}; 
    int drawnNumbers[TOTAL_NUMBERS] = {0}; 
    int drawnCount = 0;
    
    printf("Welcome to the Multiplayer Bingo Simulator!\n");
    printf("Enter the number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &players);
    
    if (players < 1 || players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting!\n");
        return 1;
    }

    srand(time(NULL));

    for (int p = 0; p < players; p++) {
        printf("\nGenerating Bingo card for Player %d:\n", p + 1);
        // Generate Bingo card
        for (int col = 0; col < BINGO_SIZE; col++) {
            int numbers[15] = {0}; // To hold numbers for a column (1-15 range)
            int drawCount = 0;
            while (drawCount < BINGO_SIZE) {
                int num = rand() % 15 + col * 15 + 1; // Numbers according to the Bingo range
                bool found = false;
                for (int i = 0; i < drawCount; i++) {
                    if (numbers[i] == num) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    numbers[drawCount++] = num;
                    bingoCards[p][drawCount-1][col] = num; // Fill the Bingo card
                }
            }
        }
        printCard(bingoCards[p]);
    }

    // Bingo game loop
    while (drawnCount < TOTAL_NUMBERS) {
        int drawnNumber;
        do {
            drawnNumber = rand() % TOTAL_NUMBERS + 1;
        } while (drawnNumbers[drawnNumber - 1] == 1); // Ensure number is not drawn already
        drawnNumbers[drawnNumber - 1] = 1; // Mark this number as drawn
        drawnCount++;
        
        printf("\nDrawn number: %d\n", drawnNumber);
        
        for (int p = 0; p < players; p++) {
            for (int row = 0; row < BINGO_SIZE; row++) {
                for (int col = 0; col < BINGO_SIZE; col++) {
                    if (bingoCards[p][row][col] == drawnNumber) {
                        bingoCards[p][row][col] = -1; // Mark the number on the card
                    }
                }
            }

            if (checkBingo(bingoCards[p])) {
                printf("Player %d has BINGO!\n", p + 1);
                playerBingo[p] = true;
            }
        }
        
        if (playerBingo[0] || playerBingo[1] || playerBingo[2] || playerBingo[3] || playerBingo[4]) {
            printf("Game Over!\n");
            break;
        }
    }

    return 0;
}

void printCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    printf(" B   I   N   G   O\n");
    for (int row = 0; row < BINGO_SIZE; row++) {
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] < 0) {
                printf(" *  ");
            } else {
                printf("%2d  ", card[row][col]);
            }
        }
        printf("\n");
    }
}

bool checkBingo(int card[BINGO_SIZE][BINGO_SIZE]) {
    // Check rows for a Bingo
    for (int row = 0; row < BINGO_SIZE; row++) {
        bool bingo = true;
        for (int col = 0; col < BINGO_SIZE; col++) {
            if (card[row][col] != -1) {
                bingo = false;
                break;
            }
        }
        if (bingo) return true;
    }

    // Check columns for a Bingo
    for (int col = 0; col < BINGO_SIZE; col++) {
        bool bingo = true;
        for (int row = 0; row < BINGO_SIZE; row++) {
            if (card[row][col] != -1) {
                bingo = false;
                break;
            }
        }
        if (bingo) return true;
    }

    // Check diagonal (top-left to bottom-right)
    bool bingo = true;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card[i][i] != -1) {
            bingo = false;
            break;
        }
    }
    if (bingo) return true;

    // Check diagonal (top-right to bottom-left)
    bingo = true;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card[i][BINGO_SIZE - 1 - i] != -1) {
            bingo = false;
            break;
        }
    }
    return bingo;
}