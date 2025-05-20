//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 512
#define TIME_LIMIT 60 // in seconds

void displayInstructions(const char *text) {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type the following text:\n\n", TIME_LIMIT);
    printf("------------------------------------------------------\n\n");
    printf("%s\n\n", text);
    printf("------------------------------------------------------\n\n");
    printf("Press Enter to start...");
    getchar();
}

void calculateResults(const char *input, const char *original, clock_t startTime, clock_t endTime) {
    int totalTime = (endTime - startTime) / CLOCKS_PER_SEC;
    int inputLength = strlen(input);
    int originalLength = strlen(original);
    int correctCharacters = 0;

    for (int i = 0; i < inputLength && i < originalLength; i++) {
        if (input[i] == original[i]) {
            correctCharacters++;
        }
    }

    double accuracy = ((double)correctCharacters / originalLength) * 100;
    double typingSpeed = (inputLength / 5.0) / (totalTime / 60.0); // WPM

    printf("\n------------------- Results -------------------\n");
    printf("Total Time: %d seconds\n", totalTime);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing Speed: %.2f words per minute\n", typingSpeed);
    printf("-----------------------------------------------\n");
}

void typingTest(const char *text) {
    char userInput[MAX_TEXT_LENGTH];
    clock_t startTime, endTime;
    int timeExceeded = 0;

    displayInstructions(text);

    startTime = clock();
    printf("\nStart typing now:\n");
    
    if (fgets(userInput, MAX_TEXT_LENGTH, stdin) == NULL) {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    
    endTime = clock();

    // Check if the time limit was exceeded
    if ((endTime - startTime) / CLOCKS_PER_SEC > TIME_LIMIT) {
        timeExceeded = 1;
    }

    // Remove newline character from user input
    userInput[strcspn(userInput, "\n")] = '\0';

    // If time exceeded
    if (timeExceeded) {
        printf("Time limit exceeded! You exceeded %d seconds.\n", TIME_LIMIT);
    }

    calculateResults(userInput, text, startTime, endTime);
}

const char *getSampleText() {
    return "The quick brown fox jumps over the lazy dog. "
           "A journey of a thousand miles begins with a single step. "
           "To be yourself in a world that is constantly trying to make you something else is the greatest accomplishment.";
}

int main() {
    const char *sampleText = getSampleText();
    typingTest(sampleText);
    return 0;
}