//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE* file, WordCount words[], int numWords) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= numWords) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

void countWords(char* text, WordCount words[], int numWords) {
    char* token;
    int i = 0;
    while ((token = strtok(text, ",.!?;:\"'"))!= NULL) {
        if (i >= numWords) {
            printf("Error: Too many words in text.\n");
            exit(1);
        }
        strcpy(words[i].word, token);
        words[i].count++;
        i++;
    }
}

void printWordCounts(WordCount words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    WordCount words[MAX_NUM_WORDS];
    int numWords = 0;

    printf("Enter number of words to count: ");
    scanf("%d", &numWords);

    readWords(file, words, numWords);
    countWords(NULL, words, numWords);
    printWordCounts(words, numWords);

    fclose(file);
    return 0;
}