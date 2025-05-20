//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int length;
} Word;

typedef struct {
    Word *words;
    int size;
} Dictionary;

void initDictionary(Dictionary *dict) {
    dict->size = 0;
    dict->words = (Word *)malloc(MAX_DICTIONARY_SIZE * sizeof(Word));
}

void addWord(Dictionary *dict, char *word) {
    if (dict->size >= MAX_DICTIONARY_SIZE) {
        printf("Dictionary is full!\n");
        return;
    }

    Word newWord;
    strcpy(newWord.word, word);
    newWord.length = strlen(word);

    dict->words[dict->size++] = newWord;
}

int isWordInDictionary(Dictionary *dict, char *word) {
    int i;

    for (i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return 1;
        }
    }

    return 0;
}

void spellCheck(char *text, Dictionary *dict) {
    int i, j;
    char word[MAX_WORD_LENGTH];

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            word[0] = tolower(text[i]);
            j = 1;

            while (isalpha(text[i + j])) {
                strncat(word, &text[i + j], 1);
                j++;
            }

            if (!isWordInDictionary(dict, word)) {
                printf("'%s' is not in the dictionary.\n", word);
            }
        }
    }
}

int main() {
    Dictionary dict;
    initDictionary(&dict);

    addWord(&dict, "apple");
    addWord(&dict, "banana");
    addWord(&dict, "cherry");

    char text[] = "I love eating apples and bananas. Cherries are good too.";

    spellCheck(text, &dict);

    return 0;
}