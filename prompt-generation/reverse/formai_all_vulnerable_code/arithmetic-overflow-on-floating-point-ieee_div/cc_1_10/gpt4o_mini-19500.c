//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// The ultimate typing speed test program - Built with Orwellian paranoia in mind
#define MAX_WORDS 50
#define MAX_LENGTH 20
#define SAMPLE_TEXT "The quick brown fox jumps over the lazy dog. Every keystroke you make is being recorded."

void clearScreen() {
    // A simple function to clear the terminal screen (use with caution)
    printf("\033[H\033[J"); // ANSI escape codes to clear the terminal
}

void showInstructions() {
    clearScreen();
    printf("Welcome to the Typing Speed Test!\n");
    printf("Your typing will be monitored closely.\n");
    printf("Type the following sentence as quickly and accurately as you can:\n");
    printf("\"%s\"\n", SAMPLE_TEXT);
    printf("Press ENTER to start, and do not try to cheat!\n");
    getchar(); // Waits for user input to proceed
}

void recordStartTime(clock_t *start) {
    *start = clock(); // Start the clock for timing the typing duration
}

void recordEndTime(clock_t start, clock_t *end) {
    *end = clock(); // Record the end time
}

void calculateSpeed(clock_t start, clock_t end, int charsTyped) {
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC; // Calculate time in seconds
    double wordsPerMinute = (charsTyped / 5.0) / (timeSpent / 60.0); // WPM calculation (5 chars per word average)

    printf("\nYou typed %d characters in %.2f seconds.\n", charsTyped, timeSpent);
    printf("Your typing speed is: %.2f words per minute.\n", wordsPerMinute);
}

int main() {
    char input[MAX_LENGTH];
    clock_t start, end;
    int charsTyped = 0;

    showInstructions();

    // The moment of truth begins now!
    recordStartTime(&start);

    // Input loop
    printf("Your text: ");
    fgets(input, sizeof(input), stdin);

    // Counting characters typed (removing newline)
    charsTyped = strlen(input) - 1; // Exclude the newline character

    // Check if the input matches the sample text
    if (strcmp(input, SAMPLE_TEXT "\n") == 0) {
        printf("Perfect match! The algorithms are satisfied.\n");
    } else {
        printf("Mismatch detected! Stay vigilant; the system is watching.\n");
    }

    // End timing
    recordEndTime(start, &end);
    
    // Finally calculate the typing speed
    calculateSpeed(start, end, charsTyped);

    // Remain paranoid
    printf("Watch out! Your typing patterns might be analyzed...\n");

    return 0;
}