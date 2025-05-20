//Falcon-180B DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[100];
    char word[MAX_WORD_LENGTH];
    int numWords = 0;
    WordFrequency wordFrequencies[MAX_WORDS];

    inputFile = fopen("input.txt", "r");

    if(inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while(fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token = strtok(line, " ");

        while(token!= NULL) {
            strcpy(word, token);
            numWords++;

            int i;
            for(i = 0; i < numWords; i++) {
                if(strcmp(word, wordFrequencies[i].word) == 0) {
                    wordFrequencies[i].frequency++;
                    break;
                }
            }

            if(i == numWords) {
                if(numWords >= MAX_WORDS) {
                    printf("Maximum number of words reached.\n");
                    exit(1);
                }

                strcpy(wordFrequencies[numWords].word, word);
                wordFrequencies[numWords].frequency = 1;
                numWords++;
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for(int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    return 0;
}