//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct Word {
    char word[20];
    int time;
} Word;

Word words[MAX_WORDS];

void main() {
    int i, j, k, time_start, time_end, total_time = 0;
    char input[20];

    // Initialize the words array
    for (i = 0; i < MAX_WORDS; i++) {
        words[i].word[0] = '\0';
        words[i].time = 0;
    }

    // Start the timer
    time_start = clock();

    // Get the user input
    printf("Enter a word: ");
    scanf("%s", input);

    // Search for the word in the array
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(input, words[i].word) == 0) {
            // Record the time taken to find the word
            words[i].time = clock() - time_start;
            break;
        }
    }

    // End the timer
    time_end = clock();

    // Calculate the total time taken
    total_time = time_end - time_start;

    // Print the results
    printf("The word %s was found in %d milliseconds.\n", words[i].word, words[i].time);
    printf("The total time taken was %d milliseconds.\n", total_time);

    return;
}