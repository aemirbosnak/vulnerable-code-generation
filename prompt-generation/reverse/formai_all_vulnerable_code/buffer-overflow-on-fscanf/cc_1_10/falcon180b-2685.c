//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: intelligent
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
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

void printWords(WordFrequency* words, int count) {
    qsort(words, count, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
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
        return 2;
    }

    char word[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordFrequency words[MAX_WORDS];

    while (fscanf(file, "%s", word)!= EOF) {
        if (wordCount >= MAX_WORDS) {
            printf("Maximum word count reached.\n");
            break;
        }

        int index = 0;
        while (index < wordCount && strcmp(words[index].word, word)!= 0) {
            index++;
        }

        if (index == wordCount) {
            strcpy(words[wordCount].word, word);
            words[wordCount].count = 1;
            wordCount++;
        } else {
            words[index].count++;
        }
    }

    fclose(file);

    printWords(words, wordCount);

    return 0;
}