//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;
    return strcmp(wordA->word, wordB->word);
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int numWords = 0;
    WordCount wordCounts[MAX_WORDS];

    printf("Enter the name of the file: ");
    scanf("%s", line);
    file = fopen(line, "r");

    if (file == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int wordIndex = 0;
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            strcpy(wordCounts[wordIndex].word, token);
            wordCounts[wordIndex].count = 1;
            wordIndex++;
            if (wordIndex >= MAX_WORDS) {
                printf("Error: Too many words\n");
                return 2;
            }
            token = strtok(NULL, ",.?!;:");
        }
        numWords++;
    }

    fclose(file);
    printWordCounts(wordCounts, numWords);

    return 0;
}