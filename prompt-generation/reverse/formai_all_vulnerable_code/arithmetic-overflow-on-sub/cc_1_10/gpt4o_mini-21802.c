//GPT-4o-mini DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_SENTENCES 10
#define MAX_LENGTH 256

char *sentences[MAX_SENTENCES] = {
    "The quick brown fox jumps over the lazy dog.",
    "A journey of a thousand miles begins with a single step.",
    "To be or not to be, that is the question.",
    "All that glitters is not gold.",
    "In the middle of difficulty lies opportunity.",
    "A bird in the hand is worth two in the bush.",
    "Fortune favors the bold.",
    "The only limit to our realization of tomorrow is our doubts of today.",
    "Success is not final, failure is not fatal: It is the courage to continue that counts.",
    "Life is what happens when you're busy making other plans."
};

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void display_instructions() {
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be given a sentence to type.\n");
    printf("Type the sentence as fast and accurately as you can.\n");
    printf("Press Enter to start...\n");
    clear_input_buffer();
}

void select_random_sentence(char *sentence) {
    int index = rand() % MAX_SENTENCES;
    strcpy(sentence, sentences[index]);
}

int calculate_wpm(int num_words, double time_taken) {
    return (int)((num_words / time_taken) * 60);
}

int count_words(const char *input) {
    int count = 0, in_word = 0;
    while (*input) {
        if (*input == ' ' || *input == '\n' || *input == '\t') {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            count++;
        }
        input++;
    }
    return count;
}

int main() {
    char input[MAX_LENGTH];
    char target_sentence[MAX_LENGTH];

    srand(time(NULL));
    display_instructions();

    select_random_sentence(target_sentence);
    printf("\nType this sentence:\n\n%s\n\n", target_sentence);
    printf("Start typing:\n");

    clock_t start_time = clock();
    fgets(input, MAX_LENGTH, stdin);
    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    int num_words_typed = count_words(input);
    int target_word_count = count_words(target_sentence);
    int wpm = calculate_wpm(num_words_typed, time_taken);

    printf("\nResults:\n");
    printf("Time taken: %.2f seconds\n", time_taken);
    printf("Typed words: %d\n", num_words_typed);
    printf("Target words: %d\n", target_word_count);
    printf("Words per minute (WPM): %d\n", wpm);
    
    if (strcmp(input, target_sentence) == 0) {
        printf("Congratulations! You typed the sentence correctly!\n");
    } else {
        printf("Oops! There were mistakes in your typing.\n");
        printf("Correct sentence: %s\n", target_sentence);
    }

    printf("Thank you for participating in the Typing Speed Test!\n");
    return 0;
}