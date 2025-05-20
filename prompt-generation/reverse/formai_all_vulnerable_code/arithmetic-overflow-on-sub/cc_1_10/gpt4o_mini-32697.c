//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 512
#define MAX_INPUT_LENGTH 512

const char* prompt_text = "The quick brown fox jumps over the lazy dog.\nType the above sentence as fast as you can:";

void clear_input_buffer() {
    while (getchar() != '\n');
}

int compare_strings(const char* original, const char* input) {
    return strcmp(original, input) == 0;
}

void display_result(double time_taken, int correct_chars, int total_chars) {
    printf("Time Taken: %.2f seconds\n", time_taken);
    printf("Total Characters Typed: %d\n", total_chars);
    printf("Correct Characters: %d\n", correct_chars);
    printf("Accuracy: %.2f%%\n",
           total_chars > 0 ? (correct_chars / (float)total_chars) * 100 : 0);
}

void typing_test() {
    char user_input[MAX_INPUT_LENGTH];
    clock_t start_time, end_time;

    printf("%s\n\n", prompt_text);
    printf("Press Enter to start the timer... ");
    clear_input_buffer();
    start_time = clock();

    // Get user input
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    // Remove newline if present
    user_input[strcspn(user_input, "\n")] = '\0'; 

    end_time = clock();
    
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int correct_chars = 0;
    int total_chars = strlen(prompt_text);

    // Compare the strings character by character
    for (int i = 0; i < strlen(user_input) && i < total_chars; i++) {
        if (user_input[i] == prompt_text[i]) {
            correct_chars++;
        }
    }

    display_result(time_taken, correct_chars, total_chars);
}

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a sentence to type.\n");
    printf("Your time, accuracy, and typing speed will be calculated.\n");
    printf("Let's begin!\n\n");
}

void print_welcome() {
    printf("==============================\n");
    printf("    Typing Speed Test\n");
    printf("==============================\n\n");
}

int main() {
    char choice;

    print_welcome();
    display_instructions();

    do {
        typing_test();

        printf("\nDo you want to try again? (y/n): ");
        scanf(" %c", &choice);
        clear_input_buffer();
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for participating!\n");
    return 0;
}