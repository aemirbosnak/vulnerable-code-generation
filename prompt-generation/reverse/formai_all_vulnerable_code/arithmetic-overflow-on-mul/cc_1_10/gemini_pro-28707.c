//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A classic Sherlock Holmes quote to test your typing speed
char *quote = "Life is infinitely stranger than anything which the mind of man could invent.";

// Function to measure typing speed
void typing_speed_test() {
    // Get the current time
    time_t start_time = time(NULL);

    // Prompt the user to start typing
    printf("Sherlock says: %s\n", quote);
    printf("Start typing now:\n");

    // Read the user's input
    char input[1000];
    fgets(input, sizeof(input), stdin);

    // Get the current time again
    time_t end_time = time(NULL);

    // Calculate the time taken to type the quote
    double time_taken = difftime(end_time, start_time);

    // Calculate the typing speed in words per minute (WPM)
    int words_per_minute = (int) ((strlen(quote) / 5) / time_taken) * 60;

    // Calculate the typing speed in characters per minute (CPM)
    int characters_per_minute = (int) ((strlen(quote)) / time_taken) * 60;

    // Display the typing speed results
    printf("Your typing speed is %d WPM or %d CPM.\n", words_per_minute, characters_per_minute);

    // Check if the user's input matches the quote
    if (strcmp(input, quote) == 0) {
        printf("Well done, Watson! You have solved the mystery of the typing test.\n");
    } else {
        printf("Elementary, my dear Watson! You still have some work to do on your typing skills.\n");
    }
}

// Main function
int main() {
    // Welcome the user
    printf("Welcome to the Sherlock Holmes Typing Speed Test.\n");

    // Start the typing speed test
    typing_speed_test();

    return 0;
}