//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

int countWords(FILE *fp, char words[][MAX_WORD_LENGTH + 1], int wordCount[]);
void printCounts(char words[][MAX_WORD_LENGTH + 1], int wordCount[], int numWords);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char words[MAX_WORDS][MAX_WORD_LENGTH + 1];
    int wordCount[MAX_WORDS] = {0};

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    int numWords = countWords(fp, words, wordCount);
    printCounts(words, wordCount, numWords);
    fclose(fp);

    return 0;
}

int countWords(FILE *fp, char words[][MAX_WORD_LENGTH + 1], int wordCount[]) {
    char word[MAX_WORD_LENGTH + 1];
    int numWords = 0;

    while (fscanf(fp, "%s", word) != EOF) {
        // Convert word to all lowercase
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }

        // Remove any non-alphanumeric characters from beginning and end of the word
        int start = 0, end = strlen(word) - 1;
        while (start <= end && !isalnum(word[start])) {
            start++;
        }
        while (end >= start && !isalnum(word[end])) {
            end--;
        }
        word[end+1] = '\0';
        strcpy(words[numWords], word);
        numWords++;
    }

    // Count the occurrences of each word
    for (int i = 0; i < numWords; i++) {
        for (int j = i + 1; j < numWords; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                wordCount[i]++;
                wordCount[j] = -1; // Mark duplicate word so it isn't counted again
            }
        }
    }

    return numWords;
}

void printCounts(char words[][MAX_WORD_LENGTH + 1], int wordCount[], int numWords) {
    printf("Word frequencies:\n");

    for (int i = 0; i < numWords; i++) {
        if (wordCount[i] > 0) {
            printf("%-20s %d\n", words[i], wordCount[i]);
        }
    }
}