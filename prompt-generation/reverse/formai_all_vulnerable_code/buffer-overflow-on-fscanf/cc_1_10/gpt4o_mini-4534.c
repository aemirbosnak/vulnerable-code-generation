//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int find_word(WordFreq *words, int total_words, const char *word) {
    for (int i = 0; i < total_words; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;  // Word found
        }
    }
    return -1;  // Word not found
}

void add_word(WordFreq *words, int *total_words, const char *word) {
    int index = find_word(words, *total_words, word);
    if (index != -1) {
        words[index].count++;
    } else {
        strcpy(words[*total_words].word, word);
        words[*total_words].count = 1;
        (*total_words)++;
    }
}

void print_word_frequencies(WordFreq *words, int total_words) {
    printf("\nWord Frequencies:\n");
    printf("------------------\n");
    for (int i = 0; i < total_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

void filter_and_count_words(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    WordFreq words[MAX_WORDS] = {0};
    int total_words = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) != EOF) {
        to_lower_case(word);
        // Remove punctuation from word
        char *cleaned_word = word;
        while (*cleaned_word) {
            if (ispunct(*cleaned_word)) {
                *cleaned_word = '\0';
                break;
            }
            cleaned_word++;
        }
        if (strlen(word) > 0) {
            add_word(words, &total_words, word);
        }
    }

    fclose(file);
    print_word_frequencies(words, total_words);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    filter_and_count_words(argv[1]);
    return EXIT_SUCCESS;
}