//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    char translation[MAX_WORD_LENGTH];
} WordPair;

int main() {
    FILE *dictionaryFile;
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    WordPair *wordPairs = (WordPair*) malloc(MAX_WORDS * sizeof(WordPair));

    dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    while (fscanf(dictionaryFile, "%s", line)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Dictionary is too large.\n");
            exit(1);
        }
        strcpy(wordPairs[numWords].word, line);
        fgets(line, MAX_WORD_LENGTH, dictionaryFile);
        strcpy(wordPairs[numWords].translation, line);
        numWords++;
    }

    fclose(dictionaryFile);

    char input[MAX_WORD_LENGTH];
    while (fgets(input, MAX_WORD_LENGTH, stdin)!= NULL) {
        int i;
        for (i = 0; i < numWords; i++) {
            if (strcmp(input, wordPairs[i].word) == 0) {
                printf("%s -> %s\n", input, wordPairs[i].translation);
                break;
            }
        }
        if (i == numWords) {
            printf("No translation found.\n");
        }
    }

    return 0;
}