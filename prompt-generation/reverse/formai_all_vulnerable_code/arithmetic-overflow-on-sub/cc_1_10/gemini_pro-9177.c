//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Initialize global variables
char text[] = "The quick brown fox jumps over the lazy dog.";
char user_input[100];
int time_elapsed;
int errors;
float wpm;

// Main function
int main() {
    // Display instructions to the user
    printf("**Typing Speed Test**\n\n");
    printf("Rules:\n");
    printf("1. You will be given a sentence to type.\n");
    printf("2. Type the sentence as quickly and accurately as possible.\n");
    printf("3. Your typing speed will be calculated in words per minute (WPM).\n\n");

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    printf("Type the following sentence:\n%s\n", text);
    fgets(user_input, sizeof(user_input), stdin);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time elapsed
    time_elapsed = (int)(end - start) / CLOCKS_PER_SEC;

    // Calculate the number of errors
    errors = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] != user_input[i]) {
            errors++;
        }
    }

    // Calculate the WPM
    wpm = (float)(strlen(text) - errors) / 5 / time_elapsed * 60;

    // Display the results
    printf("\n**Results**\n");
    printf("Errors: %d\n", errors);
    printf("Time elapsed: %d seconds\n", time_elapsed);
    printf("WPM: %.2f\n\n", wpm);

    return 0;
}