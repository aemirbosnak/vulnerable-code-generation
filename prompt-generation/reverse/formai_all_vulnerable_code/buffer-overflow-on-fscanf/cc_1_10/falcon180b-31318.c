//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;
    return strcmp(wordA->word, wordB->word);
}

void printWordFrequency(const WordFrequency* wordFrequency, int n) {
    qsort(wordFrequency, n, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].count);
    }
}

int main() {
    FILE* dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    WordFrequency dictionary[MAX_DICTIONARY_SIZE];
    int dictionarySize = 0;

    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(dictionaryFile, "%s", word)!= EOF) {
        if (dictionarySize >= MAX_DICTIONARY_SIZE) {
            printf("Error: Dictionary is full.\n");
            fclose(dictionaryFile);
            return 1;
        }
        strcpy(dictionary[dictionarySize].word, word);
        dictionary[dictionarySize].count = 0;
        dictionarySize++;
    }

    fclose(dictionaryFile);

    char inputText[100000];
    printf("Enter text to spell check: ");
    fgets(inputText, sizeof(inputText), stdin);

    char* token = strtok(inputText, ",.?!;:");
    while (token!= NULL) {
        int wordIndex = -1;
        for (int i = 0; i < dictionarySize; i++) {
            if (strcmp(dictionary[i].word, token) == 0) {
                wordIndex = i;
                break;
            }
        }

        if (wordIndex == -1) {
            printf("Unknown word: %s\n", token);
        } else {
            dictionary[wordIndex].count++;
        }

        token = strtok(NULL, ",.?!;:");
    }

    printWordFrequency(dictionary, dictionarySize);

    return 0;
}