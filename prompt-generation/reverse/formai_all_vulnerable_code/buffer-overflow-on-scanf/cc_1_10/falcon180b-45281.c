//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32
#define MAX_WORD_COUNT 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int lineNumber = 1;
    int wordCount = 0;
    WordCount wordList[MAX_WORD_COUNT];

    printf("Enter the name of the log file: ");
    scanf("%s", line);

    file = fopen(line, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", line);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        lineNumber++;
        wordCount = 0;

        // Remove newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Convert all characters to lowercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = tolower(line[i]);
        }

        // Tokenize the line into words
        char *token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);

            // Check if the word is already in the word list
            WordCount *existingWord = bsearch(word, wordList, wordCount, sizeof(WordCount), compareWords);

            if (existingWord == NULL) {
                // Add the word to the word list if it doesn't exist
                strcpy(existingWord->word, word);
                existingWord->count = 1;
                wordCount++;
            } else {
                // Increment the count of the existing word
                existingWord->count++;
            }

            token = strtok(NULL, " ");
        }
    }

    qsort(wordList, wordCount, sizeof(WordCount), compareWords);

    printf("\nWord frequency analysis for %s:\n", line);
    printf("Line number\tWord\tFrequency\n");

    for (int i = 0; i < wordCount; i++) {
        printf("%d\t%s\t%d\n", lineNumber, wordList[i].word, wordList[i].count);
    }

    fclose(file);

    return 0;
}