//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 256

void clearScreen() {
    // Clear the console screen
    printf("\033[H\033[J");
}

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type as quickly as possible.\n");
    printf("You will have 30 seconds to complete the test. Press Enter to begin.\n");
}

void countdown(int seconds) {
    while (seconds > 0) {
        printf("\rStarting in... %d", seconds);
        fflush(stdout);
        sleep(1);
        seconds--;
    }
    printf("\r                         \n"); // Clear the line
}

void typingTest(const char* sentence) {
    char input[MAX_STRING_LENGTH];
    int totalTime = 30;
    clock_t startTime, endTime;
    
    printf("Here is your sentence:\n");
    printf("\"%s\"\n", sentence);
    printf("You have 30 seconds. Start typing when you're ready!\n");
    
    startTime = clock();
    
    // Read user input
    fgets(input, MAX_STRING_LENGTH, stdin);
    
    endTime = clock();
    
    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC; // Time taken in seconds
    int totalCharsTyped = strlen(input) - 1; // Exclude the newline character

    int correctChars = 0;
    for (int i = 0; i < strlen(sentence) && i < totalCharsTyped; i++) {
        if (input[i] == sentence[i]) {
            correctChars++;
        }
    }

    printf("You typed: %s", input);
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Total characters typed: %d\n", totalCharsTyped);
    printf("Correct characters: %d\n", correctChars);
    if (timeTaken > 0) {
        double wpm = (correctChars / 5.0) / (timeTaken / 60.0); // Words per minute calculation
        printf("Your typing speed: %.2f WPM\n", wpm);
    }
}

int main() {
    const char* testSentence = "The quick brown fox jumps over the lazy dog.";
    
    clearScreen();
    displayInstructions();
    
    // Waiting for user input to start
    getchar();
    
    countdown(3);
    clearScreen();
    
    typingTest(testSentence);
    
    return 0;
}