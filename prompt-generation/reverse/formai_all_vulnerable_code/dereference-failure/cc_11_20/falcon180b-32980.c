//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char *english;
    char *alien;
} WordPair;

int main() {
    FILE *dictFile;
    char line[100];
    int numWords = 0;
    WordPair *wordPairArray = (WordPair *)malloc(MAX_WORDS * sizeof(WordPair));

    dictFile = fopen("dictionary.txt", "r");

    if (dictFile == NULL) {
        printf("Error opening dictionary file.\n");
        return 1;
    }

    while (fgets(line, 100, dictFile)!= NULL) {
        char *englishWord = strtok(line, ",");
        char *alienWord = strtok(NULL, ",");

        if (englishWord == NULL || alienWord == NULL) {
            printf("Invalid line in dictionary file: %s\n", line);
            continue;
        }

        if (numWords >= MAX_WORDS) {
            printf("Dictionary file contains too many words.\n");
            fclose(dictFile);
            return 1;
        }

        wordPairArray[numWords].english = strdup(englishWord);
        wordPairArray[numWords].alien = strdup(alienWord);
        numWords++;
    }

    fclose(dictFile);

    char input[100];
    printf("Enter a sentence to translate:\n");
    fgets(input, 100, stdin);

    char *token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(token, wordPairArray[i].english) == 0) {
                printf("%s ", wordPairArray[i].alien);
                break;
            }
        }

        if (i == numWords) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");

    for (int i = 0; i < numWords; i++) {
        free(wordPairArray[i].english);
        free(wordPairArray[i].alien);
    }

    free(wordPairArray);

    return 0;
}