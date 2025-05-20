//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *word1 = (WordFrequency *) a;
    WordFrequency *word2 = (WordFrequency *) b;

    if (word1->frequency > word2->frequency) {
        return -1;
    } else if (word1->frequency < word2->frequency) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *inputFile;
    char inputBuffer[MAX_WORD_LENGTH];
    char *word;
    WordFrequency wordFrequencies[MAX_WORDS];
    int numWords = 0;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", inputBuffer)!= EOF) {
        word = strtok(inputBuffer, ",.?!;:");

        while (word!= NULL) {
            word[strcspn(word, "0123456789")] = '\0'; // Remove any non-letter characters
            if (strlen(word) > 0) {
                for (int i = 0; i < numWords; i++) {
                    if (strcmp(wordFrequencies[i].word, word) == 0) {
                        wordFrequencies[i].frequency++;
                        break;
                    }
                }

                if (numWords >= MAX_WORDS) {
                    printf("Error: Too many unique words in input file.\n");
                    fclose(inputFile);
                    return 1;
                }

                strcpy(wordFrequencies[numWords].word, word);
                wordFrequencies[numWords].frequency = 1;
                numWords++;
            }

            word = strtok(NULL, ",.?!;:");
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    return 0;
}