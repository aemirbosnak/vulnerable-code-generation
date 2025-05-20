//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 256
#define NUM_PHRASES 5

const char* phrases[NUM_PHRASES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the end, we will remember not the words of our enemies, but the silence of our friends."
};

void display_intro() {
    printf("===========================================\n");
    printf("      Welcome to the Typing Speed Test!  \n");
    printf("===========================================\n");
    printf("Type the phrase displayed on the screen as fast as you can.\n");
    printf("Press Enter when you are ready to begin.\n");
    getchar();
}

void display_phrase(int index) {
    printf("\nType this:\n\n");
    printf("%s\n", phrases[index]);
    printf("Your input: ");
}

int main() {
    srand(time(0)); // Seed random number generator
    int phrase_index = rand() % NUM_PHRASES; // Pick a random phrase

    display_intro(); // Show introductory instructions

    // Display the phrase to type
    display_phrase(phrase_index);

    char user_input[MAX_LENGTH];
    time_t start_time, end_time;

    // Start timer
    start_time = time(NULL);

    // Get user input
    fgets(user_input, sizeof(user_input), stdin);

    // End timer
    end_time = time(NULL);

    // Trim the newline character from the input
    size_t len = strlen(user_input);
    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }

    // Analyze the result
    printf("\n===========================================\n");
    if (strcmp(user_input, phrases[phrase_index]) == 0) {
        printf("Well done! Your typing was correct!\n");
        printf("Time taken: %ld seconds\n", end_time - start_time);
        double words_per_minute = (strlen(user_input) / 5.0) / ((end_time - start_time) / 60.0);
        printf("Your typing speed: %.2f WPM (Words Per Minute)\n", words_per_minute);
    } else {
        printf("Oops! Your typing was incorrect.\n");
        printf("You typed:\n\"%s\"\nBut the correct phrase was:\n\"%s\"\n", user_input, phrases[phrase_index]);
    }

    printf("===========================================\n");
    printf("Thank you for participating! Press Enter to exit.\n");
    getchar(); // Pause before exiting

    return 0;
}