//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 255
#define TEST_SENTENCE "The quick brown fox jumps over the lazy dog."

void clearScreen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void displayInstructions() {
    printf("Typing Speed Test\n");
    printf("==================\n");
    printf("Type the following sentence as quickly as you can:\n\n");
    printf("\"%s\"\n\n", TEST_SENTENCE);
    printf("Press Enter when you are ready to start...\n");
    getchar();
}

int main() {
    char userInput[MAX_INPUT_LENGTH];
    clock_t startTime, endTime;
    double timeTaken;
    int wordCount;

    clearScreen();
    displayInstructions();

    clearScreen();
    printf("Get ready! The test will start shortly...\n");
    sleep(3); // Wait for 3 seconds

    clearScreen();
    printf("Type now:\n\n");
    
    startTime = clock(); // Start timing

    printf("\"%s\"\n\n", TEST_SENTENCE);

    // Read user input
    fgets(userInput, sizeof(userInput), stdin);

    // End timing
    endTime = clock();
    
    // Calculate the time taken in seconds
    timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Calculate the number of words typed by the user
    wordCount = 0;
    char *token = strtok(userInput, " \n"); // Tokenizing input based on space and newline
    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " \n");
    }

    // Calculate words per minute (WPM)
    double wpm = (wordCount / timeTaken) * 60;

    clearScreen();
    printf("Test complete!\n");
    printf("==================\n");
    printf("Words Typed: %d\n", wordCount);
    printf("Time Taken: %.2f seconds\n", timeTaken);
    printf("Typing Speed: %.2f words per minute (WPM)\n", wpm);
    printf("==================\n");

    // Give feedback based on performance criteria
    if (wpm < 20) {
        printf("Keep practicing, you'll get there!\n");
    } else if (wpm < 40) {
        printf("Not bad! A little more practice will help you improve.\n");
    } else {
        printf("Excellent! You're a fast typist!\n");
    }
    
    return 0;
}