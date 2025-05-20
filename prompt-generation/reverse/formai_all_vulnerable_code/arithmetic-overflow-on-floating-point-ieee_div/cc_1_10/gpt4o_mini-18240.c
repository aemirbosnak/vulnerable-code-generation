//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_LENGTH 256
#define SAMPLE_TEXT "The quick brown fox jumps over the lazy dog."

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int count_words(const char *text) {
    int count = 0;
    const char *p = text;
    int in_word = 0;

    while (*p) {
        if (isspace((unsigned char) *p)) {
            if (in_word) {
                count++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
        p++;
    }
    if (in_word) {
        count++;
    }
    return count;
}

void print_instructions() {
    printf("Typing Speed Test\n");
    printf("-----------------\n");
    printf("You will be given a sentence to type.\n");
    printf("Try to type it as fast and accurately as possible.\n");
    printf("You will be assessed based on your typing speed in words per minute (WPM).\n\n");
}

int main() {
    char user_input[MAX_LENGTH];
    clock_t start_time, end_time;
    int total_words = count_words(SAMPLE_TEXT);
    print_instructions();

    printf("Here is the sentence you need to type:\n");
    printf("\"%s\"\n", SAMPLE_TEXT);
    printf("Press ENTER to start...\n");
    clear_input_buffer();

    start_time = clock();
    printf("Start typing now:\n");

    if (fgets(user_input, sizeof(user_input), stdin) == NULL) {
        printf("Error reading input. Exiting the program.\n");
        return 1;
    }

    end_time = clock();

    // Remove the newline character from user input if there is one.
    user_input[strcspn(user_input, "\n")] = 0;

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // in seconds
    double wpm = (total_words / time_taken) * 60; // Convert to WPM

    printf("\nTime taken: %.2f seconds\n", time_taken);
    printf("Your typing speed: %.2f WPM\n", wpm);

    // Check for accuracy
    if (strcmp(user_input, SAMPLE_TEXT) == 0) {
        printf("Great job! You typed the text accurately.\n");
    } else {
        printf("You made some errors in typing. Keep practicing!\n");
    }

    int correct_chars = 0;
    for (int i = 0; i < strlen(user_input); i++) {
        if (user_input[i] == SAMPLE_TEXT[i]) {
            correct_chars++;
        }
    }
    double accuracy = ((double)correct_chars / total_words) * 100;
    printf("Your accuracy: %.2f%%\n", accuracy);

    printf("Thank you for participating!\n");
    return 0;
}