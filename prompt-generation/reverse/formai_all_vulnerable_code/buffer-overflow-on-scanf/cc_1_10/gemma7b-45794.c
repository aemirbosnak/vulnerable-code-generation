//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 1000

int main()
{
    char word[MAX_WORDS];
    int i, j, time_start, time_end, words_typed = 0;

    system("clear");

    // Start the timer
    time_start = clock();

    // Prompt the user to type words
    printf("Start typing now: ");

    // Loop until the user types a word or reaches the time limit
    while (!word[0] && words_typed < MAX_WORDS)
    {
        scanf("%s", word);

        // Increment the number of words typed
        words_typed++;

        // Clear the word
        for (i = 0; word[i] != '\0'; i++)
        {
            word[i] = '\0';
        }
    }

    // Stop the timer
    time_end = clock();

    // Calculate the time taken
    int time_taken = (time_end - time_start) / CLOCKS_PER_SEC;

    // Print the results
    printf("You typed a total of %d words in %d seconds.\n", words_typed, time_taken);

    // Calculate the average words per second
    int average_words_per_second = (words_typed * 1000) / time_taken;

    // Print the average words per second
    printf("Your average words per second is: %.2f\n", average_words_per_second);

    return 0;
}