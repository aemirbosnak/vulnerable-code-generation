//FormAI DATASET v1.0 Category: Poker Game ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(NULL));

    int playerCard1 = rand() % 13 + 1;
    int playerCard2 = rand() % 13 + 1;
    int dealerCard = rand() % 13 + 1;

    printf("Welcome to this Happy Poker Game!\n");
    printf("You got a %d and a %d.\n", playerCard1, playerCard2);
    printf("The dealer has a %d.\n", dealerCard);

    int playerTotal = playerCard1 + playerCard2;
    int dealerTotal = dealerCard;

    char hitOrStand;

    do {
        printf("Do you want to hit or stand? (h/s) ");
        scanf(" %c",&hitOrStand);

        if(hitOrStand == 'h') {
            int newCard = rand() % 13 + 1;
            playerTotal += newCard;
            printf("You got a %d.\n", newCard);
            printf("Your total is now %d.\n", playerTotal);
        } else {
            break;
        }

        if(playerTotal > 21) {
            printf("Bust! You lost.\n");
            return 0;
        }
    } while(hitOrStand == 'h');

    printf("Dealer's turn now.\n");

    while(dealerTotal < 17) {
        int newCard = rand() % 13 + 1;
        dealerTotal += newCard;
        printf("Dealer got a %d.\n", newCard);
        printf("Dealer's total is now %d.\n", dealerTotal);
    }

    if(dealerTotal > 21) {
        printf("Dealer busts! You win!\n");
    } else if(playerTotal > dealerTotal) {
        printf("You win!\n");
    } else if(playerTotal == dealerTotal) {
        printf("It's a tie!\n");
    } else {
        printf("Dealer wins!\n");
    }

    return 0;
}