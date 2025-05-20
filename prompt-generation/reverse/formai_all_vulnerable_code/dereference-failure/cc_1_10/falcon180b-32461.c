//Falcon-180B DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void readFile(FILE* file, WordFrequency* words, int* numWords) {
    char word[MAX_WORD_LENGTH];
    char c;

    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            strcpy(word, "");
            while (isalpha(c)) {
                strcat(word, tolower(c));
                c = fgetc(file);
            }
            if (strlen(word) > 0) {
                for (int i = 0; i < *numWords; i++) {
                    if (strcmp(word, words[i].word) == 0) {
                        words[i].count++;
                        break;
                    }
                }
                if (strcmp(word, words[(*numWords) - 1].word)!= 0) {
                    strcpy(words[*numWords].word, word);
                    words[*numWords].count = 1;
                    (*numWords)++;
                }
            }
        }
    }
}

void sortWords(WordFrequency* words, int numWords) {
    qsort(words, numWords, sizeof(WordFrequency), compareWords);
}

void printWords(WordFrequency* words, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE* file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    readFile(file, words, &numWords);

    fclose(file);

    sortWords(words, numWords);

    printWords(words, numWords);

    return 0;
}