//FormAI DATASET v1.0 Category: Poker Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to shuffle the deck
void shuffle(int *deck, int size)
{
    // seed the random generator
    srand(time(NULL));

    for (int i = size - 1; i > 0; i--)
    {
        // generate a random index between 0 and i
        int j = rand() % (i + 1);

        // swap the values at index i and j
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// function to print the cards in a user-friendly way
void print_card(int value, int suit)
{
    switch (value)
    {
        case 1:
            printf("Ace");
            break;
        case 11:
            printf("Jack");
            break;
        case 12:
            printf("Queen");
            break;
        case 13:
            printf("King");
            break;
        default:
            printf("%d", value);
            break;
    }

    printf(" of ");

    switch (suit)
    {
        case 1:
            printf("Hearts");
            break;
        case 2:
            printf("Diamonds");
            break;
        case 3:
            printf("Clubs");
            break;
        case 4:
            printf("Spades");
            break;
    }

    printf("\n");
}

int main()
{
    // declare a deck of cards
    int deck[52];
    for (int i = 0; i < 52; i++)
    {
        deck[i] = (i % 13) + 1;
    }

    // shuffle the deck
    shuffle(deck, 52);

    // deal two cards to each player
    int player_hand[2];
    int dealer_hand[2];

    for (int i = 0; i < 2; i++)
    {
        player_hand[i] = deck[i];
        dealer_hand[i] = deck[i+2];
    }

    // print the player's hand
    printf("Your hand:\n");
    print_card(player_hand[0], 1);
    print_card(player_hand[1], 1);

    // print the dealer's hand
    printf("\nDealer's hand:\n");
    print_card(dealer_hand[0], 1);
    printf("Face down card\n");

    // ask the player if they want another card
    int choice;
    do
    {
        printf("\nDo you want another card? (1 for yes, 0 for no): ");
        scanf("%d", &choice);

        if (choice)
        {
            // add a card to the player's hand
            player_hand[2] = deck[4];
            printf("\nYour new card:\n");
            print_card(player_hand[2], 1);
        }
    } while (choice);

    return 0;
}