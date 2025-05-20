//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_WORD_COUNT 10000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void readWords(FILE *file, WordCount *wordCounts, int count) {
    char word[MAX_WORD_SIZE];
    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= MAX_WORD_COUNT) {
            break;
        }
        wordCounts[count].word[0] = tolower(word[0]);
        strcpy(wordCounts[count].word + 1, word + 1);
        wordCounts[count].count = 1;
        count++;
    }
}

void printWords(WordCount *wordCounts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[MAX_FILE_SIZE];
    WordCount wordCounts[MAX_WORD_COUNT];
    int count = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    readWords(file, wordCounts, count);

    fclose(file);

    printWords(wordCounts, count);

    return 0;
}