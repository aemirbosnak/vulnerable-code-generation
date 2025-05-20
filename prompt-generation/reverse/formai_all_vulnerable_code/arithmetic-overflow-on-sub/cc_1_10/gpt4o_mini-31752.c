//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_SENTENCES 5
#define MAX_LENGTH 200

// Array of sample sentences for the typing test
const char *sentences[MAX_SENTENCES] = {
    "The curious cat jumped over the lazy dog.",
    "Coding in C is both challenging and rewarding.",
    "A journey of a thousand miles begins with a single step.",
    "Learning new languages expands one's horizons.",
    "The sun sets in the west, painting the sky with hues of orange."
};

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a few sentences to type.\n");
    printf("Press Enter to start the test...\n");
    getchar();
}

void select_random_sentence(char *selected_sentence) {
    srand(time(NULL));
    int index = rand() % MAX_SENTENCES;
    strcpy(selected_sentence, sentences[index]);
}

void start_typing_test(const char *sentence) {
    char user_input[MAX_LENGTH];
    printf("\nTyping Test: Type the following sentence:\n");
    printf("\"%s\"\n\n", sentence);
    printf("Begin typing and press Enter when finished.\n");

    // Time tracking
    clock_t start_time = clock();
    fgets(user_input, MAX_LENGTH, stdin);
    clock_t end_time = clock();

    // Remove the newline character from user input
    user_input[strcspn(user_input, "\n")] = 0;

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nTime taken: %.2f seconds\n", time_taken);

    // Calculate and display score
    int score = strlen(user_input) - abs(strlen(user_input) - strlen(sentence));
    printf("Your score based on the number of characters matched: %d\n", score);
}

void request_ask_retry() {
    printf("\nWould you like to try again? (y/n): ");
}

int main() {
    char another_attempt;

    do {
        char selected_sentence[MAX_LENGTH];
        display_instructions();
        select_random_sentence(selected_sentence);
        start_typing_test(selected_sentence);
        
        request_ask_retry();
        scanf(" %c", &another_attempt);
        while (getchar() != '\n');  // Clear the input buffer
    } while (another_attempt == 'y' || another_attempt == 'Y');

    printf("Thank you for participating in the Typing Speed Test! Goodbye.\n");

    return 0;
}