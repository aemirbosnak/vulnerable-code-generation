//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_TEXT_LENGTH 1024
#define TEXT_OPTIONS 5

const char *texts[TEXT_OPTIONS] = {
    "The quick brown fox jumps over the lazy dog.",
    "To be or not to be, that is the question.",
    "A journey of a thousand miles begins with a single step.",
    "All that glitters is not gold.",
    "In the end, we will remember not the words of our enemies, but the silence of our friends."
};

void display_welcome() {
    printf("========================================\n");
    printf("       Typing Speed Test Welcome       \n");
    printf("========================================\n");
    printf("Test your typing speed by typing the text displayed.\n");
    printf("Press Enter to continue...\n");
    getchar();
}

void choose_random_text(char *selected_text) {
    srand(time(NULL));
    int random_index = rand() % TEXT_OPTIONS;
    strcpy(selected_text, texts[random_index]);
}

void start_typing_test(const char *text_to_type) {
    char user_input[MAX_TEXT_LENGTH];
    printf("Type the following text:\n");
    printf("\"%s\"\n\n", text_to_type);
    printf("Start typing! Press Enter when you are done...\n");

    clock_t start_time = clock();
    fgets(user_input, MAX_TEXT_LENGTH, stdin);
    clock_t end_time = clock();

    // Calculate time taken in seconds
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Remove newline character potentially left by fgets
    size_t length = strlen(user_input);
    if (length > 0 && user_input[length - 1] == '\n') {
        user_input[length - 1] = '\0';
    }

    // Calculate typing speed in words per minute (WPM)
    int word_count = 0;
    char *word = strtok(user_input, " ");
    while (word != NULL) {
        word_count++;
        word = strtok(NULL, " ");
    }
    double wpm = (word_count / time_taken) * 60;

    printf("\nGreat job!\n");
    printf("Your typing speed is: %.2f WPM\n", wpm);
    printf("Time taken: %.2f seconds\n", time_taken);
}

int main() {
    char selected_text[MAX_TEXT_LENGTH];

    display_welcome();
    choose_random_text(selected_text);
    start_typing_test(selected_text);

    printf("\nThank you for participating in the Typing Speed Test!\n");
    printf("========================================\n");

    return 0;
}