//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(FILE* file, WordCount* wordCounts, int maxWords) {
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF && i < maxWords) {
        word[strcspn(word, "\n")] = '\0'; // remove newline character
        if (strlen(word) > 0) {
            for (int j = 0; j < strlen(word); j++) {
                if (!isalpha(word[j])) {
                    word[j] = '\0';
                }
            }
            strcpy(wordCounts[i].word, word);
            wordCounts[i].count = 1;
            i++;
        }
    }
}

void writeWordCounts(WordCount* wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int numWords = 0;
    WordCount* wordCounts = malloc(sizeof(WordCount) * 1000); // allocate memory for up to 1000 words
    if (wordCounts == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return 2;
    }

    readWords(file, wordCounts, 1000); // read up to 1000 words
    numWords = 0;
    for (int i = 0; i < 1000; i++) {
        if (strlen(wordCounts[i].word) > 0) {
            numWords++;
        }
    }

    writeWordCounts(wordCounts, numWords);

    fclose(file);
    free(wordCounts);

    return 0;
}