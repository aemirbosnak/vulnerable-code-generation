//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int add_word(WordCount *wordCounts, int *wordCountSize, const char *word) {
    for (int i = 0; i < *wordCountSize; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return *wordCountSize; // already exists
        }
    }
    
    // New word
    strcpy(wordCounts[*wordCountSize].word, word);
    wordCounts[*wordCountSize].count = 1;
    (*wordCountSize)++;
    
    return *wordCountSize; // size updated
}

void process_file(const char *filename, WordCount *wordCounts, int *wordCountSize) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        to_lower_case(word);
        
        // Remove punctuation from the word
        int len = strlen(word);
        if (len > 0) {
            int j = 0;
            for (int i = 0; i < len; i++) {
                if (isalpha(word[i])) {
                    word[j++] = word[i];
                }
            }
            word[j] = '\0';  // Null terminate the modified string
        }
        
        if (strlen(word) > 0) { // Only add non-empty words
            add_word(wordCounts, wordCountSize, word);
        }
    }
    
    fclose(file);
}

void print_word_counts(const WordCount *wordCounts, int wordCountSize) {
    printf("Word Frequency Count:\n");
    for (int i = 0; i < wordCountSize; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    WordCount wordCounts[MAX_WORD_COUNT];
    int wordCountSize = 0;

    process_file(argv[1], wordCounts, &wordCountSize);
    print_word_counts(wordCounts, wordCountSize);

    return EXIT_SUCCESS;
}