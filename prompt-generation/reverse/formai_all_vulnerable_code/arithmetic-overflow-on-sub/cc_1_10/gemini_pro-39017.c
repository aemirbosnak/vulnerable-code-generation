//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define TEST_DURATION 60 // seconds

// Array of words for the test
static char *words[] = {
    "apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "house", "ice cream", "juice",
    "kite", "lemon", "mango", "nut", "orange", "peach", "pear", "pineapple", "queen", "rabbit",
    "strawberry", "tiger", "umbrella", "violin", "watermelon", "x-ray", "yacht", "zebra"
};

// Function to generate a random word from the array
static char *get_random_word(void) {
    return words[rand() % (sizeof(words) / sizeof(char *))];
}

// Function to print the instructions
static void print_instructions(void) {
    printf("Instructions:\n");
    printf("1. Start typing as soon as the test begins.\n");
    printf("2. Type the words exactly as they appear on the screen.\n");
    printf("3. The test will end after %d seconds.\n", TEST_DURATION);
    printf("4. Press any key to start the test.\n");
}

// Function to start the test
static void start_test(void) {
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;
    int words_typed = 0;

    // Get the current time
    time(&start_time);

    // Loop until the test duration has elapsed
    while (difftime(time(NULL), start_time) < TEST_DURATION) {
        // Generate a random word
        char *word = get_random_word();

        // Print the word to the screen
        printf("%s ", word);

        // Get the user's input
        fgets(buffer, BUFFER_SIZE, stdin);

        // Check if the user's input matches the word
        if (strcmp(buffer, word) == 0) {
            // Increment the number of words typed
            words_typed++;
        }
    }

    // Get the current time
    time(&end_time);

    // Calculate the typing speed in words per minute
    double typing_speed = (double)words_typed / ((double)(end_time - start_time) / 60.0);

    // Print the typing speed to the screen
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);
}

// Main function
int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Print the instructions
    print_instructions();

    // Wait for the user to press any key
    getchar();

    // Start the test
    start_test();

    return 0;
}