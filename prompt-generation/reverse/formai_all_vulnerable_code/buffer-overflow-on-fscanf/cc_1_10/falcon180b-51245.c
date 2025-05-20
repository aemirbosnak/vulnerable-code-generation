//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void* a, const void* b) {
    const WordCount* wc1 = a;
    const WordCount* wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

void readWords(FILE* file, WordCount words[], int maxWords) {
    char word[MAX_WORD_LENGTH];
    int count = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= maxWords) {
            printf("Error: maximum number of words reached.\n");
            exit(1);
        }
        strcpy(words[count].word, word);
        words[count].count = 1;
        count++;
    }
}

void countWords(WordCount words[], int numWords) {
    qsort(words, numWords, sizeof(WordCount), compare);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;
    readWords(file, words, MAX_WORDS);
    countWords(words, numWords);

    fclose(file);
    return 0;
}