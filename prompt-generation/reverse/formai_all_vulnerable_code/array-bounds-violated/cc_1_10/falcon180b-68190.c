//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

// Function prototypes
int countWords(char *line, int *wordCount);
char *readLine(FILE *file, char *buffer, int bufferSize);
void printWordCounts(int *wordCounts, int numWords);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    int wordCounts[26] = {0}; // Assume there are 26 letters in the alphabet
    int numWords = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        int lineWords = countWords(buffer, &numWords);
        for (int i = 0; i < lineWords; i++) {
            wordCounts[(int)buffer[i] - 97]++; // Subtracting 97 to convert from ASCII code to index in array
        }
    }

    fclose(file);
    printWordCounts(wordCounts, numWords);

    return 0;
}

int countWords(char *line, int *wordCount) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; i < strlen(line); i++) {
        if (isalpha(line[i])) {
            inWord = true;
        } else if (inWord) {
            inWord = false;
            count++;
        }
    }

    if (inWord) {
        count++;
    }

    *wordCount += count;

    return count;
}

char *readLine(FILE *file, char *buffer, int bufferSize) {
    char *line = fgets(buffer, bufferSize, file);
    if (line == NULL) {
        return NULL;
    }

    // Remove newline character from end of line
    line[strcspn(line, "\n")] = '\0';

    return line;
}

void printWordCounts(int *wordCounts, int numWords) {
    printf("Word Counts:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%c: %d\n", i + 97, wordCounts[i]);
    }
}