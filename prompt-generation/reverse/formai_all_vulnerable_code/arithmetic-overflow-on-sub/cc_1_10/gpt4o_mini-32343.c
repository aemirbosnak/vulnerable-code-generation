//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 256
#define NUM_TESTS 5

const char *test_texts[NUM_TESTS] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "In the middle of difficulty lies opportunity.",
    "Success is not the key to happiness. Happiness is the key to success.",
    "What we think, we become."
};

void clear_buffer() {
    while(getchar() != '\n');
}

void display_instructions() {
    printf("\nTyping Speed Test\n");
    printf("=================\n");
    printf("You will be given a sentence to type.\n");
    printf("Press Enter to start the test!\n");
    clear_buffer();
}

void run_test(const char *test_sentence) {
    char user_input[MAX_TEXT_LENGTH];
    printf("\nType the following sentence:\n");
    printf("\"%s\"\n", test_sentence);
    
    clock_t start_time = clock();
    fgets(user_input, MAX_TEXT_LENGTH, stdin);
    clock_t end_time = clock();
    
    // Remove newline in case user presses Enter
    user_input[strcspn(user_input, "\n")] = 0;

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    int characters_typed = strlen(user_input);
    
    printf("You typed: \"%s\"\n", user_input);
    printf("Time taken: %.2f seconds\n", time_taken);
    
    if (strcmp(user_input, test_sentence) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect! The correct sentence was:\n");
        printf("\"%s\"\n", test_sentence);
    }
    
    double wpm = (characters_typed / 5.0) / (time_taken / 60.0); // Words per minute
    printf("Your typing speed: %.2f WPM\n", wpm);
}

int main() {
    display_instructions();

    for (int i = 0; i < NUM_TESTS; i++) {
        printf("Test #%d:\n", i + 1);
        run_test(test_texts[i]);
        printf("\nPress Enter for the next test...\n");
        clear_buffer();
    }

    printf("Test complete! Thank you for participating.\n");

    return 0;
}