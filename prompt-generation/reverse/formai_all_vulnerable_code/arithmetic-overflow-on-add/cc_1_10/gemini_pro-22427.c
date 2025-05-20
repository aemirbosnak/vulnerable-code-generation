//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int num_words;
} WordList;

void generate_word_list(WordList *word_list) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening word list file.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Add word to word list
        strcpy(word_list->words[word_list->num_words].word, line);
        word_list->words[word_list->num_words].length = strlen(line);
        word_list->num_words++;
    }

    fclose(file);
}

void print_word_list(WordList *word_list) {
    for (int i = 0; i < word_list->num_words; i++) {
        printf("%s (%d)\n", word_list->words[i].word, word_list->words[i].length);
    }
}

void test_typing_speed(WordList *word_list) {
    // Get user input
    printf("Enter the following words as quickly as you can:\n");
    for (int i = 0; i < word_list->num_words; i++) {
        printf("%s ", word_list->words[i].word);
    }
    printf("\n");

    // Start timer
    clock_t start = clock();

    // Get user input
    char input[MAX_WORDS * MAX_WORD_LENGTH];
    gets(input);

    // Stop timer
    clock_t end = clock();

    // Calculate typing speed
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    double words_per_minute = (double)word_list->num_words / time_taken * 60;

    // Print results
    printf("Your typing speed is %.2f words per minute.\n", words_per_minute);
}

int main() {
    // Generate word list
    WordList word_list;
    generate_word_list(&word_list);

    // Print word list
    // print_word_list(&word_list);

    // Test typing speed
    test_typing_speed(&word_list);

    return 0;
}