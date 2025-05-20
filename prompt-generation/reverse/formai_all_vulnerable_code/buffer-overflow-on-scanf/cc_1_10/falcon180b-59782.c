//Falcon-180B DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

void readFile(FILE *fp, char *filename) {
    char ch;
    int i = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (isalpha(ch)) {
            filename[i++] = tolower(ch);
        }
    }
    filename[i] = '\0';
}

void countWords(char *text, WordCount *wordCounts, int numWords) {
    char *token;
    int i = 0;
    while ((token = strtok(text, " \t\n\r\f\v"))!= NULL) {
        if (i >= numWords) {
            break;
        }
        strcpy(wordCounts[i].word, token);
        wordCounts[i].count = 1;
        i++;
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LEN];
    char text[MAX_WORDS][MAX_WORD_LEN];
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    readFile(fp, filename);

    fclose(fp);

    printf("Enter number of words to count: ");
    scanf("%d", &numWords);

    countWords(filename, wordCounts, numWords);

    printWordCounts(wordCounts, numWords);

    return 0;
}