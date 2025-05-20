//FormAI DATASET v1.0 Category: Poker Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max inclusive
int getRandomNumber(int min, int max) {
    static int initialized = 0;
    if(!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    return (rand() % (max - min + 1)) + min;
}

// Function to perform a single round of betting
int performBettingRound(int *playerChips, int *pot) {
    int bet;
    int maxBet = *playerChips;
    printf("The current pot is %d chips.\n", *pot);
    printf("You have %d chips.\n", *playerChips);
    printf("What do you want to bet (1-%d chips): ", maxBet);
    scanf("%d", &bet);
    if(bet < 1 || bet > maxBet) {
        printf("Invalid bet.\n");
        performBettingRound(playerChips, pot); // Recursive call to try again
    }
    else {
        *playerChips -= bet;
        *pot += bet;
    }
    return bet;
}

int main() {
    int playerChips = 100;
    int pot = 0;
    int playerCard1 = getRandomNumber(1, 13);
    int playerCard2 = getRandomNumber(1, 13);
    printf("Your cards are %d and %d.\n", playerCard1, playerCard2);
    int bet1 = performBettingRound(&playerChips, &pot);
    int dealerCard1 = getRandomNumber(1, 13);
    int dealerCard2 = getRandomNumber(1, 13);
    printf("The dealer's cards are %d and ????\n", dealerCard1);
    int bet2 = performBettingRound(&playerChips, &pot);
    printf("The dealer's second card is %d.\n", dealerCard2);
    if(dealerCard1 + dealerCard2 >= 17) {
        printf("Dealer stands.\n");
    }
    else {
        printf("Dealer takes another card.\n");
        int dealerCard3 = getRandomNumber(1, 13);
        printf("The dealer's third card is %d.\n", dealerCard3);
        if(dealerCard1 + dealerCard2 + dealerCard3 >= 17) {
            printf("Dealer stands.\n");
        }
        else {
            printf("Dealer takes another card.\n");
            int dealerCard4 = getRandomNumber(1, 13);
            printf("The dealer's fourth card is %d.\n", dealerCard4);
            if(dealerCard1 + dealerCard2 + dealerCard3 + dealerCard4 >= 17) {
                printf("Dealer stands.\n");
            }
            else {
                printf("Dealer takes another card.\n");
                int dealerCard5 = getRandomNumber(1, 13);
                printf("The dealer's fifth card is %d.\n", dealerCard5);
                if(dealerCard1 + dealerCard2 + dealerCard3 + dealerCard4 + dealerCard5 >= 17) {
                    printf("Dealer stands.\n");
                }
                else {
                    printf("Dealer busts!\n");
                    playerChips += pot;
                    printf("You win %d chips!\n", pot);
                    return 0;
                }
            }
        }
    }
    if(playerCard1 + playerCard2 > dealerCard1 + dealerCard2) {
        playerChips += pot;
        printf("You win %d chips!\n", pot);
    }
    else {
        printf("Dealer wins!\n");
    }
    return 0;
}