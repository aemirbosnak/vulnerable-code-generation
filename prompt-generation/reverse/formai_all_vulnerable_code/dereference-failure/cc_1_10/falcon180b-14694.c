//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_LENGTH 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} word_t;

typedef struct {
    word_t *words;
    int num_words;
} dictionary_t;

void load_dictionary(const char *filename, dictionary_t *dict) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int num_words = 0;
    dict->words = (word_t *)malloc(MAX_DICTIONARY_LENGTH * sizeof(word_t));
    while (fscanf(fp, "%s", dict->words[num_words].word)!= EOF) {
        dict->words[num_words].is_correct = true;
        num_words++;
    }
    dict->num_words = num_words;
    fclose(fp);
}

bool is_correct_word(const char *word, dictionary_t *dict) {
    int word_len = strlen(word);
    if (word_len > MAX_WORD_LENGTH) {
        return false;
    }

    for (int i = 0; i < dict->num_words; i++) {
        int dict_word_len = strlen(dict->words[i].word);
        if (dict_word_len == word_len && strcasecmp(word, dict->words[i].word) == 0) {
            return dict->words[i].is_correct;
        }
    }

    return false;
}

void suggest_corrections(const char *word, dictionary_t *dict) {
    int word_len = strlen(word);
    if (word_len > MAX_WORD_LENGTH) {
        printf("Error: word is too long.\n");
        return;
    }

    bool found_correct_word = false;
    for (int i = 0; i < dict->num_words; i++) {
        int dict_word_len = strlen(dict->words[i].word);
        if (dict_word_len == word_len && strcasecmp(word, dict->words[i].word) == 0) {
            printf("Correct spelling: %s\n", dict->words[i].word);
            found_correct_word = true;
            break;
        }
    }

    if (!found_correct_word) {
        printf("No suggestions found.\n");
    }
}

int main() {
    dictionary_t dict;
    load_dictionary("dictionary.txt", &dict);

    char word[MAX_WORD_LENGTH];
    printf("Enter a word to check: ");
    scanf("%s", word);

    if (is_correct_word(word, &dict)) {
        printf("Word is correct.\n");
    } else {
        suggest_corrections(word, &dict);
    }

    return 0;
}