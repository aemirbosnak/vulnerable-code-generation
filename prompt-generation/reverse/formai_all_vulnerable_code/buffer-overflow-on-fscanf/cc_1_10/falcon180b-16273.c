//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50
#define MIN_WORD_LEN 3
#define THRESHOLD 5

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

void loadWords(char *filename, Word *words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading words\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(fp, "%s", words[numWords].word)!= EOF) {
        numWords++;
    }
    fclose(fp);
}

int isSpam(char *message, Word *words) {
    int numWords = 0;
    int totalWords = 0;

    char *token = strtok(message, " ");
    while (token!= NULL) {
        totalWords++;

        int i;
        for (i = 0; i < numWords; i++) {
            if (strcasecmp(token, words[i].word) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Too many words\n");
                exit(1);
            }

            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
        }

        token = strtok(NULL, " ");
    }

    int spamCount = 0;
    for (int i = 0; i < numWords; i++) {
        if (words[i].count >= THRESHOLD) {
            spamCount++;
        }
    }

    return (double)spamCount / totalWords >= 0.1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s message\n", argv[0]);
        exit(1);
    }

    char message[1000];
    strcpy(message, argv[1]);

    Word words[MAX_WORDS];
    loadWords("words.txt", words);

    if (isSpam(message, words)) {
        printf("Spam\n");
    } else {
        printf("Not spam\n");
    }

    return 0;
}