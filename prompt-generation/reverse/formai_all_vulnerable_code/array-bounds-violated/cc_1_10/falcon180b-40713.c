//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;
    return strcmp(wordA->word, wordB->word);
}

int main() {
    char input[10000];
    char *token;
    WordCount words[MAX_WORD_COUNT];
    int numWords = 0;
    int i;

    // Read input from user
    printf("Enter text to count words: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Tokenize input into words
    token = strtok(input, " \t\r\n\f\v,.!?;:\"'()[]{}<>");
    while (token!= NULL) {
        if (numWords >= MAX_WORD_COUNT) {
            printf("Error: Too many words in input.\n");
            return 1;
        }
        strcpy(words[numWords].word, token);
        words[numWords].count = 1;
        numWords++;
        token = strtok(NULL, " \t\r\n\f\v,.!?;:\"'()[]{}<>");
    }

    // Sort words alphabetically
    qsort(words, numWords, sizeof(WordCount), compareWords);

    // Print word count
    printf("Word Count:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}