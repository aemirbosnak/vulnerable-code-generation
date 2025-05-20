//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEXT "The quick brown fox jumps over the lazy dog"
#define MAX_WPM 100

int main() {
    char text[100];
    int length;
    int correct = 0, incorrect = 0;
    int chars_per_second, words_per_minute;
    double accuracy;
    time_t start_time, end_time;
    srand(time(NULL));

    printf("Welcome to the C Typing Speed Test!\n");

    // Get the length of the text
    length = strlen(TEXT);

    // Initialize the text array with random characters
    for (int i = 0; i < length; i++) {
        text[i] = TEXT[i] + rand() % 26;
    }

    // Start the timer
    start_time = time(NULL);

    // Get user input
    printf("Start typing:\n");
    fgets(text, 100, stdin);

    // Stop the timer
    end_time = time(NULL);

    // Calculate the time taken
    double time_taken = difftime(end_time, start_time);

    // Calculate the number of chars per second
    chars_per_second = (double)strlen(text) / time_taken;

    // Calculate the number of words per minute
    words_per_minute = chars_per_second / 5;

    // Calculate the accuracy
    accuracy = ((double)correct / strlen(TEXT)) * 100;

    // Print the results
    printf("\nResults:\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Chars per second: %.2f\n", chars_per_second);
    printf("Words per minute: %.2f\n", words_per_minute);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}