//FormAI DATASET v1.0 Category: Table Game ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

int playerScore = 0;
int dealerScore = 0;
int playerChoice = 1;
int card;
int round = 1;

// generate seed for random number generation using time as seed
srand(time(NULL));

// Starts the game with round 1
while(round ==1){
    printf("\nRound %d\n\n", round);
    printf("Dealing initial cards...\n\n");

    // Player receives two card values
    card = rand() % 11 + 1;
    playerScore += card;
    printf("Player card 1: %d\n", card);

    card = rand() % 11 + 1;
    playerScore += card;
    printf("Player card 2: %d\n\n", card);

    // Dealer receives one card value
    card = rand() % 11 + 1;
    dealerScore += card;
    printf("Dealer card: %d\n\n", card);

    // Player's turn
    while(playerChoice == 1){

        printf("Your current score: %d\n", playerScore);
        printf("Would you like to hit or stay? (1 for hit, 0 for stay): ");
        scanf("%d", &playerChoice);

        // Player takes another card if they choose to "hit"
        if(playerChoice == 1){

            card = rand() % 11 + 1;
            playerScore += card;
            printf("Player card: %d\n", card);

            // Check if player busts
            if(playerScore > 21){
                printf("\nPLAYER BUSTS!\n");
                printf("Dealer wins!\n\n");
                playerChoice = 0;
            }

        }

    }

    // Dealer's turn
    printf("Dealer reveals their face-down card...\n");
    printf("Dealer's current score: %d\n\n", dealerScore);

    while(dealerScore < 17){

        printf("Dealer takes another card...\n");
        card = rand() % 11 + 1;
        dealerScore += card;
        printf("Dealer card: %d\n", card);
        printf("Dealer's current score: %d\n\n", dealerScore);

        // Check if dealer busts
        if(dealerScore > 21){
            printf("\nDEALER BUSTS!\n");
            printf("Player wins!\n\n");
            playerChoice = 0;
        }

    }

    // Determine winner if neither player busts
    if(playerScore <= 21 && dealerScore <= 21){

        if(playerScore > dealerScore){
            printf("\nPLAYER WINS!\n");
            printf("Player score: %d\n", playerScore);
            printf("Dealer score: %d\n\n", dealerScore);
        }
        else if(playerScore < dealerScore){
            printf("\nDEALER WINS!\n");
            printf("Player score: %d\n", playerScore);
            printf("Dealer score: %d\n\n", dealerScore);
        }
        else{
            printf("\nTIE GAME!\n\n");
        }

    }

    // Ask player if they would like to play another round
    if(playerScore <= 21 && dealerScore <= 21){
        printf("Would you like to play another round? (1 for yes, 0 for no): ");
        scanf("%d", &round);
        playerChoice = 1;
        playerScore = 0;
        dealerScore = 0;
    }
    else{
        printf("Cannot play another round as a player has busted...\n\n");
        round = 0;
    }

}

printf("Thanks for playing!\n");

return 0;
}