//Falcon-180B DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_CHAR_LENGTH 10

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *inputFile = NULL;
    char line[MAX_LINE_LENGTH];
    char *word = NULL;
    size_t len = 0;
    ssize_t read;
    int totalWords = 0;
    int totalChars = 0;
    WordCount *wordCounts = NULL;
    int numWords = 0;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: could not open input file\n");
        exit(1);
    }

    // Allocate memory for wordCounts array
    wordCounts = malloc(sizeof(WordCount) * 100);
    if (wordCounts == NULL) {
        fprintf(stderr, "Error: could not allocate memory for wordCounts array\n");
        exit(1);
    }

    // Read input file line by line
    while ((read = getline(&line, &len, inputFile))!= -1) {
        totalWords++;
        totalChars += read;

        // Tokenize line into words
        word = strtok(line, " ");
        while (word!= NULL) {
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(wordCounts[i].word, word) == 0) {
                    wordCounts[i].count++;
                    break;
                }
            }
            if (i == numWords) {
                if (numWords >= 100) {
                    fprintf(stderr, "Error: too many unique words\n");
                    exit(1);
                }
                wordCounts[numWords].word = strdup(word);
                wordCounts[numWords].count = 1;
                numWords++;
            }
            word = strtok(NULL, " ");
        }
    }

    // Print word counts
    printf("Total words: %d\n", totalWords);
    printf("Total characters: %d\n", totalChars);
    printf("Word count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    // Free memory
    free(line);
    free(word);
    for (int i = 0; i < numWords; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    return 0;
}