//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 1024
#define SAMPLE_TEXT "The quick brown fox jumps over the lazy dog."
#define TEXT_LENGTH 43 // Length of SAMPLE_TEXT

void display_instructions() {
    printf("Typing Speed Test\n");
    printf("==================\n");
    printf("Type the following sentence as quickly and accurately as you can:\n");
    printf("\"%s\"\n\n", SAMPLE_TEXT);
    printf("Press Enter when you are ready to start...\n");
    getchar(); // Wait for user to press Enter
}

double measure_typing_time() {
    char input[MAX_INPUT_LENGTH];
    
    // Record the start time
    clock_t start_time = clock();
    
    // User Input
    printf("Start typing now:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Record the end time
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    return time_taken;
}

void calculate_speed(double time_taken, const char *input) {
    int input_length = strlen(input);
    if (input_length > 0 && input[input_length - 1] == '\n') {
        input_length--; // Remove the newline character
    }
    
    // Calculate words (we consider a word to be any combination of characters with spaces)
    int word_count = 0;
    for (int i = 0; i < input_length; i++) {
        if (input[i] == ' ' || input[i] == '\n') {
            word_count++;
        }
    }
    // Add one more word if the last word is not followed by a space or newline.
    if (input_length > 0 && input[input_length - 1] != ' ' && input[input_length - 1] != '\n') {
        word_count++;
    }

    // Calculate typing speed in words per minute
    double minutes_taken = time_taken / 60.0;
    double speed = word_count / minutes_taken;
    
    printf("\nYour Typing Speed: %.2f words per minute.\n", speed);
}

void check_accuracy(const char *input) {
    // Compare the user's input with the sample text
    if (strcmp(input, SAMPLE_TEXT) == 0 || strcmp(input, "The quick brown fox jumps over the lazy dog.\n") == 0) {
        printf("Your input is correct!\n");
    } else {
        printf("Your input had errors. Let's check...\n");
        printf("Expected: \"%s\"\n", SAMPLE_TEXT);
        printf("Your Input: \"%s\"\n", input);
    }
}

int main() {
    display_instructions();

    double time_taken = measure_typing_time();
    
    // Buffer for user’s input
    char input[MAX_INPUT_LENGTH];
    // Read user input to check for accuracy
    printf("Please type the text exactly as it appears:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // Calculate speed and accuracy
    calculate_speed(time_taken, input);
    check_accuracy(input);
    
    printf("\nThank you for participating in the typing speed test! Goodbye.\n");

    return 0;
}