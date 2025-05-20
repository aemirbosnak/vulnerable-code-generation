//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main() {
    // Initialize variables
    char text[] = "This is a sample text for typing speed test. Try to type this text as fast and as accurately as possible.";
    int length = strlen(text);
    int errors = 0;
    int characters = 0;
    int wpm = 0;
    int accuracy = 0;
    int time_start;
    int time_end;
    float time_elapsed;
    float speed;

    // Get start time
    time_start = time(NULL);

    // Display the text
    printf("Type the following text as fast and as accurately as possible:\n\n%s\n\n", text);

    // Get user input
    char input[length + 1];
    scanf("%s", input);

    // Get end time
    time_end = time(NULL);

    // Calculate time elapsed
    time_elapsed = (float)(time_end - time_start);

    // Calculate speed
    speed = (float)characters / time_elapsed * 60.0;

    // Calculate accuracy
    for (int i = 0; i < length; i++) {
        if (input[i] != text[i]) {
            errors++;
        }
    }
    accuracy = (float)(length - errors) / length * 100.0;

    // Calculate WPM
    wpm = (int)(speed * accuracy / 5);

    // Display results
    printf("Your typing speed is %d WPM with an accuracy of %d%%\n", wpm, accuracy);

    return 0;
}