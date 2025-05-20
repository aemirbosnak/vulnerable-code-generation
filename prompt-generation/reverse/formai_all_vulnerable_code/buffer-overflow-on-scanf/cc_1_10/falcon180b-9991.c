//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* word = strtok(str, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }
    return count;
}

// Function to print word count for each line in a file
void printWordCounts(FILE* file) {
    char line[1000];
    int lineCount = 0;
    int wordCount = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        lineCount++;
        wordCount += countWords(line);
        printf("Line %d: %d words\n", lineCount, wordCount);
    }
}

// Function to get file name from user
char* getFileName() {
    char fileName[100];
    printf("Enter file name: ");
    scanf("%s", fileName);
    return fileName;
}

int main() {
    char* fileName = getFileName();
    FILE* file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    printWordCounts(file);
    fclose(file);

    return 0;
}