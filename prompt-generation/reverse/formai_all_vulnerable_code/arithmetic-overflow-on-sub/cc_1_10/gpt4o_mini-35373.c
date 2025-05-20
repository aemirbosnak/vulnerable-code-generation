//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_LENGTH 1024
#define MAX_INPUT_LENGTH 1024

// Function declarations
void clearBuffer();
void showInstructions();
void calculateWPM(double seconds, int wordCount);
int getWordCount(const char *text);
void getUserInput(char *input, int maxLength);

int main() {
    const char *sampleText = "The quick brown fox jumps over the lazy dog. This sentence is often used to test typing speed.";
    char userInput[MAX_INPUT_LENGTH];
    clock_t startTime, endTime;

    showInstructions();

    printf("\nType the following text:\n\n%s\n\n", sampleText);
    printf("Press Enter when you are ready to start...\n");
    clearBuffer();

    // Start the timer
    startTime = clock();

    // Get user input
    getUserInput(userInput, MAX_INPUT_LENGTH);

    // Stop the timer
    endTime = clock();

    // Calculate the time taken
    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    
    // Calculate the word count of the original and user input
    int originalWordCount = getWordCount(sampleText);
    int userWordCount = getWordCount(userInput);

    // Display results
    printf("\nYou typed:\n%s\n", userInput);
    printf("\nTime taken: %.2f seconds\n", timeTaken);
    calculateWPM(timeTaken, userWordCount);
    printf("Original text had %d words.\n", originalWordCount);
    printf("You typed %d words.\n", userWordCount);

    return 0;
}

// Function to show instructions
void showInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type. Try to type it as fast and accurately as possible.\n");
}

// Function to calculate and display Words Per Minute (WPM)
void calculateWPM(double seconds, int wordCount) {
    if (seconds == 0.0) {
        printf("Error: Time taken is zero.\n");
        return;
    }
    double minutes = seconds / 60.0;
    double wpm = wordCount / minutes;
    printf("Your typing speed is: %.2f words per minute.\n", wpm);
}

// Function to count the number of words in a given text
int getWordCount(const char *text) {
    int count = 0;
    int inWord = 0;
    
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            inWord = 0; // We are outside a word
        } else {
            if (inWord == 0) { // We found a new word
                count++;
                inWord = 1;
            }
        }
    }
    return count;
}

// Function to clear the input buffer
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

// Function to get user input safely
void getUserInput(char *input, int maxLength) {
    if (fgets(input, maxLength, stdin) != NULL) {
        // Remove the trailing newline character
        input[strcspn(input, "\n")] = '\0';
    } else {
        input[0] = '\0'; // If input fails, set to empty string
    }
}