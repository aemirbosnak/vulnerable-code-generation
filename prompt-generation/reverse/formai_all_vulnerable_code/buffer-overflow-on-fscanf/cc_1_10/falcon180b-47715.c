//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readWords(char* filename, WordCount* wordCounts) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
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
            if (wordCounts[0].word[0] == '\0') {
                strcpy(wordCounts[0].word, word);
            } else {
                printf("Error: Too many unique words in file.\n");
                exit(1);
            }
        }
    }

    fclose(file);
}

void printWordCounts(WordCount* wordCounts) {
    int i;
    for (i = 0; i < MAX_WORDS; i++) {
        if (wordCounts[i].word[0]!= '\0') {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    WordCount wordCounts[MAX_WORDS];
    readWords(argv[1], wordCounts);
    printWordCounts(wordCounts);

    return 0;
}