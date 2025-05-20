//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void addWord(char* sentence, int start, int end, WordCount* wordCounts, int numWords) {
    int length = end - start + 1;
    if (length > MAX_WORD_LENGTH) {
        length = MAX_WORD_LENGTH;
    }
    strncpy(wordCounts[numWords].word, sentence + start, length);
    wordCounts[numWords].word[length] = '\0';
    wordCounts[numWords].count++;
    numWords++;
}

int compareWords(const void* a, const void* b) {
    const WordCount* wc1 = (const WordCount*)a;
    const WordCount* wc2 = (const WordCount*)b;
    return wc2->count - wc1->count;
}

void printTopWords(WordCount* wordCounts, int numWords, int topN) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    printf("Top %d words:\n", topN);
    for (int i = 0; i < topN && i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char sentence[1000];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    while (fgets(sentence, sizeof(sentence), file)!= NULL) {
        int start = 0;
        int end = 0;
        while (end < strlen(sentence)) {
            if (isalnum(sentence[end])) {
                end++;
            } else {
                addWord(sentence, start, end - 1, wordCounts, numWords);
                start = end;
            }
        }
        addWord(sentence, start, strlen(sentence) - 1, wordCounts, numWords);
        numWords++;
    }

    fclose(file);

    int topN = 10;
    printf("Total words: %d\n", numWords);
    printTopWords(wordCounts, numWords, topN);

    return 0;
}