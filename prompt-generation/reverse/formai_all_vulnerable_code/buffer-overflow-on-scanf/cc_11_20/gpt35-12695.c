//FormAI DATASET v1.0 Category: Table Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_score, dealer_score;
    int player_cards[10], dealer_cards[10];
    int player_num_cards = 0, dealer_num_cards = 0;
    int card, i;
    char hit_or_stand;

    srand(time(0));

    // Deal initial cards to player and dealer
    player_cards[player_num_cards++] = rand() % 13 + 1;
    player_cards[player_num_cards++] = rand() % 13 + 1;
    dealer_cards[dealer_num_cards++] = rand() % 13 + 1;
    dealer_cards[dealer_num_cards++] = rand() % 13 + 1;

    // Print initial game state
    printf("Welcome to Cyberpunk Blackjack!\n");
    printf("You have been dealt the following cards:\n");
    printf("Card 1: %d\nCard 2: %d\n", player_cards[0], player_cards[1]);
    printf("Total: %d\n", player_cards[0] + player_cards[1]);
    printf("The dealer has one face-up card:\n");
    printf("Card: %d\n", dealer_cards[0]);

    // Player turn
    while (1) {
        printf("Do you want to hit (h) or stand (s)? ");
        scanf(" %c", &hit_or_stand);

        if (hit_or_stand == 'h') {
            card = rand() % 13 + 1;
            player_cards[player_num_cards++] = card;
            printf("You have been dealt a %d.\n", card);
            player_score = 0;
            for (i = 0; i < player_num_cards; i++) {
                player_score += player_cards[i];
            }
            printf("Total: %d\n", player_score);
            if (player_score > 21) {
                printf("You went bust! Dealer wins!\n");
                return 0;
            }
        }
        else if (hit_or_stand == 's') {
            printf("You have chosen to stand.\n");
            break;
        }
        else {
            printf("Invalid input. Please enter 'h' or 's'.\n");
        }
    }

    // Dealer turn
    dealer_score = dealer_cards[0] + dealer_cards[1];
    printf("The dealer reveals his face-down card: %d\n", dealer_cards[1]);
    while (dealer_score <= 16) {
        card = rand() % 13 + 1;
        dealer_cards[dealer_num_cards++] = card;
        printf("The dealer has been dealt a %d.\n", card);
        dealer_score = 0;
        for (i = 0; i < dealer_num_cards; i++) {
            dealer_score += dealer_cards[i];
        }
        printf("Dealer total: %d\n", dealer_score);
    }
    if (dealer_score > 21) {
        printf("The dealer went bust! You win!\n");
        return 0;
    }

    // Determine winner
    printf("Dealer total: %d\n", dealer_score);
    printf("Your total: %d\n", player_score);
    if (player_score > dealer_score) {
        printf("You win!\n");
    } else if (player_score == dealer_score) {
        printf("It's a tie!\n");
    } else {
        printf("Dealer wins!\n");
    }

    return 0;
}