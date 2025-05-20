//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_SENTENCES 10
#define MAX_LENGTH 100

const char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of difficulty lies opportunity.",
    "Success usually comes to those who are too busy to be looking for it.",
    "The future belongs to those who believe in the beauty of their dreams.",
    "What we think, we become.",
    "Your time is limited, don't waste it living someone else's life.",
    "The only way to do great work is to love what you do."
};

void clear_input_buffer() {
    while (getchar() != '\n');
}

double calculate_typing_speed(int characters, double time_taken) {
    return (characters / 5.0) / (time_taken / 60.0);
}

void display_results(int total_chars, double time_taken) {
    double speed = calculate_typing_speed(total_chars, time_taken);
    printf("You typed %d characters in %.2f seconds.\n", total_chars, time_taken);
    printf("Your typing speed is: %.2f WPM (Words Per Minute)\n", speed);
}

int get_user_input(char *input_buffer, size_t buffer_size) {
    printf("Type the following sentence:\n");
    int index = rand() % MAX_SENTENCES;
    
    printf("\"%s\"\n", sentences[index]);
    double start_time = (double)clock() / CLOCKS_PER_SEC;

    // Read user input
    fgets(input_buffer, buffer_size, stdin);
    double end_time = (double)clock() / CLOCKS_PER_SEC;
    
    return end_time - start_time;
}

int main() {
    char user_input[MAX_LENGTH];
    int total_chars;
    double time_taken;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Press Enter to start...\n");
    getchar(); // Wait for the user to press enter
    clear_input_buffer(); // Clear the input buffer

    time_taken = get_user_input(user_input, sizeof(user_input));
    total_chars = strlen(user_input) - 1; // Subtract 1 for the newline character

    // Remove leading/trailing spaces
    char *p = user_input;
    while (isspace(*p)) p++; // Leading spaces
    char *end = p + strlen(p) - 1;
    while (end > p && isspace(*end)) end--;
    *(end + 1) = '\0';

    display_results(total_chars, time_taken);

    return 0;
}