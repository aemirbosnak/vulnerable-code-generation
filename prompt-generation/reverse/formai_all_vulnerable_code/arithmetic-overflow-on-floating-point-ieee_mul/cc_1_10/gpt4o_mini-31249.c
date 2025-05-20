//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 1024

void clearScreen() {
    // Clear the terminal screen (ANSI escape code)
    printf("\033[H\033[J");
}

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be shown a passage to type. Type it as fast as you can.\n");
    printf("Press Enter when you are finished.\n");
    printf("Good luck!\n\n");
}

void getPassage(char *passage) {
    printf("Please enter a passage for typing (press Enter on a new line to finish):\n");
    fgets(passage, MAX_LENGTH, stdin);
    size_t len = strlen(passage);
    if (len > 0 && passage[len - 1] == '\n') {
        passage[len - 1] = '\0';  // Remove the newline character
    }
}

void startTypingTest(char *passage) {
    char input[MAX_LENGTH];
    printf("Type the following passage:\n");
    printf("\"%s\"\n\n", passage);
    
    time_t startTime, endTime;
    time(&startTime);

    printf("Begin typing now:\n");
    fgets(input, MAX_LENGTH, stdin);
    time(&endTime);

    if (strcmp(input, passage) == 0) {
        printf("Great job! You typed the passage correctly.\n");
    } else {
        printf("Oops! There were some mistakes.\n");
    }

    double timeTaken = difftime(endTime, startTime);
    int wordsTyped = strlen(input) / 5;  // Approximate words
    double typingSpeed = (wordsTyped / timeTaken) * 60; // words per minute

    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Typing speed: %.2f WPM\n", typingSpeed);
}

int main() {
    char passage[MAX_LENGTH];

    clearScreen();
    displayInstructions();
    getPassage(passage);
    startTypingTest(passage);

    return 0;
}