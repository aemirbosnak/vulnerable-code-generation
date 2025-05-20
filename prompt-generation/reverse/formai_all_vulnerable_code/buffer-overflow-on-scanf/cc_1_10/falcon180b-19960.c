//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readWords(char* filename, WordCount words[], int numWords) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LEN];
    while (fscanf(fp, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }
        if (i == numWords) {
            strcpy(words[numWords - 1].word, word);
            words[numWords - 1].count = 1;
            numWords++;
        }
    }

    fclose(fp);
}

void printWords(WordCount words[], int numWords) {
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    WordCount words[MAX_WORDS];
    int numWords = 0;

    readWords(filename, words, numWords);

    printf("Enter the word to search: ");
    char searchWord[MAX_WORD_LEN];
    scanf("%s", searchWord);

    int found = 0;
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, searchWord) == 0) {
            printf("Found %s %d times\n", searchWord, words[i].count);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Word not found\n");
    }

    return 0;
}