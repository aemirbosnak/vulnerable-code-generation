//FormAI DATASET v1.0 Category: Memory Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array
void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int main()
{
    int deck[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Creates an array of values to use in the game.
    int card1, card2, match1, match2; // Variables to keep track of chosen cards and matching pairs.
    int num_attempts = 0; // Variable to keep track of number of attempts taken.

    srand(time(0)); // Seeds the random number generator with the current time.

    shuffle(deck, 10); // Shuffles the deck of cards.

    printf("***Welcome to the Memory Game***\n\n");

    while (match1 != 1 || match2 != 2) // Continues game until both matching pairs are found.
    {
        printf("Choose a card (1-10): ");
        scanf("%d", &card1);

        while (card1 < 1 || card1 > 10) // Checks if chosen card is within the valid range.
        {
            printf("Invalid choice, please choose again: ");
            scanf("%d", &card1);
        }

        printf("Choose another card (1-10): ");
        scanf("%d", &card2);

        while (card2 < 1 || card2 > 10) // Checks if chosen card is within the valid range.
        {
            printf("Invalid choice, please choose again: ");
            scanf("%d", &card2);
        }

        if (card1 == card2) // Checks if both chosen cards are the same.
        {
            printf("You have chosen the same card twice, please choose again.\n\n");
            continue; // Skips the current iteration of the loop and goes to the next iteration.
        }

        printf("\nFirst card: %d\nSecond card: %d\n\n", deck[card1-1], deck[card2-1]);
        
        if (deck[card1-1] == deck[card2-1]) // Checks if chosen cards form a matching pair.
        {
            printf("Congratulations, you have found a matching pair!\n\n");
            if (match1 == 0)
            {
                match1 = 1;
            }
            else
            {
                match2 = 2;
            }
        }
        else
        {
            printf("Sorry, the chosen cards do not match.\n\n");
        }

        num_attempts++; // Increments number of attempts taken.
    }

    printf("Congratulations, you have found both matching pairs!\n");
    printf("Total number of attempts taken: %d\n", num_attempts);

    return 0;
}