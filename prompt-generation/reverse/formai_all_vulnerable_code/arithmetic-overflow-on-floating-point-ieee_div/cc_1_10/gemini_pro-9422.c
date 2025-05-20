//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    // Initialize variables
    char targetText[] = "The quick brown fox jumps over the lazy dog.";
    char inputText[100];
    int targetLength = strlen(targetText);
    int inputLength;
    clock_t start, end;
    double timeElapsed;
    int errors = 0;

    // Display instructions
    printf("** Typing Speed Test **\n\n");
    printf("Instructions:\n");
    printf("1. Read the target text carefully.\n");
    printf("2. Type the same text in the input box below.\n");
    printf("3. Press Enter to submit your response.\n\n");

    // Display target text
    printf("Target Text:\n");
    printf("%s\n\n", targetText);

    // Get input from user
    printf("Your Input:\n");
    fgets(inputText, sizeof(inputText), stdin);

    // Calculate input length
    inputLength = strlen(inputText);

    // Calculate time taken
    start = clock();
    end = clock();
    timeElapsed = (double)(end - start) / CLOCKS_PER_SEC;

    // Check for errors
    for (int i = 0; i < targetLength; i++) {
        if (inputText[i] != targetText[i]) {
            errors++;
        }
    }

    // Calculate typing speed
    double typingSpeed = (double)(inputLength - errors) / timeElapsed;

    // Display results
    printf("\nResults:\n");
    printf("Typing Speed: %.2f words per minute\n", typingSpeed * 60);
    printf("Errors: %d\n", errors);

    return 0;
}