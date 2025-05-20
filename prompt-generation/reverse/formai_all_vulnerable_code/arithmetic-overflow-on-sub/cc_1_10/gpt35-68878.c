//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define constants
#define MAX_LENGTH 100
#define NUM_TESTS 10

// Function to generate random strings of letters for typing test
char *generateRandomString(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + (rand() % 26);
    }
    string[length] = '\0';
    return string;
}

int main() {
    // Seed random number generator
    srand(time(0));

    // Define variables
    char input[MAX_LENGTH];
    char *generatedString;
    int successes = 0;
    int attempts = 0;
    clock_t start, end;
    double timeTaken;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following strings as fast as you can:\n");

    // Loop through and generate test strings
    for (int i = 0; i < NUM_TESTS; i++) {
        generatedString = generateRandomString(rand() % MAX_LENGTH);
        printf("%s\n", generatedString);

        // Record start time
        start = clock();

        // Get user input and record end time
        fgets(input, MAX_LENGTH, stdin);
        end = clock();

        // Compare input to generated string and record results
        if (strcmp(generatedString, input) == 0) {
            printf("Correct! Time taken: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
            successes++;
        } else {
            printf("Incorrect. Please try again.\n");
        }
        attempts++;

        // Free memory allocated for generated string
        free(generatedString);
    }

    // Calculate and display results
    timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n\nTyping speed test complete!\n");
    printf("You had %d successes out of %d attempts.\n", successes, NUM_TESTS);
    printf("Your typing accuracy was %.2f%%.\n", ((double)successes / (double)attempts) * 100);
    printf("Your average time per correct entry was %f seconds.\n", timeTaken / successes);

    return 0;
}