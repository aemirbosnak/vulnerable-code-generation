//FormAI DATASET v1.0 Category: Poker Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define MAX_PLAYERS 8
#define HAND_SIZE 5

void shuffle(int deck[]);
void deal(int deck[], int num_players, int hand_size);
int card_value(int card);
void print_hand(int hand[], int hand_size);
int find_pair(int hand[], int hand_size);
int find_two_pair(int hand[], int hand_size);
int find_three_of_a_kind(int hand[], int hand_size);
int find_straight(int hand[], int hand_size);
int find_flush(int hand[], int hand_size);
int find_full_house(int hand[], int hand_size);
int find_four_of_a_kind(int hand[], int hand_size);
int find_straight_flush(int hand[], int hand_size);

char *rank[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
char *suit[] = {"Clubs","Diamonds","Hearts","Spades"};

int main(void)
{
    int deck[NUM_CARDS], num_players, hand_size;
    srand((unsigned)time(NULL));
    
    printf("Welcome to C Poker Game!\n");
    printf("Enter the number of players (maximum of 8): ");
    scanf("%d", &num_players);
    printf("Enter the hand size (maximum of 5): ");
    scanf("%d", &hand_size);
    
    if(num_players < 2 || num_players > MAX_PLAYERS)
    {
        printf("Invalid number of players.\n");
        return 1;
    }
    
    if(hand_size < 1 || hand_size > HAND_SIZE)
    {
        printf("Invalid hand size.\n");
        return 1;
    }
    
    printf("\nShuffling deck...\n");
    shuffle(deck);
    
    printf("\nDealing cards...\n");
    deal(deck, num_players, hand_size);
    
    return 0;
}

void shuffle(int deck[])
{
    int i;
    
    for(i = 0; i < NUM_CARDS; i++)
    {
        deck[i] = i;
    }
    
    for(i = NUM_CARDS - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(int deck[], int num_players, int hand_size)
{
    int i, j, hand[num_players][hand_size];
    
    for(i = 0; i < num_players; i++)
    {
        for(j = 0; j < hand_size; j++)
        {
            hand[i][j] = deck[(i * hand_size) + j];
        }
    }
    
    for(i = 0; i < num_players; i++)
    {
        printf("\nPlayer %d's hand:\n", i + 1);
        print_hand(hand[i], hand_size);
        printf("\n");
    }
}

int card_value(int card)
{
    return card % NUM_RANKS;
}

void print_hand(int hand[], int hand_size)
{
    int i;
    
    for(i = 0; i < hand_size; i++)
    {
        int card = hand[i];
        printf("%s of %s\n", rank[card_value(card)], suit[card / NUM_RANKS]);
    }
}

int find_pair(int hand[], int hand_size)
{
    int i, j, count[NUM_RANKS] = {0};
    
    for(i = 0; i < hand_size; i++)
    {
        count[card_value(hand[i])]++;
    }
    
    for(j = NUM_RANKS - 1; j >= 0; j--)
    {
        if(count[j] == 2)
        {
            return j;
        }
    }
    
    return -1;
}

int find_two_pair(int hand[], int hand_size)
{
    int i, j, count[NUM_RANKS] = {0}, num_pairs = 0;
    
    for(i = 0; i < hand_size; i++)
    {
        count[card_value(hand[i])]++;
    }
    
    for(j = NUM_RANKS - 1; j >= 0; j--)
    {
        if(count[j] == 2)
        {
            num_pairs++;
        }
    }
    
    if(num_pairs == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int find_three_of_a_kind(int hand[], int hand_size)
{
    int i, j, count[NUM_RANKS] = {0};
    
    for(i = 0; i < hand_size; i++)
    {
        count[card_value(hand[i])]++;
    }
    
    for(j = NUM_RANKS - 1; j >= 0; j--)
    {
        if(count[j] == 3)
        {
            return j;
        }
    }
    
    return -1;
}

int find_straight(int hand[], int hand_size)
{
    int i, j, count = 0;
    int straights[NUM_RANKS] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    for(i = 0; i < hand_size; i++)
    {
        straights[card_value(hand[i])] = 1;
    }
    
    for(j = 0; j < NUM_RANKS - 4; j++)
    {
        if(straights[j] && straights[j + 1] && straights[j + 2] && straights[j + 3] && straights[j + 4])
        {
            return j + 4;
        }
    }
    
    return -1;
}

int find_flush(int hand[], int hand_size)
{
    int i, count[NUM_SUITS] = {0};
    
    for(i = 0; i < hand_size; i++)
    {
        count[hand[i] / NUM_RANKS]++;
    }
    
    for(i = 0; i < NUM_SUITS; i++)
    {
        if(count[i] == hand_size)
        {
            return 1;
        }
    }
    
    return 0;
}

int find_full_house(int hand[], int hand_size)
{
    int i, j, count[NUM_RANKS] = {0}, three_of_a_kind = -1, num_pairs = 0;
    
    for(i = 0; i < hand_size; i++)
    {
        count[card_value(hand[i])]++;
    }
    
    for(j = NUM_RANKS - 1; j >= 0; j--)
    {
        if(count[j] == 3)
        {
            three_of_a_kind = j;
        }
        else if(count[j] == 2)
        {
            num_pairs++;
        }
    }
    
    if(three_of_a_kind >= 0 && num_pairs >= 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int find_four_of_a_kind(int hand[], int hand_size)
{
    int i, j, count[NUM_RANKS] = {0};
    
    for(i = 0; i < hand_size; i++)
    {
        count[card_value(hand[i])]++;
    }
    
    for(j = NUM_RANKS - 1; j >= 0; j--)
    {
        if(count[j] == 4)
        {
            return j;
        }
    }
    
    return -1;
}

int find_straight_flush(int hand[], int hand_size)
{
    if(find_flush(hand, hand_size) && find_straight(hand, hand_size) >= 0)
    {
        return find_straight(hand, hand_size);
    }
    else
    {
        return -1;
    }
}