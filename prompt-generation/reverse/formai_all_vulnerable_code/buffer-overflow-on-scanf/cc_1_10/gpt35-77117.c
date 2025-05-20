//FormAI DATASET v1.0 Category: Memory Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 10
#define MAX_GUESS 5

int main()
{
    int numbers[MAX_NUMBERS];
    int guesses[MAX_GUESS];
    int i, j, count, guess, correct, found;

    // Initialize random number generator
    srand(time(NULL));

    // Generate random numbers
    for(i = 0; i < MAX_NUMBERS; i++)
        numbers[i] = rand() % 100;

    // Print out numbers for debugging purposes
    printf("Numbers: ");
    for(i = 0; i < MAX_NUMBERS; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    // Prompt user for guesses
    for(i = 0; i < MAX_GUESS; i++)
    {
        printf("Guess #%d: ", i + 1);
        scanf("%d", &guesses[i]);
    }

    // Check guesses against numbers
    count = 0;
    for(i = 0; i < MAX_GUESS; i++)
    {
        correct = 0;
        found = 0;
        for(j = 0; j < MAX_NUMBERS; j++)
        {
            if(guesses[i] == numbers[j])
            {
                if(!found)
                    correct++;
                found = 1;
            }
        }
        count += correct;
        printf("Guess #%d: %d correct\n", i + 1, correct);
    }

    // Print out results
    printf("You got %d out of %d correct!\n", count, MAX_NUMBERS);

    return 0;
}