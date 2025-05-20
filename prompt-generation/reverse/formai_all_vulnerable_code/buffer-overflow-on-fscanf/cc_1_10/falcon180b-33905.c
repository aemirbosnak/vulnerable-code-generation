//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordTranslation;

int loadWords(WordTranslation* translations, int maxWords) {
    FILE* file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words file.\n");
        return 0;
    }

    int numWords = 0;
    while (numWords < maxWords && fscanf(file, "%s %s", translations[numWords].word, translations[numWords].translation) == 2) {
        numWords++;
    }

    fclose(file);
    return numWords;
}

int main() {
    WordTranslation translations[MAX_WORDS];
    int numTranslations = loadWords(translations, MAX_WORDS);

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        char* word = strtok(input, " ");
        while (word!= NULL) {
            for (int i = 0; i < numTranslations; i++) {
                if (strcmp(word, translations[i].word) == 0) {
                    printf("%s ", translations[i].translation);
                }
            }

            word = strtok(NULL, " ");
        }

        printf("\n");
    }

    return 0;
}