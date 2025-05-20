//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(char* filename, WordCount* wordCounts) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        int found = 0;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (wordCounts->count >= MAX_WORDS) {
                printf("Error: maximum number of words reached\n");
                exit(1);
            }
            strcpy(wordCounts[wordCounts->count].word, word);
            wordCounts[wordCounts->count].count = 1;
            wordCounts->count++;
        }
    }

    fclose(file);
}

void printWordCounts(WordCount* wordCounts) {
    printf("Word counts:\n");
    for (int i = 0; i < wordCounts->count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    WordCount wordCounts[MAX_WORDS];
    readFile(argv[1], &wordCounts);
    printWordCounts(&wordCounts);

    return 0;
}