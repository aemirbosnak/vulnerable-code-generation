//FormAI DATASET v1.0 Category: Memory Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 20
#define MATCH_THRESHOLD 5

void shuffle(int array[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        int j = rand() % size;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void printBoard(int board[], int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(board[i] == -1)
            printf("~ ");
        else
            printf("%d ", board[i]);
    }
    printf("\n\n");
}

int main()
{
    srand(time(NULL));
    int cardDeck[NUM_CARDS];
    int board[NUM_CARDS];
    int selections[MATCH_THRESHOLD];
    int numMatches = 0;
    int attempts = 0;

    int i,j;
    for(i = 0; i < NUM_CARDS; i++)
    {
        cardDeck[i] = (i%10) + 1;
    }

    for(i = 0; i < NUM_CARDS; i++)
    {
        board[i] = -1;
    }

    shuffle(cardDeck, NUM_CARDS);

    printf("================= MEMORY GAME =================\n\n");
    printf("Try to match the cards!\n");
    printf("You have %d attempts remaining.\n\n", MATCH_THRESHOLD);

    while(numMatches < MATCH_THRESHOLD && attempts < MATCH_THRESHOLD)
    {
        printBoard(board, NUM_CARDS);

        int selection;
        printf("Enter the index of a card to reveal: ");
        scanf("%d", &selection);

        if(selection < 0 || selection >= NUM_CARDS)
            continue;

        if(board[selection] != -1)
            continue;

        board[selection] = cardDeck[selection];
        selections[attempts] = cardDeck[selection];
        attempts++;

        printBoard(board, NUM_CARDS);

        if(attempts % 2 == 0)
        {
            if(selections[attempts-2] == selections[attempts-1])
            {
                printf("Match found!\n");
                numMatches++;
            }
            else
            {
                printf("No match found!\n");
                board[attempts-2] = -1;
                board[attempts-1] = -1;
            }
        }

        printf("\n%d attempts remaining.\n\n", MATCH_THRESHOLD - attempts);
    }

    if(numMatches == MATCH_THRESHOLD)
        printf("You win!\n");
    else
        printf("You lose! Better luck next time.\n");

    return 0;
}