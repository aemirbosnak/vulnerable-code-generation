//Falcon-180B DATASET v1.0 Category: File handling ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *word;
    int count;
} WordCount;

bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void trim(char *str) {
    int len = strlen(str);
    while (isspace(str[len-1])) {
        str[--len] = '\0';
    }
}

void readWords(FILE *fp, WordCount *wordCounts, int numWords) {
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        trim(line);

        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            if (i >= numWords) {
                break;
            }

            strcpy(word, token);
            trim(word);

            if (strlen(word) > 0) {
                WordCount *wc = wordCounts + i;
                if (wc->word == NULL) {
                    wc->word = strdup(word);
                    wc->count = 1;
                } else if (strcmp(word, wc->word) == 0) {
                    wc->count++;
                }
            }

            i++;
            token = strtok(NULL, ",.?!;:");
        }
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        if (wordCounts[i].word!= NULL) {
            printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    int numWords = 10;
    WordCount wordCounts[numWords];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    readWords(fp, wordCounts, numWords);
    printWordCounts(wordCounts, numWords);

    fclose(fp);
    return 0;
}