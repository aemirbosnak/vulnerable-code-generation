//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void loadWords(char *filename, Word *words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }
    int numWords = 0;
    while (fscanf(fp, "%s", words[numWords].word)!= EOF) {
        words[numWords].count = 0;
        numWords++;
    }
    fclose(fp);
}

int isSpam(char *text, Word *words) {
    int numWords = 0;
    int spamWords = 0;
    int totalWords = 0;
    char *token = strtok(text, ",.!?;:");
    while (token!= NULL) {
        totalWords++;
        if (strlen(token) <= MAX_WORD_LENGTH) {
            for (int i = 0; i < numWords; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    words[i].count++;
                    spamWords++;
                }
            }
            if (numWords < MAX_WORDS - 1) {
                strcpy(words[numWords].word, token);
                words[numWords].count++;
                numWords++;
            }
        }
        token = strtok(NULL, ",.!?;:");
    }
    if (spamWords > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Word words[MAX_WORDS];
    loadWords("spam_words.txt", words);
    char text[100000];
    printf("Enter text to check for spam: ");
    fgets(text, sizeof(text), stdin);
    int isSpamResult = isSpam(text, words);
    if (isSpamResult == 1) {
        printf("The text contains spam.\n");
    } else {
        printf("The text does not contain spam.\n");
    }
    return 0;
}