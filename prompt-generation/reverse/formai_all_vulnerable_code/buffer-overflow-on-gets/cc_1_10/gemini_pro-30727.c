//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to get the current time in milliseconds
long long get_current_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000 + (long long)ts.tv_nsec / 1000000;
}

// Function to test the typing speed
void test_typing_speed() {
    // Get the input text
    char text[1000];
    printf("Enter the text to be typed: ");
    gets(text);

    // Get the current time
    long long start_time = get_current_time_ms();

    // Get the user's input
    char input[1000];
    printf("Start typing: ");
    gets(input);

    // Get the end time
    long long end_time = get_current_time_ms();

    // Calculate the time taken
    long long time_taken = end_time - start_time;

    // Calculate the number of characters typed per minute
    int num_chars = strlen(text);
    int num_chars_per_minute = (num_chars * 60000) / time_taken;

    // Print the results
    printf("Time taken: %lld ms\n", time_taken);
    printf("Number of characters typed: %d\n", num_chars);
    printf("Typing speed: %d characters per minute\n", num_chars_per_minute);
}

// Main function
int main() {
    // Test the typing speed
    test_typing_speed();

    return 0;
}