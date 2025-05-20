//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 100

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int find_word(WordCount *wordCounts, int size, const char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void insert_or_increment(WordCount *wordCounts, int *size, const char *word) {
    int index = find_word(wordCounts, *size, word);
    if (index != -1) {
        wordCounts[index].count++;
    } else {
        if (*size < MAX_WORDS) {
            strcpy(wordCounts[*size].word, word);
            wordCounts[*size].count = 1;
            (*size)++;
        } else {
            printf("Error: Maximum word limit reached.\n");
        }
    }
}

void print_word_counts(WordCount *wordCounts, int size) {
    printf("Word Frequency Count:\n");
    for (int i = 0; i < size; i++) {
        printf("'%s' : %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void process_text(FILE *file, WordCount *wordCounts, int *size) {
    char word[MAX_LENGTH];
    while(fscanf(file, "%s", word) != EOF) {
        // Remove punctuation and convert to lower case
        char cleanWord[MAX_LENGTH];
        int j = 0;
        for (int i = 0; word[i]; i++) {
            if (isalpha(word[i])) {
                cleanWord[j++] = word[i];
            }
        }
        cleanWord[j] = '\0';
        to_lowercase(cleanWord);
        
        if (strlen(cleanWord) > 0) {
            insert_or_increment(wordCounts, size, cleanWord);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordCount wordCounts[MAX_WORDS];
    int size = 0;

    process_text(file, wordCounts, &size);

    fclose(file);

    print_word_counts(wordCounts, size);

    return EXIT_SUCCESS;
}