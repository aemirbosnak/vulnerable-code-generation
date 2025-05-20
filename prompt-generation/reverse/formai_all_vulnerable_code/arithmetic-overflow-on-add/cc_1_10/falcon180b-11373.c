//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: high level of detail
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

void readWords(char* filename, WordCount* wordCounts) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = hash(word);
        if (index >= 0 && index < MAX_WORD_COUNT) {
            wordCounts[index].count++;
        }
    }

    fclose(file);
}

int hash(char* word) {
    int sum = 0;
    while (*word) {
        sum += *word;
        word++;
    }
    return sum % MAX_WORD_COUNT;
}

void printWordCounts(WordCount* wordCounts) {
    printf("Word\tCount\n");
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    WordCount wordCounts[MAX_WORD_COUNT];

    readWords(filename, wordCounts);
    printWordCounts(wordCounts);

    return 0;
}