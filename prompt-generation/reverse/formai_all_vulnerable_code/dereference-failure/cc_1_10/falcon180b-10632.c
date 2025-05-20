//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordCountA = (WordCount*)a;
    WordCount* wordCountB = (WordCount*)b;

    return strcmp(wordCountA->word, wordCountB->word);
}

void countWords(char* input, int inputLength, WordCount* wordCounts) {
    int i, j, k;
    char word[MAX_WORD_LENGTH];
    char* token;

    for (i = 0; i < inputLength; i++) {
        if (isspace(input[i])) {
            token = strtok_r(&input[i], " ", &input[inputLength]);
            if (token == NULL) {
                break;
            }
            strcpy(word, token);
            j = 0;
            while (j < strlen(word)) {
                if (isalpha(word[j])) {
                    word[j] = tolower(word[j]);
                    j++;
                } else {
                    word[j] = '\0';
                    break;
                }
            }
            k = 0;
            while (k < MAX_WORD_LENGTH && word[k]!= '\0') {
                if (isalpha(word[k])) {
                    break;
                }
                k++;
            }
            if (k == MAX_WORD_LENGTH) {
                break;
            }
            strncpy(word, word + k, MAX_WORD_LENGTH - k);
            wordCounts[hash(word) % MAX_WORDS].count++;
        }
    }
}

int hash(char* word) {
    int hash = 0;
    int i;

    for (i = 0; i < strlen(word); i++) {
        hash = (hash * 31 + tolower(word[i])) % MAX_WORDS;
    }

    return hash;
}

void printWordCounts(WordCount* wordCounts) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main() {
    FILE* inputFile;
    char input[MAX_WORD_LENGTH * 1000000];
    WordCount wordCounts[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    fread(input, sizeof(char), MAX_WORD_LENGTH * 1000000, inputFile);
    fclose(inputFile);

    countWords(input, strlen(input), wordCounts);
    qsort(wordCounts, MAX_WORDS, sizeof(WordCount), compareWords);
    printWordCounts(wordCounts);

    return 0;
}