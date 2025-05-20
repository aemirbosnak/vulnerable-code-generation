//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 256

const char *sample_text = "The quick brown fox jumps over the lazy dog.";

void display_instructions() {
    printf("********************************************\n");
    printf("*          Typing Speed Test              *\n");
    printf("********************************************\n");
    printf("Instructions:\n");
    printf("1. You will see a sample text on the screen.\n");
    printf("2. Type the text as quickly and accurately as you can.\n");
    printf("3. Press Enter when you are done.\n");
    printf("********************************************\n\n");
}

double calculate_speed(int correct_chars, double time_taken) {
    return (correct_chars / time_taken) * 60; // speed in characters per minute
}

void get_user_input(char *input_buffer) {
    printf("Type the following text:\n\n");
    printf("\"%s\"\n\n", sample_text);
    printf("> ");
    fgets(input_buffer, MAX_TEXT_LENGTH, stdin);
    // Remove newline character if present
    input_buffer[strcspn(input_buffer, "\n")] = 0;
}

int count_correct_characters(const char *user_input) {
    int correct_count = 0;
    for (int i = 0; i < strlen(sample_text); i++) {
        if (user_input[i] == sample_text[i]) {
            correct_count++;
        } else {
            break; // Stop counting at the first incorrect character
        }
    }
    return correct_count;
}

void display_results(int correct_chars, double time_taken, double speed) {
    printf("\n********************************************\n");
    printf("Results:\n");
    printf("Correct Characters: %d\n", correct_chars);
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Typing Speed: %.2f characters per minute\n", speed);
    printf("********************************************\n");
}

int main() {
    char user_input[MAX_TEXT_LENGTH];
    clock_t start_time, end_time;

    display_instructions();
    
    start_time = clock();
    get_user_input(user_input);
    end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC; // seconds
    int correct_chars = count_correct_characters(user_input);
    double speed = calculate_speed(correct_chars, time_taken);

    display_results(correct_chars, time_taken, speed);
    
    return 0;
}