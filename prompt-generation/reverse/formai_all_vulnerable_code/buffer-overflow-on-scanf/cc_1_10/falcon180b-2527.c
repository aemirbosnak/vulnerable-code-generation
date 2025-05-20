//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readWords(FILE *inputFile, WordCount words[]) {
    char word[MAX_WORD_LEN];
    int i = 0;
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in input file.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

void countWords(FILE *inputFile, WordCount words[]) {
    char word[MAX_WORD_LEN];
    int i = 0;
    while (fscanf(inputFile, "%s", word)!= EOF) {
        for (int j = 0; j < i; j++) {
            if (strcmp(word, words[j].word) == 0) {
                words[j].count++;
                break;
            }
        }
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in input file.\n");
            exit(1);
        }
        strcpy(words[i].word, word);
        words[i].count = 1;
        i++;
    }
}

void printWords(WordCount words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *inputFile;
    char inputFileName[MAX_WORD_LEN];
    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    printf("Do you want to count the words? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        countWords(inputFile, words);
    } else {
        readWords(inputFile, words);
    }

    fclose(inputFile);
    printWords(words, numWords);

    return 0;
}