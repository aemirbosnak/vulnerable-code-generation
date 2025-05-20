//FormAI DATASET v1.0 Category: Poker Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array to hold the deck of cards
const char *deck[] = {
    "Ace of Hearts", "Two of Hearts", "Three of Hearts", "Four of Hearts", "Five of Hearts",
    "Six of Hearts", "Seven of Hearts", "Eight of Hearts", "Nine of Hearts", "Ten of Hearts",
    "Jack of Hearts", "Queen of Hearts", "King of Hearts",
    "Ace of Diamonds", "Two of Diamonds", "Three of Diamonds", "Four of Diamonds", "Five of Diamonds",
    "Six of Diamonds", "Seven of Diamonds", "Eight of Diamonds", "Nine of Diamonds", "Ten of Diamonds",
    "Jack of Diamonds", "Queen of Diamonds", "King of Diamonds",
    "Ace of Clubs", "Two of Clubs", "Three of Clubs", "Four of Clubs", "Five of Clubs",
    "Six of Clubs", "Seven of Clubs", "Eight of Clubs", "Nine of Clubs", "Ten of Clubs",
    "Jack of Clubs", "Queen of Clubs", "King of Clubs",
    "Ace of Spades", "Two of Spades", "Three of Spades", "Four of Spades", "Five of Spades",
    "Six of Spades", "Seven of Spades", "Eight of Spades", "Nine of Spades", "Ten of Spades",
    "Jack of Spades", "Queen of Spades", "King of Spades"
};

// Function to shuffle deck of cards randomly
void shuffleDeck(const char **deck)
{
    srand(time(NULL)); // Initialize random seed

    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        const char *temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int main()
{
    int total_players, i, j, k, num_of_turns;
    printf("Enter the number of players (2-6): ");
    scanf("%d", &total_players);

    if (total_players < 2 || total_players > 6) {
        printf("Number of players should be between 2 and 6!\n");
        return 0;
    }

    shuffleDeck(deck); // Shuffle the deck before dealing

    char player_cards[total_players][2][30]; // Array to hold cards of each player
    for (i = 0; i < total_players; i++) {
        for (j = 0; j < 2; j++) {
            sprintf(player_cards[i][j], "%s", deck[(i*2)+j]); // Assign 2 cards to each player
        }
    }

    printf("Cards Dealt:\n");
    for (i = 0; i < total_players; i++) {
        printf("Player %d: %s, %s\n", i+1, player_cards[i][0], player_cards[i][1]); // Print cards of each player
    }

    int community_cards [5] = {0}; // Array to hold community cards
    printf("\nFlop(turn) cards:\n");

    // Deal the flop
    for (k = 0; k < 3; k++) {
       sprintf(community_cards[k], "%s", deck[5+ k]); // Assign 3 flop cards
       printf("%d: %s\n", k+1,community_cards[k]);
    }

    // Deal the turn
    sprintf(community_cards[3], "%s", deck[8]);
    printf("\nTurn card: %s\n", community_cards[3]);

    // Deal the river
    sprintf(community_cards[4], "%s", deck[9]);
    printf("\nRiver card: %s\n", community_cards[4]);

    return 0;
}