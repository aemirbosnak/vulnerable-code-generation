//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEXT_LENGTH 256
#define MAX_INPUT_LENGTH 256

void display_instructions(const char *prompt) {
    printf("--------------------------------------------------\n");
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following text as accurately and quickly as possible:\n");
    printf("--------------------------------------------------\n");
    printf("%s\n\n", prompt);
    printf("Press Enter when you're ready to start...\n");
    getchar();
}

void calculate_results(const char *prompt, const char *user_input, double time_taken) {
    int total_chars = strlen(prompt);
    int correct_chars = 0;

    for (int i = 0; i < total_chars; i++) {
        if (prompt[i] == user_input[i]) {
            correct_chars++;
        }
    }

    double accuracy = ((double)correct_chars / total_chars) * 100;
    double wpm = (correct_chars / 5.0) / (time_taken / 60.0); // Calculate WPM

    printf("--------------------------------------------------\n");
    printf("Typing Speed Test Results:\n");
    printf("--------------------------------------------------\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Character accuracy: %.2f%%\n", accuracy);
    printf("Words per minute (WPM): %.2f\n", wpm);
    printf("--------------------------------------------------\n");
}

int main() {
    const char *test_prompt = "The only limit to our realization of tomorrow is our doubts of today.";
    char user_input[MAX_INPUT_LENGTH];
    clock_t start_time, end_time;

    display_instructions(test_prompt);

    start_time = clock();
    printf("Start typing now:\n");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    end_time = clock();

    // Remove newline character from user_input
    user_input[strcspn(user_input, "\n")] = 0;

    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    calculate_results(test_prompt, user_input, elapsed_time);
    
    return 0;
}