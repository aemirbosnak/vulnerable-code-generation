//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 500
#define MAX_INPUT_LENGTH 500

void displayInstructions() {
    printf("=== Typing Speed Test ===\n");
    printf("Type the following text as fast as you can:\n");
    printf("Press ENTER when you finish.\n");
}

void generateRandomText(char *text) {
    const char *sampleTexts[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Pack my box with five dozen liquor jugs.",
        "How vexingly quick daft zebras jump!",
        "Sphinx of black quartz, judge my vow.",
        "Bright vixens jump; dozy fowl quack.",
        "A blazing sun flies high over amazing horizons."
    };
    int numTexts = sizeof(sampleTexts) / sizeof(sampleTexts[0]);

    srand(time(NULL));
    strcpy(text, sampleTexts[rand() % numTexts]);
}

double calculateSpeed(int charCount, double seconds) {
    return (charCount / seconds) * 60; // words per minute
}

int main() {
    char randomText[MAX_TEXT_LENGTH];
    char userInput[MAX_INPUT_LENGTH];
    clock_t startTime, endTime;

    displayInstructions();

    // Generate a random text for the user to type
    generateRandomText(randomText);
    printf("\nText to type:\n%s\n\n", randomText);

    // Start the stopwatch
    printf("Ready... Type now!\n");
    startTime = clock();

    // Get the user input
    fgets(userInput, MAX_INPUT_LENGTH, stdin);
    
    // End the stopwatch
    endTime = clock();
    
    // Check if the user input matches the random text
    userInput[strcspn(userInput, "\n")] = 0; // Remove trailing newline
    int charCount = strlen(userInput);
    
    if (strcmp(userInput, randomText) == 0) {
        printf("\nExcellent, you typed it correctly!\n");
    } else {
        printf("\nOops, there's a mistake. Try again!\n");
    }

    // Calculate time taken
    double seconds = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
    
    // Calculate and display typing speed
    double speed = calculateSpeed(charCount, seconds);
    printf("Time taken: %.2f seconds\n", seconds);
    printf("Your typing speed: %.2f characters per minute\n", speed);
    
    return 0;
}