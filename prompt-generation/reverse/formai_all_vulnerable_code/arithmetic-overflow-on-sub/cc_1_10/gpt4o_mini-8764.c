//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_INPUT_LENGTH 1000

// Function to display rules and instructions
void display_instructions() {
    printf("\n--- Typing Speed Test ---\n");
    printf("1. You will be presented with a sentence to type.\n");
    printf("2. Type the sentence as fast and accurately as you can.\n");
    printf("3. Your time will be recorded and your typing speed will be calculated.\n");
    printf("4. Press 'Enter' after typing the sentence to complete the test.\n\n");
}

// Function to generate a random sentence
void generate_random_sentence(char *sentence, int length) {
    const char *text_samples[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Sphinx of black quartz, judge my vow.",
        "Pack my box with five dozen liquor jugs.",
        "How razorback-jumping frogs can bunch up.",
        "Jinxed wizards pluck ivy from the big quilt.",
        "A mad boxer shot a quick, gloved jab to the jaw.",
        "The five boxing wizards jump quickly."
    };
    int num_samples = sizeof(text_samples) / sizeof(text_samples[0]);
    strcpy(sentence, text_samples[rand() % num_samples]);
}

// Function to calculate typing speed in WPM
double calculate_wpm(int num_chars, double time_taken) {
    return (num_chars / 5.0) / (time_taken / 60.0);
}

// Typing test function
void typing_test() {
    char sentence[MAX_TEXT_LENGTH];
    char user_input[MAX_INPUT_LENGTH];
    
    generate_random_sentence(sentence, MAX_TEXT_LENGTH);
    
    printf("Your sentence to type:\n");
    printf("\"%s\"\n", sentence);
    printf("Press 'Enter' to start...\n");
    getchar();

    clock_t start_time = clock();
    
    printf("Start typing:\n");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    
    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    // Remove the trailing newline from user input
    user_input[strcspn(user_input, "\n")] = 0;

    // Calculate number of characters typed and compare with the sentence
    int correct_chars = 0;
    for (int i = 0; i < strlen(sentence) && i < strlen(user_input); i++) {
        if (sentence[i] == user_input[i]) {
            correct_chars++;
        }
    }

    double speed = calculate_wpm(correct_chars, time_taken);
    
    printf("\n--- Results ---\n");
    printf("Typed: \"%s\"\n", user_input);
    printf("Original: \"%s\"\n", sentence);
    printf("Number of correct characters: %d out of %d\n", correct_chars, strlen(sentence));
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Your typing speed: %.2f WPM\n", speed);
}

int main() {
    srand(time(NULL));
    display_instructions();
    typing_test();
    
    return 0;
}