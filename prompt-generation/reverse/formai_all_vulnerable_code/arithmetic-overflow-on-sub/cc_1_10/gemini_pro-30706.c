//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    // Initialize variables
    int correct = 0, incorrect = 0, total = 0;
    char input[100];
    char quote[] = "To be or not to be, that is the question.";

    // Start the timer
    clock_t start = clock();

    // Prompt the user to start typing
    printf("Start typing the following quote:\n\"%s\"\n", quote);

    // Get the user's input
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Check the user's input for accuracy
    for (int i = 0; i < strlen(quote); i++) {
        if (tolower(input[i]) == tolower(quote[i])) {
            correct++;
        } else {
            incorrect++;
        }
    }

    // Calculate the total number of characters typed
    total = strlen(input);

    // Calculate the typing speed in words per minute (WPM)
    double wpm = ((double)correct / 5) / (time_taken / 60);

    // Display the results
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Total: %d\n", total);
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typing speed: %.2f WPM\n", wpm);

    return 0;
}