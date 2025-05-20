//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main() {
    FILE *fp;
    char line[MAX_WORD_LEN];
    char *token;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, MAX_WORD_LEN, fp)) {
        token = strtok(line, " ");

        while (token!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached\n");
                exit(1);
            }

            strcpy(words[numWords].word, token);
            words[numWords].count++;
            numWords++;

            token = strtok(NULL, " ");
        }
    }

    fclose(fp);

    printf("Word\tCount\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}