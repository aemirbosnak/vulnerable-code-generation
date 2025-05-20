//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHARS 1000
#define TEXT_LENGTH 200

// Function to print the instruction and the sample text
void print_instructions(const char *text) {
    printf("\n\t\tWelcome to the Typing Speed Test!\n");
    printf("\t-------------------------------------------------\n");
    printf("\tYou will be presented with a text to type.\n");
    printf("\tYour goal is to type it as quickly and accurately as possible.\n");
    printf("\tPlease press ENTER when you're ready to start!\n\n");
    
    printf("\tHere's the text you need to type:\n");
    printf("\t-------------------------------------------------\n");
    printf("\t\"%s\"\n", text);
    printf("\t-------------------------------------------------\n");
    printf("\tGet ready! Press ENTER to begin...\n");
    getchar();  // Wait for the user to press ENTER
}

// Function to calculate WPM
float calculate_wpm(int words, double seconds) {
    return (words / (seconds / 60.0));
}

int main() {
    // Sample text to type
    const char *sample_text = "The quick brown fox jumps over the lazy dog. "
                              "A journey of a thousand miles begins with a single step. "
                              "In the midst of chaos, there is also opportunity.";
    
    // Variables to hold user input and timing
    char user_input[MAX_CHARS];
    clock_t start_time, end_time;

    // Print instructions and await user input
    print_instructions(sample_text);

    // Start the timer
    printf("\n\tTime to type! Go!\n");
    start_time = clock();

    // Capture user input
    fgets(user_input, MAX_CHARS, stdin);

    // End the timer
    end_time = clock();

    // Calculate time taken in seconds
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Calculate number of words in the user's input
    int words = 0;
    char *token = strtok(user_input, " \n"); // Tokenize the input by spaces and newlines
    while (token != NULL) {
        words++;
        token = strtok(NULL, " \n");
    }

    // Calculate WPM
    float wpm = calculate_wpm(words, time_taken);

    // Print results
    printf("\n\t-------------------------------------------------\n");
    printf("\tYour results:\n");
    printf("\tTime taken: %.2f seconds\n", time_taken);
    printf("\tWords typed: %d\n", words);
    printf("\tWords per minute (WPM): %.2f\n", wpm);
    printf("\t-------------------------------------------------\n");

    // Feedback based on WPM
    if (wpm < 20) {
        printf("\tKeep practicing! You'll get there!\n");
    } else if (wpm < 40) {
        printf("\tGood job! You're getting faster!\n");
    } else {
        printf("\tAmazing speed! You've mastered typing!\n");
    }

    printf("\tThank you for participating in the Typing Speed Test!\n");
    printf("\t-------------------------------------------------\n");

    return 0;
}