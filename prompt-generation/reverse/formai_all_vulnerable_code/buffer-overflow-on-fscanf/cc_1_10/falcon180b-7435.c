//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

struct word {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
};

struct word *load_words(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    struct word *words = malloc(sizeof(struct word) * MAX_WORDS);
    if (words == NULL) {
        printf("Error: out of memory\n");
        exit(1);
    }

    int num_words = 0;
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words in file %s\n", filename);
            exit(1);
        }

        strcpy(words[num_words].word, word);
        words[num_words].is_correct = true;
        num_words++;
    }

    fclose(fp);
    return words;
}

bool is_correct_word(const struct word *words, const char *word) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return words[i].is_correct;
        }
    }
    return false;
}

void correct_word(const struct word *words, int index, const char *corrected_word) {
    strcpy(words[index].word, corrected_word);
}

int main() {
    struct word *words = load_words("words.txt");

    char input_word[MAX_WORD_LENGTH];
    while (fgets(input_word, MAX_WORD_LENGTH, stdin)!= NULL) {
        char *word = strtok(input_word, " ");
        while (word!= NULL) {
            if (!is_correct_word(words, word)) {
                printf("Misspelled word: %s\n", word);
            }
            word = strtok(NULL, " ");
        }
    }

    return 0;
}