//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(((const Word *)a)->word, ((const Word *)b)->word);
}

int main() {
    FILE *dictionaryFile = fopen("dictionary.txt", "r");
    if (dictionaryFile == NULL) {
        perror("Error opening dictionary file");
        return EXIT_FAILURE;
    }

    Word dictionary[MAX_WORDS];
    int numWords = 0;
    while (fscanf(dictionaryFile, "%s", dictionary[numWords].word) != EOF) {
        numWords++;
    }
    fclose(dictionaryFile);

    qsort(dictionary, numWords, sizeof(Word), compareWords);

    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    char input[256];
    while (fgets(input, sizeof(input), inputFile) != NULL) {
        char *word = strtok(input, " ");
        while (word != NULL) {
            int low = 0;
            int high = numWords - 1;
            int mid;
            int found = 0;
            while (low <= high && !found) {
                mid = (low + high) / 2;
                int comparison = strcmp(word, dictionary[mid].word);
                if (comparison == 0) {
                    found = 1;
                } else if (comparison < 0) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (!found) {
                printf("%s is not in the dictionary\n", word);
            }

            word = strtok(NULL, " ");
        }
    }
    fclose(inputFile);

    return EXIT_SUCCESS;
}