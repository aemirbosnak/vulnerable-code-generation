//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define TEST_PHRASE "The quick brown fox jumps over the lazy dog."
#define PROMPT "Type the following phrase as fast as you can:\n\n"

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void displayInstructions() {
    printf("Welcome to the C Typing Speed Test!\n");
    printf("Try to type the given phrase as quickly as possible.\n");
    printf("Let's see how fast you can type!\n\n");
}

int main() {
    char input[BUFFER_SIZE];
    clock_t startTime, endTime;
    double timeTaken;
    
    clearScreen();
    displayInstructions();

    printf("%s", PROMPT);
    printf("%s\n\n", TEST_PHRASE);
    sleep(2); // Give the user time to prepare
    clearScreen();

    printf("Start typing now:\n");

    startTime = clock();

    // Get user input
    fgets(input, BUFFER_SIZE, stdin);
    // Remove the newline character from fgets
    input[strcspn(input, "\n")] = 0;

    endTime = clock();

    // Calculate the time taken in seconds
    timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Display results
    printf("\nThank you for typing!\n");
    printf("You typed: %s\n", input);
    
    // Check if the input matches the test phrase
    if (strcmp(input, TEST_PHRASE) == 0) {
        printf("Congratulations! You typed it correctly!\n");
    } else {
        printf("Oops! There was a mistake. Try again!\n");
    }

    printf("Time taken: %.2f seconds\n", timeTaken);
    
    // Calculate and print typing speed in words per minute (WPM)
    int wordsTyped = (int)(strlen(input) / 5.0); // Rough estimate of words
    double wpm = (wordsTyped / timeTaken) * 60.0;
    
    printf("Your typing speed: %.2f WPM\n", wpm);
    
    // Thank the user
    printf("\nThanks for playing the Typing Speed Test! Have a great day!\n");

    return 0;
}