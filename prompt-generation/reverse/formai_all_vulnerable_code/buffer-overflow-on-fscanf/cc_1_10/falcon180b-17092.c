//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define SPAM_THRESHOLD 0.5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void loadWords(char *filename, WordCount *words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading words file\n");
        exit(1);
    }

    int numWords = 0;
    while (fscanf(fp, "%s", words[numWords].word)!= EOF) {
        numWords++;
    }

    fclose(fp);
}

int isSpam(char *message, WordCount *words) {
    int numWords = 0;
    int spamWords = 0;

    char *token = strtok(message, " \t\r\n\f\v,.?!;:");
    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, words[i].word) == 0) {
                words[i].count++;
                spamWords++;
            }
        }

        if (numWords >= MAX_WORDS - 1) {
            break;
        }

        strcpy(words[numWords].word, token);
        words[numWords].count = 1;
        numWords++;

        token = strtok(NULL, " \t\r\n\f\v,.?!;:");
    }

    double spamPercentage = (double)spamWords / numWords * 100;
    return spamPercentage >= SPAM_THRESHOLD;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <words_file> <message_file>\n", argv[0]);
        exit(1);
    }

    WordCount words[MAX_WORDS];
    loadWords(argv[1], words);

    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Error loading message file\n");
        exit(1);
    }

    char message[MAX_WORD_LENGTH * 100];
    fgets(message, sizeof(message), fp);

    int isSpamMessage = isSpam(message, words);

    if (isSpamMessage) {
        printf("Spam detected\n");
    } else {
        printf("No spam detected\n");
    }

    fclose(fp);
    return 0;
}