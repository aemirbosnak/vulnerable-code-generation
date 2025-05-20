//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wc1 = a;
    const WordCount* wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    char logFile[MAX_LOG_LINES];
    char line[MAX_LOG_LINES];
    char word[MAX_WORD_LENGTH];
    FILE* fp;
    int numLines = 0;
    int numWords = 0;
    WordCount words[MAX_WORD_LENGTH];

    // Get log file name from user
    printf("Enter log file name: ");
    scanf("%s", logFile);

    // Open log file for reading
    fp = fopen(logFile, "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    // Read each line of the log file
    while (fgets(line, MAX_LOG_LINES, fp)!= NULL) {
        numLines++;

        // Tokenize the line into words
        char* token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(word, token);

            // Check if the word is already in the word count array
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }

            // If the word is not found, add it to the array
            if (!found) {
                strcpy(words[numWords].word, word);
                words[numWords].count = 1;
                numWords++;
            }

            token = strtok(NULL, " ");
        }
    }

    // Sort the word count array by word frequency
    qsort(words, numWords, sizeof(WordCount), compareWords);

    // Print the word count results
    printf("\nWord Frequency Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    fclose(fp);
    return 0;
}