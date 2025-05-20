//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Function to clear the console screen
void clear_screen() {
    // ANSI escape code to clear the screen
    printf("\033[H\033[J");
}

// Function to display instructions
void display_instructions(const char *sentence) {
    clear_screen();
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following sentence as fast as you can:\n");
    printf("\"%s\"\n\n", sentence);
    printf("Press Enter when you are ready to start...\n");
    getchar();  // Wait for user to press enter
}

// Function to calculate typing speed
double calculate_speed(time_t start, time_t end, int char_count) {
    double duration = difftime(end, start);  // Duration in seconds
    double words_per_minute = (char_count / 5.0) / (duration / 60.0);
    return words_per_minute;
}

int main() {
    const char *test_sentence = "The quick brown fox jumps over the lazy dog.";
    char user_input[256];
    time_t start_time, end_time;

    // Display instructions and wait for user input
    display_instructions(test_sentence);

    // Start timing
    start_time = time(NULL);
    
    // Read user input
    printf("\nStart typing now:\n");
    fgets(user_input, sizeof(user_input), stdin);
    
    // Stop timing
    end_time = time(NULL);

    // Check how many characters they typed
    int char_count = strlen(user_input);
    // Remove the newline character
    if (user_input[char_count - 1] == '\n') {
        user_input[char_count - 1] = '\0';
        char_count--;
    }

    // Calculate typing speed
    double speed = calculate_speed(start_time, end_time, char_count);

    // Clear the screen again to show results
    clear_screen();
    printf("You typed: \"%s\"\n", user_input);
    printf("Typing Speed: %.2f words per minute\n", speed);
    
    // Check for accuracy
    int correct_chars = 0;
    for (int i = 0; i < char_count; i++) {
        if (user_input[i] == test_sentence[i]) {
            correct_chars++;
        }
    }
    double accuracy = (double)correct_chars / (strlen(test_sentence)) * 100;

    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Thank you for participating!\n");

    return 0;
}