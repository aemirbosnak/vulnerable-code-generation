//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 30
#define THRESHOLD 5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *) a;
    WordFrequency *wordB = (WordFrequency *) b;

    return wordB->frequency - wordA->frequency;
}

int isSpam(char *email) {
    FILE *fp = fopen("spam_words.txt", "r");
    char word[MAX_WORD_LENGTH];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    if (fp == NULL) {
        printf("Error: could not open spam_words.txt\n");
        return 0;
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many spam words\n");
            return 0;
        }

        words[numWords].word[0] = tolower(word[0]);
        strcpy(&words[numWords].word[1], &word[1]);
        words[numWords].frequency = 1;
        numWords++;
    }

    fclose(fp);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    int totalFrequency = 0;

    for (int i = 0; i < numWords; i++) {
        totalFrequency += words[i].frequency;

        if (strstr(email, words[i].word)!= NULL) {
            return 1;
        }
    }

    return totalFrequency >= THRESHOLD;
}

int main() {
    char email[1000];

    printf("Enter an email: ");
    scanf("%s", email);

    if (isSpam(email)) {
        printf("Spam\n");
    } else {
        printf("Not spam\n");
    }

    return 0;
}