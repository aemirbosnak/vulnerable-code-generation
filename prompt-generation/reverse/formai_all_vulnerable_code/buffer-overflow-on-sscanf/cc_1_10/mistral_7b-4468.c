//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRANSLATIONS 100

typedef struct TranslationTable {
    char human[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

void printTranslations(Translation translations[]) {
    int i;
    for (i = 0; i < MAX_TRANSLATIONS; i++) {
        printf("%s --> %s\n", translations[i].human, translations[i].alien);
    }
}

int main() {
    Translation translationTable[MAX_TRANSLATIONS];
    int numTranslations = 0;
    char input[MAX_WORD_LENGTH];

    printf("Configure the translation table:\n");

    while (numTranslations < MAX_TRANSLATIONS && fgets(input, sizeof(input), stdin) != NULL) {
        sscanf(input, "%s %s", translationTable[numTranslations].human, translationTable[numTranslations].alien);
        numTranslations++;
    }

    printTranslations(translationTable);

    printf("\nTranslate human language to alien:\n");
    while (1) {
        printf("Enter a word or type 'quit' to exit: ");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "quit\n") == 0) {
            break;
        }

        int i;
        for (i = 0; i < numTranslations; i++) {
            if (strcmp(translationTable[i].human, input) == 0) {
                printf("Alien translation: %s\n", translationTable[i].alien);
                break;
            }
        }

        if (i == numTranslations) {
            printf("Unknown human word.\n");
        }
    }

    return 0;
}