//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordEntry;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_valid_word(const char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isalpha(word[i]) && !(word[i] == '\'' && i > 0 && i < strlen(word) - 1)) {
            return 0;
        }
    }
    return 1;
}

int add_word(WordEntry *word_entries, int *total_words, const char *word) {
    for (int i = 0; i < *total_words; i++) {
        if (strcmp(word_entries[i].word, word) == 0) {
            word_entries[i].count++;
            return 0; // already exists
        }
    }
    // New word
    strcpy(word_entries[*total_words].word, word);
    word_entries[*total_words].count = 1;
    (*total_words)++;
    return 1; // added new word
}

void print_word_frequencies(const WordEntry *word_entries, int total_words) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < total_words; i++) {
        printf("%s: %d\n", word_entries[i].word, word_entries[i].count);
    }
}

void cleanup(WordEntry *word_entries, int total_words) {
    for (int i = 0; i < total_words; i++) {
        memset(word_entries[i].word, 0, MAX_WORD_LEN);
        word_entries[i].count = 0;
    }
}

int main() {
    char input_filename[100];
    printf("Enter the filename to read: ");
    scanf("%99s", input_filename);

    FILE *file = fopen(input_filename, "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordEntry word_entries[MAX_WORDS];
    int total_words = 0;
    char buffer[MAX_WORD_LEN];

    while (fscanf(file, "%s", buffer) == 1) {
        to_lowercase(buffer);
        if (is_valid_word(buffer)) {
            add_word(word_entries, &total_words, buffer);
        }
    }

    fclose(file);
    print_word_frequencies(word_entries, total_words);
    cleanup(word_entries, total_words); // cleanup resources if necessary

    return EXIT_SUCCESS;
}