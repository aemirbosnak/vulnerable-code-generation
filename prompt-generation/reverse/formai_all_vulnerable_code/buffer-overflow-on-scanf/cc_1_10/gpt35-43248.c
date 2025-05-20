//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
#define MAX_WORDS 10000

typedef struct WordCount {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readWords(WordCount words[], int* numWords, char* fileName);
void countWords(WordCount words[], int* numWords, char* input, int len);
void sortWords(WordCount words[], int numWords);
void printWords(WordCount words[], int numWords);

int main() {
    char fileName[MAX_WORD_LEN];
    printf("Enter the name of the file to read from: ");
    scanf("%s", fileName);

    WordCount words[MAX_WORDS];
    int numWords = 0;
    readWords(words, &numWords, fileName);

    sortWords(words, numWords);
    printWords(words, numWords);

    return 0;
}

void readWords(WordCount words[], int* numWords, char* fileName) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;

    fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while(getline(&line, &len, fp) != -1) {
        countWords(words, numWords, line, len);
    }

    free(line);
    fclose(fp);
}

void countWords(WordCount words[], int* numWords, char* input, int len) {
    char word[MAX_WORD_LEN];
    int i,j,currentWordLen;

    for(i = 0; i < len; i++) {

        // Skip non-alphanumeric characters
        while(i < len && !isalnum(input[i])) {
            i++;
        }

        currentWordLen = 0;
        // Get the current word
        while(i < len && isalnum(input[i])) {
            word[currentWordLen++] = tolower(input[i++]);
        }

        if(currentWordLen > 0) {
            word[currentWordLen] = '\0';
            // Check if word is already in array
            for(j = 0; j < *numWords; j++) {
                if(strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    break;
                }
            }
            // Add new word to array
            if(j == *numWords) {
                strcpy(words[j].word, word);
                words[j].count = 1;
                (*numWords)++;
            }
        }
    }
}

void sortWords(WordCount words[], int numWords) {
    int i, j;
    WordCount temp;
    for(i = 0; i < numWords; i++) {
        for(j = i+1; j < numWords; j++) {
            if(strcmp(words[i].word, words[j].word) > 0) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

void printWords(WordCount words[], int numWords) {
    int i;
    for(i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}