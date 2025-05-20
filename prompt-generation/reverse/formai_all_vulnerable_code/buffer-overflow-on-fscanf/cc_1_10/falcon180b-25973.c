//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Cryptic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    bool is_correct;
} word_t;

word_t words[MAX_WORDS];
int num_words = 0;

void load_words(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(file, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in file '%s'\n", filename);
            exit(1);
        }

        strcpy(words[num_words].word, word);
        words[num_words].is_correct = true;
        num_words++;
    }

    fclose(file);
}

bool is_word(const char* text, int start, int end) {
    if (start >= end) {
        return false;
    }

    for (int i = start; i <= end; i++) {
        if (!isalnum(text[i])) {
            return false;
        }
    }

    return true;
}

void spell_check(const char* text) {
    int len = strlen(text);
    int i = 0;

    while (i < len) {
        int j = i;
        while (j < len && isalnum(text[j])) {
            j++;
        }

        if (is_word(text, i, j)) {
            int k = 0;
            while (k < num_words && strcmp(words[k].word, text + i)) {
                k++;
            }

            if (k == num_words ||!words[k].is_correct) {
                printf("Misspelled word: %s\n", text + i);
            }
        }

        i = j;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    load_words(argv[1]);
    spell_check(argv[1]);

    return 0;
}