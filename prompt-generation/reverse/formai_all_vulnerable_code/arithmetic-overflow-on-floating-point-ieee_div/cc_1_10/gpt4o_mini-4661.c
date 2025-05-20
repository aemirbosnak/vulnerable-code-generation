//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 256
#define NUM_SENTENCES 5

const char *sentences[NUM_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be yourself in a world that is constantly trying to make you something else is the greatest accomplishment.",
    "In the end, we will remember not the words of our enemies, but the silence of our friends.",
    "Life is like riding a bicycle. To keep your balance, you must keep moving."
};

void clear_screen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

int main() {
    char user_input[MAX_LINE_LENGTH];
    int sentence_index;
    clock_t start_time, end_time;

    printf("=========================================\n");
    printf("         Typing Speed Test              \n");
    printf("=========================================\n");
    printf("Type the following sentence as fast as you can:\n");

    // Generate a random index for sentences
    srand(time(NULL));
    sentence_index = rand() % NUM_SENTENCES;

    // Display the chosen sentence to type
    printf("\n%s\n\n", sentences[sentence_index]);
    
    // Start the timer
    start_time = clock();

    // Get user input
    printf("Your input: ");
    fgets(user_input, MAX_LINE_LENGTH, stdin);

    // End the timer
    end_time = clock();

    // Calculate elapsed time in seconds
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the number of characters typed, excluding newline
    int chars_typed = strlen(user_input) - 1; // -1 to exclude '\n'

    // Calculate typing speed in characters per minute (CPM)
    double typing_speed = (chars_typed / time_taken) * 60;

    // Check if the input matches the sentence
    if (strcmp(user_input, sentences[sentence_index]) == 0) {
        printf("\nCongratulations! You typed the sentence correctly.\n");
    } else {
        printf("\nOops! The input does not match the sentence.\n");
    }

    // Display the typing results
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %.2f characters per minute (CPM)\n", typing_speed);

    printf("\nThank you for participating!\n");
    printf("=========================================\n");

    return 0;
}