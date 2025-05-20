//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;
    
    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    int i, j;
    FILE *inputFile;
    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    
    while (fscanf(inputFile, "%s", input)!= EOF) {
        for (i = 0; i < strlen(input); i++) {
            if (isalpha(input[i])) {
                strncpy(word, input + i, strlen(input) - i);
                word[strlen(input) - i] = '\0';
                
                for (j = 0; j < numWords; j++) {
                    if (strcmp(word, wordCounts[j].word) == 0) {
                        wordCounts[j].count++;
                        break;
                    }
                }
                
                if (j == numWords) {
                    strcpy(wordCounts[numWords].word, word);
                    wordCounts[numWords].count = 1;
                    numWords++;
                }
            }
        }
    }
    
    fclose(inputFile);
    
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
    
    return 0;
}