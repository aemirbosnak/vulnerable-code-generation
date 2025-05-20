//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

// Define the list of words to be typed
char *words[] = {
    "ability", "absence", "abundance", "acceptance", "access", "accident", "accommodation",
    "accompaniment", "accomplishment", "accord", "account", "accuracy", "accusation", "achievement",
    "acquisition", "acre", "action", "activity", "actor", "actress", "addition", "address",
    "adequacy", "adhesion", "adjustment", "administration", "admission", "adolescence", "adoption",
    "advance", "advantage", "adventure", "advertisement", "advice", "affair", "affection", "affinity"
};

// Define the maximum number of words to be typed
#define MAX_WORDS 100

// Define the maximum time allowed for the test (in seconds)
#define MAX_TIME 60

// Main function
int main()
{
    // Initialize random number generator
    srand(time(NULL));

    // Get the user's name
    char name[BUFFER_SIZE];
    printf("Enter your name: ");
    scanf("%s", name);

    // Get the user's desired test duration
    int duration;
    printf("Enter the desired test duration (in seconds): ");
    scanf("%d", &duration);

    // Check if the user's desired test duration is valid
    if (duration < 1 || duration > MAX_TIME)
    {
        printf("Invalid test duration. Please enter a value between 1 and %d.\n", MAX_TIME);
        return 1;
    }

    // Initialize the test
    int words_typed = 0;
    int errors = 0;
    time_t start_time = time(NULL);
    time_t end_time = start_time + duration;

    // Main loop
    while (time(NULL) < end_time)
    {
        // Get a random word
        int word_index = rand() % (sizeof(words) / sizeof(char *));
        char *word = words[word_index];

        // Display the word to the user
        printf("%s\n", word);

        // Get the user's input
        char input[BUFFER_SIZE];
        scanf("%s", input);

        // Check if the user's input is correct
        if (strcmp(input, word) != 0)
        {
            errors++;
        }

        // Increment the number of words typed
        words_typed++;
    }

    // Calculate the user's typing speed
    double wpm = (double)words_typed / duration * 60;

    // Display the results
    printf("\n%s, your typing speed is %.2f words per minute with %d errors.\n", name, wpm, errors);

    return 0;
}