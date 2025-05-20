//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEXT_TO_TYPE "The quick brown fox jumps over the lazy dog."
#define MAX_LENGTH 256

void display_instructions() {
    printf("Typing Speed Test\n");
    printf("-------------------\n");
    printf("Instructions:\n");
    printf("1. You will be given a sentence to type.\n");
    printf("2. Type the sentence as quickly and accurately as possible.\n");
    printf("3. Press Enter when you are done.\n");
    printf("-------------------\n");
}

void clean_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

double calculate_speed(int time_taken, int character_count) {
    return (character_count / (time_taken / 60.0));
}

int main() {
    char user_input[MAX_LENGTH];
    clock_t start_time, end_time;
    double total_time, speed;
    int correct_count = 0;

    display_instructions();
    printf("\nText to type:\n%s\n\n", TEXT_TO_TYPE);

    printf("Press Enter to start typing...");
    clean_input_buffer();
    
    start_time = clock();

    printf("Start typing now:\n");
    fgets(user_input, MAX_LENGTH, stdin);

    end_time = clock();
    total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Remove newline character if present
    size_t len = strlen(user_input);
    if (len > 0 && user_input[len - 1] == '\n') {
        user_input[len - 1] = '\0';
    }

    // Calculate correct character count
    for (int i = 0; i < strlen(TEXT_TO_TYPE); i++) {
        if (user_input[i] == TEXT_TO_TYPE[i]) {
            correct_count++;
        }
    }

    int total_characters = strlen(TEXT_TO_TYPE);
    speed = calculate_speed(total_time, correct_count);

    printf("\nResults:\n");
    printf("Total time taken: %.2f seconds\n", total_time);
    printf("Correct characters: %d out of %d\n", correct_count, total_characters);
    printf("Typing speed: %.2f characters per minute\n", speed);

    // Display feedback on accuracy
    double accuracy = (correct_count / (double)total_characters) * 100;
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}