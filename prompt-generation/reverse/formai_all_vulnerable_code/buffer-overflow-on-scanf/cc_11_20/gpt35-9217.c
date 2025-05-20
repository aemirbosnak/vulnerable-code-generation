//FormAI DATASET v1.0 Category: Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int money = 1000;
    int bet;
    int player_total = 0;
    int dealer_total = 0;
    int player_wins = 0;
    int dealer_wins = 0;
    int draws = 0;
    
    printf("Welcome to BlackJack!\n");
    printf("You have $%d.\n", money);
    
    while (money > 0) {
        printf("\nNew Round!\n");
        
        // get the player's bet
        printf("How much would you like to bet? ");
        scanf("%d", &bet);
        while (bet > money || bet <= 0) {
            printf("Invalid bet. Please enter a valid bet: ");
            scanf("%d", &bet);
        }
        
        // deal the player and dealer two cards each
        int card1 = rand() % 13 + 1;
        int card2 = rand() % 13 + 1;
        player_total = card1 + card2;
        printf("You have been dealt a %d and a %d.\n", card1, card2);
        
        card1 = rand() % 13 + 1;
        card2 = rand() % 13 + 1;
        dealer_total = card1 + card2;
        printf("The dealer's face-up card is a %d.\n", card1);
        
        // player's turn
        while (player_total < 21) {
            printf("Your total is %d. Would you like to hit or stay? ", player_total);
            char choice;
            scanf(" %c", &choice);
            if (choice == 'h') {
                int new_card = rand() % 13 + 1;
                printf("You have been dealt a %d.\n", new_card);
                player_total += new_card;
            } else {
                break;
            }
        }
        
        // dealer's turn, if player didn't bust
        if (player_total <= 21) {
            printf("\nDealer's turn.\n");
            while (dealer_total < 17) {
                int new_card = rand() % 13 + 1;
                printf("The dealer has been dealt a %d.\n", new_card);
                dealer_total += new_card;
            }
        }
        
        // compare the hands and determine the winner
        if (player_total > 21) {
            printf("You bust! Dealer wins.\n");
            dealer_wins++;
            money -= bet;
        } else if (dealer_total > 21) {
            printf("Dealer busts! You win.\n");
            player_wins++;
            money += bet;
        } else if (player_total > dealer_total) {
            printf("You win!\n");
            player_wins++;
            money += bet;
        } else if (dealer_total > player_total) {
            printf("Dealer wins.\n");
            dealer_wins++;
            money -= bet;
        } else {
            printf("It's a tie.\n");
            draws++;
        }
        
        // print out the stats
        printf("\nPlayer wins: %d\n", player_wins);
        printf("Dealer wins: %d\n", dealer_wins);
        printf("Ties: %d\n", draws);
        printf("Your total money: $%d\n", money);
    }
    
    printf("\nYou have no more money! Game over.\n");
    
    return 0;
}