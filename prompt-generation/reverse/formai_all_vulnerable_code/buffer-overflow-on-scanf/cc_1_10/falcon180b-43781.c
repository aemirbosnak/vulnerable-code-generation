//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100
#define MAX_WORD_COUNT 1000
#define MAX_LINE_SIZE 1000

typedef struct {
    char word[MAX_WORD_SIZE];
    int count;
} WordCount;

typedef struct {
    WordCount words[MAX_WORD_COUNT];
    int wordCount;
} LineCount;

void readLine(FILE *fp, char line[MAX_LINE_SIZE]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(fp))!= EOF && ch!= '\n' && i < MAX_LINE_SIZE - 1) {
        line[i++] = tolower(ch);
    }

    line[i] = '\0';
}

void buildIndex(FILE *fp, WordCount words[MAX_WORD_COUNT]) {
    char line[MAX_LINE_SIZE];
    int i = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *word = strtok(line, ",.?!;:");

        while (word!= NULL) {
            int j;
            for (j = 0; j < i; j++) {
                if (strcmp(words[j].word, word) == 0) {
                    words[j].count++;
                    break;
                }
            }

            if (j == i) {
                strcpy(words[i].word, word);
                words[i].count = 1;
                i++;
            }

            word = strtok(NULL, ",.?!;:");
        }
    }
}

void printIndex(WordCount words[MAX_WORD_COUNT], int wordCount) {
    printf("Word\tCount\n");

    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }
}

int main() {
    FILE *fp;
    char filename[MAX_LINE_SIZE];
    WordCount words[MAX_WORD_COUNT];
    int wordCount = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    buildIndex(fp, words);

    fclose(fp);

    printIndex(words, wordCount);

    return 0;
}