//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

int main() {
    FILE *file;
    char line[100];
    char word[MAX_WORD_LENGTH];
    WordFrequency *wordFrequency = NULL;
    int numWords = 0;
    int numUniqueWords = 0;
    int i;

    // Open file for reading
    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Initialize word frequency array
    wordFrequency = malloc(MAX_WORDS * sizeof(WordFrequency));
    if (wordFrequency == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    for (i = 0; i < MAX_WORDS; i++) {
        wordFrequency[i].count = 0;
    }

    // Read file and count word frequencies
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",\t\n\r\f\v");
        while (token!= NULL) {
            int len = strlen(token);
            if (len > MAX_WORD_LENGTH) {
                len = MAX_WORD_LENGTH;
            }
            strncpy(word, token, len);
            word[len] = '\0';
            if (isalpha(word[0])) {
                numWords++;
                bool found = false;
                for (i = 0; i < numUniqueWords; i++) {
                    if (strcmp(wordFrequency[i].word, word) == 0) {
                        wordFrequency[i].count++;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    if (numUniqueWords >= MAX_WORDS) {
                        printf("Error: too many unique words.\n");
                        exit(1);
                    }
                    strncpy(wordFrequency[numUniqueWords].word, word, MAX_WORD_LENGTH);
                    wordFrequency[numUniqueWords].count = 1;
                    numUniqueWords++;
                }
            }
            token = strtok(NULL, ",\t\n\r\f\v");
        }
    }

    // Print word frequencies
    printf("Total words: %d\n", numWords);
    printf("Unique words: %d\n", numUniqueWords);
    printf("Word frequencies:\n");
    for (i = 0; i < numUniqueWords; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].count);
    }

    // Free memory and close file
    free(wordFrequency);
    fclose(file);

    return 0;
}