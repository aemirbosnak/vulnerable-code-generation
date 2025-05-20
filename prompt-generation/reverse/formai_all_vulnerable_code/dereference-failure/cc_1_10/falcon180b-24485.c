//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 10000
#define MAX_WORDS 10000

typedef struct {
    char *word;
    int count;
} Word;

typedef struct {
    Word *words;
    int num_words;
} Dictionary;

void init_dictionary(Dictionary *dict) {
    dict->num_words = 0;
    dict->words = malloc(MAX_WORDS * sizeof(Word));
}

void add_word(Dictionary *dict, const char *word) {
    int i;
    for (i = 0; i < dict->num_words; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            dict->words[i].count++;
            return;
        }
    }
    if (dict->num_words >= MAX_WORDS) {
        printf("Error: Dictionary is full.\n");
        exit(1);
    }
    dict->words[dict->num_words].word = strdup(word);
    dict->words[dict->num_words].count = 1;
    dict->num_words++;
}

void print_dictionary(Dictionary *dict) {
    int i;
    for (i = 0; i < dict->num_words; i++) {
        printf("%s: %d\n", dict->words[i].word, dict->words[i].count);
    }
}

void free_dictionary(Dictionary *dict) {
    int i;
    for (i = 0; i < dict->num_words; i++) {
        free(dict->words[i].word);
    }
    free(dict->words);
}

void translate(Dictionary *dict, const char *text) {
    char *word;
    int i, j, k;
    char *sentence = strdup(text);
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        word = strdup(token);
        i = 0;
        while (dict->words[i].word!= NULL && strcmp(dict->words[i].word, word)!= 0) {
            i++;
        }
        if (dict->words[i].word == NULL) {
            printf("%s: (unknown)\n", word);
        } else {
            printf("%s: %s\n", word, dict->words[i].word);
        }
        free(word);
        free(token);
        token = strtok(NULL, " ");
    }
    free(sentence);
}

int main() {
    Dictionary dict;
    init_dictionary(&dict);
    add_word(&dict, "hello");
    add_word(&dict, "world");
    translate(&dict, "hello world");
    print_dictionary(&dict);
    free_dictionary(&dict);
    return 0;
}