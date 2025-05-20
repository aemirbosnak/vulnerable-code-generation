//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_SENTENCES 5
#define MAX_LENGTH 256

const char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of difficulty lies opportunity."
};

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with a sentence to type.\n");
    printf("Type the sentence as quickly and accurately as you can.\n");
    printf("Your typing speed will be calculated in words per minute (WPM).\n\n");
}

void select_sentence(char *buffer) {
    int index = rand() % MAX_SENTENCES;
    strcpy(buffer, sentences[index]);
}

double calculate_typing_speed(double seconds, int word_count) {
    return (word_count / seconds) * 60.0;
}

void start_typing_test() {
    char typed_sentence[MAX_LENGTH];
    char random_sentence[MAX_LENGTH];
    int word_count;
    clock_t start_time, end_time;

    select_sentence(random_sentence);
    printf("Type the following sentence:\n");
    printf("\"%s\"\n\n", random_sentence);

    display_instructions();
    printf("Press Enter to start the test.");
    getchar();

    start_time = clock();
    printf("Start typing now:\n");
    
    // Using fgets to capture typed sentence
    fgets(typed_sentence, MAX_LENGTH, stdin);
    end_time = clock();

    // Remove the newline character from fgets input
    typed_sentence[strcspn(typed_sentence, "\n")] = 0;

    // Count words in the typed sentence
    word_count = 0;
    char *token = strtok(typed_sentence, " ");
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }

    // Calculate total time taken in seconds
    double seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double speed = calculate_typing_speed(seconds, word_count);

    printf("\nYour typed sentence: \"%s\"\n", typed_sentence);
    printf("The correct sentence was: \"%s\"\n", random_sentence);
    
    if (strcmp(typed_sentence, random_sentence) == 0) {
        printf("Perfect! You typed it correctly.\n");
    } else {
        printf("There were mistakes in your typing.\n");
    }

    printf("Time taken: %.2f seconds\n", seconds);
    printf("Your typing speed: %.2f WPM\n", speed);
}

int main() {
    srand(time(NULL)); // Seed for random numbers
    start_typing_test();
    return 0;
}