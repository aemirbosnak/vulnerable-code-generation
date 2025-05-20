//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    char input[MAX_WORD_LENGTH];
    char output[MAX_WORD_LENGTH];
    int wordCount = 0;
    WordTranslation translations[MAX_WORDS];
    int translationCount = 0;

    printf("Enter a list of words, separated by spaces:\n");
    scanf("%s", input);

    char* token = strtok(input, " ");
    while (token!= NULL) {
        if (wordCount >= MAX_WORDS) {
            printf("Error: too many words\n");
            exit(1);
        }

        strcpy(translations[wordCount].word, token);
        printf("Enter the translation for %s:\n", token);
        scanf("%s", translations[wordCount].translation);

        wordCount++;
        translationCount++;
        token = strtok(NULL, " ");
    }

    printf("Enter a phrase to translate:\n");
    scanf("%s", input);

    token = strtok(input, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < wordCount; i++) {
            if (strcmp(token, translations[i].word) == 0) {
                strcpy(output, translations[i].translation);
                break;
            }
        }

        if (i == wordCount) {
            strcpy(output, token);
        }

        printf("%s ", output);
        token = strtok(NULL, " ");
    }

    printf("\n");

    return 0;
}