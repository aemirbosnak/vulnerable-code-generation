//FormAI DATASET v1.0 Category: Poker Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random card number from 1 to 13
int random_card() {
    return (rand() % 13) + 1;
}

// function to print the player's cards
void print_cards(int p1_card1, int p1_card2) {
    printf("Your hand: %d and %d\n", p1_card1, p1_card2);
}

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // variables for player 1 cards and dealer cards
    int p1_card1, p1_card2, dealer_card1, dealer_card2;
    
    // deal the cards
    p1_card1 = random_card();
    p1_card2 = random_card();
    dealer_card1 = random_card();
    dealer_card2 = random_card();
    
    // print the player's cards
    print_cards(p1_card1, p1_card2);
    
    // ask if the player wants to hit or stay
    char choice;
    printf("Do you want to hit or stay? (h/s)\n");
    scanf(" %c", &choice);
    
    // if the player hits, deal another card
    int p1_total;
    if (choice == 'h') {
        int p1_card3 = random_card();
        printf("You drew a %d.\n", p1_card3);
        p1_total = p1_card1 + p1_card2 + p1_card3;
    } else {
        p1_total = p1_card1 + p1_card2;
    }
    
    // if the player's total is over 21, they bust and lose
    if (p1_total > 21) {
        printf("You went over 21! You lose.\n");
        return 0;
    }
    
    // print the dealer's cards
    printf("Dealer's hand: %d and ??\n", dealer_card1);
    
    // dealer hits until their total is 17 or higher
    int dealer_total;
    while (dealer_total < 17) {
        int dealer_card3 = random_card();
        dealer_total = dealer_card1 + dealer_card2 + dealer_card3;
        printf("Dealer drew a %d.\n", dealer_card3);
    }
    
    // reveal the dealer's second card and total
    printf("Dealer's second card was %d.\n", dealer_card2);
    dealer_total += dealer_card2;
    printf("Dealer's total is %d.\n", dealer_total);
    
    // determine the winner
    if (dealer_total > 21) {
        printf("Dealer busts! You win.\n");
    } else if (p1_total > dealer_total) {
        printf("You win!\n");
    } else if (p1_total < dealer_total) {
        printf("Dealer wins.\n");
    } else {
        printf("It's a tie!\n");
    }
    
    return 0;
}