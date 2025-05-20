//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int size;
    int capacity;
} Dictionary;

Dictionary *createDictionary() {
    Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
    dict->words = (WordFrequency *)malloc(MAX_DICTIONARY_SIZE * sizeof(WordFrequency));
    dict->size = 0;
    dict->capacity = MAX_DICTIONARY_SIZE;
    return dict;
}

void destroyDictionary(Dictionary *dict) {
    free(dict->words);
    free(dict);
}

void addWord(Dictionary *dict, char *word) {
    if (dict->size >= dict->capacity) {
        printf("Dictionary is full. Cannot add more words.\n");
        return;
    }

    WordFrequency *wf = &dict->words[dict->size];
    strcpy(wf->word, word);
    wf->frequency = 1;

    dict->size++;
}

int getWordFrequency(Dictionary *dict, char *word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return dict->words[i].frequency;
        }
    }

    return 0;
}

void printDictionary(Dictionary *dict) {
    for (int i = 0; i < dict->size; i++) {
        printf("%s: %d\n", dict->words[i].word, dict->words[i].frequency);
    }
}

int isWord(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }

    Dictionary *dict = createDictionary();

    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (isWord(word)) {
            addWord(dict, word);
        }
    }

    fclose(inputFile);

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token = strtok(line, ",.!?;:");
        while (token!= NULL) {
            if (isWord(token)) {
                int frequency = getWordFrequency(dict, token);
                if (frequency > 0) {
                    printf("%s (%d)\n", token, frequency);
                }
            }

            token = strtok(NULL, ",.!?;:");
        }
    }

    fclose(inputFile);

    destroyDictionary(dict);

    return 0;
}