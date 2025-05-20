//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} WordPair;

int loadWords(WordPair *wordPairs, int numPairs) {
    FILE *fp = fopen("words.txt", "r");
    if (!fp) {
        printf("Error: could not open words.txt\n");
        return 0;
    }

    int i = 0;
    while (fscanf(fp, "%s %s", wordPairs[i].word, wordPairs[i].translation) == 2 && i < numPairs) {
        i++;
    }

    fclose(fp);
    return i;
}

int translate(char *text, WordPair *wordPairs, int numPairs) {
    char *token;
    char *saveptr;
    int numTranslations = 0;

    token = strtok_r(text, " ", &saveptr);
    while (token!= NULL) {
        int i;
        for (i = 0; i < numPairs; i++) {
            if (strcmp(token, wordPairs[i].word) == 0) {
                printf("%s -> %s\n", token, wordPairs[i].translation);
                numTranslations++;
                break;
            }
        }
        if (i == numPairs) {
            printf("%s (no translation)\n", token);
        }
        token = strtok_r(NULL, " ", &saveptr);
    }

    return numTranslations;
}

int main() {
    WordPair wordPairs[MAX_WORDS];
    int numPairs = loadWords(wordPairs, MAX_WORDS);

    char text[MAX_WORD_LEN * 100];
    printf("Enter text to translate:\n");
    fgets(text, sizeof(text), stdin);

    int numTranslations = translate(text, wordPairs, numPairs);
    if (numTranslations == 0) {
        printf("No translations found.\n");
    }

    return 0;
}