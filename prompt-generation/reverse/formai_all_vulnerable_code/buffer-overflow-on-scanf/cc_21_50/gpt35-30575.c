//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0)); // Initialize random number generator
    
    printf("Welcome to the Bingo Simulator!\n\n");
    
    char paranoiaLevel[4]; // User-defined paranoia level
    
    printf("Choose your paranoia level (1-3): ");
    scanf("%s", paranoiaLevel);
    
    int maxBalls = 75;
    int ballsDrawn = 0;
    int numberCalled;
    int paranoidNumber;
    
    if (paranoiaLevel[0] == '1') {
        paranoidNumber = rand() % 11; // Generate paranoid number between 0 and 10
    } else if (paranoiaLevel[0] == '2') {
        paranoidNumber = rand() % 26; // Generate paranoid number between 0 and 25
    } else if (paranoiaLevel[0] == '3') {
        paranoidNumber = rand() % 51; // Generate paranoid number between 0 and 50
    }
    
    int bingoCard[5][5] = {0}; // Initialize bingo card
    
    printf("\nYour Bingo Card:\n");
    
    // Fill in bingo card with random numbers
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                bingoCard[i][j] = paranoidNumber; // Place paranoid number in center of card
            } else {
                bingoCard[i][j] = rand() % maxBalls + 1; // Generate random number between 1 and 75
            }
            printf("%d\t", bingoCard[i][j]);
        }
        printf("\n");
    }
    
    printf("\nLet's begin!\n\n");
    
    // Draw balls until someone gets Bingo
    while (1) {
        numberCalled = rand() % maxBalls + 1; // Generate random number between 1 and 75
        ballsDrawn++;
        printf("Ball #%d: %d\n", ballsDrawn, numberCalled);
        
        // Check if number is on user's bingo card
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (bingoCard[i][j] == numberCalled) {
                    bingoCard[i][j] = 0; // Mark number as called
                    printf("Your card has %d!\n", numberCalled);
                }
            }
        }
        
        // Check for Bingo
        int rowSum;
        int colSum;
        int diag1Sum = 0;
        int diag2Sum = 0;
        
        // Check rows
        for (int i = 0; i < 5; i++) {
            rowSum = 0;
            for (int j = 0; j < 5; j++) {
                rowSum += bingoCard[i][j];
            }
            if (rowSum == 0) {
                printf("\nBINGO! You won in %d balls!\n", ballsDrawn);
                return 0;
            }
        }
        
        // Check columns
        for (int j = 0; j < 5; j++) {
            colSum = 0;
            for (int i = 0; i < 5; i++) {
                colSum += bingoCard[i][j];
            }
            if (colSum == 0) {
                printf("\nBINGO! You won in %d balls!\n", ballsDrawn);
                return 0;
            }
        }
        
        // Check diagonals
        for (int i = 0; i < 5; i++) {
            diag1Sum += bingoCard[i][i];
            diag2Sum += bingoCard[i][4-i];
        }
        if (diag1Sum == 0 || diag2Sum == 0) {
            printf("\nBINGO! You won in %d balls!\n", ballsDrawn);
            return 0;
        }
        
        // Wait for user to press enter to continue
        printf("\nPress ENTER to continue.");
        while (getchar() != '\n'); // Clear input buffer
        getchar();
    }
    
    return 0;
}