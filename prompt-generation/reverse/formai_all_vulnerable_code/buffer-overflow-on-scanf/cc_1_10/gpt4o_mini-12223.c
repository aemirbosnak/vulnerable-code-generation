//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_SIZE 5
#define MAX_NUM 75

void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]);
void printCard(int card[BINGO_SIZE][BINGO_SIZE]);
void drawNumber(int drawnNumbers[MAX_NUM]);
int checkBingo(int card[BINGO_SIZE][BINGO_SIZE]);
void markNumber(int card[BINGO_SIZE][BINGO_SIZE], int number);

int main() {
    int bingoCard[BINGO_SIZE][BINGO_SIZE];
    int drawnNumbers[MAX_NUM] = {0};
    char response;
    
    srand(time(NULL)); // Seed the random number generator

    // Initialize the Bingo card
    initializeCard(bingoCard);

    // Main game loop
    while (1) {
        printf("\nYour Bingo Card:\n");
        printCard(bingoCard);
        
        // Draw a number
        drawNumber(drawnNumbers);
        
        // Check for a winning condition
        if (checkBingo(bingoCard)) {
            printf("Bingo! You've won!\n");
            break;
        }

        // Ask if the player wants to continue
        printf("Do you want to continue playing? (y/n): ");
        scanf(" %c", &response);
        if (response == 'n') {
            printf("Thanks for playing! Your final card:\n");
            printCard(bingoCard);
            break;
        }
    }

    return 0;
}

// Function to initialize a Bingo card with random numbers
void initializeCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    int i, j, num;

    for (j = 0; j < BINGO_SIZE; j++) {
        int colStart = j * 15 + 1; // 1-15, 16-30, 31-45, 46-60, 61-75
        int colEnd = colStart + 14;
        int count = 0;

        while (count < BINGO_SIZE) {
            num = rand() % (colEnd - colStart + 1) + colStart; // Random number in column range
            int duplicate = 0;

            // Check for duplicates
            for (i = 0; i < count; i++) {
                if (card[i][j] == num) {
                    duplicate = 1;
                    break;
                }
            }

            if (!duplicate) {
                card[count][j] = num;
                count++;
            }
        }
    }
    card[2][2] = 0; // Center space is free
}

// Function to print the Bingo card
void printCard(int card[BINGO_SIZE][BINGO_SIZE]) {
    const char* headers[BINGO_SIZE] = {"B", "I", "N", "G", "O"};
    printf(" %s   %s   %s   %s   %s\n", headers[0], headers[1], headers[2], headers[3], headers[4]);
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] == 0) {
                printf(" *  "); // Marked by player's number (free space)
            } else {
                printf("%2d  ", card[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to draw a number and mark it on the Bingo card
void drawNumber(int drawnNumbers[MAX_NUM]) {
    int number;
    do {
        number = rand() % MAX_NUM + 1;
    } while (drawnNumbers[number - 1] != 0); // Avoid drawing the same number

    printf("Drew number: %d\n", number);
    drawnNumbers[number - 1] = 1; // Mark the number as drawn
}

// Function to check if the player has a Bingo
int checkBingo(int card[BINGO_SIZE][BINGO_SIZE]) {
    // Check rows
    for (int i = 0; i < BINGO_SIZE; i++) {
        int rowBingo = 1;
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] != 0) {
                rowBingo = 0;
                break;
            }
        }
        if (rowBingo) return 1; // Bingo found in row
    }

    // Check columns
    for (int j = 0; j < BINGO_SIZE; j++) {
        int colBingo = 1;
        for (int i = 0; i < BINGO_SIZE; i++) {
            if (card[i][j] != 0) {
                colBingo = 0;
                break;
            }
        }
        if (colBingo) return 1; // Bingo found in column
    }

    // Check diagonals
    int diagBingo1 = 1, diagBingo2 = 1;
    for (int i = 0; i < BINGO_SIZE; i++) {
        if (card[i][i] != 0) diagBingo1 = 0;    // Check primary diagonal
        if (card[i][BINGO_SIZE - 1 - i] != 0) diagBingo2 = 0; // Check secondary diagonal
    }
    if (diagBingo1 || diagBingo2) return 1; // Bingo found in diagonals
    
    return 0; // No Bingo
}

// Function to mark a drawn number on the Bingo card
void markNumber(int card[BINGO_SIZE][BINGO_SIZE], int number) {
    for (int i = 0; i < BINGO_SIZE; i++) {
        for (int j = 0; j < BINGO_SIZE; j++) {
            if (card[i][j] == number) {
                card[i][j] = 0; // Mark the number
            }
        }
    }
}