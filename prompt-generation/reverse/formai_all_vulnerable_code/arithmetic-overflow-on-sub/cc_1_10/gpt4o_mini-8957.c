//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define PHRASE "The quick brown fox jumps over the lazy dog"
#define WORD_COUNT 9

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void displayInstructions() {
    printf("Typing Speed Test\n");
    printf("==================\n");
    printf("Type the following phrase:\n\n");
    printf("\"%s\"\n\n", PHRASE);
    printf("Press Enter to start...\n");
    getchar();
}

double calculateWPM(int timeTaken, int wordCount) {
    return (double)wordCount / (timeTaken / 60.0);
}

int main() {
    clearScreen();
    displayInstructions();

    clock_t startTime = clock();

    char userInput[256];
    printf("Start typing now:\n");
    fgets(userInput, sizeof(userInput), stdin);

    clock_t endTime = clock();
    double timeTakenInSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Remove trailing newline character from fgets input
    userInput[strcspn(userInput, "\n")] = 0;

    clearScreen();
    printf("Time taken: %.2f seconds\n", timeTakenInSeconds);

    if (strcmp(userInput, PHRASE) == 0) {
        printf("Perfect match!\n");
    } else {
        printf("Your input was different!\n");
        printf("Expected: \"%s\"\n", PHRASE);
        printf("Your input: \"%s\"\n", userInput);
    }

    double wpm = calculateWPM(timeTakenInSeconds, WORD_COUNT);
    printf("Your typing speed: %.2f WPM\n", wpm);

    // Memory cleanup
    memset(userInput, 0, sizeof(userInput));

    printf("\nPress Enter to exit...\n");
    getchar();
    return 0;
}