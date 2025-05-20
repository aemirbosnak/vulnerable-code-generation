//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 255
#define SAMPLE_TEXT "The quick brown fox jumps over the lazy dog."
#define TIME_LIMIT 30

void displayInstructions() {
    printf("=== Typing Speed Test ===\n");
    printf("Type the following text as fast as you can:\n");
    printf("\"%s\"\n\n", SAMPLE_TEXT);
    printf("You have %d seconds to complete it. Press Enter when you're ready.\n", TIME_LIMIT);
    getchar(); // Wait for user to press Enter
}

int main() {
    displayInstructions();

    char userInput[MAX_LENGTH];
    clock_t startTime, endTime;

    printf("Start typing now!\n\n");
    startTime = clock();

    fgets(userInput, MAX_LENGTH, stdin);
    
    endTime = clock();

    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    if (timeTaken > TIME_LIMIT) {
        printf("Time's up! You exceeded the limit of %d seconds.\n", TIME_LIMIT);
        return 0;
    }

    // Compare user input with the sample text
    int errors = 0;
    int length = strlen(SAMPLE_TEXT);
    for (int i = 0; i < length; i++) {
        if (userInput[i] != SAMPLE_TEXT[i]) {
            errors++;
        }
    }

    // Calculate typing speed
    int charsTyped = strlen(userInput) - 1; // Exclude newline character
    double typingSpeed = ((charsTyped - errors) / timeTaken) * 60; // Characters per minute

    printf("\n=== Results ===\n");
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Characters typed: %d\n", charsTyped);
    printf("Errors: %d\n", errors);
    printf("Typing speed: %.2f CPM (corrected for errors)\n", typingSpeed);

    printf("\nThanks for participating! Press Enter to exit.\n");
    getchar(); // Wait for user to press Enter before exiting
    return 0;
}