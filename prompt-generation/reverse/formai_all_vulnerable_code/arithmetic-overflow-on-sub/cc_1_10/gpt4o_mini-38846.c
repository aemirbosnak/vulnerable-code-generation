//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LENGTH 256
#define SAMPLE_TEXT "The quick brown fox jumps over the lazy dog"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void displayInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type.\n");
    printf("Type it as quickly and accurately as you can.\n\n");
    printf("Here is the sentence:\n");
    printf("\"%s\"\n\n", SAMPLE_TEXT);
    printf("Press Enter to start...\n");
    clearInputBuffer();
}

double calculateWPM(double timeInSeconds, int wordCount) {
    return (wordCount / timeInSeconds) * 60;
}

int main() {
    char input[MAX_LENGTH];
    char* token;
    int wordCount;
    clock_t startTime, endTime;
    double elapsedTime;

    displayInstructions();

    // Start the timer
    startTime = clock();

    // Get the user input
    fgets(input, sizeof(input), stdin);
    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;

    // End the timer
    endTime = clock();
    
    // Calculate elapsed time
    elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Count the words in the input
    wordCount = 0;
    token = strtok(input, " ");
    while (token != NULL) {
        wordCount++;
        token = strtok(NULL, " ");
    }

    // Calculate WPM
    double wpm = calculateWPM(elapsedTime, wordCount);

    // Check for accuracy
    if (strcmp(input, SAMPLE_TEXT) == 0) {
        printf("Perfectly typed!\n");
    } else {
        printf("There were errors in your typing. Keep practicing!\n");
    }

    // Print results
    printf("You typed %d words in %.2f seconds.\n", wordCount, elapsedTime);
    printf("Your typing speed is %.2f words per minute.\n", wpm);

    return 0;
}