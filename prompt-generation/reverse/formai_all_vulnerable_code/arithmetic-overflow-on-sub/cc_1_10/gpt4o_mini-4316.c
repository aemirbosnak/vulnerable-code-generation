//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 256
#define TEST_SENTENCE "The quick brown fox jumps over the lazy dog."

void clear_buffer() {
    while (getchar() != '\n'); // clear input buffer
}

void print_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be prompted to type the following sentence:\n");
    printf("\"%s\"\n\n", TEST_SENTENCE);
    printf("Press Enter when you are ready to start.\n");
    clear_buffer();
}

double calculate_speed(int character_count, double time_taken) {
    return (character_count / time_taken) * 60; // words per minute
}

void execute_typing_test() {
    char user_input[MAX_LENGTH];
    clock_t start, end;

    printf("3... 2... 1... Start typing!\n\n");
    start = clock();

    fgets(user_input, MAX_LENGTH, stdin);
    end = clock();

    // Calculate the time taken in seconds
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Count the number of characters typed
    int len_user_input = strlen(user_input);
    int len_test_sentence = strlen(TEST_SENTENCE);

    // Calculate speed
    double typing_speed = calculate_speed(len_user_input, time_taken);

    // Output results
    printf("\nTime taken: %.2f seconds\n", time_taken);
    printf("You typed: %d characters\n", len_user_input);
    printf("Your typing speed: %.2f characters per minute\n", typing_speed);

    // Feedback
    if (strncmp(user_input, TEST_SENTENCE, len_test_sentence) == 0) {
        printf("Congratulations! You typed the sentence correctly!\n");
    } else {
        printf("Oops! There were some mistakes in the sentence. Try again!\n");
    }
}

int main() {
    print_instructions();
    execute_typing_test();

    return 0;
}