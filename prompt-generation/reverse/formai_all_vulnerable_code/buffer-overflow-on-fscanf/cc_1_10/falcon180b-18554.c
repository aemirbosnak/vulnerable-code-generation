//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DICTIONARY_SIZE 10000
#define WORD_LENGTH 100

typedef struct {
    char word[WORD_LENGTH];
    int length;
} Word;

typedef struct {
    Word *words;
    int size;
} Dictionary;

Dictionary *createDictionary() {
    Dictionary *dict = (Dictionary *) malloc(sizeof(Dictionary));
    dict->words = (Word *) malloc(DICTIONARY_SIZE * sizeof(Word));
    dict->size = 0;
    return dict;
}

void addWord(Dictionary *dict, char *word) {
    Word *newWord = (Word *) malloc(sizeof(Word));
    strcpy(newWord->word, word);
    newWord->length = strlen(word);
    dict->words[dict->size++] = *newWord;
    free(newWord);
}

void loadDictionary(Dictionary *dict, char *filename) {
    FILE *file = fopen(filename, "r");
    char word[WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        addWord(dict, word);
    }
    fclose(file);
}

void freeDictionary(Dictionary *dict) {
    for (int i = 0; i < dict->size; i++) {
        free(dict->words[i].word);
    }
    free(dict->words);
    free(dict);
}

int isWord(Dictionary *dict, char *word) {
    Word *foundWord = NULL;
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            foundWord = &dict->words[i];
            break;
        }
    }
    if (foundWord!= NULL) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Dictionary *dict = createDictionary();
    loadDictionary(dict, "dictionary.txt");
    char sentence[1000];
    while (fgets(sentence, sizeof(sentence), stdin)!= NULL) {
        char *word = strtok(sentence, " ");
        while (word!= NULL) {
            if (!isWord(dict, word)) {
                printf("Possible spelling mistake: %s\n", word);
            }
            word = strtok(NULL, " ");
        }
    }
    freeDictionary(dict);
    return 0;
}