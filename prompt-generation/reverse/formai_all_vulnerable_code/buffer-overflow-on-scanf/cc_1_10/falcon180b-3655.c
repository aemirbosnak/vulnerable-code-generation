//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;
    return strcmp(wordA->word, wordB->word);
}

void readFile(FILE *file, Word *words) {
    char word[MAX_WORD_LEN];
    char ch;
    int wordLen = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[wordLen++] = tolower(ch);
        } else {
            if (wordLen > 0) {
                word[wordLen] = '\0';
                Word *found = bsearch(&word, words, MAX_WORDS, sizeof(Word), compareWords);
                if (found == NULL) {
                    if (wordLen < MAX_WORD_LEN) {
                        strcpy(found->word, word);
                        found->count = 1;
                    } else {
                        printf("Word '%s' is too long and will be ignored.\n", word);
                    }
                } else {
                    found->count++;
                }
            }
            wordLen = 0;
        }
    }
    if (wordLen > 0) {
        word[wordLen] = '\0';
        Word *found = bsearch(&word, words, MAX_WORDS, sizeof(Word), compareWords);
        if (found == NULL) {
            if (wordLen < MAX_WORD_LEN) {
                strcpy(found->word, word);
                found->count = 1;
            } else {
                printf("Word '%s' is too long and will be ignored.\n", word);
            }
        } else {
            found->count++;
        }
    }
}

void printWords(Word *words, int numWords) {
    qsort(words, numWords, sizeof(Word), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *file;
    Word words[MAX_WORDS];
    int numWords = 0;
    char fileName[MAX_WORD_LEN];
    printf("Enter file name: ");
    scanf("%s", fileName);
    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }
    readFile(file, words);
    fclose(file);
    printWords(words, numWords);
    return 0;
}