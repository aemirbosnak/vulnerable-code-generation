//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 100

// Define the number of words in the test.
#define NUM_WORDS 10

// Define the minimum and maximum word lengths.
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 10

// Define the minimum and maximum typing speeds.
#define MIN_TYPING_SPEED 30
#define MAX_TYPING_SPEED 100

// Main function.
int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Generate the test words.
    char words[NUM_WORDS][MAX_WORD_LENGTH + 1];
    for (int i = 0; i < NUM_WORDS; i++) {
        // Generate a random word length.
        int word_length = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;

        // Generate the word.
        for (int j = 0; j < word_length; j++) {
            words[i][j] = 'a' + rand() % 26;
        }
        words[i][word_length] = '\0';
    }

    // Print the instructions.
    printf("Typing Speed Test\n");
    printf("Instructions:\n");
    printf("   Type the following words as quickly and accurately as possible.\n");
    printf("   Press the Enter key after each word.\n");

    // Start the timer.
    clock_t start = clock();

    // Get the input string.
    char input[MAX_INPUT_LENGTH];
    for (int i = 0; i < NUM_WORDS; i++) {
        printf("%s", words[i]);
        scanf("%s", input);
    }

    // Stop the timer.
    clock_t end = clock();

    // Calculate the typing speed.
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    double typing_speed = NUM_WORDS / time_taken;

    // Print the results.
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);

    return 0;
}