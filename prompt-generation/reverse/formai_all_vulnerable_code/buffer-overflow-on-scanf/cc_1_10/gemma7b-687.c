//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: automated
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 1000

int main()
{
    char words[MAX_WORDS][20];
    int i, j, k, time_start, time_end, total_time = 0;
    int words_entered = 0;

    printf("Enter a word: ");

    // Start the timer
    time_start = clock();

    // Loop to read words until the user enters a word that is already in the list
    while (1)
    {
        char word[20];
        scanf("%s", word);

        for (i = 0; i < words_entered; i++)
        {
            if (strcmp(word, words[i]) == 0)
            {
                printf("That word is already in the list.\n");
                break;
            }
        }

        if (strcmp(word, "") == 0)
        {
            break;
        }

        strcpy(words[words_entered], word);
        words_entered++;
    }

    // Stop the timer
    time_end = clock();

    // Calculate the total time taken
    total_time = time_end - time_start;

    // Print the total time taken
    printf("Total time taken: %d seconds\n", total_time);

    return 0;
}