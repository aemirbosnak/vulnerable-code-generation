//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000 // Maximum size of log file
#define MAX_LINE_SIZE 200 // Maximum length of each line in log file
#define MAX_WORD_SIZE 20 // Maximum length of each word in log file
#define MAX_WORD_COUNT 100 // Maximum number of unique words to count

typedef struct {
    char word[MAX_WORD_SIZE]; // Word to count
    int count; // Number of occurrences
} WordCount;

int main() {
    FILE *logFile;
    char line[MAX_LINE_SIZE];
    int lineCount = 0;
    int wordCount = 0;
    WordCount wordList[MAX_WORD_COUNT]; // Array to store word counts

    // Open log file for reading
    logFile = fopen("logfile.txt", "r");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    // Read each line from the log file
    while (fgets(line, MAX_LINE_SIZE, logFile)!= NULL) {
        lineCount++;

        // Remove newline character from the end of the line
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        // Split line into words
        char *word = strtok(line, " ");
        while (word!= NULL) {
            wordCount++;
            if (wordCount >= MAX_WORD_COUNT) {
                printf("Error: Too many unique words in log file.\n");
                exit(1);
            }

            // Convert word to lowercase
            for (int i = 0; i < strlen(word); i++) {
                word[i] = tolower(word[i]);
            }

            // Check if word is already in the array
            int found = 0;
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(word, wordList[i].word) == 0) {
                    wordList[i].count++;
                    found = 1;
                    break;
                }
            }

            // Add word to array if not found
            if (!found) {
                strcpy(wordList[wordCount].word, word);
                wordList[wordCount].count = 1;
                wordCount++;
            }

            word = strtok(NULL, " ");
        }
    }

    // Print total number of lines and words
    printf("Total lines: %d\n", lineCount);
    printf("Total words: %d\n", wordCount);

    // Print word counts
    printf("Word counts:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }

    // Close log file
    fclose(logFile);

    return 0;
}