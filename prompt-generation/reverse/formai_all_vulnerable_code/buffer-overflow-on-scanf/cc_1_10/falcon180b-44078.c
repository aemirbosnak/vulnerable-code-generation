//Falcon-180B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

// Function to remove leading and trailing white spaces from a string
void trim(char* str) {
    int i, j;
    for (i = 0; i < strlen(str); i++) {
        if (!isspace(str[i])) {
            break;
        }
    }
    for (j = strlen(str) - 1; j >= 0; j--) {
        if (!isspace(str[j])) {
            str[j + 1] = '\0';
            break;
        }
    }
}

// Function to count words in a line of text
int countWords(char* line) {
    int count = 0;
    char* word = strtok(line, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to read a file and count total words and lines
void countWordsAndLines(FILE* fp) {
    char line[MAX_LINE_LENGTH];
    int lineCount = 0;
    int wordCount = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        lineCount++;
        trim(line);
        int words = countWords(line);
        wordCount += words;
    }
    printf("Total lines: %d\n", lineCount);
    printf("Total words: %d\n", wordCount);
}

int main() {
    FILE* fp;
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    countWordsAndLines(fp);
    fclose(fp);
    return 0;
}