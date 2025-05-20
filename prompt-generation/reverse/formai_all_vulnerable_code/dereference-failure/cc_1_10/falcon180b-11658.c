//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MIN_WORD_LENGTH 3

typedef struct {
    char *word;
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int isSpam(const char *message) {
    int spamCount = 0;
    char *words[MAX_WORDS];
    int wordCount = 0;

    // tokenize message into words
    char *token = strtok(message, " ");
    while (token!= NULL) {
        if (strlen(token) >= MIN_WORD_LENGTH) {
            words[wordCount++] = strdup(token);
        }
        token = strtok(NULL, " ");
    }

    // count frequency of each word
    WordFrequency *frequencies = malloc(wordCount * sizeof(WordFrequency));
    for (int i = 0; i < wordCount; i++) {
        frequencies[i].word = words[i];
        frequencies[i].frequency = 1;
    }
    qsort(frequencies, wordCount, sizeof(WordFrequency), compareWords);

    // check for spam words
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(frequencies[i].word, "viagra") == 0 ||
            strcmp(frequencies[i].word, "cialis") == 0 ||
            strcmp(frequencies[i].word, "levitra") == 0) {
            spamCount++;
        }
    }

    // free memory
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    free(frequencies);

    return spamCount > 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    char *message = argv[1];
    if (isSpam(message)) {
        printf("Spam detected!\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}