//Falcon-180B DATASET v1.0 Category: Text processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[MAX_WORD_LEN];
    char word[MAX_WORD_LEN];
    FILE* inputFile;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", input);

    inputFile = fopen(input, "r");

    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords == MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        if (strlen(word) > MAX_WORD_LEN) {
            printf("Word is too long.\n");
            continue;
        }

        for (int i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                printf("Word contains non-letter characters.\n");
                continue;
            }
        }

        strcpy(words[numWords].word, word);
        words[numWords].count = 1;
        numWords++;
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Sorted list of unique words:\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}