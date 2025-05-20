//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define NUM_PAIRS 4
#define SIZE 4

/* Function to check if two cards are the same */
int isSameCard(int card1, int card2)
{
    return (card1 == card2);
}

/* Function to print a card */
void printCard(int card)
{
    if (card == 1)
        printf("A\n");
    else if (card == 2)
        printf("B\n");
    else if (card == 3)
        printf("C\n");
    else if (card == 4)
        printf("D\n");
    else
        printf("Invalid card\n");
}

/* Function to check if a card is open */
int isOpenCard(int card)
{
    return (card!= 0);
}

/* Function to play the game */
void playGame()
{
    int cards[NUM_PAIRS][SIZE] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };

    int turns = 0;
    int currentPair = 0;
    int score = 0;

    while (score < NUM_PAIRS * 2)
    {
        printf("Turn %d:\n", ++turns);
        for (int i = 0; i < NUM_PAIRS; i++)
        {
            int card1 = cards[i][0];
            int card2 = cards[i][1];

            printf("Card %d: ", i + 1);
            printCard(card1);
            printf(" vs. Card %d: ", i + 1);
            printCard(card2);
            printf("\n");
        }
        printf("Select a pair of cards to flip:\n");
        int choice = -1;
        while (choice < 1 || choice > NUM_PAIRS)
        {
            printf("Enter the number of the pair of cards to flip: ");
            scanf("%d", &choice);
        }
        int card1 = cards[choice - 1][0];
        int card2 = cards[choice - 1][1];

        if (isSameCard(card1, card2))
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect.\n");
        }
        printf("Score: %d\n", score);

        for (int i = 0; i < NUM_PAIRS; i++)
        {
            if (isSameCard(cards[i][0], cards[i][1]))
            {
                cards[i][0] = 0;
                cards[i][1] = 0;
            }
            else if (isOpenCard(cards[i][0]) && isOpenCard(cards[i][1]))
            {
                if (isSameCard(cards[i][0], card1) && isSameCard(cards[i][1], card2))
                {
                    cards[i][0] = card1;
                    cards[i][1] = card2;
                }
                else if (isSameCard(cards[i][0], card2) && isSameCard(cards[i][1], card1))
                {
                    cards[i][0] = card2;
                    cards[i][1] = card1;
                }
                else
                {
                    cards[i][0] = 0;
                    cards[i][1] = 0;
                }
            }
        }
        printf("Turn %d:\n", turns);
        for (int i = 0; i < NUM_PAIRS; i++)
        {
            int card1 = cards[i][0];
            int card2 = cards[i][1];

            printf("Card %d: ", i + 1);
            printCard(card1);
            printf(" vs. Card %d: ", i + 1);
            printCard(card2);
            printf("\n");
        }
        printf("Select a pair of cards to flip:\n");
        choice = -1;
        while (choice < 1 || choice > NUM_PAIRS)
        {
            printf("Enter the number of the pair of cards to flip: ");
            scanf("%d", &choice);
        }
        card1 = cards[choice - 1][0];
        card2 = cards[choice - 1][1];
    }
    printf("Congratulations, you won!\n");
}

int main()
{
    playGame();
    return 0;
}