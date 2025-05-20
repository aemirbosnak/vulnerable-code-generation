//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: Linus Torvalds
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

int compare(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;
    return wordB->count - wordA->count; // Sort in descending order
}

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_word_valid(const char *word) {
    for (int i = 0; word[i]; i++) {
        if (!isalpha(word[i])) return 0;
    }
    return 1; // valid word
}

void add_word(WordCount *wordCounts, int *totalWords, const char *word) {
    for (int i = 0; i < *totalWords; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }
    // New word
    strcpy(wordCounts[*totalWords].word, word);
    wordCounts[*totalWords].count = 1;
    (*totalWords)++;
}

void process_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    WordCount wordCounts[MAX_WORDS] = {0};
    int totalWords = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) == 1) {
        to_lower_case(buffer);
        if (is_word_valid(buffer)) {
            add_word(wordCounts, &totalWords, buffer);
        }
    }

    fclose(file);

    // Sort words by count
    qsort(wordCounts, totalWords, sizeof(WordCount), compare);

    // Print the results
    printf("Word Frequency Count:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_file(argv[1]);

    return EXIT_SUCCESS;
}