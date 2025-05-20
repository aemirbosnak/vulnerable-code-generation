//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_STRING_LENGTH 500
#define MAX_TEXT_LENGTH 256
#define PROMPT_LENGTH 128

void clear_screen() {
    // Clear the terminal screen
    printf("\033[H\033[J");
}

void display_instructions(const char *text) {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type. Please type it as quickly and accurately as you can!\n\n");
    printf("Here is your sentence:\n\n");
    printf("%s\n\n", text);
    printf("Press Enter when you're ready to start...\n");
    getchar();
}

double calculate_speed(time_t start_time, time_t end_time, int word_count) {
    double time_taken = difftime(end_time, start_time);
    // Convert seconds to minutes
    double minutes_taken = time_taken / 60.0;
    return (word_count / minutes_taken);
}

int main() {
    const char *sample_texts[] = {
        "The quick brown fox jumps over the lazy dog.",
        "A journey of a thousand miles begins with a single step.",
        "To be or not to be, that is the question.",
        "In the middle of difficulty lies opportunity.",
        "Life is what happens when you are busy making other plans."
    };

    // Seed the random number generator and select a random text
    srand(time(NULL));
    int random_index = rand() % (sizeof(sample_texts) / sizeof(sample_texts[0]));
    const char *selected_text = sample_texts[random_index];

    clear_screen();
    display_instructions(selected_text);

    char user_input[MAX_TEXT_LENGTH] = {0};
    time_t start_time, end_time;

    printf("\nStart Typing:\n");
    start_time = time(NULL); // Start timer
    fgets(user_input, sizeof(user_input), stdin);
    end_time = time(NULL); // End timer

    // Remove trailing newline character
    user_input[strcspn(user_input, "\n")] = 0;

    // Count words in user input and sample text
    int user_word_count = 0, sample_word_count = 0;
    char *token;

    token = strtok(user_input, " ");
    while (token != NULL) {
        user_word_count++;
        token = strtok(NULL, " ");
    }

    token = strtok((char *)selected_text, " ");
    while (token != NULL) {
        sample_word_count++;
        token = strtok(NULL, " ");
    }

    // Calculate typing speed in WPM
    double speed = calculate_speed(start_time, end_time, user_word_count);

    printf("\nResults:\n");
    printf("You typed %d words.\n", user_word_count);
    printf("The sample text consisted of %d words.\n", sample_word_count);
    printf("Your typing speed: %.2f WPM\n", speed);
    
    if (user_word_count == sample_word_count) {
        printf("Congratulations! You typed the complete text.\n");
    } else {
        printf("You missed some part of the text. Keep practicing!\n");
    }

    printf("\nThank you for participating in the Typing Speed Test!\n");
    printf("Press Enter to exit...\n");
    getchar(); // Wait for the user to press Enter before exiting

    return 0;
}