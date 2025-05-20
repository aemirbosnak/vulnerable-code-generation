//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int isSpam(char *message) {
    char *words[MAX_WORDS];
    int numWords = 0;
    char word[100];
    FILE *spamWordsFile = fopen("spamWords.txt", "r");

    if (spamWordsFile == NULL) {
        printf("Error: could not open spamWords.txt\n");
        exit(1);
    }

    while (fscanf(spamWordsFile, "%s", word)!= EOF) {
        words[numWords] = strdup(word);
        numWords++;
    }

    fclose(spamWordsFile);

    qsort(words, numWords, sizeof(char *), compareWords);

    int spamCount = 0;

    for (int i = 0; i < numWords; i++) {
        char *word = words[i];
        int wordCount = 0;

        char *token = strtok(message, " ");
        while (token!= NULL) {
            if (strcmp(token, word) == 0) {
                wordCount++;
            }
            token = strtok(NULL, " ");
        }

        if (wordCount > 0) {
            spamCount++;
        }
    }

    if (spamCount >= 5) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char message[1000];
    printf("Enter message: ");
    scanf("%s", message);

    if (isSpam(message)) {
        printf("Message is spam\n");
    } else {
        printf("Message is not spam\n");
    }

    return 0;
}