//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordEntry;

void to_lowercase(char* str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int compare_entries(const void* a, const void* b) {
    return ((WordEntry*)b)->count - ((WordEntry*)a)->count;
}

void count_words(FILE* file, WordEntry* words, int* total_words) {
    char word[MAX_WORD_LENGTH];
    int found;
    *total_words = 0;

    while (fscanf(file, "%s", word) == 1) {
        to_lowercase(word);
        found = 0;

        for (int i = 0; i < *total_words; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && *total_words < MAX_WORDS) {
            strcpy(words[*total_words].word, word);
            words[*total_words].count = 1;
            (*total_words)++;
        }
    }
}

void print_word_frequencies(WordEntry* words, int total_words) {
    printf("\nWord Frequencies:\n");
    printf("------------------\n");
    for (int i = 0; i < total_words; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordEntry words[MAX_WORDS];
    int total_words;

    count_words(file, words, &total_words);
    fclose(file);

    qsort(words, total_words, sizeof(WordEntry), compare_entries);
    print_word_frequencies(words, total_words);

    return EXIT_SUCCESS;
}