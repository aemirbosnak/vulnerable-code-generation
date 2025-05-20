//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SENTENCES 5
#define MAX_LENGTH 256

// List of sentences to use for the typing test
const char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of difficulty lies opportunity."
};

// Function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to measure typing speed
void measure_typing_speed(const char *sentence) {
    char input[MAX_LENGTH];
    clock_t start, end;
    double time_taken;

    printf("\nType the following sentence:\n");
    printf("\"%s\"\n", sentence);
    printf("Press ENTER when you are ready to start...\n");
    clear_input_buffer();
    
    // Start timer
    start = clock();

    // Get user input
    printf("Start typing: ");
    fgets(input, sizeof(input), stdin);

    // Stop timer
    end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC; // Time in seconds

    // Replace newline character with a null terminator if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Calculate typing speed in WPM
    int word_count = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }
    
    double wpm = (word_count / time_taken) * 60; // Words per minute

    // Display results
    printf("\nYou typed: \"%s\"\n", input);
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Your typing speed: %.2f WPM\n", wpm);

    // Check if the input matches the sentence or not
    if (strcmp(input, sentence) == 0) {
        printf("Congratulations! You typed the sentence correctly.\n");
    } else {
        printf("Oops! There's a mistake in your typing.\n");
    }
}

int main() {
    int choice;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Choose a sentence to test your typing speed:\n");

    for (int i = 0; i < MAX_SENTENCES; i++) {
        printf("%d. %s\n", i + 1, sentences[i]);
    }
    
    printf("Enter the number of the sentence you want to type (1-%d): ", MAX_SENTENCES);
    scanf("%d", &choice);
    clear_input_buffer();

    if (choice < 1 || choice > MAX_SENTENCES) {
        printf("Invalid choice. Please run the program again.\n");
        return 1;
    }

    measure_typing_speed(sentences[choice - 1]);

    return 0;
}