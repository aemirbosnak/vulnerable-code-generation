//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int isSpam(char *message, int numWords, Word words[MAX_WORDS]) {
    int i, j;
    int spamCount = 0;

    for (i = 0; i < numWords; i++) {
        for (j = 0; j < numWords - i; j++) {
            if (strcmp(words[j].word, words[j + i].word) == 0) {
                spamCount++;
                break;
            }
        }
    }

    return spamCount >= 2;
}

int main() {
    FILE *fp;
    char message[100000];
    char word[MAX_WORD_LENGTH];
    Word words[MAX_WORDS];
    int numWords = 0;

    fp = fopen("spam_words.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        strcpy(words[numWords].word, word);
        words[numWords].count = 0;
        numWords++;
    }

    fclose(fp);

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    int i, j;
    char *token;

    token = strtok(message, " ");

    while (token!= NULL) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == numWords) {
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
        }

        token = strtok(NULL, " ");
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    if (isSpam(message, numWords, words)) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}