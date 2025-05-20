//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grateful Style C Table Game Example
// Developed by [Your Name Here]

int main() {
    // Set up the variables for the game
    int playerScore = 0, dealerScore = 0;
    char choice;

    // Display welcome message along with game rules
    printf("Welcome to the Grateful Style C Table Game!\n");
    printf("The goal is to get as close to 21 as possible without going over.\n");
    printf("Face cards are worth 10 points and an Ace is worth 11 or 1 point.\n");
    printf("Do you want to play? (y/n): ");
    scanf("%c", &choice);

    // Game loop starts here
    while(choice == 'y'){
        int playerCard1, playerCard2, dealerCard1, dealerCard2;

        // Generate random cards for player and dealer
        srand(time(NULL));
        playerCard1 = rand() % 11 + 1;
        playerCard2 = rand() % 11 + 1;
        dealerCard1 = rand() % 11 + 1;
        dealerCard2 = rand() % 11 + 1;

        // Display the cards for player and dealer
        printf("\nYour Cards: %d, %d", playerCard1, playerCard2);
        printf("\nDealer's Card: %d\n", dealerCard1);

        // Calculate the total scores for player and dealer
        playerScore = playerCard1 + playerCard2;
        dealerScore = dealerCard1 + dealerCard2;

        // Ask the player if they want to hit or stay
        printf("\nDo you want to hit or stay? (h/s): ");
        scanf(" %c", &choice);

        // Hit loop starts here
        while(choice == 'h'){
            int card = rand() % 11 + 1;
            playerScore += card;

            // Display the card for player and total score
            printf("\nYou drew a %d", card);
            printf("\nYour Score: %d", playerScore);

            // Check if player went over 21 and lost
            if(playerScore > 21){
                printf("\n\nYour Score: %d", playerScore);
                printf("\nDealer's Score: %d", dealerScore);
                printf("\nSorry, you went over 21! You lost!\n");
                // Ask the player if they want to play again
                printf("\nDo you want to play again? (y/n): ");
                scanf(" %c", &choice);
                break;
            }
            
            // Ask the player if they want to hit or stay
            printf("\nDo you want to hit or stay? (h/s): ");
            scanf(" %c", &choice);
        }

        // Dealer's turn starts here
        while(dealerScore < 17){
            int card = rand() % 11 + 1;
            dealerScore += card;

            // Display the card for dealer and total score
            printf("\nDealer drew a %d", card);
            printf("\nDealer's Score: %d", dealerScore);

            // Check if dealer went over 21 and player wins
            if(dealerScore > 21){
                printf("\n\nYour Score: %d", playerScore);
                printf("\nDealer's Score: %d", dealerScore);
                printf("\nCongratulations! Dealer went over 21, so you win!\n");
                // Ask the player if they want to play again
                printf("\nDo you want to play again? (y/n): ");
                scanf(" %c", &choice);
                break;
            }
        }

        // Check the scores and determine the winner
        if((dealerScore >= 17 && playerScore <= 21 && playerScore > dealerScore) || (dealerScore > 21 && playerScore <= 21)){
            printf("\n\nYour Score: %d", playerScore);
            printf("\nDealer's Score: %d", dealerScore);
            printf("\nCongratulations! You win!\n");
        }
        else if((playerScore <= 21 && dealerScore >= 17 && dealerScore > playerScore) || (playerScore > 21 && dealerScore <= 21)){
            printf("\n\nYour Score: %d", playerScore);
            printf("\nDealer's Score: %d", dealerScore);
            printf("\nSorry, you lost!\n");
        }
        else{
            printf("\n\nYour Score: %d", playerScore);
            printf("\nDealer's Score: %d", dealerScore);
            printf("\nIt's a tie!\n");
        }

        // Ask the player if they want to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("\nThank you for playing the Grateful Style C Table Game! Goodbye!\n");

    return 0;
}