//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordFrequency;

void readWords(FILE *fp, WordFrequency *wordFreq, int numWords) {
    char word[MAX_WORD_LEN];
    while (numWords > 0 && fscanf(fp, "%s", word)!= EOF) {
        int len = strlen(word);
        if (len > 0 && isalpha(word[0])) {
            word[len - 1] = '\0'; // remove newline character
            for (int i = 0; i < len; i++) {
                word[i] = tolower(word[i]);
            }
            int idx = 0;
            while (idx < numWords && strcmp(wordFreq[idx].word, word) < 0) {
                idx++;
            }
            if (idx < numWords) {
                wordFreq[idx].count++;
            } else {
                idx = numWords;
                while (idx > 0 && strcmp(wordFreq[idx - 1].word, word) > 0) {
                    idx--;
                }
                for (int i = numWords - 1; i > idx; i--) {
                    strcpy(wordFreq[i].word, wordFreq[i - 1].word);
                    wordFreq[i].count = wordFreq[i - 1].count;
                }
                strcpy(wordFreq[idx].word, word);
                wordFreq[idx].count = 1;
                numWords++;
            }
        }
    }
}

void printWordFrequencies(WordFrequency *wordFreq, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s %d\n", wordFreq[i].word, wordFreq[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    WordFrequency wordFreq[MAX_WORDS];
    int numWords = 0;
    readWords(fp, wordFreq, numWords);
    fclose(fp);
    printf("Word frequencies:\n");
    printWordFrequencies(wordFreq, numWords);
    return 0;
}