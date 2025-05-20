//Code Llama-13B DATASET v1.0 Category: Typing Speed Test ; Style: surprised
/*
 * C Typing Speed Test Example Program
 *
 * This program takes in a sentence or phrase from the user and then
 * tests their typing speed by displaying the sentence and then
 * asking them to type it back in. The program then calculates the
 * user's typing speed and displays the results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure for the user's typing speed results
typedef struct {
    int total_chars;
    double time_taken;
    double wpm;
} typing_speed_t;

// Define the function to calculate the user's typing speed
typing_speed_t calculate_typing_speed(char *sentence) {
    // Get the length of the sentence
    int sentence_length = strlen(sentence);

    // Prompt the user to type the sentence
    printf("Type the sentence below: ");

    // Initialize variables for the user's typing speed
    int total_chars = 0;
    double time_taken = 0;

    // Start the timer
    clock_t start = clock();

    // Loop until the user types the entire sentence
    while (total_chars < sentence_length) {
        // Get the next character from the user
        char c = getchar();

        // If the character is a newline, stop the loop
        if (c == '\n') {
            break;
        }

        // Otherwise, increment the total number of characters typed
        total_chars++;
    }

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken to type the sentence
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed in words per minute
    double wpm = (double)total_chars / 5 / time_taken;

    // Return the results
    typing_speed_t results = {
        .total_chars = total_chars,
        .time_taken = time_taken,
        .wpm = wpm
    };

    return results;
}

// Define the main function
int main() {
    // Define the sentence to be typed
    char sentence[] = "The quick brown fox jumps over the lazy dog.";

    // Calculate the user's typing speed
    typing_speed_t results = calculate_typing_speed(sentence);

    // Display the results
    printf("You typed %d characters in %.2f seconds, which is %.2f wpm.\n",
           results.total_chars, results.time_taken, results.wpm);

    return 0;
}