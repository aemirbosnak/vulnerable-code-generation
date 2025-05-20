//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. ";
    int text_length = strlen(text);
    int words_typed = 0;
    int correct_words = 0;
    int incorrect_words = 0;
    int total_chars_typed = 0;
    int backspaces = 0;
    int num_errors = 0;
    int start_time, end_time;
    double elapsed_time;
    double words_per_minute;
    double characters_per_minute;

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will have 1 minute to type the following text:\n\n%s\n", text);
    printf("Press ENTER to begin...\n");
    getchar(); // wait for user to press ENTER

    start_time = clock(); // start timer

    while (difftime(clock(), start_time) < 60) { // loop for 1 minute
        int c = getchar(); // get user input

        if (c == '\n') { // user pressed ENTER
            end_time = clock(); // stop timer
            elapsed_time = difftime(end_time, start_time); // calculate elapsed time

            if (elapsed_time < 60) { // check if test was completed within 1 minute
                printf("Test completed in %.2f seconds.\n", elapsed_time);
            } else {
                printf("Test completed in 1 minute.\n");
            }

            words_per_minute = (double)words_typed / (elapsed_time / 60); // calculate words per minute
            characters_per_minute = (double)total_chars_typed / (elapsed_time / 60); // calculate characters per minute

            printf("Words typed: %d\n", words_typed);
            printf("Correct words: %d\n", correct_words);
            printf("Incorrect words: %d\n", incorrect_words);
            printf("Total characters typed: %d\n", total_chars_typed);
            printf("Backspaces: %d\n", backspaces);
            printf("Errors: %d\n", num_errors);
            printf("Words per minute: %.2f\n", words_per_minute);
            printf("Characters per minute: %.2f\n", characters_per_minute);

            break;
        } else if (c == '\b' || c == 127) { // user pressed BACKSPACE or DELETE
            backspaces++;
            num_errors++;
        } else if (c == '\r') { // user pressed ENTER without typing anything
            num_errors++;
        } else {
            total_chars_typed++;

            if (c == text[text_length - 1]) { // check if last character typed is correct
                correct_words++;
            } else {
                incorrect_words++;
            }
        }
    }

    return 0;
}