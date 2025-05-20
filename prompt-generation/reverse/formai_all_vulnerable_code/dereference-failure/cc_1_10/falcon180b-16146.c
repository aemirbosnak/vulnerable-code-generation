//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char* word;
    int count;
} WordFrequency;

void initializeFrequencyTable(WordFrequency* frequencyTable, int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        frequencyTable[i].word = NULL;
        frequencyTable[i].count = 0;
    }
}

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

int getWordFrequency(char* text, int textLength, WordFrequency* frequencyTable, int tableSize) {
    int wordStartIndex = 0;
    int wordLength = 0;
    char word[MAX_WORD_LENGTH];

    while (textLength > 0) {
        if (isalnum(text[0])) {
            word[wordLength++] = tolower(text[0]);
            text++;
            textLength--;
        } else {
            word[wordLength] = '\0';
            int wordIndex = 0;

            if (wordLength > 0) {
                qsort(frequencyTable, tableSize, sizeof(WordFrequency), compareWords);

                for (int i = 0; i < tableSize; i++) {
                    if (strcmp(frequencyTable[i].word, word) == 0) {
                        wordIndex = i;
                        break;
                    }
                }

                if (wordIndex == tableSize) {
                    if (wordLength <= MAX_WORD_LENGTH - 1) {
                        strcpy(frequencyTable[tableSize - 1].word, word);
                        frequencyTable[tableSize - 1].count = 1;
                    }
                } else {
                    frequencyTable[wordIndex].count++;
                }
            }

            wordStartIndex = text - word;
            wordLength = 0;
        }
    }

    return 0;
}

void printFrequencyTable(WordFrequency* frequencyTable, int tableSize) {
    for (int i = 0; i < tableSize; i++) {
        if (frequencyTable[i].word!= NULL) {
            printf("%s: %d\n", frequencyTable[i].word, frequencyTable[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int fileLength = ftell(file);
    rewind(file);

    char* text = malloc(fileLength + 1);

    if (text == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 1;
    }

    fread(text, fileLength, 1, file);
    text[fileLength] = '\0';

    int tableSize = 1000;
    WordFrequency* frequencyTable = malloc(tableSize * sizeof(WordFrequency));

    if (frequencyTable == NULL) {
        printf("Error allocating memory.\n");
        free(text);
        fclose(file);
        return 1;
    }

    initializeFrequencyTable(frequencyTable, tableSize);
    getWordFrequency(text, fileLength, frequencyTable, tableSize);
    printFrequencyTable(frequencyTable, tableSize);

    free(text);
    free(frequencyTable);
    fclose(file);

    return 0;
}