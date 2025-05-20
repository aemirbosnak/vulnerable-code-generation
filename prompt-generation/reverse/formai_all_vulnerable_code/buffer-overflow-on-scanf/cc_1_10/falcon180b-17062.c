//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int main() {
    int numWords;
    WordTranslation translations[1000];
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
    FILE *inputFile;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open input file
    inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read in translations
    numWords = 0;
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        if (strlen(line) > 0) {
            sscanf(line, "%s %s", word, translation);
            strcpy(translations[numWords].word, word);
            strcpy(translations[numWords].translation, translation);
            numWords++;
        }
    }
    fclose(inputFile);

    // Prompt user for word to translate
    printf("Enter word to translate: ");
    scanf("%s", word);

    // Translate word
    for (int i = 0; i < numWords; i++) {
        if (strcmp(word, translations[i].word) == 0) {
            printf("%s = %s\n", word, translations[i].translation);
            break;
        }
    }

    return 0;
}