//Falcon-180B DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *inputFile;
    char inputText[1000000];
    char word[MAX_WORD_LENGTH];
    int wordLength;
    int totalWords = 0;
    WordFrequency wordFrequencies[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", inputText);

    inputFile = fopen(inputText, "r");

    if (inputFile == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", word)!= EOF) {
        wordLength = strlen(word);

        if (wordLength > 0 && isalpha(word[0])) {
            totalWords++;

            for (int i = 0; i < MAX_WORDS; i++) {
                if (wordFrequencies[i].count == 0) {
                    strcpy(wordFrequencies[i].word, word);
                    wordFrequencies[i].count = 1;
                    break;
                }
            }
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, totalWords, sizeof(WordFrequency), compareWords);

    printf("Word frequencies:\n");

    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    return 0;
}