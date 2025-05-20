//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS_IN_FILE 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordCountA = (const WordCount*)a;
    const WordCount* wordCountB = (const WordCount*)b;

    return strcmp(wordCountA->word, wordCountB->word);
}

void readWordsFromFile(const char* filename, WordCount* words, int* numWords) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    char buffer[1024];
    int wordCount = 0;

    while (fscanf(file, "%s", buffer)!= EOF) {
        int wordLength = strlen(buffer);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Warning: word '%s' is too long (max length is %d)\n", buffer, MAX_WORD_LENGTH);
            continue;
        }

        strcpy(word, buffer);
        for (int i = 0; i < wordLength; i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }

        int wordIndex = bsearch(&word, words, *numWords, sizeof(WordCount), compareWords);
        if (wordIndex == *numWords) {
            if (*numWords >= MAX_WORDS_IN_FILE) {
                printf("Error: too many unique words in file (max is %d)\n", MAX_WORDS_IN_FILE);
                exit(1);
            }
            strcpy(words[*numWords].word, word);
            words[*numWords].count = 0;
            (*numWords)++;
        }
        words[wordIndex].count++;
        wordCount++;
    }

    fclose(file);
}

void printWordCounts(WordCount* words, int numWords) {
    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        if (words[i].count > 0) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    WordCount words[MAX_WORDS_IN_FILE];
    int numWords = 0;

    readWordsFromFile(argv[1], words, &numWords);
    qsort(words, numWords, sizeof(WordCount), compareWords);

    printWordCounts(words, numWords);

    return 0;
}