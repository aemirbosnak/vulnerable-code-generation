//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

// Function to count words in a string
int countWords(char *str) {
    int count = 0;
    char *p = strtok(str, ",.?!;:");
    while (p!= NULL) {
        count++;
        p = strtok(NULL, ",.?!;:");
    }
    return count;
}

// Function to count characters in a string
int countChars(char *str) {
    int count = 0;
    while (*str!= '\0') {
        count++;
        str++;
    }
    return count;
}

// Function to count lines in a string
int countLines(char *str) {
    int count = 0;
    char *p = str;
    while (*p!= '\0') {
        if (*p == '\n') {
            count++;
        }
        p++;
    }
    return count;
}

int main() {
    FILE *fp;
    char filename[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    char *word;
    int numWords = 0;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Count words, characters, and lines in file
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        numWords += countWords(line);
    }
    rewind(fp);
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        numWords += countWords(line);
    }
    rewind(fp);
    while (fgets(line, MAX_WORD_LENGTH, fp)!= NULL) {
        countLines(line);
    }

    // Close file
    fclose(fp);

    // Print results
    printf("Number of words: %d\n", numWords);
    printf("Number of characters: %d\n", countChars(line));
    printf("Number of lines: %d\n", countLines(line));

    return 0;
}