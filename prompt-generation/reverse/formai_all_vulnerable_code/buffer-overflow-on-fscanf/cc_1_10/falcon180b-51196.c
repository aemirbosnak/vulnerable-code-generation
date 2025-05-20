//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void readFile(FILE* file, WordFrequency* words, int maxWords) {
    char word[MAX_WORD_LENGTH];
    int wordCount = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (wordCount >= maxWords) {
            break;
        }

        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }

        int found = 0;
        for (i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[wordCount].word, word);
            words[wordCount].count = 1;
            wordCount++;
        }
    }
}

void sortWords(WordFrequency* words, int count) {
    qsort(words, count, sizeof(WordFrequency), compareWords);
}

void printWords(const WordFrequency* words, int count) {
    for (int i = 0; i < count; i++) {
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
    int wordCount = 0;

    readFile(file, words, MAX_WORDS);
    sortWords(words, wordCount);
    printWords(words, wordCount);

    fclose(file);
    return 0;
}