//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordA = (const WordCount*)a;
    const WordCount* wordB = (const WordCount*)b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    char* token;
    while (fscanf(file, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        int length = strlen(word);
        if (length > MAX_WORD_LENGTH) {
            printf("Word too long: %s\n", word);
            continue;
        }

        for (int i = 0; i < length; i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
                length = i;
                break;
            }
        }

        strcpy(words[numWords].word, word);
        words[numWords].count = 1;
        numWords++;
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}