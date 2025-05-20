//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 256
#define SAMPLE_TEXT "The quick brown fox jumps over the lazy dog."
#define WORD_COUNT 9

// Function to clear the input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Function to display the instructions and the sample text
void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type.\n");
    printf("Your task is to type the following sentence as quickly and accurately as possible:\n");
    printf("--------------------------------------------------------------------------\n");
    printf("\"%s\"\n", SAMPLE_TEXT);
    printf("--------------------------------------------------------------------------\n");
    printf("Press Enter when you are ready to start...\n");
    clearInputBuffer();
}

// Function to calculate the typing speed in words per minute
double calculateWPM(double seconds) {
    return (WORD_COUNT / seconds) * 60.0;
}

// Main function
int main() {
    char input[BUFFER_SIZE];
    clock_t startTime, endTime;
    double timeTaken, wpm;

    displayInstructions();

    // Wait for the user to press Enter
    getchar();

    // Start the timer
    startTime = clock();

    // Get user input
    printf("Start typing now: ");
    fgets(input, BUFFER_SIZE, stdin);

    // Stop the timer
    endTime = clock();

    // Calculate the time taken in seconds
    timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Remove the newline character from input if present
    input[strcspn(input, "\n")] = '\0';

    // Compare input with the original text
    if (strcmp(input, SAMPLE_TEXT) == 0) {
        printf("Well done! You typed the sentence correctly.\n");
    } else {
        printf("Your input did not match the original sentence.\n");
    }

    // Calculate and display typing speed
    wpm = calculateWPM(timeTaken);
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Typing speed: %.2f words per minute (WPM)\n", wpm);

    return 0;
}