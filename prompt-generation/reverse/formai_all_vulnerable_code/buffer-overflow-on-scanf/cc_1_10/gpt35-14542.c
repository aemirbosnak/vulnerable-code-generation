//FormAI DATASET v1.0 Category: Table Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function declarations */
int rollDice();
int calculateSum(int dice1, int dice2, int dice3);


int main() {
    int playerSum, dealerSum;
    int playerWins = 0, dealerWins = 0;
    int roundNum = 1;
    char playAgain = 'y';
    
    printf("************ WELCOME TO C TABLE GAME! ************\n\n");
    
    /* Loop for the game rounds */
    while (playAgain == 'y' || playAgain == 'Y') {
        printf("ROUND %d\n", roundNum);
        
        /* Players roll the dice */
        printf("You are rolling the dice...\n");
        playerSum = calculateSum(rollDice(), rollDice(), rollDice());
        printf("You got %d!\n", playerSum);
        printf("Dealer is rolling the dice...\n");
        dealerSum = calculateSum(rollDice(), rollDice(), rollDice());
        printf("Dealer got %d!\n", dealerSum);
        
        /* Determine winner */
        if (playerSum > dealerSum) {
            printf("Congrats! You win!\n");
            playerWins++;
        } else if (playerSum == dealerSum) {
            printf("It's a tie!\n");
        } else {
            printf("Dealer wins. Better luck next time!\n");
            dealerWins++;
        }
        
        /* Display current score */
        printf("Current score:\n");
        printf("You: %d\n", playerWins);
        printf("Dealer: %d\n\n", dealerWins);
        
        /* Prompt for next round */
        printf("Do you want to play another round? (y/n) ");
        scanf(" %c", &playAgain);
        while (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
            printf("Invalid input. Please enter 'y' to play another round or 'n' to quit. ");
            scanf(" %c", &playAgain);
        }
        
        roundNum++; /* Increment round number */
    }
    
    printf("\n************ THANKS FOR PLAYING! ************\n");
    
    return 0;
}


/* Function for rolling dice */
int rollDice() {
    srand(time(NULL));
    return (rand() % 6) + 1;
}


/* Function for calculating sum of dice */
int calculateSum(int dice1, int dice2, int dice3) {
    return dice1 + dice2 + dice3;
}