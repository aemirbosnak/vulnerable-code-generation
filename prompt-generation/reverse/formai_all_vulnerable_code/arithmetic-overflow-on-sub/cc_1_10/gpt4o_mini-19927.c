//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define TEXT_TO_TYPE "The quick brown fox jumps over the lazy dog."

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
}

int main() {
    char userInput[BUFFER_SIZE];
    clock_t startTime, endTime;
    double timeTaken;
    int correctCharacters = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You need to type the following text:\n");
    printf("\"%s\"\n\n", TEXT_TO_TYPE);
    
    printf("Press Enter to start...");
    clearInputBuffer(); // Clear input buffer before starting
    getchar(); // Wait for user to press Enter

    startTime = clock(); // Start the timer

    printf("Start typing:\n");
    if (fgets(userInput, BUFFER_SIZE, stdin) != NULL) {
        // Remove newline character from user input if present
        size_t len = strlen(userInput);
        if (len > 0 && userInput[len - 1] == '\n') {
            userInput[len - 1] = '\0';
        }
    } else {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    endTime = clock(); // End the timer

    // Calculate the time taken in seconds
    timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // Compare user input to the original text
    for (size_t i = 0; i < strlen(TEXT_TO_TYPE); i++) {
        if (userInput[i] == TEXT_TO_TYPE[i]) {
            correctCharacters++;
        }
    }

    // Display results
    printf("\nResults:\n");
    printf("You typed: \"%s\"\n", userInput);
    printf("Correct characters: %d out of %lu\n", correctCharacters, strlen(TEXT_TO_TYPE));
    printf("Time taken: %.2f seconds\n", timeTaken);
    
    // Calculate and display typing speed (characters per minute)
    double typingSpeed = (correctCharacters / timeTaken) * 60;
    printf("Typing Speed: %.2f characters per minute\n", typingSpeed);

    return EXIT_SUCCESS;
}