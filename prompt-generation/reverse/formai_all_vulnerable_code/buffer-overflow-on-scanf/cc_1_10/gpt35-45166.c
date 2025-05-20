//FormAI DATASET v1.0 Category: Poker Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to shuffle the deck of cards */
void shuffle(int deck[52])
{
    int i, temp, random;
    for (i = 0; i < 52; i++) {
        random = rand() % 52;
        temp = deck[i];
        deck[i] = deck[random];
        deck[random] = temp;
    }
}

/* Function to display the given hand */
void display(int hand[5])
{
    int i;
    printf("\nYour Hand:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", hand[i]);
    }
    printf("\n");
}

int main()
{
    int deck[52], hand[5], i, j, choice;

    srand(time(NULL));

    printf("Welcome to the Poker Game!\n");

    /* Initializing the deck of cards */
    for (i = 0; i < 13; i++) {
        deck[i] = i + 2;
        deck[i + 13] = i + 2;
        deck[i + 26] = i + 2;
        deck[i + 39] = i + 2;
    }

    shuffle(deck); /* Shuffle the deck of cards */

    /* Dealing the first hand to the player */
    for (i = 0; i < 5; i++) {
        hand[i] = deck[i];
    }

    display(hand); /* Display the given hand */

    printf("Do you want to change any cards?\n");
    printf("Press 1 for Yes and 0 for No: ");
    scanf("%d", &choice);

    /* If player wants to change cards, re-deal */
    if (choice == 1) {
        for (i = 0; i < 5; i++) {
            printf("Do you want to change card %d?\n", i + 1);
            printf("Press 1 for Yes and 0 for No: ");
            scanf("%d", &choice);

            if (choice == 1) {
                hand[i] = deck[i + 5]; /* Re-deal the card */
            }
        }

        display(hand); /* Display the final hand */
    }

    printf("\nThank you for playing the Poker Game!\n");

    return 0;
}