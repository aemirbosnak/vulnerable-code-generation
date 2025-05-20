//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAX_TIME 60 // in seconds
#define MAX_WORDS 10 // maximum words to type
#define MAX_LEN 10 // maximum length of a word

// Function prototypes
void start_typing_test();

// Main function
int main()
{
    start_typing_test();

    return 0;
}

// Function to start the typing test
void start_typing_test()
{
    char words[MAX_WORDS][MAX_LEN] = {"apple", "banana", "cherry", "dragon", "elephant",
                                      "flamingo", "giraffe", "hippopotamus", "iguana", "jaguar"};
    int i, word_index, correct_count = 0, seconds_left = MAX_TIME;
    time_t start_time, current_time;

    srand(time(NULL)); // Seed the random number generator

    // Start the countdown timer
    time(&start_time);

    while (seconds_left > 0)
    {
        // Generate a random index for the word to type
        word_index = rand() % MAX_WORDS;

        // Print the word for the user to type
        printf("%s\n", words[word_index]);

        // Get user input
        char input[MAX_LEN];
        scanf("%s", input);

        // Check if the input matches the generated word
        if (strcmp(input, words[word_index]) == 0)
        {
            correct_count++;
        }

        // Update the countdown timer
        time(&current_time);
        seconds_left = MAX_TIME - (int)difftime(current_time, start_time);
    }

    // Calculate typing speed
    int words_per_minute = (correct_count / MAX_TIME) * 60;

    // Display results
    printf("Time's up!\n");
    printf("Your typing speed: %d words per minute\n", words_per_minute);
}