//Falcon2-11B DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    char *fileName = argv[1];
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char buffer[1000];
    int lineCount = 0;
    int wordCount = 0;
    int summaryLength = 0;
    char *summary = NULL;
    char *word = NULL;
    char *line = NULL;
    int maxWordLength = 0;
    int maxLineLength = 0;
    int lineLength = 0;

    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        lineCount++;
        line = strdup(buffer);
        lineLength = strlen(line);
        if (maxLineLength < lineLength) {
            maxLineLength = lineLength;
        }

        word = strtok(line, " \t\n");
        while (word!= NULL) {
            wordCount++;
            if (strlen(word) > maxWordLength) {
                maxWordLength = strlen(word);
            }
            word = strtok(NULL, " \t\n");
        }
    }

    fclose(fp);

    printf("Summary of %s:\n", argv[1]);
    printf("Number of lines: %d\n", lineCount);
    printf("Number of words: %d\n", wordCount);
    printf("Maximum line length: %d\n", maxLineLength);
    printf("Maximum word length: %d\n", maxWordLength);
    printf("Summary length: %d\n", summaryLength);

    summary = malloc(summaryLength + 1);
    if (summary == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    line = strdup(buffer);
    lineLength = strlen(line);
    word = strtok(line, " \t\n");
    while (word!= NULL) {
        if (strlen(word) > summaryLength || lineLength - strlen(word) < summaryLength) {
            if (strlen(word) > maxWordLength) {
                word[maxWordLength] = '\0';
            }
            strcat(summary, word);
        }
        word = strtok(NULL, " \t\n");
    }

    printf("Summary:\n%s\n", summary);

    free(summary);
    free(line);
    free(word);
    return 0;
}