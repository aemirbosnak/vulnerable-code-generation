//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int word_exists(WordCount words[], int word_count, const char *word) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i; // Found the word, return the index
        }
    }
    return -1; // Word not found
}

void add_word(WordCount words[], int *word_count, const char *word) {
    int index = word_exists(words, *word_count, word);
    if (index != -1) {
        words[index].count++; // Increment count if found
    } else {
        strncpy(words[*word_count].word, word, MAX_WORD_LENGTH);
        words[*word_count].count = 1; // Add new word
        (*word_count)++;
    }
}

void sort_word_counts(WordCount words[], int word_count) {
    for (int i = 0; i < word_count - 1; i++) {
        for (int j = i + 1; j < word_count; j++) {
            if (words[i].count < words[j].count) {
                WordCount temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void print_word_counts(WordCount words[], int word_count) {
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void free_resources(WordCount words[]) {
    // In this case, we are using a statically allocated array,
    // no dynamic memory is allocated here so this function does nothing.
    // Included for future extensibility if needed.
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    WordCount words[MAX_WORDS];
    int word_count = 0;
    char buffer[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", buffer) != EOF) {
        to_lowercase(buffer); // Convert to lowercase
        // Remove trailing punctuations
        int length = strlen(buffer);
        while (length > 0 && ispunct(buffer[length - 1])) {
            buffer[length - 1] = '\0';
            length--;
        }
        // Add word to count
        add_word(words, &word_count, buffer);
    }

    fclose(file);

    // Sort and print the words
    sort_word_counts(words, word_count);
    print_word_counts(words, word_count);

    // Clean up resources
    free_resources(words);
    
    return 0;
}