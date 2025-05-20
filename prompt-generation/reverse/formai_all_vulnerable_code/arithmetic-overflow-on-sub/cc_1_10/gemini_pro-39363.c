//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <time.h>

#define BUFFER_LENGTH 1000

int main() {
    char text[] = "This is a sample text for typing speed test. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";
    char buffer[BUFFER_LENGTH];
    int start_time, end_time;
    float time_taken;
    int correct_characters, incorrect_characters, total_characters;

    // Get the starting time
    start_time = time(NULL);

    // Prompt the user to start typing
    printf("Start typing the text below:\n\n%s\n", text);

    // Get the input from the user
    fgets(buffer, BUFFER_LENGTH, stdin);

    // Get the ending time
    end_time = time(NULL);

    // Calculate the time taken by the user
    time_taken = (float)(end_time - start_time);

    // Calculate the number of correct characters typed by the user
    correct_characters = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (buffer[i] == text[i]) {
            correct_characters++;
        }
    }

    // Calculate the number of incorrect characters typed by the user
    incorrect_characters = strlen(text) - correct_characters;

    // Calculate the total number of characters typed by the user
    total_characters = strlen(text);

    // Calculate the typing speed of the user in words per minute (WPM)
    float wpm = ((float)correct_characters / 5) * (60 / time_taken);

    // Print the results
    printf("\nYour typing speed is: %.2f WPM\n", wpm);
    printf("Correct characters: %d\n", correct_characters);
    printf("Incorrect characters: %d\n", incorrect_characters);
    printf("Total characters: %d\n", total_characters);

    return 0;
}