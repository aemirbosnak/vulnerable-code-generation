//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constants for bingo card size and number of balls in play
#define ROWS 5
#define COLS 5
#define NUM_BALLS 75

// Function prototype to generate random number within a range
int generateRandomNumber(int min, int max);

// Main function
int main(void) {
    // Set seed for random number generation
    srand(time(NULL));

    // Define and initialize 2D arrays for the player's bingo card and the called balls
    int playerCard[ROWS][COLS] = {0};
    bool calledBalls[NUM_BALLS] = {false};

    // Initialize variables for storing the player's name and number of matches
    char playerName[20];
    int numMatches = 0;

    // Prompt user for their name and greet them
    printf("Welcome to the C Bingo Simulator! Please enter your name: ");
    scanf("%s", playerName);
    printf("\nHi, %s! Let's start playing Bingo!\n", playerName);

    // Generate random numbers and fill the player's card with them
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Generate random number and check if it has already been added to the card
            int num;
            do {
                num = generateRandomNumber(j * 15 + 1, j * 15 + 15);
            } while (playerCard[i][j] == num);

            // Add number to player's card
            playerCard[i][j] = num;
        }
    }

    // Print the player's card
    printf("\nHere is your bingo card:\n\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (playerCard[i][j] < 10) {
                printf("  %d ", playerCard[i][j]);
            } else {
                printf(" %d ", playerCard[i][j]);
            }
        }
        printf("\n");
    }

    // Game loop
    while (numMatches < 5) {
        // Generate random number and check if it has already been called
        int num;
        bool alreadyCalled;
        do {
            num = generateRandomNumber(1, NUM_BALLS);
            alreadyCalled = calledBalls[num - 1];
        } while (alreadyCalled);

        // Mark ball as called and print it
        calledBalls[num - 1] = true;
        printf("\n%d\n", num);

        // Check if the called number matches any number on the player's card
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (playerCard[i][j] == num) {
                    playerCard[i][j] = 0;
                    numMatches++;

                    // Print message indicating a match was found
                    printf("\nCongratulations, %s! You have %d matches!\n", playerName, numMatches);

                    // Check if the player has Bingo
                    bool hasBingo = false;

                    // Check rows for Bingo
                    for (int i = 0; i < ROWS; i++) {
                        bool rowBingo = true;
                        for (int j = 0; j < COLS; j++) {
                            if (playerCard[i][j] != 0) {
                                rowBingo = false;
                                break;
                            }
                        }
                        if (rowBingo) {
                            hasBingo = true;
                            break;
                        }
                    }

                    // Check columns for Bingo
                    for (int j = 0; j < COLS; j++) {
                        bool colBingo = true;
                        for (int i = 0; i < ROWS; i++) {
                            if (playerCard[i][j] != 0) {
                                colBingo = false;
                                break;
                            }
                        }
                        if (colBingo) {
                            hasBingo = true;
                            break;
                        }
                    }

                    // Check diagonals for Bingo
                    if (playerCard[0][0] == 0 && playerCard[1][1] == 0 && playerCard[2][2] == 0 &&
                        playerCard[3][3] == 0 && playerCard[4][4] == 0) {
                        hasBingo = true;
                    }
                    if (playerCard[0][4] == 0 && playerCard[1][3] == 0 && playerCard[2][2] == 0 &&
                        playerCard[3][1] == 0 && playerCard[4][0] == 0) {
                        hasBingo = true;
                    }

                    // Print message if the player has Bingo
                    if (hasBingo) {
                        printf("\nBINGO! Congratulations, %s! You win!\n", playerName);
                        return 0;
                    }
                }
            }
        }
    }

    // Print message indicating all matches have been found but no Bingo
    printf("\nSorry, %s! You have found all the matches but did not get Bingo. Better luck next time!\n", playerName);

    return 0;
}

// Function to generate random number within a range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}