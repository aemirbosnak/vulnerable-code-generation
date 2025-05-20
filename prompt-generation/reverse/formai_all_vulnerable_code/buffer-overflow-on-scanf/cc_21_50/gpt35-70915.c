//FormAI DATASET v1.0 Category: Poker Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //Seed the random number generator with current time
    int player_cards[2], dealer_cards[2], player_sum = 0, dealer_sum = 0;
    char play_again = 'y';

    printf("Welcome to immersive Poker game!\n");

    while (play_again == 'y')
    {
        printf("Dealing cards...\n");

        //Deal two cards to Player
        player_cards[0] = rand() % 13 + 1; //Random card number between 1 and 13
        player_cards[1] = rand() % 13 + 1;
        printf("Player cards: %d %d\n", player_cards[0], player_cards[1]);

        //Calculate Player's hand sum
        for (int i = 0; i < 2; i++)
        {
            if (player_cards[i] == 1) //Ace
                player_sum += 11;
            else if (player_cards[i] > 10) //Face cards
                player_sum += 10;
            else
                player_sum += player_cards[i];
        }

        //Deal two cards to Dealer
        dealer_cards[0] = rand() % 13 + 1;
        dealer_cards[1] = rand() % 13 + 1;

        //Calculate Dealer's hand sum
        if (dealer_cards[0] == 1) //Ace
        {
            if ((dealer_sum + 11) > 21) //Ace value is 1
                dealer_sum += 1;
            else //Ace value is 11
                dealer_sum += 11;
        } else if (dealer_cards[0] > 10) //Face cards
             dealer_sum += 10;
        else
            dealer_sum += dealer_cards[0];

        //Display one of Dealer's cards
        printf("Dealer cards: %d X\n", dealer_cards[0]);

        //Player's turn
        char hit_or_stand;
        do
        {
            printf("Do you want to hit or stand? (h/s)\n");
            scanf(" %c", &hit_or_stand);
            if (hit_or_stand == 'h')
            {
                int new_card = rand() % 13 + 1;
                printf("You draw a %d\n", new_card);
                if (new_card == 1) //Ace
                {
                    if ((player_sum + 11) > 21) //Ace value is 1
                        player_sum += 1;
                    else //Ace value is 11
                        player_sum += 11;
                }
                else if (new_card > 10) //Face cards
                    player_sum += 10;
                else
                    player_sum += new_card;

                printf("Your current hand sum: %d\n", player_sum);

                if (player_sum > 21)
                {
                    printf("Bust! You lose.\n");
                    play_again = 'n';
                    break;
                }
            }
            else if (hit_or_stand == 's')
                break;
            else
                printf("Invalid input. Try again.\n");
        } while (hit_or_stand != 's');

        //Dealer's turn
        if (play_again == 'y')
        {
            printf("Dealer's turn...\n");
            while (dealer_sum < 17)
            {
                int new_card = rand() % 13 + 1;
                printf("Dealer draw a %d\n", new_card);
                if (new_card == 1) //Ace
                {
                    if ((dealer_sum + 11) > 21) //Ace value is 1
                        dealer_sum += 1;
                    else //Ace value is 11
                        dealer_sum += 11;
                }
                else if (new_card > 10) //Face cards
                    dealer_sum += 10;
                else
                    dealer_sum += new_card;

                printf("Dealer's current hand sum: %d\n", dealer_sum);
            }

            //Compare hands and determine winner
            if (dealer_sum > 21)
            {
                printf("Dealer busted! You win!\n");
            }
            else if (dealer_sum > player_sum)
            {
                printf("Dealer wins!\n");
            }
            else if (dealer_sum < player_sum)
            {
                printf("You win!\n");
            }
            else
            {
                printf("It's a tie!\n");
            }

            //Ask to play again
            printf("Do you want to play again? (y/n)\n");
            scanf(" %c", &play_again);
            player_sum = 0;
            dealer_sum = 0;
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}