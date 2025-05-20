//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

typedef struct {
    WordFrequency *words;
    int size;
} Dictionary;

Dictionary *createDictionary() {
    Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
    dict->words = (WordFrequency *)malloc(MAX_DICTIONARY_SIZE * sizeof(WordFrequency));
    dict->size = 0;
    return dict;
}

void addWord(Dictionary *dict, char *word) {
    WordFrequency *wf = &dict->words[dict->size];
    strcpy(wf->word, word);
    wf->count = 1;
    dict->size++;
}

int isWordInDictionary(Dictionary *dict, char *word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->words[i].word, word) == 0) {
            return 1;
        }
    }
    return 0;
}

void printDictionary(Dictionary *dict) {
    for (int i = 0; i < dict->size; i++) {
        printf("%s %d\n", dict->words[i].word, dict->words[i].count);
    }
}

void freeDictionary(Dictionary *dict) {
    free(dict->words);
    free(dict);
}

int main() {
    FILE *fp;
    char word[MAX_WORD_LEN];
    char filename[MAX_WORD_LEN];
    char line[MAX_WORD_LEN];
    int count = 0;
    int totalWords = 0;
    int misspelledWords = 0;
    Dictionary *dict = createDictionary();

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        totalWords++;
        if (isWordInDictionary(dict, word)) {
            count++;
        } else {
            misspelledWords++;
            addWord(dict, word);
        }
    }

    fclose(fp);

    printf("Total words: %d\n", totalWords);
    printf("Correctly spelled words: %d\n", count);
    printf("Misspelled words: %d\n", misspelledWords);
    printf("Dictionary:\n");
    printDictionary(dict);

    freeDictionary(dict);

    return 0;
}