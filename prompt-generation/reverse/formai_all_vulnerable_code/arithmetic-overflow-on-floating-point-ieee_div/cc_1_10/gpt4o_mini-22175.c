//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH 256

// Sample sentences for typing test
const char *sentences[] = {
    "The quick brown fox jumps over the lazy dog.",
    "To be or not to be, that is the question.",
    "A journey of a thousand miles begins with a single step.",
    "All that glitters is not gold.",
    "The early bird catches the worm."
};

// Function to clear the screen
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to provide a random sentence
const char* get_random_sentence() {
    int index = rand() % (sizeof(sentences) / sizeof(sentences[0]));
    return sentences[index];
}

// Function to calculate time difference in seconds
double time_difference(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + 
           (end.tv_nsec - start.tv_nsec) / 1e9;
}

// Typing test function
void typing_test() {
    char input[MAX_LENGTH];
    
    clear_screen();
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following sentence as fast as you can:\n");

    const char *sentence = get_random_sentence();
    printf(">> %s\n\n", sentence);

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    printf("Your Input: ");
    fgets(input, sizeof(input), stdin);
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Calculate time taken
    double time_taken = time_difference(start, end);
    
    // Check if the input matches the sentence
    if (strcmp(input, sentence) == 0) {
        printf("\nGreat job! You typed it correctly!\n");
    } else {
        printf("\nOops! There were some mistakes in your typing.\n");
    }

    // Calculate speed (words per minute)
    int words_count = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') {
            words_count++;
        }
    }

    double wpm = (words_count / time_taken) * 60;
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Your typing speed is: %.2f words per minute.\n", wpm);
}

// Main function
int main() {
    srand(time(NULL)); // Seed the random number generator
    char play_again;

    do {
        typing_test();
        printf("\nDo you want to try again? (Y/N): ");
        scanf(" %c", &play_again);
        clear_screen();
    } while (play_again == 'Y' || play_again == 'y');

    printf("Thank you for playing! Keep practicing!\n");
    return 0;
}