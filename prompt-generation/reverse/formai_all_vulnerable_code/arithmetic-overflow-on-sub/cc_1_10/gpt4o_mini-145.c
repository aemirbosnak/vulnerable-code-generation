//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Function prototypes
void displayIntroduction();
void getUserInput(char* userInput, int maxLen);
double calculateTypingSpeed(int duration, int sentenceLength);
void displayResults(int duration, double speed);
void cleanup();

#define MAX_INPUT_LENGTH 256
#define SENTENCE "The quick brown fox jumps over the lazy dog."

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Introduce the game
    displayIntroduction();
    
    // Prepare to take user input
    char userInput[MAX_INPUT_LENGTH];
    clock_t start, end;

    printf("Type the following sentence as fast as you can:\n");
    printf("\"%s\"\n\n", SENTENCE);
    
    // Start timer
    start = clock();
    
    // Get user input
    getUserInput(userInput, MAX_INPUT_LENGTH);
    
    // End timer
    end = clock();
    
    // Calculate duration in seconds
    int duration = (int)((end - start) / CLOCKS_PER_SEC);
    
    // Calculate typing speed
    double speed = calculateTypingSpeed(duration, strlen(SENTENCE));

    // Display results
    displayResults(duration, speed);
    
    // Cleanup and return
    cleanup();
    return 0;
}

// Display introduction information
void displayIntroduction() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have to type a sentence as fast and accurately as possible.\n");
    printf("Let's see how fast you can type!\n\n");
}

// Function to get user input
void getUserInput(char* userInput, int maxLen) {
    // Clear input buffer
    memset(userInput, 0, maxLen);
    
    // Prompt user for input
    fgets(userInput, maxLen, stdin);
    
    // Remove newline character if present
    userInput[strcspn(userInput, "\n")] = 0;
}

// Function to calculate typing speed
double calculateTypingSpeed(int duration, int sentenceLength) {
    if (duration == 0) {
        return 0.0; // Avoid division by zero
    }
    return (double)sentenceLength / (duration / 60.0); // Speed in characters per minute
}

// Function to display results
void displayResults(int duration, double speed) {
    printf("\nYou took %d seconds to type the sentence.\n", duration);
    printf("Your typing speed was %.2f characters per minute.\n", speed);
    if (speed > 40) {
        printf("Great job! You're a fast typist!\n");
    } else if (speed > 20) {
        printf("Not bad! A little more practice, and you'll improve.\n");
    } else {
        printf("Keep practicing, and you'll get faster!\n");
    }
}

// Cleanup function (if needed)
void cleanup() {
    // Currently, this function doesn't perform any actions,
    // but it's kept for future development if needed.
}