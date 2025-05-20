//Falcon-180B DATASET v1.0 Category: Data mining ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *word1 = (WordCount*)a;
    WordCount *word2 = (WordCount*)b;
    return strcmp(word1->word, word2->word);
}

int main() {
    char input[1000];
    char word[MAX_WORD_LENGTH];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords = 0;
    WordCount wordCounts[MAX_WORDS];

    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    // Convert input to lowercase
    for (int i = 0; input[i]!= '\0'; i++) {
        input[i] = tolower(input[i]);
    }

    // Tokenize input into words
    char *token = strtok(input, " ");
    while (token!= NULL) {
        strcpy(word, token);
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in input.\n");
            exit(1);
        }
        strcpy(words[numWords], word);
        numWords++;
        token = strtok(NULL, " ");
    }

    // Count occurrences of each word
    for (int i = 0; i < numWords; i++) {
        for (int j = 0; j < numWords; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
    }

    // Sort words by count
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    // Print results
    printf("Word Counts:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}