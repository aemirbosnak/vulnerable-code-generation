//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void ReadFile(FILE *file, WordCount *wordCounts, int count) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        for (int j = 0; j < count; j++) {
            if (strcmp(wordCounts[j].word, word) == 0) {
                wordCounts[j].count++;
                break;
            }
        }
        if (i < count) {
            strcpy(wordCounts[i].word, word);
            wordCounts[i].count = 1;
            i++;
        }
    }
}

void PrintWordCounts(WordCount *wordCounts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *file;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    WordCount wordCounts[MAX_WORDS];
    int count = 0;
    ReadFile(file, wordCounts, count);
    fclose(file);
    PrintWordCounts(wordCounts, count);
    return 0;
}