//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 50000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

typedef struct {
    Word *words;
    int num_words;
} Dictionary;

Dictionary *create_dictionary() {
    Dictionary *dict = (Dictionary *) malloc(sizeof(Dictionary));
    dict->words = (Word *) malloc(MAX_DICTIONARY_SIZE * sizeof(Word));
    dict->num_words = 0;
    return dict;
}

void add_word(Dictionary *dict, char *word) {
    if (dict->num_words >= MAX_DICTIONARY_SIZE) {
        printf("Dictionary is full.\n");
        return;
    }
    Word *new_word = (Word *) malloc(sizeof(Word));
    strcpy(new_word->word, word);
    new_word->is_correct = true;
    dict->words[dict->num_words] = *new_word;
    dict->num_words++;
}

bool is_correct_word(Dictionary *dict, char *word) {
    for (int i = 0; i < dict->num_words; i++) {
        if (strcasecmp(dict->words[i].word, word) == 0) {
            return dict->words[i].is_correct;
        }
    }
    return false;
}

void print_dictionary(Dictionary *dict) {
    printf("Dictionary:\n");
    for (int i = 0; i < dict->num_words; i++) {
        printf("%s - %s\n", dict->words[i].word, dict->words[i].is_correct? "Correct" : "Incorrect");
    }
}

int main() {
    Dictionary *dict = create_dictionary();
    char word[MAX_WORD_LENGTH];
    while (true) {
        printf("Enter a word to add to the dictionary: ");
        scanf("%s", word);
        add_word(dict, word);
        printf("Enter a word to check: ");
        scanf("%s", word);
        if (is_correct_word(dict, word)) {
            printf("%s is correct.\n", word);
        } else {
            printf("%s is incorrect.\n", word);
        }
    }
    return 0;
}