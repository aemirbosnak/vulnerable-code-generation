//Falcon-180B DATASET v1.0 Category: Text processing ; Style: expert-level
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

char inputText[1000000];
int inputTextLength;
char *word;
int wordLength;
int numWords;
WordCount *wordCounts;

void readInput() {
    printf("Enter input text: ");
    fgets(inputText, sizeof(inputText), stdin);
    inputTextLength = strlen(inputText);
    inputText[inputTextLength - 1] = '\0'; // remove newline character
}

void tokenize() {
    char *input = inputText;
    char *pos = strtok(input, ",.!?;:\"'");
    while (pos!= NULL) {
        word = strtok(pos, ",.!?;:\"'");
        wordLength = strlen(word);
        if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
            if (numWords >= MAX_WORDS) {
                printf("Error: maximum number of words (%d) reached.\n", MAX_WORDS);
                exit(1);
            }
            strcpy(wordCounts[numWords].word, word);
            wordCounts[numWords].count = 1;
            numWords++;
        }
        pos = strtok(NULL, ",.!?;:\"'");
    }
}

void countWords() {
    int i, j;
    for (i = 0; i < numWords - 1; i++) {
        for (j = i + 1; j < numWords; j++) {
            if (strcmp(wordCounts[i].word, wordCounts[j].word) == 0) {
                wordCounts[i].count += wordCounts[j].count;
                wordCounts[j].count = 0;
            }
        }
    }
}

void printWordCounts() {
    int i;
    printf("Word Counts:\n");
    for (i = 0; i < numWords; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main() {
    readInput();
    tokenize();
    countWords();
    printWordCounts();
    return 0;
}