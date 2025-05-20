//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WPM_THRESHOLD 100 // Words per minute threshold to pass the test
#define TEST_DURATION 60 // Test duration in seconds

// Array of words for the test
char *words[] = {
    "abracadabra", "banana", "cat", "dog", "elephant", "fish", "grape", "house",
    "ice cream", "juice", "kangaroo", "lemon", "monkey", "nut", "orange", "pear",
    "queen", "rabbit", "strawberry", "tiger", "umbrella", "violin", "watermelon",
    "xylophone", "yacht", "zebra"
};

// Function to generate a random word from the array
char *get_random_word() {
    int index = rand() % (sizeof(words) / sizeof(char *));
    return words[index];
}

// Function to get the current time in milliseconds
long long get_current_time_ms() {
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC, &time);
    return (long long)time.tv_sec * 1000 + (long long)time.tv_nsec / 1000000;
}

// Function to run the typing speed test
void run_test() {
    // Initialize variables
    char input[100];
    int words_typed = 0;
    long long start_time = get_current_time_ms();

    // Loop until the test duration is reached
    while (get_current_time_ms() - start_time < TEST_DURATION * 1000) {
        // Get a random word
        char *word = get_random_word();

        // Prompt the user to type the word
        printf("Type the word: %s\n", word);

        // Get the user's input
        scanf("%s", input);

        // Check if the input matches the word
        if (strcmp(input, word) == 0) {
            words_typed++;
        }
    }

    // Calculate the typing speed in WPM
    double wpm = (double)words_typed / TEST_DURATION * 60;

    // Print the results
    printf("You typed %d words in %d seconds.\n", words_typed, TEST_DURATION);
    printf("Your typing speed is %.2f WPM.\n", wpm);

    // Check if the user passed the test
    if (wpm >= WPM_THRESHOLD) {
        printf("Congratulations! You passed the test.\n");
    } else {
        printf("Sorry, you did not pass the test.\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the typing speed test
    run_test();

    return 0;
}