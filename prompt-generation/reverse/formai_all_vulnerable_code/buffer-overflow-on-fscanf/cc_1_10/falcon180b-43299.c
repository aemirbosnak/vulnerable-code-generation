//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LEN 20
#define MAX_DICT_SIZE 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int frequency;
} word_t;

typedef struct {
    word_t *words;
    int size;
} dictionary_t;

void init_dictionary(dictionary_t *dict) {
    dict->size = 0;
    dict->words = (word_t *)malloc(MAX_DICT_SIZE * sizeof(word_t));
}

void add_word(dictionary_t *dict, char *word) {
    word_t *new_word = &dict->words[dict->size];
    strcpy(new_word->word, word);
    new_word->frequency = 1;
    dict->size++;
}

int find_word(dictionary_t *dict, char *word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void print_dictionary(dictionary_t *dict) {
    for (int i = 0; i < dict->size; i++) {
        printf("%s %d\n", dict->words[i].word, dict->words[i].frequency);
    }
}

int main() {
    dictionary_t dict;
    init_dictionary(&dict);
    char word[MAX_WORD_LEN];
    while (fscanf(stdin, "%s", word)!= EOF) {
        int index = find_word(&dict, word);
        if (index == -1) {
            add_word(&dict, word);
        } else {
            dict.words[index].frequency++;
        }
    }
    print_dictionary(&dict);
    return 0;
}