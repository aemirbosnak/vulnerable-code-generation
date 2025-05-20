//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    const Word *wordA = (const Word *)a;
    const Word *wordB = (const Word *)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFilename[50], outputFilename[50];
    char line[1000];
    char word[MAX_WORD_LENGTH];
    int wordIndex = 0;
    Word words[MAX_WORDS];

    printf("Enter input filename: ");
    scanf("%s", inputFilename);

    printf("Enter output filename: ");
    scanf("%s", outputFilename);

    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        int i = 0;
        while (i < strlen(line)) {
            if (isalpha(line[i])) {
                int j = 0;
                while (i < strlen(line) && isalpha(line[i])) {
                    word[j++] = tolower(line[i++]);
                }
                word[j] = '\0';

                for (int k = 0; k < wordIndex; k++) {
                    if (strcmp(words[k].word, word) == 0) {
                        words[k].count++;
                        break;
                    }
                }

                if (wordIndex < MAX_WORDS) {
                    strcpy(words[wordIndex].word, word);
                    words[wordIndex].count = 1;
                    wordIndex++;
                }
            } else {
                i++;
            }
        }
    }

    qsort(words, wordIndex, sizeof(Word), compareWords);

    fprintf(outputFile, "Word count:\n");
    for (int i = 0; i < wordIndex; i++) {
        fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}