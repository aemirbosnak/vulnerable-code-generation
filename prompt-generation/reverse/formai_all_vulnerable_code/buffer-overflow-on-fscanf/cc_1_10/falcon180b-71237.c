//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    const WordFrequency *wordA = a;
    const WordFrequency *wordB = b;
    return strcasecmp(wordA->word, wordB->word);
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    char *word;
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        word = strtok(inputBuffer, ",.?!;:\"'");
        while (word!= NULL) {
            numWords++;
            if (numWords > MAX_WORDS) {
                printf("Exceeded maximum number of words\n");
                fclose(inputFile);
                return 1;
            }
            for (int i = 0; i < numWords - 1; i++) {
                if (strcmp(wordFrequencies[i].word, word) == 0) {
                    wordFrequencies[i].frequency++;
                    break;
                }
            }
            if (numWords == MAX_WORDS) {
                break;
            }
            WordFrequency newWordFrequency;
            strcpy(newWordFrequency.word, word);
            newWordFrequency.frequency = 1;
            wordFrequencies[numWords] = newWordFrequency;
            word = strtok(NULL, ",.?!;:\"'");
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    return 0;
}