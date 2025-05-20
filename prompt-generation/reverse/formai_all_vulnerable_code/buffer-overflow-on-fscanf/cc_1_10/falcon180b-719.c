//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_DICTIONARY_SIZE 1000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

typedef struct {
    char *word;
    int count;
} DictionaryEntry;

void readDictionary(DictionaryEntry dictionary[], int *size) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error reading dictionary file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count].word)!= EOF) {
        count++;
    }

    *size = count;
    fclose(file);
}

void countWords(char *text, DictionaryEntry dictionary[], int size, WordCount *wordCounts) {
    int i, j;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char word[MAX_WORD_LEN];
            j = 0;
            while (isalpha(text[i + j]) && j < MAX_WORD_LEN - 1) {
                word[j] = tolower(text[i + j]);
                j++;
            }
            word[j] = '\0';

            for (int k = 0; k < size; k++) {
                if (strcmp(word, dictionary[k].word) == 0) {
                    wordCounts[k].count++;
                    break;
                }
            }
        }
    }
}

void printWordCounts(WordCount wordCounts[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
    int dictionarySize = 0;
    readDictionary(dictionary, &dictionarySize);

    char text[MAX_WORD_LEN];
    fgets(text, MAX_WORD_LEN, stdin);

    WordCount wordCounts[MAX_DICTIONARY_SIZE];
    for (int i = 0; i < dictionarySize; i++) {
        wordCounts[i].count = 0;
    }

    countWords(text, dictionary, dictionarySize, wordCounts);

    printWordCounts(wordCounts, dictionarySize);

    return 0;
}