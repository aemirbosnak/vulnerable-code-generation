//Falcon-180B DATASET v1.0 Category: Text processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *)a;
    WordCount *wordB = (WordCount *)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    int numWords = 0;
    WordCount words[MAX_WORDS];

    printf("Enter the name of the file you want to process: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        char *word;
        int i;

        for (i = 0; i < numWords; i++) {
            if (strcmp(words[i].word, line) == 0) {
                words[i].count++;
                break;
            }
        }

        if (i == numWords) {
            if (numWords >= MAX_WORDS) {
                printf("Error: Too many unique words.\n");
                exit(1);
            }

            word = strtok(line, ",.!?;:\"'");
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}