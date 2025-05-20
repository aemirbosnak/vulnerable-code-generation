//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORDS 1000
#define MIN_WORD_LEN 3
#define MAX_WORD_LEN 15

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *) a;
    WordFrequency *word2 = (WordFrequency *) b;

    if (word1->frequency > word2->frequency) {
        return -1;
    } else if (word1->frequency < word2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int isSpam(const char *message) {
    FILE *fp;
    char word[MAX_WORD_LEN + 1];
    WordFrequency words[MAX_WORDS];
    int numWords = 0;
    int spamWords = 0;
    int i;

    fp = fopen("spam_words.txt", "r");
    if (fp == NULL) {
        printf("Error opening spam_words.txt\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word)!= EOF) {
        for (i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                break;
            }
        }
        if (i == numWords) {
            strcpy(words[numWords].word, word);
            words[numWords].frequency = 1;
            numWords++;
        }
    }

    fclose(fp);

    for (i = 0; i < numWords; i++) {
        if (words[i].frequency >= 3) {
            spamWords++;
        }
    }

    if (spamWords >= 3) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char message[1000];

    printf("Enter a message: ");
    fgets(message, 1000, stdin);

    if (isSpam(message)) {
        printf("Message is spam\n");
    } else {
        printf("Message is not spam\n");
    }

    return 0;
}