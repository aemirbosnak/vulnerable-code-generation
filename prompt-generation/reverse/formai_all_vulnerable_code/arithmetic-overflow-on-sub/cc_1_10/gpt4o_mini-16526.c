//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_SIZE 256
#define TIME_LIMIT 30 // Time limit in seconds for testing
#define SAMPLE_TEXTS_COUNT 5

const char* sample_texts[SAMPLE_TEXTS_COUNT] = {
    "The quick brown fox jumps over the lazy dog.",
    "Programming is a way of thinking.",
    "In the middle of difficulty lies opportunity.",
    "Success usually comes to those who are too busy to be looking for it.",
    "Don't watch the clock; do what it does. Keep going."
};

// Function to clear the terminal screen (paranoia mode)
void clear_screen() {
    // Clear the screen for better visibility
    if (system("clear") == -1) {
        fprintf(stderr, "Error clearing screen!\n");
        exit(EXIT_FAILURE);
    }
}

// Function to get the current time in seconds
time_t get_current_time() {
    return time(NULL);
}

// Function to display the instructions for the user
void display_instructions() {
    clear_screen();
    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will have %d seconds to type the following sentence as fast as you can.\n", TIME_LIMIT);
    printf("Be prepared, do not be distracted!\n");
    printf("Here is the sample text:\n");
}

// Function to calculate typing speed
float calculate_speed(int char_count, float time_taken) {
    return (char_count / time_taken) * 60; // Speed in characters per minute
}

// Function to get user input and monitor typing
void start_typing_test(const char* sample_text) {
    char user_input[MAX_TEXT_SIZE];
    time_t start_time = get_current_time();
    time_t elapsed_time = 0;

    printf("%s\n", sample_text);
    printf("Start typing:\n");

    while (elapsed_time < TIME_LIMIT) {
        printf("> ");
        fflush(stdout); // Ensure prompt is shown before input
        fgets(user_input, MAX_TEXT_SIZE, stdin);

        elapsed_time = get_current_time() - start_time;

        if (strcmp(user_input, sample_text) == 0) {
            printf("Correctly typed within the time limit!\n");
            int char_count = strlen(sample_text);
            float speed = calculate_speed(char_count, elapsed_time);
            printf("Your typing speed: %.2f characters per minute\n", speed);
            return;
        } else {
            printf("Incorrect input. Focus! Keep typing!\n");
            // Alert the user they are off track
        }
    }

    printf("Time's up! You didn't match the text in time.\n");
}

// Function to randomly select a sample text
const char* get_random_sample_text() {
    srand(time(NULL));
    return sample_texts[rand() % SAMPLE_TEXTS_COUNT];
}

// Main testing function
int main() {
    char continuation_response;

    do {
        display_instructions();
        const char* selected_text = get_random_sample_text();
        start_typing_test(selected_text);

        printf("\nDo you want to try again (y/n)? ");
        fflush(stdin);
        scanf(" %c", &continuation_response);

        if (continuation_response == 'y' || continuation_response == 'Y') {
            continue; // Restart the loop for another test
        } else {
            break; // Exit the test
        }

    } while (1);

    printf("Thank you for participating in the typing speed test. Stay paranoid! Goodbye!\n");

    return 0;
}