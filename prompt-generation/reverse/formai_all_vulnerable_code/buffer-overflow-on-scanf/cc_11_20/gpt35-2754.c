//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // seed the random number generator

    int player_cards[10], dealer_cards[10]; // arrays to hold the cards
    int player_score = 0, dealer_score = 0; // variables to track scores
    int player_card_count = 0, dealer_card_count = 0;
    int game_over = 0;

    // deal the first two cards to the player and dealer
    player_cards[0] = rand() % 10 + 1; // draw a card between 1-10
    dealer_cards[0] = rand() % 10 + 1;
    player_cards[1] = rand() % 10 + 1;
    dealer_cards[1] = rand() % 10 + 1;

    player_card_count = 2;
    dealer_card_count = 2;

    // display the initial hands
    printf("Player's hand: %d %d\n", player_cards[0], player_cards[1]);
    printf("Dealer's hand: %d X\n", dealer_cards[0]);

    // player's turn
    while (!game_over)
    {
        char choice;
        printf("Hit or Stand? (h/s): ");
        scanf(" %c", &choice);

        if (choice == 'h') // player wants to hit
        {
            player_cards[player_card_count] = rand() % 10 + 1; // draw a card
            player_card_count++;
            player_score = 0;
            
            // calculate the new score
            for (int i = 0; i < player_card_count; i++)
            {
                player_score += player_cards[i];
            }

            // display the new hand and score
            printf("Player's hand: ");
            for (int i = 0; i < player_card_count; i++)
            {
                printf("%d ", player_cards[i]);
            }
            printf("\nPlayer's score: %d\n", player_score);

            if (player_score > 21) // bust
            {
                printf("Player busts! Dealer wins.\n");
                game_over = 1;
            }
        }
        else // player stands
        {
            printf("Player stands.\n");
            game_over = 1;
        }
    }

    // dealer's turn
    if (!game_over)
    {
        printf("Dealer's hand: %d %d\n", dealer_cards[0], dealer_cards[1]);
        while (dealer_score < 17) // dealer hits until score is at least 17
        {
            dealer_cards[dealer_card_count] = rand() % 10 + 1; // draw a card
            dealer_card_count++;
            dealer_score = 0;

            // calculate the new score
            for (int i = 0; i < dealer_card_count; i++)
            {
                dealer_score += dealer_cards[i];
            }

            // display the new hand and score
            printf("Dealer hits: %d\n", dealer_cards[dealer_card_count-1]);
            printf("Dealer's hand: ");
            for (int i = 0; i < dealer_card_count; i++)
            {
                printf("%d ", dealer_cards[i]);
            }
            printf("\nDealer's score: %d\n", dealer_score);

            if (dealer_score > 21) // bust
            {
                printf("Dealer busts! Player wins.\n");
                game_over = 1;
            }
        }

        if (!game_over) // neither player nor dealer busted
        {
            printf("Dealer stands.\n");
            printf("Player's score: %d\n", player_score);
            printf("Dealer's score: %d\n", dealer_score);

            if (player_score > dealer_score) // player wins
            {
                printf("Player wins!\n");
            }
            else if (dealer_score > player_score) // dealer wins
            {
                printf("Dealer wins!\n");
            }
            else // tie
            {
                printf("It's a tie!\n");
            }
        }
    }

    return 0;
}