//FormAI DATASET v1.0 Category: Poker Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define SUITS 4
#define NUM_RANKS 13
#define HAND_SIZE 5
#define MAX_PLAYERS 6

// Global variables
int deck[SUITS][NUM_RANKS];
char players[MAX_PLAYERS][20];
int num_players;
int player_scores[MAX_PLAYERS][2];

// Function prototypes
void initialize_deck();
void shuffle_cards();
void deal_cards(int);
int get_card_value(int);
void sort_hand(int, int[]);
int evaluate_hand(int[]);

int main()
{
    // Seed the random number generator
    srand((unsigned) time(NULL));
    
    // Initialize the deck of cards
    initialize_deck();
    
    // Get the number of players
    printf("Enter the number of players (2-6): ");
    scanf("%d", &num_players);
    while (num_players < 2 || num_players > 6)
    {
        printf("Invalid number of players. Please enter a number between 2 and 6: ");
        scanf("%d", &num_players);
    }
    
    // Get the name of each player
    printf("\nEnter the name of each player:\n");
    for (int i = 0; i < num_players; i++)
    {
        printf("Player %d: ", i+1);
        scanf("%s", players[i]);
    }
    
    // Shuffle the deck of cards
    printf("\nShuffling the deck...\n");
    shuffle_cards();
    printf("\nDeck shuffled.\n");
    
    // Deal the cards to each player
    for (int i = 0; i < num_players; i++)
    {
        deal_cards(i);
    }
    
    // Display each player's hand
    printf("\n");
    for (int i = 0; i < num_players; i++)
    {
        printf("%s's hand:\n", players[i]);
        for (int j = 0; j < HAND_SIZE; j++)
        {
            printf("%d of ", get_card_value(player_scores[i][j]));
            switch (player_scores[i][j] % NUM_RANKS)
            {
                case 0: printf("Ace\n"); break;
                case 10: printf("Jack\n"); break;
                case 11: printf("Queen\n"); break;
                case 12: printf("King\n"); break;
                default: printf("%d\n", (player_scores[i][j] % NUM_RANKS) + 1);
            }
        }
        printf("\n");
    }
    
    // Evaluate each player's hand
    for (int i = 0; i < num_players; i++)
    {
        printf("%s's hand is worth %d points.\n", players[i], evaluate_hand(player_scores[i]));
    }
    
    return 0;
}

// Function definitions
void initialize_deck()
{
    for (int i = 0; i < SUITS; i++)
    {
        for (int j = 0; j < NUM_RANKS; j++)
        {
            deck[i][j] = j;
        }
    }
}

void shuffle_cards()
{
    int temp, suit1, rank1, suit2, rank2;
    for (int i = 0; i < SUITS * NUM_RANKS * 4; i++)
    {
        suit1 = rand() % SUITS;
        rank1 = rand() % NUM_RANKS;
        suit2 = rand() % SUITS;
        rank2 = rand() % NUM_RANKS;
        
        temp = deck[suit1][rank1];
        deck[suit1][rank1] = deck[suit2][rank2];
        deck[suit2][rank2] = temp;
    }
}

void deal_cards(int player)
{
    sort_hand(player, player_scores[player]); // Sort hand in ascending order
    for (int i = 0; i < HAND_SIZE; i++)
    {
        player_scores[player][i] = deck[i][player]; // Deal cards from top of deck
    }
}

int get_card_value(int card)
{
    int value;
    switch (card % NUM_RANKS)
    {
        case 0: value = 11; break;
        case 10:
        case 11:
        case 12: value = 10; break;
        default: value = (card % NUM_RANKS) + 1;
    }
    return value;
}

void sort_hand(int player, int hand[])
{
    int temp;
    for (int i = 0; i < HAND_SIZE - 1; i++)
    {
        for (int j = i + 1; j < HAND_SIZE; j++)
        {
            if (hand[j] < hand[i])
            {
                temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
}

int evaluate_hand(int hand[])
{
    int score = 0;
    int num_aces = 0;
    int has_straight = 0;
    int has_flush = 0;
    int same_rank_count;
    
    // Check for flush
    for (int i = 1; i < HAND_SIZE; i++)
    {
        if (hand[i] / NUM_RANKS != hand[0] / NUM_RANKS)
        {
            has_flush = 0;
            break;
        }
        else
        {
            has_flush = 1;
        }
    }
    
    // Check for straight
    if (hand[4] % NUM_RANKS == 0 && hand[3] % NUM_RANKS == 9) // Ace-high straight
    {
        has_straight = 1;
    }
    else if (hand[4] % NUM_RANKS - hand[0] % NUM_RANKS == 4) // Regular straight
    {
        has_straight = 1;
    }
    
    // Check for pairs, three of a kind, and four of a kind
    for (int i = 0; i < HAND_SIZE; i++)
    {
        same_rank_count = 0;
        for (int j = i + 1; j < HAND_SIZE; j++)
        {
            if (hand[j] % NUM_RANKS == hand[i] % NUM_RANKS)
            {
                same_rank_count++; // Two cards with the same rank
            }
        }
        switch (same_rank_count)
        {
            case 1: score += 2; break; // One pair
            case 2:
                score += 6; // Three of a kind
                if (hand[i] % NUM_RANKS == 0)
                {
                    num_aces++;
                }
                break;
            case 3: score += 12; break; // Four of a kind
        }
    }
    
    // Score for flush and straight
    if (has_flush && has_straight)
    {
        score += 20; // Straight flush
    }
    else if (has_flush)
    {
        score += 10; // Flush
    }
    else if (has_straight)
    {
        score += 15; // Straight
    }
    
    // Score for aces
    for (int i = 0; i < num_aces; i++)
    {
        if (score + 11 <= 21)
        {
            score += 11; // Ace counts as 11
        }
        else
        {
            score += 1; // Ace counts as 1
        }
    }
    
    return score;
}