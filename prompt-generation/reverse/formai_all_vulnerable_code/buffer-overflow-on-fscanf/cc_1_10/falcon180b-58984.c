//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 30
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LEN];
    bool is_valid;
} Word;

typedef struct {
    Word words[MAX_DICTIONARY_SIZE];
    int size;
} Dictionary;

void init_dictionary(Dictionary* dict) {
    dict->size = 0;
}

void load_dictionary(Dictionary* dict, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        Word w = {.word = word,.is_valid = true };
        if (dict->size >= MAX_DICTIONARY_SIZE) {
            printf("Dictionary is full. Cannot add more words.\n");
            break;
        }
        dict->words[dict->size++] = w;
    }

    fclose(file);
}

bool is_word_valid(const char* word, Dictionary* dict) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}

void check_spelling(const char* text, Dictionary* dict) {
    char word[MAX_WORD_LEN];
    int index = 0;
    while (*text) {
        if (isalnum(*text)) {
            word[index++] = tolower(*text);
        } else {
            if (index > 0) {
                word[index] = '\0';
                if (!is_word_valid(word, dict)) {
                    printf("Possible spelling error: %s\n", word);
                }
                index = 0;
            }
        }
        text++;
    }
    if (index > 0) {
        word[index] = '\0';
        if (!is_word_valid(word, dict)) {
            printf("Possible spelling error: %s\n", word);
        }
    }
}

int main() {
    Dictionary dict;
    init_dictionary(&dict);
    load_dictionary(&dict, "dictionary.txt");

    char text[1000];
    printf("Enter text to check spelling:\n");
    fgets(text, sizeof(text), stdin);

    check_spelling(text, &dict);

    return 0;
}