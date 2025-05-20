//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with a sentence to type.\n");
    printf("Type the sentence as quickly as you can.\n");
    printf("Your typing speed will be calculated in words per minute (WPM).\n");
    printf("Press ENTER to begin...\n");
    getchar();
}

void getTestSentence(char *sentence) {
    // Sample sentence for typing practice
    strcpy(sentence, "The quick brown fox jumps over the lazy dog.");
}

int main(void) {
    char sentence[MAX_LENGTH];
    char userInput[MAX_LENGTH];
    clock_t startTime, endTime;
    double duration;
    int words, wpm;

    // Display instructions
    displayInstructions();

    // Get the test sentence
    getTestSentence(sentence);

    // Display the sentence to type
    printf("\nType the following sentence:\n");
    printf("\"%s\"\n", sentence);
    
    // Start the timer
    startTime = clock();

    // Get user input
    printf("Your input: ");
    fgets(userInput, MAX_LENGTH, stdin);
    
    // Stop the timer
    endTime = clock();

    // Calculate duration in seconds
    duration = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Remove newline from userInput
    userInput[strcspn(userInput, "\n")] = 0;

    // Count words in both sentences
    words = 0;
    for (int i = 0; userInput[i] != '\0'; i++) {
        if (userInput[i] == ' ' || userInput[i] == '\0') {
            words++;
        }
    }
    words++; // Add one for the last word

    // Calculate words per minute
    wpm = (int)((words / duration) * 60);

    // Display result
    printf("\nYou typed: \"%s\"\n", userInput);
    printf("Time taken: %.2f seconds\n", duration);
    printf("Your typing speed: %d words per minute (WPM)\n", wpm);
    
    // Close message
    printf("Thank you for participating in the typing speed test!\n");

    return 0;
}