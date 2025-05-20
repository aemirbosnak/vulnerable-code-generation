//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUOTES 5
#define MAX_LENGTH 200

const char *quotes[MAX_QUOTES] = {
    "The only limit to our realization of tomorrow is our doubts of today.",
    "It does not matter how slowly you go as long as you do not stop.",
    "Success usually comes to those who are too busy to be looking for it.",
    "Don’t watch the clock; do what it does. Keep going.",
    "The future belongs to those who believe in the beauty of their dreams."
};

void print_quote(const char *quote) {
    printf("\nType the following quote:\n");
    printf("\"%s\"\n", quote);
}

int calculate_wpm(int words, double time_in_minutes) {
    return (int)(words / time_in_minutes);
}

int main() {
    srand(time(NULL)); // Random seed for quote selection
    int selected_index = rand() % MAX_QUOTES; // Select a random quote
    const char *selected_quote = quotes[selected_index];

    print_quote(selected_quote);

    char user_input[MAX_LENGTH];
    clock_t start_time, end_time;

    printf("Start typing (Press Enter when done):\n");
    start_time = clock();
    fgets(user_input, sizeof(user_input), stdin);
    end_time = clock();

    // Calculate time taken in minutes
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    time_taken /= 60; // Convert to minutes

    // Process the user input
    user_input[strcspn(user_input, "\n")] = 0; // Remove newline character

    // Calculate number of words in both quotes
    int quote_word_count = 0, input_word_count = 0;
    char *token;
    
    // Tokenize the quote
    token = strtok((char *)selected_quote, " ");
    while (token != NULL) {
        quote_word_count++;
        token = strtok(NULL, " ");
    }

    // Tokenize the user input
    token = strtok(user_input, " ");
    while (token != NULL) {
        input_word_count++;
        token = strtok(NULL, " ");
    }

    // Check for correctness
    if (strcmp(user_input, selected_quote) == 0) {
        printf("Perfect match!\n");
    } else {
        printf("Your input did not match the quote. Try again!\n");
    }

    // Calculate typing speed
    int typing_speed = calculate_wpm(input_word_count, time_taken);
    printf("You typed %d words in %.2f minutes.\n", input_word_count, time_taken);
    printf("Your typing speed is %d words per minute.\n", typing_speed);

    return 0;
}