//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int isSpam(char* email) {
    int spamCount = 0;
    char* words[MAX_WORDS];
    int numWords = 0;
    FILE* fp = fopen("spam_words.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open spam_words.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%s", words[numWords])!= EOF) {
        numWords++;
    }

    fclose(fp);

    for (int i = 0; i < numWords; i++) {
        int len = strlen(words[i]);
        int j;
        for (j = 0; j <= strlen(email) - len; j++) {
            if (strncasecmp(email + j, words[i], len) == 0) {
                spamCount++;
                break;
            }
        }
    }

    if (spamCount >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char email[MAX_WORD_LEN];
    printf("Enter an email address: ");
    scanf("%s", email);

    if (isSpam(email)) {
        printf("The email address is spam.\n");
    } else {
        printf("The email address is not spam.\n");
    }

    return 0;
}