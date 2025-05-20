//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 25

struct wordItem {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

typedef struct wordItem wordItem;

void convertToLower(char* string);
void insertWord(char* word, wordItem* words, int* wordCount);
void printWords(wordItem* words, int wordCount);
int compare(const void* a, const void* b);

int main() {
    wordItem words[500];
    int wordCount = 0;
    char word[MAX_WORD_LENGTH];
    FILE* file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file");
        return -1;
    }

    while (fscanf(file, "%s", word) != EOF) {
        convertToLower(word);
        insertWord(word, words, &wordCount);
    }

    fclose(file);

    qsort(words, wordCount, sizeof(wordItem), compare);

    printWords(words, wordCount);

    return 0;
}

void convertToLower(char* string) {
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
    }
}

void insertWord(char* word, wordItem* words, int* wordCount) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return;
        }
    }

    wordItem newWord;
    strcpy(newWord.word, word);
    newWord.frequency = 1;
    words[*wordCount] = newWord;
    (*wordCount)++;
}

void printWords(wordItem* words, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        printf("%s - %d\n", words[i].word, words[i].frequency);
    }
}

int compare(const void* a, const void* b) {
    wordItem* wordA = (wordItem*)a;
    wordItem* wordB = (wordItem*)b;

    return (wordB->frequency - wordA->frequency);
}