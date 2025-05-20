//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define QUOTE_COUNT 5
#define MAX_LENGTH 256

const char* quotes[QUOTE_COUNT] = {
    "The journey of a thousand miles begins with one step.",
    "To be yourself in a world that is constantly trying to make you something else is the greatest accomplishment.",
    "In the end, we will remember not the words of our enemies, but the silence of our friends.",
    "Life is either a daring adventure or nothing at all.",
    "You miss 100% of the shots you don’t take."
};

void clear_screen() {
    // Clear the terminal screen using ANSI escape codes
    printf("\033[H\033[J");
}

int main() {
    char input[MAX_LENGTH];
    int random_index;
    time_t start_time, end_time;
    double elapsed_time;
    int word_count;
    
    // Seed the random number generator
    srand(time(NULL));
    random_index = rand() % QUOTE_COUNT;

    clear_screen();
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following quote as quickly as possible:\n\n");
    printf("\"%s\"\n\n", quotes[random_index]);
    printf("Press ENTER when you are ready to start...\n");
    getchar(); // Wait for the user to press ENTER

    // Start timing
    start_time = time(NULL);
    
    // Get user input
    printf("Start typing now:\n");
    fgets(input, MAX_LENGTH, stdin);
    
    // End timing
    end_time = time(NULL);
    
    // Strip the newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Calculate elapsed time
    elapsed_time = difftime(end_time, start_time);
    
    // Count words in input
    word_count = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }

    // Calculate words per minute
    double wpm = (word_count / elapsed_time) * 60;

    // Display results
    clear_screen();
    printf("You typed: \"%s\"\n", input);
    printf("It took you %.2f seconds to type.\n", elapsed_time);
    printf("Your typing speed is: %.2f WPM\n", wpm);
    
    // Provide feedback on accuracy
    if (strcmp(input, quotes[random_index]) == 0) {
        printf("Excellent! You typed the quote correctly!\n");
    } else {
        printf("Your input did not match the quote. Try again to improve!\n");
    }

    printf("Thank you for participating in the Typing Speed Test!\n");
    return 0;
}