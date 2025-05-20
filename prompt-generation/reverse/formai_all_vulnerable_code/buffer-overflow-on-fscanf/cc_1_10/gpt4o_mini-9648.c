//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_valid_word(char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isalpha(word[i]) && word[i] != '\'') {
            return 0;
        }
    }
    return 1;
}

void insert_or_increment(WordFrequency *freq_array, int *size, char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(freq_array[i].word, word) == 0) {
            freq_array[i].count++;
            return;
        }
    }
    strcpy(freq_array[*size].word, word);
    freq_array[*size].count = 1;
    (*size)++;
}

void print_word_frequencies(WordFrequency *freq_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", freq_array[i].word, freq_array[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    WordFrequency freq_array[MAX_WORDS];
    int size = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) != EOF) {
        to_lowercase(word);
        if (is_valid_word(word)) {
            insert_or_increment(freq_array, &size, word);
        }
    }

    fclose(file);

    printf("Word Frequencies:\n");
    print_word_frequencies(freq_array, size);

    return 0;
}