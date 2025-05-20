//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 256
#define SENTENCE_COUNT 5

// Sample sentences for the typing test.
const char *sentences[SENTENCE_COUNT] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be, or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the midst of chaos, there is also opportunity."
};

// Function to clear the standard output before displaying the current sentence.
void clearScreen() {
    printf("\033[H\033[J");
}

// Function to display the current sentence and return the elapsed time.
double typingTest(const char *sentence) {
    char userInput[MAX_LENGTH];
    time_t startTime, endTime;

    printf("Type the following sentence:\n");
    printf("--------------------------------------------------\n");
    printf("%s\n", sentence);
    printf("--------------------------------------------------\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for the user to press Enter
    clearScreen();

    startTime = time(NULL); // Record the start time
    printf("Start typing now!\n");

    // Read user input
    fgets(userInput, MAX_LENGTH, stdin);
    
    endTime = time(NULL); // Record the end time

    // Calculate the elapsed time in seconds
    double elapsedTime = difftime(endTime, startTime);
    
    // Remove the newline character from userInput
    userInput[strcspn(userInput, "\n")] = 0;

    // Return elapsed time
    return elapsedTime;
}

// Function to calculate typing speed in words per minute (WPM)
double calculateWPM(const char *input, double elapsedTime) {
    int wordCount = 0;
    const char *ptr = input;

    while (*ptr) {
        if (*ptr == ' ') {
            wordCount++;
        }
        ptr++;
    }

    // Include the last word if there's no space at the end
    if (wordCount > 0) {
        wordCount++;
    }

    // Convert elapsed time to minutes
    double minutes = elapsedTime / 60.0;

    // Calculate WPM
    double wpm = wordCount / minutes;
    return wpm;
}

// Main function to coordinate the typing test
int main() {
    int score, testIndex;
    printf("Welcome to the Typing Speed Test!\n");
    printf("----------------------------------\n");
    
    while (1) {
        // Randomly select a sentence
        srand(time(NULL));
        testIndex = rand() % SENTENCE_COUNT;
        
        // Conduct typing test
        double timeTaken = typingTest(sentences[testIndex]);
        double wpm = calculateWPM(sentences[testIndex], timeTaken);

        // Display results
        printf("--------------------------------------------------\n");
        printf("Time taken: %.2f seconds\n", timeTaken);
        printf("Your typing speed: %.2f WPM\n", wpm);
        printf("Would you like to take the test again? (y/n): ");
        
        char option = getchar();
        getchar(); // Consume newline character

        if (option != 'y' && option != 'Y') {
            break;
        }
        clearScreen();
    }

    printf("Thank you for participating in the Typing Speed Test!\n");
    return 0;
}