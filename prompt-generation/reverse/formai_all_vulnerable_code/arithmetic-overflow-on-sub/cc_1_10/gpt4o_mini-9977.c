//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: ultraprecise
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
#define PROMPT_SIZE 512

void clear_buffer() {
    while (getchar() != '\n');
}

void display_instructions() {
    printf("Welcome to the C Typing Speed Test!\n");
    printf("Type the given text as quickly and accurately as you can.\n");
    printf("Press Enter when you're ready to start.\n\n");
}

void display_text(const char *text) {
    printf("\nType the following text:\n\n");
    printf("\"%s\"\n\n", text);
}

int get_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) == NULL) {
        printf("Error reading input.\n");
        return 0;
    }
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
    return 1;
}

void calculate_speed_and_accuracy(const char *original_text, const char *user_input, double time_taken) {
    int chars_typed = strlen(user_input);
    int total_chars = strlen(original_text);

    int correct_chars = 0;
    for (int i = 0; i < chars_typed && i < total_chars; i++) {
        if (user_input[i] == original_text[i]) {
            correct_chars++;
        }
    }

    double accuracy = ((double)correct_chars / total_chars) * 100;
    double speed_wpm = (chars_typed / 5.0) / (time_taken / 60.0);

    printf("\nResults:\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typed characters: %d\n", chars_typed);
    printf("Correct characters: %d\n", correct_chars);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Speed: %.2f WPM\n", speed_wpm);
}

int main() {
    const char *text_to_type = "The quick brown fox jumps over the lazy dog.";
    char user_input[BUFFER_SIZE];
    
    display_instructions();
    clear_buffer();

    getchar(); // Wait for user to press Enter

    display_text(text_to_type);

    printf("Press Enter to start...\n");
    clear_buffer();
    getchar(); // Wait for user to press Enter to start

    clock_t start_time = clock();

    if (!get_input(user_input, sizeof(user_input))) {
        return 1; // Exit on input error
    }

    clock_t end_time = clock();

    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    calculate_speed_and_accuracy(text_to_type, user_input, time_taken);

    printf("\nThank you for participating in the typing speed test!\n");

    return 0;
}