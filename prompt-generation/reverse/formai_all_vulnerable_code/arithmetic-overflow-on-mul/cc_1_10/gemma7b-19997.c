//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: happy
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WORDS 10

int main()
{
    char words[MAX_WORDS][20] = {
        "The quick brown fox jumps over the lazy dog.",
        "A wise old owl sat on a tree.",
        "The cat sat on the mat.",
        "The bread was buttered.",
        "A merry-go-round went round and round.",
        "Twinkle, twinkle, little star.",
        "Mary had a little lamb.",
        "The farmer drove his tractor.",
        "The train went to the station.",
        "The clock ticked"
    };

    int i, j, score = 0, time_taken = 0, total_words = MAX_WORDS;

    printf("Welcome to the C Typing Speed Test!\n");

    // Timer start
    time_t start_time = time(NULL);

    // Randomly select a word from the list
    i = rand() % total_words;

    // Print the word
    printf("Type the following word as quickly as possible:\n\n%s\n", words[i]);

    // Get the user's input
    char user_input[20];

    // Timer stop
    time_t end_time = time(NULL);

    // Calculate the time taken
    time_taken = (int)(end_time - start_time) * 1000;

    // Calculate the score
    score = (words[i] - user_input) / MAX_WORDS * 100;

    // Print the results
    printf("\nYour score: %d%%", score);
    printf("\nTime taken: %.2f seconds", (double)time_taken / 1000);
    printf("\nThank you for participating!");

    return 0;
}