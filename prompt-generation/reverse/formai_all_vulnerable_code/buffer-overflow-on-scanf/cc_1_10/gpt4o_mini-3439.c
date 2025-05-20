//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256
#define QUOTE "The only way to do great work is to love what you do."

void clear_input_buffer() {
    while (getchar() != '\n');
}

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Your task is to type the following quote:\n");
    printf("\"%s\"\n", QUOTE);
    printf("Press Enter when you're ready to start...\n");
    clear_input_buffer();
}

int main(void) {
    char user_input[MAX_LENGTH];
    char continue_testing = 'y';
    
    while (continue_testing == 'y') {
        display_instructions();

        // Wait for the user to press Enter
        getchar();

        printf("Start typing now!\n");

        // Start time
        clock_t start_time = clock();

        // Get user input
        fgets(user_input, MAX_LENGTH, stdin);

        // End time
        clock_t end_time = clock();

        // Calculate elapsed time in seconds
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        // Remove the newline character from user input if it exists
        user_input[strcspn(user_input, "\n")] = '\0';

        // Calculate WPM
        int word_count = 0;
        char *token = strtok(user_input, " ");
        while (token != NULL) {
            word_count++;
            token = strtok(NULL, " ");
        }

        double minutes_elapsed = time_taken / 60;
        double wpm = (word_count / minutes_elapsed);

        // Report results
        printf("\nTime taken: %.2f seconds\n", time_taken);
        printf("You typed: \"%s\"\n", user_input);
        printf("You entered %d words.\n", word_count);
        printf("Your typing speed is: %.2f words per minute (WPM)\n", wpm);

        // Ask if the user wants to try again
        printf("Do you want to try again? (y/n): ");
        clear_input_buffer();
        scanf("%c", &continue_testing);
    }

    printf("Thank you for participating in the Typing Speed Test!\n");
    return 0;
}