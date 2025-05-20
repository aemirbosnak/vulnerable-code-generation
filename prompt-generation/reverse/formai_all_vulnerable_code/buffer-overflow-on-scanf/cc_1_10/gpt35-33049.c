//FormAI DATASET v1.0 Category: Poker Game ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to shuffle the deck of cards
void shuffle(int *deck)
{
    int i, j, temp;
    for(i=0; i<52; i++)
    {
        j = rand()%52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print the rank and suit of each card
void printCard(int card)
{
    const char *suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *ranks[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", 
                                "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    printf("%s of %s \n", ranks[card%13], suits[card/13]);
}

// Function to determine poker hand type and display score
void determineHand(int *hand, int *score)
{
    int i, j;
    int counts[13] = {0};
    int pairs = 0, threeOfAKind = 0, fourOfAKind = 0;
    int flush = 0, straight = 0, straightFlush = 0;
    for(i=0; i<5; i++)
        counts[hand[i]%13]++;
    
    for(i=0; i<13; i++)
    {
        if(counts[i] == 2) pairs++;
        if(counts[i] == 3) threeOfAKind++;
        if(counts[i] == 4) fourOfAKind++;
    }
    
    for(i=0; i<4; i++)
    {
        int suitCount = 0;
        for(j=0; j<5; j++)
        {
            if((hand[j]/13) == i) suitCount++;
        }
        if(suitCount == 5)
        {
            flush = 1;
            break;
        }
    }
    
    int straightCount = 0;
    for(i=0; i<11; i++)
    {
        if(counts[i] == 1 && counts[i+1] == 1 && counts[i+2] == 1 && counts[i+3] == 1 && counts[i+4] == 1)
        {
            straight = 1;
            break;
        }
    }
    
    if(straight && flush)
    {
        straightFlush = 1;
        *score += 800;
    }
    else if(fourOfAKind)
    {
        *score += 700 + (fourOfAKind * 50);
    }
    else if(threeOfAKind && pairs == 1)
    {
        *score += 600;
    }
    else if(flush)
    {
        *score += 500;
    }
    else if(straight)
    {
        *score += 400;
    }
    else if(threeOfAKind)
    {
        *score += 300;
    }
    else if(pairs == 2)
    {
        *score += 200;
    }
    else if(pairs == 1)
    {
        *score += 100;
    }
}

// Function to play the game
void playPoker()
{
    int deck[52], hand[5], score = 0;
    int i, j, cardNumber = 0;
    srand(time(NULL));
    for(i=0; i<52; i++) deck[i] = i;
    
    // Shuffle the deck
    shuffle(deck);
    
    // Draw 5 cards
    for(i=0; i<5; i++)
    {
        hand[i] = deck[cardNumber++];
        printCard(hand[i]);
    }
    
    // Determine hand type and calculate score
    determineHand(hand, &score);
    printf("Score: %d\n", score);
}

int main()
{
    int choice = 0;
    while(choice != 2)
    {
        printf("\n1. Play Poker\n2. Quit\n\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                playPoker();
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}