//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct WordFreq {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

int word_compare(const void *a, const void *b) {
    return strcmp(((WordFreq *)a)->word, ((WordFreq *)b)->word);
}

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int is_valid_char(char c) {
    return (isalpha(c) || c == '\''); // Allow alphabets and apostrophes
}

void process_text(FILE *file, WordFreq *words, int *word_count) {
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        // Clean the word by removing invalid characters
        char clean_word[MAX_WORD_LENGTH] = "";
        int j = 0;

        for (int i = 0; buffer[i]; i++) {
            if (is_valid_char(buffer[i])) {
                clean_word[j++] = buffer[i];
            }
        }
        clean_word[j] = '\0';
        
        // Convert to lower case
        to_lower_case(clean_word);

        // Check if the word already exists
        int found = 0;
        for (int i = 0; i < *word_count; i++) {
            if (strcmp(words[i].word, clean_word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        
        // If not found, add a new word
        if (!found && *word_count < MAX_WORDS) {
            strcpy(words[*word_count].word, clean_word);
            words[*word_count].count = 1;
            (*word_count)++;
        }
    }
}

void print_word_frequencies(WordFreq *words, int word_count) {
    printf("\nWord Frequencies:\n");
    printf("-----------------\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordFreq words[MAX_WORDS];
    int word_count = 0;

    process_text(file, words, &word_count);
    fclose(file);

    // Sort the words alphabetically
    qsort(words, word_count, sizeof(WordFreq), word_compare);

    print_word_frequencies(words, word_count);
    
    return EXIT_SUCCESS;
}