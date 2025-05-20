//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_SENTENCES 5
#define BUFFER_SIZE 256

// Define a list of sentences for the typing test
const char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "To be or not to be, that is the question.",
    "A journey of a thousand miles begins with a single step.",
    "All that glitters is not gold.",
    "Brevity is the soul of wit."
};

// Function for choosing a random sentence
const char* get_random_sentence() {
    return sentences[rand() % MAX_SENTENCES];
}

// Function to calculate time taken in seconds
double get_time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

// Function to clear the console
void clear_console() {
    // ANSI escape sequence to clear screen
    printf("\033[H\033[J");
}

// Function to display the typing test
void typing_test() {
    char input[BUFFER_SIZE];
    double elapsed_time;
    struct timespec start_time, end_time;

    // Select a random sentence
    const char *sentence = get_random_sentence();
    
    // Clear the console and display the sentence
    clear_console();
    printf("Type the following sentence as fast as you can:\n\n");
    printf("\"%s\"\n\n", sentence);
    printf("Press Enter when you are ready...\n");
    getchar();

    // Start the timer
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Read user input
    printf("\nStart typing:\n");
    fgets(input, sizeof(input), stdin);

    // Stop the timer
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = get_time_diff(start_time, end_time);

    // Evaluate the test
    clear_console();
    printf("You typed:\n\"%s\"\n", input);
    printf("The correct sentence was:\n\"%s\"\n", sentence);

    // Calculate typing speed in WPM
    int words_typed = 0;
    char *word = strtok(input, " \n");
    while (word != NULL) {
        words_typed++;
        word = strtok(NULL, " \n");
    }
    double wpm = (words_typed / 5.0) / (elapsed_time / 60.0);

    // Display results
    printf("Elapsed time: %.2f seconds\n", elapsed_time);
    printf("Words Per Minute (WPM): %.2f\n", wpm);
    printf("Thank you for participating!\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    while (1) {
        typing_test();
        printf("\nWould you like to try again? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            break;
        }
        getchar(); // Clear newline character from buffer
    }

    printf("Goodbye!\n");
    return 0;
}