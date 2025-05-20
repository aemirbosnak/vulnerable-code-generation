//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *alien;
} WordPair;

int main() {
    FILE *fp;
    char line[100];
    int numWords = 0;
    WordPair *wordPairs = NULL;

    fp = fopen("words.txt", "r");

    if (fp == NULL) {
        printf("Error: Could not open words.txt\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *englishWord = strtok(line, ",");
        char *alienWord = strtok(NULL, ",");

        if (englishWord == NULL || alienWord == NULL) {
            printf("Error: Invalid line in words.txt\n");
            exit(1);
        }

        if (numWords == MAX_WORDS) {
            printf("Error: Too many words in words.txt\n");
            exit(1);
        }

        wordPairs[numWords].english = strdup(englishWord);
        wordPairs[numWords].alien = strdup(alienWord);
        numWords++;
    }

    fclose(fp);

    char input[100];
    while (1) {
        printf("Enter a sentence to translate: ");
        fgets(input, sizeof(input), stdin);

        char *sentence = strdup(input);
        char *token = strtok(sentence, " ");

        while (token!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(token, wordPairs[i].english) == 0) {
                    printf("%s ", wordPairs[i].alien);
                    break;
                }
            }

            if (i == numWords) {
                printf("%s ", token);
            }

            token = strtok(NULL, " ");
        }

        printf("\n");
    }

    return 0;
}