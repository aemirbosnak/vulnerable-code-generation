//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_LENGTH 256 // Max length of input

// Function to generate a random sentence for typing
const char* get_random_sentence() {
    const char* sentences[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Hello, world! Welcome to the typing speed test.",
        "Learning to code is both challenging and rewarding.",
        "Practice makes perfect—let's see how fast you can type!",
        "Keep calm and code on!",
        "A journey of a thousand miles begins with a single step.",
        "There is no place like 127.0.0.1.",
        "Why did the programmer quit his job? Because he didn't get arrays.",
        "All work and no play makes Jack a dull boy.",
        "To be or not to be, that is the question."
    };
    int total_sentences = sizeof(sentences) / sizeof(sentences[0]);
    return sentences[rand() % total_sentences];
}

// Function to measure typing speed
void measure_typing_speed() {
    const char* sentence = get_random_sentence();
    char user_input[MAX_LENGTH];
    
    printf("Here's the sentence you need to type:\n");
    printf("\"%s\"\n", sentence);
    printf("Type it as fast as you can and press Enter!\n\n");

    // Old command line trick: press to continue
    printf("Press Enter when you're ready... ");
    getchar();
    
    // Start timing
    clock_t start_time = clock();
    
    printf("Go! ");
    fgets(user_input, MAX_LENGTH, stdin);
    
    // End timing
    clock_t end_time = clock();

    // Remove trailing newline from user input
    user_input[strcspn(user_input, "\n")] = 0;

    // Calculate time taken in seconds
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Count words
    int word_count = 0;
    char *token = strtok(user_input, " ");
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }

    // Calculate typing speed (words per minute)
    double words_per_minute = (word_count / time_taken) * 60;

    // Display results
    printf("\n--- Results ---\n");
    printf("You typed: \"%s\"\n", user_input);
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Your typing speed: %.2f words per minute\n", words_per_minute);
    
    if (strcmp(sentence, user_input) == 0) {
        printf("Great job! You typed the sentence correctly!\n");
    } else {
        printf("Oops! There were some mistakes. Keep practicing!\n");
    }
    
    printf("Thank you for participating! Type fast, but don’t forget to laugh along the way!\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    measure_typing_speed();
    return 0;
}