//Falcon-180B DATASET v1.0 Category: Educational ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wordA = (const WordCount*)a;
    const WordCount* wordB = (const WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

void readFile(FILE* file, WordCount* words, int* numWords) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        if (*numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }

        int found = 0;
        for (i = 0; i < *numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[*numWords].word, word);
            words[*numWords].count = 1;
            (*numWords)++;
        }
    }
}

void writeFile(FILE* file, WordCount* words, int numWords) {
    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        fprintf(file, "%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        return 1;
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    readFile(inputFile, words, &numWords);

    writeFile(outputFile, words, numWords);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}