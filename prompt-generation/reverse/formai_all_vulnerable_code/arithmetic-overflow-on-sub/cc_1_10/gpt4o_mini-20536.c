//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_INPUT 256
#define TARGET_TEXT "The quick brown fox jumps over the lazy dog"
#define WORD_COUNT 9  // The number of words in the TARGET_TEXT

void print_instructions() {
    printf("Typing Speed Test\n");
    printf("=================\n");
    printf("Type the following text exactly as shown:\n\n");
    printf("\"%s\"\n\n", TARGET_TEXT);
    printf("Press ENTER when you are ready to start.\n");
    getchar();
}

void countdown(int seconds) {
    printf("Get ready! Starting in:\n");
    for (int i = seconds; i > 0; --i) {
        printf("%d...\n", i);
        sleep(1);
    }
}

void get_user_input(char *input) {
    printf("Start typing now:\n");
    clock_t start_time = clock();
    fgets(input, MAX_INPUT, stdin);
    clock_t end_time = clock();
    
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken: %.2f seconds\n", time_taken);
}

double calculate_wpm(double time_taken) {
    if (time_taken == 0) return 0;  // Prevent division by zero
    return (WORD_COUNT / time_taken) * 60;  // Calculate words per minute
}

void display_results(const char *input, double wpm) {
    printf("\nYour Input: \"%s\"", input);
    printf("Expected: \"%s\"\n", TARGET_TEXT);
    
    if (strcmp(input, TARGET_TEXT) == 0) {
        printf("Congratulations! You typed correctly!\n");
    } else {
        printf("Some errors were found in your typing.\n");
    }
    
    printf("Your typing speed: %.2f WPM\n", wpm);
}

int main() {
    char user_input[MAX_INPUT];
    print_instructions();
    
    countdown(5);
    
    get_user_input(user_input);
    
    // Remove the newline character from fgets
    user_input[strcspn(user_input, "\n")] = 0;
    
    double time_taken = (double)strlen(user_input) / 5.0; // Example for calculating time based on average typing speed
    double wpm = calculate_wpm(time_taken);
    
    display_results(user_input, wpm);
    
    return 0;
}