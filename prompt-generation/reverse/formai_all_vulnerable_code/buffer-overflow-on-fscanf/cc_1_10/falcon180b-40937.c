//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int isSpam(char *emailContent) {
    char *words[MAX_WORDS];
    int wordCount = 0;
    int spamWordsCount = 0;

    char *token = strtok(emailContent, " ");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            words[wordCount++] = strdup(token);
        }
        token = strtok(NULL, " ");
    }

    qsort(words, wordCount, sizeof(char *), compareWords);

    FILE *spamWordsFile = fopen("spam_words.txt", "r");
    if (spamWordsFile == NULL) {
        printf("Error opening spam_words.txt\n");
        exit(1);
    }

    char spamWord[MAX_WORD_LENGTH];
    while (fscanf(spamWordsFile, "%s", spamWord)!= EOF) {
        int i;
        for (i = 0; i < wordCount; i++) {
            if (strcmp(spamWord, words[i]) == 0) {
                spamWordsCount++;
                break;
            }
        }
    }

    fclose(spamWordsFile);

    if (spamWordsCount >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char emailContent[100000];
    printf("Enter email content: ");
    fgets(emailContent, sizeof(emailContent), stdin);

    int isSpamResult = isSpam(emailContent);

    if (isSpamResult == 1) {
        printf("The email is spam.\n");
    } else {
        printf("The email is not spam.\n");
    }

    return 0;
}