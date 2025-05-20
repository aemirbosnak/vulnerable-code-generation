//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256
#define MESSAGE "The quick brown fox jumps over the lazy dog"

void display_welcome_message() {
    printf("\n");
    printf("****************************************\n");
    printf("       Welcome to the Typing Test!     \n");
    printf("****************************************\n");
    printf("Type the following sentence as fast as you can:\n");
    printf("\"%s\"\n", MESSAGE);
    printf("Press ENTER when you are ready to start...\n");
    getchar();
}

void measure_typing_speed() {
    char input[MAX_LENGTH];
    clock_t start, end;

    printf("\nReady? Begin typing now:\n");

    // Start timing
    start = clock();
    
    // Get user input
    fgets(input, MAX_LENGTH, stdin);
    
    // End timing
    end = clock();
    
    // Calculate time taken in seconds
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC; 
    
    // Trim newline character from the input
    input[strcspn(input, "\n")] = 0;

    // Calculate words typed and typing speed
    int words_typed = 0;
    char *token = strtok(input, " ");
    while (token) {
        words_typed++;
        token = strtok(NULL, " ");
    }

    double speed_wpm = (words_typed / time_taken) * 60;

    // Display results
    printf("\nYour typing test is complete!\n");
    printf("You typed %d words in %.2f seconds.\n", words_typed, time_taken);
    printf("Your typing speed is: %.2f words per minute.\n", speed_wpm);
}

int main() {
    display_welcome_message();
    measure_typing_speed();
    
    printf("\nThank you for participating!\n");
    printf("Press ENTER to exit...\n");
    getchar();

    return 0;
}