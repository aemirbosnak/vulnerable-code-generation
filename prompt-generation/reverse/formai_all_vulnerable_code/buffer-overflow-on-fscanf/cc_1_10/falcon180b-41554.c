//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    const Word *wordA = a;
    const Word *wordB = b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[MAX_WORD_LENGTH];
    char *token;
    FILE *inputFile;
    Word words[MAX_WORDS];
    int numWords = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Read input file and count frequency of words
    while (fscanf(inputFile, "%s", input)!= EOF) {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character
        token = strtok(input, ",.?!:;\"'");
        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Error: too many words.\n");
                exit(1);
            }
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
            token = strtok(NULL, ",.?!:;\"'");
        }
    }

    // Sort words by frequency
    qsort(words, numWords, sizeof(Word), compareWords);

    // Print top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Close input file
    fclose(inputFile);

    return 0;
}