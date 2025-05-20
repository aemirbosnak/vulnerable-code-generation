//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PHRASES 5
#define MAX_LENGTH 256

const char *phrases[MAX_PHRASES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "Life is what happens when you're busy making other plans."
};

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a phrase to type. Try to type it as quickly and accurately as possible.\n");
    printf("Press Enter when you are ready to begin!\n");
    getchar();
}

void clear_screen() {
    // Clear the terminal screen; this works in most Linux terminals
    printf("\033[H\033[J");
}

int main() {
    srand(time(0));
    char input[MAX_LENGTH];
    int random_index;
    double time_taken;
    struct timespec start_time, end_time;

    clear_screen();
    display_instructions();
    
    while(1) {
        random_index = rand() % MAX_PHRASES; // Get a random index
        const char* phrase_to_type = phrases[random_index];

        // Prompt the user with the phrase
        printf("\nType the following phrase:\n\n");
        printf("%s\n\n", phrase_to_type);
        
        clock_gettime(CLOCK_MONOTONIC, &start_time); // Start the timer
        
        // Capture user input
        fgets(input, MAX_LENGTH, stdin);
        
        clock_gettime(CLOCK_MONOTONIC, &end_time); // End the timer

        // Calculate time taken
        time_taken = (end_time.tv_sec - start_time.tv_sec) + 
                     (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

        // Check if the input matches the phrase (considering new line)
        if (strncmp(input, phrase_to_type, strlen(phrase_to_type)) == 0) {
            printf("Well done! You typed it correctly.\n");
            printf("Time taken: %.2f seconds\n", time_taken);
        } else {
            printf("Oops! There were some mistakes.\n");
            printf("You typed: %s", input);
            printf("Expected: %s", phrase_to_type);
        }
        
        printf("\nWould you like to try another phrase? (y/n): ");
        fgets(input, MAX_LENGTH, stdin);
        
        if (strcmp(input, "n\n") == 0 || strcmp(input, "N\n") == 0) {
            break; // Exit the loop if the user does not want to continue
        }

        clear_screen();
    }

    printf("Thank you for playing the Typing Speed Test!\n");
    return 0;
}