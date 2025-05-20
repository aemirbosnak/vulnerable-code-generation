//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

typedef struct {
    Word *words;
    int size;
} Dictionary;

void init_dictionary(Dictionary *dict) {
    dict->size = 0;
    dict->words = (Word *)malloc(MAX_DICTIONARY_SIZE * sizeof(Word));
}

void add_word(Dictionary *dict, char *word, bool is_correct) {
    if (dict->size >= MAX_DICTIONARY_SIZE) {
        printf("Error: Dictionary is full.\n");
        return;
    }

    strcpy(dict->words[dict->size].word, word);
    dict->words[dict->size].is_correct = is_correct;
    dict->size++;
}

bool is_correct_word(Dictionary *dict, char *word) {
    int i;

    for (i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0 && dict->words[i].is_correct) {
            return true;
        }
    }

    return false;
}

void spell_check(Dictionary *dict, char *text) {
    char word[MAX_WORD_LENGTH];
    int i, j, len;

    i = 0;
    while ((len = strlen(text + i)) > 0) {
        if (isalnum(text[i])) {
            strncpy(word, text + i, len);
            word[len] = '\0';
            if (!is_correct_word(dict, word)) {
                printf("Possible misspelling: %s\n", word);
            }
        }

        i += len;
        while (i < strlen(text) &&!isalnum(text[i])) {
            i++;
        }
    }
}

int main() {
    Dictionary dict;
    init_dictionary(&dict);

    add_word(&dict, "hello", true);
    add_word(&dict, "world", true);
    add_word(&dict, "misspelled", false);

    char text[] = "Hello, world! This is a misspelled word.";
    spell_check(&dict, text);

    return 0;
}