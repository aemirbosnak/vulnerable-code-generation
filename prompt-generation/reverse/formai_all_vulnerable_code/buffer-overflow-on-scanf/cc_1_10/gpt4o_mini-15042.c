//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME 256
#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 1000

// Structure to hold words and their counts
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function prototypes
void toLowerCase(char *str);
void addOrUpdateWord(WordCount *wordCounts, int *wordCountSize, const char *word);
void printWordCounts(const WordCount *wordCounts, int wordCountSize);
void countWordsInFile(const char *filename);

int main() {
    char filename[MAX_FILENAME];

    printf("Welcome to the C Word Count Tool!\n");
    printf("Please enter the filename (including .txt): ");
    scanf("%s", filename);

    countWordsInFile(filename);

    return 0;
}

void countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    WordCount wordCounts[MAX_WORD_COUNT];
    int wordCountSize = 0;
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", buffer) != EOF) {
        toLowerCase(buffer);
        addOrUpdateWord(wordCounts, &wordCountSize, buffer);
    }

    fclose(file);
    printWordCounts(wordCounts, wordCountSize);
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void addOrUpdateWord(WordCount *wordCounts, int *wordCountSize, const char *word) {
    for (int i = 0; i < *wordCountSize; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }

    if (*wordCountSize < MAX_WORD_COUNT) {
        strcpy(wordCounts[*wordCountSize].word, word);
        wordCounts[*wordCountSize].count = 1;
        (*wordCountSize)++;
    } else {
        printf("Warning: Maximum word limit reached. New words will not be counted.\n");
    }
}

void printWordCounts(const WordCount *wordCounts, int wordCountSize) {
    printf("\nWord Count Results:\n");
    printf("-------------------\n");

    for (int i = 0; i < wordCountSize; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
    printf("-------------------\n");
}