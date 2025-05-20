//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LEN 100
#define MAX_WORD_COUNT 100000

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void initializeWordCounts(WordCount* counts, int count) {
    for (int i = 0; i < count; i++) {
        counts[i].word[0] = '\0';
        counts[i].count = 0;
    }
}

void readWords(FILE* file, WordCount* counts, int count) {
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int len = strlen(word);
        if (len <= MAX_WORD_LEN) {
            for (int i = 0; i < count; i++) {
                if (strcmp(counts[i].word, word) == 0) {
                    counts[i].count++;
                    break;
                }
            }
        }
    }
}

void printWordCounts(WordCount* counts, int count) {
    for (int i = 0; i < count; i++) {
        if (counts[i].count > 0) {
            printf("%s: %d\n", counts[i].word, counts[i].count);
        }
    }
}

int main() {
    FILE* file;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return 1;
    }

    int wordCount = 0;
    char word[MAX_WORD_LEN];
    while (fscanf(file, "%s", word)!= EOF) {
        int len = strlen(word);
        if (len > 0 && isalpha(word[0])) {
            word[len - 1] = '\0';
            wordCount++;
        }
    }

    WordCount* counts = malloc(wordCount * sizeof(WordCount));
    if (counts == NULL) {
        printf("Memory error.\n");
        return 1;
    }

    initializeWordCounts(counts, wordCount);
    readWords(file, counts, wordCount);

    printWordCounts(counts, wordCount);

    free(counts);
    fclose(file);

    return 0;
}