//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char symbol;
    char alienSymbol;
} Translation;

void readTranslationsFromFile(char *filename, Translation *translations, int *numTranslations) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    int numTrans = 0;

    while (fgets(line, sizeof(line), file)) {
        Translation translation;
        sscanf(line, "%c %c", &translation.symbol, &translation.alienSymbol);
        translations[numTrans] = translation;
        numTrans++;
    }

    fclose(file);
    *numTranslations = numTrans;
}

int main() {
    int numTranslations = 0;
    Translation *translations;

    readTranslationsFromFile("translations.txt", translations, &numTranslations);

    char input[1024];
    printf("Enter a string to translate: ");
    fgets(input, sizeof(input), stdin);

    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < numTranslations; j++) {
            if (input[i] == translations[j].symbol) {
                printf("%c", translations[j].alienSymbol);
                break;
            }
        }
        printf("%c", input[i]);
    }

    free(translations);

    return 0;
}