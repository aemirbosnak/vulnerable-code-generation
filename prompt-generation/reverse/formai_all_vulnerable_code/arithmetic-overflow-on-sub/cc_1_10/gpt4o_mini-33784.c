//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 256
#define TARGET_TEXT "The quick brown fox jumps over the lazy dog."

void display_instructions() {
    printf("Typing Speed Test\n");
    printf("===================\n");
    printf("Type the following sentence as quickly as you can:\n");
    printf("\"%s\"\n", TARGET_TEXT);
    printf("Press 'Enter' when you finish typing.\n\n");
}

int main() {
    char user_input[MAX_INPUT_LENGTH];
    clock_t start_time, end_time;
    double time_taken;

    // Display instructions to the user
    display_instructions();

    // Start timing
    start_time = clock();

    // Get user input
    printf("Your input: ");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);

    // Stop timing
    end_time = clock();

    // Remove newline character from fgets
    user_input[strcspn(user_input, "\n")] = 0;

    // Calculate elapsed time in seconds
    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Evaluate the user's input against the target text
    if (strcmp(user_input, TARGET_TEXT) == 0) {
        printf("\nExcellent! You typed the sentence correctly.\n");
    } else {
        printf("\nOops! There were some mistakes. Please try again.\n");
    }

    // Calculate typing speed in words per minute (WPM)
    int word_count = 1; // Start with one word
    for (int i = 0; user_input[i] != '\0'; i++) {
        if (user_input[i] == ' ') {
            word_count++;
        }
    }

    double wpm = (word_count / time_taken) * 60;
    printf("Your time: %.2f seconds\n", time_taken);
    printf("Your typing speed: %.2f words per minute\n", wpm);

    return 0;
}