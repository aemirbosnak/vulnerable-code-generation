//Falcon-180B DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readTextFile(FILE* file, char* text);
void processText(char* text, WordCount* wordCounts);
void printWordCounts(WordCount* wordCounts, int numWords);
int compareWords(const void* a, const void* b);

int main() {
    FILE* file;
    char filename[100];
    char text[100000];
    WordCount wordCounts[MAX_WORDS];

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    readTextFile(file, text);
    fclose(file);

    processText(text, wordCounts);
    qsort(wordCounts, MAX_WORDS, sizeof(WordCount), compareWords);
    printWordCounts(wordCounts, MAX_WORDS);

    return 0;
}

void readTextFile(FILE* file, char* text) {
    int c;
    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            strcat(text, &c);
        }
    }
}

void processText(char* text, WordCount* wordCounts) {
    char* word;
    int i = 0;
    while ((word = strtok(text, " "))!= NULL) {
        if (i < MAX_WORDS) {
            strcpy(wordCounts[i].word, word);
            wordCounts[i].count = 1;
            i++;
        } else {
            printf("Error: too many unique words.\n");
        }
    }
}

void printWordCounts(WordCount* wordCounts, int numWords) {
    printf("Word Counts:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}