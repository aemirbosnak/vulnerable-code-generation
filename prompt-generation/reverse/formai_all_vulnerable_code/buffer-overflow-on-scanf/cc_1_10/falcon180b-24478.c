//Falcon-180B DATASET v1.0 Category: Data mining ; Style: realistic
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
    WordCount *c1 = (WordCount *)a;
    WordCount *c2 = (WordCount *)b;
    return strcmp(c1->word, c2->word);
}

int main() {
    char inputText[1000000];
    char word[MAX_WORD_LENGTH];
    FILE *inputFile;
    int i, j, k, numWords;
    WordCount wordCounts[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", inputText);

    inputFile = fopen(inputText, "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }

    numWords = 0;
    while (fscanf(inputFile, "%s", word)!= EOF) {
        word[strcspn(word, "\n\r")] = '\0'; // Remove newline character
        for (i = 0; i < strlen(word); i++) {
            if (isalpha(word[i])) {
                word[i] = tolower(word[i]);
            } else {
                word[i] = '\0';
            }
        }
        if (strlen(word) > 0) {
            for (i = 0; i < numWords; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                strcpy(wordCounts[numWords].word, word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
        }
    }

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    fclose(inputFile);
    return 0;
}