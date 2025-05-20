//Falcon-180B DATASET v1.0 Category: Text processing ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void countWords(char* str, int start, int end, WordCount words[], int numWords) {
    if (start >= end) {
        return;
    }

    char* wordStart = str + start;
    while (start < end && isspace(wordStart[start])) {
        start++;
    }

    char* wordEnd = str + end - 1;
    while (end > start && isspace(wordEnd[end - 1])) {
        end--;
    }

    int wordLen = end - start;
    if (wordLen > MAX_WORD_LEN - 1) {
        wordLen = MAX_WORD_LEN - 1;
    }

    strncpy(words[numWords].word, wordStart, wordLen);
    words[numWords].word[wordLen] = '\0';
    words[numWords].count++;

    countWords(str, start + wordLen, end, words, numWords);
}

int main() {
    FILE* fp;
    char line[4096];
    WordCount words[MAX_WORDS];
    int numWords = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        countWords(line, 0, strlen(line) - 1, words, numWords);
    }

    fclose(fp);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}