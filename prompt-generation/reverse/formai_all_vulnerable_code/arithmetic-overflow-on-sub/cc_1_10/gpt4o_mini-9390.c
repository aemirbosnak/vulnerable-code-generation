//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 256
#define NUM_TESTS 5

const char *sampleTexts[NUM_TESTS] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of difficulty lies opportunity."
};

void clearScreen() {
    // Clear the console screen for a retro feel
    printf("\033[H\033[J");
}

void printHeader() {
    clearScreen();
    printf("*************************************\n");
    printf("    Welcome to the Typing Speed Test  \n");
    printf("*************************************\n\n");
}

void printInstructions(const char *text) {
    printf("Type the following text as fast as you can:\n\n");
    printf("\"%s\"\n\n", text);
    printf("Press Enter when you are ready to start typing...\n");
    getchar(); // Wait for the user to press Enter
}

int calculateSpeed(double timeTaken, int charCount) {
    return (int)((charCount / 5.0) / (timeTaken / 60)); // WPM conversion
}

void runTest() {
    int testIndex = rand() % NUM_TESTS;
    const char *selectedText = sampleTexts[testIndex];
    char userInput[MAX_LENGTH];

    printInstructions(selectedText);

    clock_t start = clock();
    printf("\nStart typing now:\n");

    fgets(userInput, MAX_LENGTH, stdin);
    clock_t end = clock();

    // Measure time taken in seconds
    double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

    // Count the number of characters typed (excluding newline)
    int charCount = strlen(userInput);
    if (userInput[charCount - 1] == '\n') {
        userInput[--charCount] = '\0'; // Remove newline character
    }

    printf("\nYou typed %d characters in %.2f seconds.\n", charCount, timeTaken);
    int wpm = calculateSpeed(timeTaken, charCount);
    printf("Your typing speed is: %d WPM\n\n", wpm);
}

void printFarewell() {
    printf("Thank you for participating in the Typing Speed Test!\n");
    printf("Goodbye!\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator
    printHeader();

    for (int i = 0; i < 3; i++) { // Run the test three times
        runTest();
        printf("Press Enter to continue to the next test...\n");
        getchar();
    }

    printFarewell();
    return 0;
}