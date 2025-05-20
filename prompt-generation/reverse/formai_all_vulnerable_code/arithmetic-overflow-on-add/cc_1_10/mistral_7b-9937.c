//MISTRAL-7B DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define WORDS_ARRAY_SIZE 10000

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

bool is_alphanumeric(char c) {
    return (isalpha(c) || isdigit(c) || c == '_');
}

char* word_copy(const char* word) {
    size_t length = strlen(word);
    char* copy = malloc(length + 1);
    strncpy(copy, word, length + 1);
    return copy;
}

void add_word(Word* words, char* word) {
    for (int i = 0; i < WORDS_ARRAY_SIZE; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            free(word);
            return;
        }
    }

    for (int i = 0; i < WORDS_ARRAY_SIZE - 1; i++) {
        words[i] = words[i + 1];
    }

    strcpy(words[WORDS_ARRAY_SIZE - 1].word, word);
    words[WORDS_ARRAY_SIZE - 1].count = 1;
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    Word words[WORDS_ARRAY_SIZE];
    int num_words = 0;
    char line[1024];

    while (fgets(line, sizeof(line), file) != NULL) {
        char* token = strtok(line, " ");
        while (token != NULL) {
            if (is_alphanumeric(token[0])) {
                char* word = word_copy(token);
                add_word(words, word);
                num_words++;
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    printf("Total words: %d\n", num_words);
    for (int i = 0; i < WORDS_ARRAY_SIZE; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }

    return 0;
}