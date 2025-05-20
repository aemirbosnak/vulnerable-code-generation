//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TIME 30 // test time in seconds
#define MAX_KEY_LENGTH 50
#define NUM_OF_TESTS 5

char *test_sentences[NUM_OF_TESTS] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the end, we will remember not the words of our enemies, but the silence of our friends."
};

void display_instructions() {
    printf("=== Typing Speed Test ===\n");
    printf("You have %d seconds to type the following sentences.\n", MAX_TIME);
    printf("Press Enter when you are ready to start...\n");
    getchar(); // Wait for the user to press Enter
}

void clear_screen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void run_typing_test(char *sentence) {
    char input[MAX_KEY_LENGTH];
    clock_t start_time, end_time;
    int elapsed_time;

    printf("\nType the following sentence:\n");
    printf("\"%s\"\n", sentence);
    printf("Start typing now!\n");

    start_time = clock(); // Start the timer
    fgets(input, MAX_KEY_LENGTH, stdin); // Get user input
    end_time = clock(); // Stop the timer

    elapsed_time = (int)(((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000); // Get elapsed time in milliseconds
    getchar(); // Consume the newline character from the input buffer

    // Calculate typing metrics
    int input_length = strlen(input);
    if (input[input_length - 1] == '\n') { 
        input[input_length - 1] = '\0'; // Remove newline character for comparison
    }
    int correct_chars = 0;
    for (int i = 0; i < input_length; i++) {
        if (input[i] == sentence[i]) {
            correct_chars++;
        }
    }

    float typing_speed = (correct_chars / (elapsed_time / 60000.0)); // Calculate speed in WPM
    int accuracy = (correct_chars * 100) / strlen(sentence); // Calculate accuracy percentage

    // Display results
    printf("\n=== Results ===\n");
    printf("Time taken: %d ms\n", elapsed_time);
    printf("Typing speed: %.2f WPM\n", typing_speed);
    printf("Accuracy: %d%%\n", accuracy);
}

int main() {
    clear_screen(); // Clear the screen
    display_instructions(); // Show instructions

    for (int i = 0; i < NUM_OF_TESTS; i++) {
        run_typing_test(test_sentences[i]); // Run the typing test for each sentence
        printf("\nPress Enter to continue to the next test...\n");
        getchar(); // Wait for user input to continue
        clear_screen(); // Clear the screen again
    }

    printf("Thank you for participating!\n");
    return 0;
}