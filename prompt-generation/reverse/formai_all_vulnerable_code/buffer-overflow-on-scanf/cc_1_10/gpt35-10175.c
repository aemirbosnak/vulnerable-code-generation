//FormAI DATASET v1.0 Category: Poker Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define card constants
#define CLUBS 0
#define DIAMONDS 1
#define HEARTS 2
#define SPADES 3
#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

// Define variables to store player and dealer hand values
int playerHandValue = 0;
int dealerHandValue = 0;

// Declare functions
int drawCard();
void playerTurn();
void dealerTurn();
int checkWinner();

// Main function
int main()
{
    // Set seed for random number generator
    srand(time(NULL));

    // Draw initial cards for player and dealer
    printf("Drawing initial cards...\n\n");
    playerHandValue += drawCard();
    dealerHandValue += drawCard();
    printf("You drew a card with value %d. Your current hand value is %d.\n\n", playerHandValue % 13, playerHandValue);
    printf("The dealer drew a card with value %d. His current hand value is %d.\n\n", dealerHandValue % 13, dealerHandValue);

    // Player turn
    playerTurn();

    // Dealer turn
    dealerTurn();

    // Check winner
    int winner = checkWinner();
    if (winner == 1)
    {
        printf("You win!\n");
    }
    else if (winner == -1)
    {
        printf("The dealer wins!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }

    return 0;
}

// Draw a card
int drawCard()
{
    // Generate random card value between 1-13
    int cardValue = rand() % 13 + 1;

    // Adjust for face cards
    if (cardValue > 10)
    {
        cardValue = 10;
    }

    return cardValue;
}

// Player turn
void playerTurn()
{
    // Loop until player decides to stand or hand value goes over 21
    while (1)
    {
        // Ask player for decision
        char decision;
        printf("Your current hand value is %d. Do you want to hit or stand? (h/s)\n", playerHandValue);
        scanf(" %c", &decision);

        // Draw a new card if player hits
        if (decision == 'h')
        {
            playerHandValue += drawCard();
            printf("You drew a card with value %d. Your current hand value is %d.\n\n", playerHandValue % 13, playerHandValue);
        }

        // End turn if player stands or hand value goes over 21
        else if (decision == 's' || playerHandValue > 21)
        {
            printf("Your turn is over.\n\n");
            break;
        }
    }
}

// Dealer turn
void dealerTurn()
{
    // Loop until hand value is at least 17
    while (dealerHandValue < 17)
    {
        dealerHandValue += drawCard();
        printf("The dealer drew a card with value %d. His current hand value is %d.\n\n", dealerHandValue % 13, dealerHandValue);
    }

    printf("The dealer's turn is over.\n\n");
}

// Check winner
int checkWinner()
{
    // Check for player and dealer hand values
    if (playerHandValue > 21)
    {
        return -1;
    }
    else if (dealerHandValue > 21)
    {
        return 1;
    }
    else if (playerHandValue > dealerHandValue)
    {
        return 1;
    }
    else if (dealerHandValue > playerHandValue)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}