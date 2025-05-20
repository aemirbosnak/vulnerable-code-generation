//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 256
#define QUOTE_COUNT 5

const char *quotes[] = {
    "The only way to do great work is to love what you do.",
    "Life is what happens when you're busy making other plans.",
    "Get busy living or get busy dying.",
    "You miss 100% of the shots you don't take.",
    "Believe you can and you're halfway there."
};

void clear_buffer() {
    while (getchar() != '\n');
}

void print_banner() {
    printf("\n=========================================\n");
    printf("           TYPING SPEED TEST            \n");
    printf("=========================================\n");
}

void display_quote() {
    srand(time(NULL));
    int random_index = rand() % QUOTE_COUNT;
    printf("\"%s\"\n", quotes[random_index]);
}

float calculate_wpm(int words, float time_taken) {
    return (words / time_taken) * 60.0;
}

void start_typing_test(const char *text) {
    char user_input[MAX_STRING_LENGTH];
    int word_count = 0;

    printf("Type the following text:\n\n%s\n\n", text);
    printf("Begin in 5 seconds...\n");
    for (int i = 5; i > 0; i--) {
        printf("%d... ", i);
        fflush(stdout);
        sleep(1);
    }
    printf("\nGo!\n");

    clock_t start_time = clock();
    fgets(user_input, MAX_STRING_LENGTH, stdin);
    clock_t end_time = clock();

    // Count words in user input
    char *token = strtok(user_input, " \n");
    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " \n");
    }

    float time_taken = (float)(end_time - start_time) / CLOCKS_PER_SEC;
    float wpm = calculate_wpm(word_count, time_taken);

    printf("\nYour typing speed: %.2f WPM\n", wpm);
    printf("You typed %d words in %.2f seconds.\n", word_count, time_taken);
}

int main() {
    print_banner();
    
    display_quote();

    const char *test_text = "The quick brown fox jumps over the lazy dog.";

    start_typing_test(test_text);

    printf("\nThank you for playing!\n");
    return 0;
}