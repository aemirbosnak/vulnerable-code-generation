//FormAI DATASET v1.0 Category: Table Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_hand[5], dealer_hand[5];
    char player_choice;
    int player_total, dealer_total;
    int i, j;

    srand(time(NULL));

    printf("Welcome to the Cyberpunk Blackjack table.\n\n");

    // Initialize hands
    for (i=0; i < 5; i++)
    {
        player_hand[i] = 0;
        dealer_hand[i] = 0;
    }

    // Deal cards for player
    printf("Your hand: ");
    for (i=0; i < 2; i++)
    {
        player_hand[i] = rand() % 13 + 1;
        printf("%d ", player_hand[i]);
    }
    player_total = player_hand[0] + player_hand[1];
    printf("\nYour total: %d\n\n", player_total);

    // Deal cards for dealer
    printf("Dealer's hand: ");
    dealer_hand[0] = rand() % 13 + 1;
    printf("%d *\n\n", dealer_hand[0]);

    // Player's turn
    while (player_choice != 's')
    {
        printf("Hit or Stand? (h/s): ");
        scanf(" %c", &player_choice);

        if (player_choice == 'h')
        {
            for (i=0; i < 5; i++)
            {
                if (player_hand[i] == 0)
                {
                    player_hand[i] = rand() % 13 + 1;
                    printf("Your card: %d\n", player_hand[i]);
                    player_total += player_hand[i];
                    break;
                }
            }
            printf("Your total: %d\n\n", player_total);

            if (player_total > 21)
            {
                printf("BUST! You lose.\n");
                return 0;
            }
        }
    }

    // Dealer's turn
    printf("\nDealer's turn.\n");
    printf("Dealer's hand: %d %d\n", dealer_hand[0], dealer_hand[1]);
    dealer_total = dealer_hand[0] + dealer_hand[1];
    while (dealer_total < 17)
    {
        for (i=0; i < 5; i++)
        {
            if (dealer_hand[i] == 0)
            {
                dealer_hand[i] = rand() % 13 + 1;
                printf("Dealer's card: %d\n", dealer_hand[i]);
                dealer_total += dealer_hand[i];
                break;
            }
        }
        printf("Dealer's total: %d\n\n", dealer_total);

        if (dealer_total > 21)
        {
            printf("Dealer BUSTS! You win!\n");
            return 0;
        }
    }

    // Determine winner
    printf("Your total: %d\n", player_total);
    printf("Dealer's total: %d\n", dealer_total);
    if (player_total > dealer_total)
    {
        printf("You win!\n");
    }
    else if (player_total < dealer_total)
    {
        printf("Dealer wins.\n");
    }
    else
    {
        printf("Push (tie).\n");
    }

    return 0;
}