//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 256
#define MAX_TIME_LIMIT 60

void print_instructions();
void start_typing_test(const char *text);
void calculate_speed(int words_typed, double time_taken);
void clear_buffer();

int main() {
    srand(time(NULL)); // Seed for random number generation

    const char *texts[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Typing speed tests improve your skills and accuracy.",
        "Efficient programmers always strive for greatness.",
        "The rain in Spain stays mainly in the plain.",
        "To be or not to be, that is the question."
    };

    int num_texts = sizeof(texts) / sizeof(texts[0]);
    int random_index = rand() % num_texts;

    print_instructions();
    start_typing_test(texts[random_index]);

    return 0;
}

void print_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type as quickly and accurately as possible.\n");
    printf("You have a time limit of %d seconds. Press Enter when you are ready to start.\n", MAX_TIME_LIMIT);
    clear_buffer();
}

void start_typing_test(const char *text) {
    printf("\nYour sentence is:\n\"%s\"\n", text);
    printf("Press Enter to begin...");
    clear_buffer();

    double start_time = time(NULL);
    char user_input[MAX_TEXT_LENGTH];
    printf("\nStart typing:\n");

    fgets(user_input, sizeof(user_input), stdin); // User types the sentence

    double end_time = time(NULL);
    double time_taken = difftime(end_time, start_time);

    // Check if the input was within the time limit
    if (time_taken > MAX_TIME_LIMIT) {
        printf("\nTime's up! You took too long.\n");
        return;
    }

    // Calculate the number of words typed
    int words_typed = 0;
    char *token = strtok(user_input, " ");
    while (token != NULL) {
        words_typed++;
        token = strtok(NULL, " ");
    }

    calculate_speed(words_typed, time_taken);
}

void calculate_speed(int words_typed, double time_taken) {
    double speed = (words_typed / time_taken) * 60; // Words per minute (WPM)
    printf("\nYou typed %d words in %.2f seconds.\n", words_typed, time_taken);
    printf("Your typing speed is: %.2f words per minute (WPM).\n", speed);
}

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}