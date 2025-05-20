//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Sherlock Holmes's typing test
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create a list of words
    char *words[] = {
        "deduction",
        "observation",
        "inference",
        "investigation",
        "mystery",
        "crime",
        "detective",
        "sherlock",
        "holmes",
        "watson",
        "lestrade",
        "moran",
        "irene",
        "adler",
        "bohemia",
        "scandal",
        "sign",
        "four",
        "valley",
        "terror",
        "baskerville",
        "hound"
    };

    // Get the number of words to type
    int num_words;
    printf("How many words would you like to type? ");
    scanf("%d", &num_words);

    // Get the time the test started
    time_t start_time = time(NULL);

    // Start the typing test
    int i;
    for (i = 0; i < num_words; i++) {
        // Get the next word
        char *word = words[rand() % (sizeof(words) / sizeof(char *))];

        // Print the word
        printf("%s ", word);

        // Get the user's input
        char input[100];
        scanf("%s", input);

        // Check if the user's input is correct
        if (strcmp(input, word) != 0) {
            printf("Incorrect! The correct word is '%s'.\n", word);
        }
    }

    // Get the time the test ended
    time_t end_time = time(NULL);

    // Calculate the time it took to complete the test
    double time_taken = difftime(end_time, start_time);

    // Calculate the typing speed
    double typing_speed = num_words / time_taken;

    // Print the results
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    return 0;
}