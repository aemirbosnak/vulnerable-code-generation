//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_SENTENCES 10
#define MAX_LENGTH 256

const char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "The only thing we have to fear is fear itself.",
    "In the middle of difficulty lies opportunity.",
    "Success is not final, failure is not fatal.",
    "You miss 100% of the shots you don't take.",
    "It is our choices that show what we truly are.",
    "Life is what happens when you're busy making other plans."
};

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will see a sentence that you need to type as quickly as possible.\n");
    printf("Press ENTER to start!\n");
}

const char* get_random_sentence() {
    return sentences[rand() % MAX_SENTENCES];
}

int get_typing_speed(time_t start, time_t end, int words) {
    double seconds = difftime(end, start);
    double minutes = seconds / 60;
    return (int)(words / minutes);
}

void typing_test() {
    char input[MAX_LENGTH];
    const char* test_sentence = get_random_sentence();
    int word_count = 0;
    
    // Calculate word count from the sentence
    char *token = strtok(test_sentence, " ");
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }

    printf("\nType the following sentence:\n");
    printf("\"%s\"\n", test_sentence);
    printf("You have 30 seconds to complete the typing.\n");

    // Start timer
    time_t start_time = time(NULL);
    fgets(input, sizeof(input), stdin);
    time_t end_time = time(NULL);

    // Measure WPM
    int speed = get_typing_speed(start_time, end_time, word_count);
    
    printf("\nYou typed: \"%s\"\n", input);
    printf("Your typing speed is: %d words per minute\n", speed);
}

int main() {
    srand(time(NULL));
    char retry;
    
    do {
        display_instructions();
        getchar(); // Wait for user to press ENTER
        typing_test();

        printf("Would you like to try again? (y/n): ");
        scanf(" %c", &retry);
        getchar(); // Consume newline character after scanf
    } while (retry == 'y' || retry == 'Y');
    
    printf("Thank you for participating in the Typing Speed Test!\n");
    return 0;
}