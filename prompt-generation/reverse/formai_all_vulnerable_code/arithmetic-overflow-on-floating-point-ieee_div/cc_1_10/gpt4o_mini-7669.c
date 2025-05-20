//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define SAMPLE_TEXT "The quick brown fox jumps over the lazy dog."
#define BUFFER_SIZE 256

void display_instructions() {
    printf("=================================\n");
    printf("=== Typing Speed Test Program ===\n");
    printf("=================================\n");
    printf("Instructions:\n");
    printf("1. You will be given a sentence to type.\n");
    printf("2. Type the sentence as fast and accurately as you can.\n");
    printf("3. Press Enter when you are finished.\n");
    printf("=================================\n\n");
}

void get_user_input(char *input) {
    printf("Type the following sentence:\n");
    printf("\"%s\"\n\n", SAMPLE_TEXT);
    printf("Your input: ");
    fgets(input, BUFFER_SIZE, stdin);
}

int calculate_accuracy(char *input) {
    int correct_chars = 0;
    for (int i = 0; i < strlen(SAMPLE_TEXT); i++) {
        if (input[i] == SAMPLE_TEXT[i]) {
            correct_chars++;
        }
    }
    return (correct_chars * 100) / strlen(SAMPLE_TEXT);
}

float calculate_speed(clock_t start_time, clock_t end_time) {
    float time_taken = (float)(end_time - start_time) / CLOCKS_PER_SEC; // in seconds
    int char_count = strlen(SAMPLE_TEXT);
    return (char_count / time_taken) * 60; // characters per minute
}

int main() {
    char user_input[BUFFER_SIZE];
    clock_t start_time, end_time;
    
    display_instructions();

    printf("Press Enter to start...\n");
    getchar();
    
    start_time = clock(); // Start timing
    get_user_input(user_input);
    end_time = clock(); // End timing

    // Strip newline character from fgets
    size_t len = strlen(user_input);
    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }

    int accuracy = calculate_accuracy(user_input);
    float speed = calculate_speed(start_time, end_time);
    
    printf("\nResults:\n");
    printf("=================================\n");
    printf("Typing Speed: %.2f characters per minute\n", speed);
    printf("Accuracy: %d%%\n", accuracy);
    printf("=================================\n");
    
    return 0;
}