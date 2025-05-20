//FormAI DATASET v1.0 Category: Table Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed
    int player_total, dealer_total;
    char hit_or_stand;
    
    // print game instructions
    printf("\nWelcome to C Table Game!\n\n");
    printf("Instructions:\n");
    printf("- The goal of the game is to get as close to 21 as possible without going over.\n");
    printf("- You will be playing against the dealer.\n");
    printf("- The dealer will deal you two cards to start.\n");
    printf("- You can hit (get another card) or stand (keep your current total).\n");
    printf("- If your total goes over 21, you lose.\n");
    printf("- If the dealer's total is higher than yours, you lose.\n");
    printf("- If the dealer's total goes over 21, you win.\n");
    printf("- Good luck!\n\n");
    
    // deal initial cards
    int card1 = rand() % 10 + 1;
    int card2 = rand() % 10 + 1;
    player_total = card1 + card2;
    
    printf("Your cards: %d %d\n", card1, card2);
    printf("Your total: %d\n\n", player_total);
    
    // dealer's turn
    int dealer_card1 = rand() % 10 + 1;
    int dealer_card2 = rand() % 10 + 1;
    dealer_total = dealer_card1 + dealer_card2;
    
    printf("Dealer's first card: %d\n", dealer_card1);
    
    while (dealer_total < 17)
    {
        // dealer hits if total is less than 17
        int dealer_new_card = rand() % 10 + 1;
        printf("Dealer hits and gets a %d\n", dealer_new_card);
        dealer_total += dealer_new_card;
    }
    
    printf("Dealer's total: %d\n\n", dealer_total);
    
    // player's turn
    do
    {
        printf("Do you want to hit or stand? (h/s): ");
        scanf(" %c", &hit_or_stand);
        
        if (hit_or_stand == 'h')
        {
            int player_new_card = rand() % 10 + 1;
            printf("You hit and get a %d\n", player_new_card);
            player_total += player_new_card;
            printf("Your total: %d\n\n", player_total);
        }
    } while (hit_or_stand != 's' && player_total < 21);
    
    // determine winner
    if (player_total > 21)
    {
        printf("You went over 21. You lose!\n");
    }
    else if (dealer_total > 21)
    {
        printf("The dealer went over 21. You win!\n");
    }
    else if (player_total > dealer_total)
    {
        printf("You beat the dealer. You win!\n");
    }
    else if (dealer_total > player_total)
    {
        printf("The dealer beat you. You lose!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
    
    return 0;
}