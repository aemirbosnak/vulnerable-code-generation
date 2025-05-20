//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clear_buffer() {
    while(getchar() != '\n');
}

int main() {
    const char *passage = "The quick brown fox jumps over the lazy dog";
    char user_input[256];
    int words = 10; // The number of words in the passage
    clock_t start, end;

    printf("Thank you for taking the typing speed test!\n");
    printf("Please type the following passage:\n");
    printf("--------------------------------------------------\n");
    printf("%s\n", passage);
    printf("--------------------------------------------------\n");
    printf("Press Enter when you are ready to start...\n");
    clear_buffer();
    
    start = clock(); // Start the timer
    
    printf("Go! Start typing:\n");
    fgets(user_input, sizeof(user_input), stdin);
    
    end = clock(); // End the timer
    
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC; // Calculate time taken in seconds
    time_taken = time_taken / 60; // Convert to minutes
    
    // Calculate the number of words typed
    int user_words = 0;
    char *token = strtok(user_input, " \n");
    while(token != NULL) {
        user_words++;
        token = strtok(NULL, " \n");
    }
    
    // Calculate words per minute
    double wpm = user_words / time_taken;

    // Display results to the user
    printf("\nThank you for completing the typing test!\n");
    printf("Here's your performance report:\n");
    printf("--------------------------------------------------\n");
    printf("Total time: %.2f minutes\n", time_taken);
    printf("Words typed: %d\n", user_words);
    printf("Typing speed: %.2f words per minute (WPM)\n", wpm);
    
    // Message of appreciation
    if (wpm < 20) {
        printf("You are just getting started. Keep practicing, and you will improve!\n");
    } else if (wpm < 40) {
        printf("You're doing well! With a bit more practice, you'll be even faster!\n");
    } else {
        printf("Amazing! Your typing speed is commendable. Thank you for participating!\n");
    }
    
    printf("Thank you for sharing your time with us today!\n");
    
    return 0;
}