//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PHRASE_LENGTH 256

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with a phrase to type.\n");
    printf("Type the phrase as quickly as you can after pressing Enter.\n");
    printf("Let's see how fast you can type!\n\n");
}

void displayPhrase(const char *phrase) {
    printf("Your phrase is:\n");
    printf("\"%s\"\n", phrase);
}

void calculateSpeed(clock_t start, clock_t end, int characterCount) {
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;  // Time in seconds
    double speed = (double)characterCount / timeTaken;           // Characters per second
    printf("Your typing speed: %.2f characters per second\n", speed);
}

int main() {
    const char *phrase = "The quick brown fox jumps over the lazy dog";
    char input[MAX_PHRASE_LENGTH];
    
    displayInstructions();
    
    // Display the phrase to be typed
    displayPhrase(phrase);
    
    printf("Press Enter to start typing...\n");
    getchar();  // Wait for the user to press Enter

    clock_t startTime = clock();  // Start the timer
    printf("Start typing:\n");
    
    // Capture user input
    fgets(input, sizeof(input), stdin);
    
    // Measure end time
    clock_t endTime = clock();
    
    // Remove newline character from input if present
    input[strcspn(input, "\n")] = 0;

    // Check if the typed phrase matches the original
    if (strcmp(input, phrase) == 0) {
        printf("Great job! You typed the phrase correctly.\n");
    } else {
        printf("Oops! You didn't type the phrase exactly. Keep practicing!\n");
    }

    // Calculate and display typing speed
    calculateSpeed(startTime, endTime, strlen(input));

    return 0;
}