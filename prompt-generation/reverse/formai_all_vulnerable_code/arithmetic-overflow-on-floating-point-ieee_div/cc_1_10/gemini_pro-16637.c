//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main() {
    // Initialize variables

    char *text = "This is a typing speed test. Type the following text as quickly and accurately as possible.";
    int text_length = strlen(text);
    char buffer[BUFFER_SIZE];
    int buffer_index = 0;
    int errors = 0;
    clock_t start_time, end_time;
    double time_elapsed;
    int wpm;

    // Start the timer
    start_time = clock();

    // Get input from the user
    printf("Type the following text:\n\n%s\n\n", text);
    while (1) {
        // Get the next character from the user
        char c = getchar();

        // Check if the user has finished typing
        if (c == '\n') {
            break;
        }

        // Check if the user has made an error
        if (c != text[buffer_index]) {
            errors++;
        }

        // Store the character in the buffer
        buffer[buffer_index++] = c;
    }

    // Stop the timer
    end_time = clock();

    // Calculate the time elapsed
    time_elapsed = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate the WPM
    wpm = (int)((buffer_index / 5) / time_elapsed);

    // Print the results
    printf("\n\nResults:\n");
    printf("Errors: %d\n", errors);
    printf("Time elapsed: %.2f seconds\n", time_elapsed);
    printf("WPM: %d\n", wpm);

    return 0;
}