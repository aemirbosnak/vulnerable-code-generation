//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: real-life
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

void readWords(char* filename, WordCount* wordCounts, int maxWords) {
    FILE* file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= maxWords) {
            break;
        }

        for (int j = 0; j < strlen(word); j++) {
            if (!isalpha(word[j])) {
                word[j] = '\0';
            }
        }

        strcpy(wordCounts[i].word, word);
        wordCounts[i].count = 1;
        i++;
    }

    fclose(file);
}

void countWords(WordCount* wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(wordCounts[i].word, wordCounts[j].word) == 0) {
                wordCounts[i].count += wordCounts[j].count;
                wordCounts[j].count = 0;
            }
        }
    }
}

void printWords(WordCount* wordCounts, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <max_words>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];
    int maxWords = atoi(argv[2]);

    WordCount wordCounts[MAX_WORDS];
    readWords(filename, wordCounts, maxWords);
    countWords(wordCounts, maxWords);
    printWords(wordCounts, maxWords);

    return 0;
}