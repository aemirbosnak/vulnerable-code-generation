//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_WORD_SIZE 50

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

void readWords(char *filename, WordCount *wordCounts) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char word[MAX_WORD_SIZE];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        WordCount *wordCount = NULL;
        int found = 0;
        for (i = 0; i < MAX_SIZE; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            if (wordCounts[MAX_SIZE - 1].word[0]!= '\0') {
                printf("Error: too many unique words in file\n");
                exit(1);
            }
            strcpy(wordCounts[MAX_SIZE - 1].word, word);
            wordCounts[MAX_SIZE - 1].count = 1;
        }
    }

    fclose(file);
}

void printWords(WordCount *wordCounts) {
    printf("Word\tCount\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (wordCounts[i].word[0]!= '\0') {
            printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_SIZE];
    strcpy(filename, argv[1]);

    WordCount wordCounts[MAX_SIZE];
    readWords(filename, wordCounts);
    printWords(wordCounts);

    return 0;
}