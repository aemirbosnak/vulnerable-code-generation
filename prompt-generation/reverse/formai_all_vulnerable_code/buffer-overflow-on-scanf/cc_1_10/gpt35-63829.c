//FormAI DATASET v1.0 Category: Table Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    int playerPoints = 0, compPoints = 0;
    int playerCard1, playerCard2, compCard1, compCard2;
    char choice;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Print welcome message and instructions
    printf("Welcome to C Table Game!\n\n");
    printf("The goal of the game is to get as close to 21 points as possible without going over.\n");
    printf("You will be dealt two cards at the beginning, and you can choose to receive more cards or stop.\n");
    printf("After you make your choice, the computer will reveal its cards and draw more cards if necessary.\n");
    printf("The player with the highest number of points wins!\n\n");
    
    // Deal cards to player and computer
    playerCard1 = rand() % 11 + 1;
    playerCard2 = rand() % 11 + 1;
    compCard1 = rand() % 11 + 1;
    compCard2 = rand() % 11 + 1;
    playerPoints = playerCard1 + playerCard2;
    compPoints = compCard1 + compCard2;
    
    // Print player's cards and points
    printf("Your cards are: %d and %d\n", playerCard1, playerCard2);
    printf("Your total points are: %d\n\n", playerPoints);
    
    // Player's turn
    while (1) {
        // Ask for player's choice
        printf("Do you want to draw another card? (y/n) ");
        scanf(" %c", &choice);
        
        // Draw a card if player chooses to
        if (choice == 'y') {
            int card = rand() % 11 + 1;
            printf("You drew a %d\n", card);
            playerPoints += card;
            printf("Your total points are now: %d\n\n", playerPoints);
        }
        // Stop player's turn if they choose to or go over 21 points
        else {
            if (playerPoints > 21) {
                printf("You went over 21 points! You lose!\n");
                return 0;
            }
            else {
                printf("You chose to stop at %d points.\n\n", playerPoints);
                break;
            }
        }
    }
    
    // Computer's turn
    printf("The computer's cards are: %d and %d\n", compCard1, compCard2);
    printf("The computer's total points are: %d\n\n", compPoints);
    while (compPoints < 17) {
        int card = rand() % 11 + 1;
        printf("The computer drew a %d\n", card);
        compPoints += card;
        printf("The computer's total points are now: %d\n\n", compPoints);
    }
    
    // Determine winner
    if (compPoints > 21) {
        printf("The computer went over 21 points! You win!\n");
        return 0;   
    }
    else if (compPoints > playerPoints) {
        printf("The computer has %d points and you have %d points. You lose!\n", compPoints, playerPoints);
        return 0;
    }
    else if (playerPoints > compPoints) {
        printf("You have %d points and the computer has %d points. You win!\n", playerPoints, compPoints);
        return 0;
    }
    else {
        printf("You and the computer have the same number of points. It's a tie!\n");
        return 0;
    }
}