//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000

typedef struct {
    char word[50];
    int count;
} WordCount;

void readWords(char* filename, WordCount words[]) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                int j = 0;
                while (isalpha(line[i + j]) && j < 50) {
                    j++;
                }
                if (j > 0) {
                    strncpy(words[i].word, &line[i], j);
                    words[i].word[j] = '\0';
                    words[i].count++;
                }
            }
            i++;
        }
    }

    fclose(fp);
}

void printWords(WordCount words[], int numWords) {
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    WordCount words[MAX_WORDS];
    readWords(argv[1], words);

    int numWords = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].count > 0) {
            numWords++;
        }
    }

    printWords(words, numWords);

    return 0;
}