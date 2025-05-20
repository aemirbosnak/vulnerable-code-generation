//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}

void displayWelcomeMessage() {
    clearScreen();
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following sentence as fast as you can:\n");
}

void displayInstructions(const char *sentence) {
    printf("\nYour sentence to type is:\n");
    printf("\"%s\"\n", sentence);
    printf("\nPress ENTER to start...");
    getchar();
}

void startTypingTest(const char *sentence) {
    char userInput[MAX_LENGTH];
    printf("\nStart typing now:\n");
    clock_t startTime = clock();
    
    // Reading user input
    fgets(userInput, MAX_LENGTH, stdin);
    
    clock_t endTime = clock();
    
    // Stripping new line character from userInput
    userInput[strcspn(userInput, "\n")] = 0;

    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC; // in seconds
    double wpm = (strlen(userInput) / 5.0) / (timeTaken / 60.0); // basic WPM calculation

    printf("\nTime taken: %.2f seconds\n", timeTaken);
    printf("Words per minute: %.2f\n", wpm);
}

int main() {
    const char *testSentence = "The quick brown fox jumps over the lazy dog.";
    
    displayWelcomeMessage();
    displayInstructions(testSentence);
    startTypingTest(testSentence);
    
    printf("\nThank you for participating! Press ENTER to exit...");
    getchar();
    return 0;
}