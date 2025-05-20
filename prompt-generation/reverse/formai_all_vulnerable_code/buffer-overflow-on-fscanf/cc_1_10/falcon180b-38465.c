//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    bool is_correct;
} word_t;

void load_words(const char* filename, word_t words[MAX_WORDS]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH + 1];
    int num_words = 0;

    while (fscanf(file, "%s", word) == 1) {
        if (num_words >= MAX_WORDS) {
            printf("Too many words in file: %s\n", filename);
            exit(1);
        }

        strcpy(words[num_words].word, word);
        words[num_words].is_correct = true;
        num_words++;
    }

    fclose(file);
}

void check_spelling(const char* text, const word_t words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH + 1];
    int word_len;

    while ((word_len = fscanf(stdin, "%s", word)) == 1) {
        bool is_correct = false;

        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, words[i].word) == 0) {
                is_correct = true;
                break;
            }
        }

        if (!is_correct) {
            printf("Possible spelling error: %s\n", word);
        }
    }
}

int main() {
    word_t words[MAX_WORDS];

    load_words("words.txt", words);
    check_spelling(stdin, words);

    return 0;
}