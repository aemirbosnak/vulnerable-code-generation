//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    char input[MAX_WORD_LENGTH];
    char output[MAX_WORD_LENGTH];
    char *word;
    char *translation;
    WordTranslation translations[MAX_WORDS];
    int numTranslations = 0;
    int i;

    printf("Enter cat words separated by spaces:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    // Split input into words
    word = strtok(input, " ");
    while (word!= NULL) {
        // Look up translation in dictionary
        for (i = 0; i < numTranslations; i++) {
            if (strcmp(word, translations[i].word) == 0) {
                strcpy(output, translations[i].translation);
                break;
            }
        }
        if (i == numTranslations) {
            // Word not found in dictionary, ask user for translation
            printf("Enter translation for %s:\n", word);
            fgets(translation, MAX_WORD_LENGTH, stdin);
            strcpy(translations[numTranslations].word, word);
            strcpy(translations[numTranslations].translation, translation);
            numTranslations++;
        }
        word = strtok(NULL, " ");
    }

    // Print translations
    for (i = 0; i < numTranslations; i++) {
        printf("%s -> %s\n", translations[i].word, translations[i].translation);
    }

    return 0;
}