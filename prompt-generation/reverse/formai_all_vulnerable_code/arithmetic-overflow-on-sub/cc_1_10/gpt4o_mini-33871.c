//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clear_buffer() {
    while (getchar() != '\n');
}

void display_quote() {
    printf("Type the quote below:\n");
    printf("    \"But, soft! What light through yonder window breaks?\"\n");
}

int main() {
    char user_input[256];
    char *quote = "\"But, soft! What light through yonder window breaks?\"";
    
    printf("Welcome to the Romeo and Juliet Typing Speed Test!\n");
    printf("Prepare for a test of thy typing prowess...\n");

    // Display the quote and instruct the user
    display_quote();

    // Record starting time
    clock_t start_time = clock();

    // Capture user input
    fgets(user_input, sizeof(user_input), stdin);
    
    // Record ending time
    clock_t end_time = clock();

    // Calculate typing time
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    
    // Remove newline character from fgets if present
    user_input[strcspn(user_input, "\n")] = 0;

    // Calculate the speed
    int chars_typed = strlen(user_input);
    double speed_wpm = (chars_typed / 5.0) / (time_taken / 60.0);
    
    // Display the results
    printf("\nThine results are in:\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Characters typed: %d\n", chars_typed);
    printf("Speed: %.2f Words per Minute (WPM)\n", speed_wpm);

    // Check if the input matches
    if (strcmp(user_input, quote) == 0) {
        printf("Thou hast typed the quote correctly! A perfect match!\n");
    } else {
        printf("Alas! Thy typing was not as true as Romeo's love.\n");
        printf("The correct quote was:\n%s\n", quote);
    }

    printf("May the stars guide your fingers in future tests!\n");
    return 0;
}