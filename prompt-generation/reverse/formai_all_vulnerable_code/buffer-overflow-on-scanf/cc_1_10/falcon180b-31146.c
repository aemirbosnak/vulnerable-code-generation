//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE* file, WordCount* wordCounts, int numWords) {
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            if (i >= numWords) {
                printf("Error: exceeded maximum number of words.\n");
                exit(1);
            }
            strcpy(wordCounts[i].word, "");
            while (isalpha(ch)) {
                strcat(wordCounts[i].word, ch);
                ch = fgetc(file);
            }
            wordCounts[i].count = 1;
            i++;
        }
    }
}

void printWordCounts(WordCount* wordCounts, int numWords) {
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        if (strcmp(wordCounts[i].word, "")!= 0) {
            printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
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
        printf("Error: could not open file.\n");
        exit(1);
    }
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    readFile(file, wordCounts, MAX_WORDS);
    fclose(file);
    printWordCounts(wordCounts, numWords);
    return 0;
}