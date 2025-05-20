//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_WORD_LENGTH 50
#define WORD_DELIMITER " "

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readLogFile(char *logFilePath, WordCount *wordCounts) {
    FILE *logFile = fopen(logFilePath, "r");
    if (logFile == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    char line[MAX_LOG_ENTRIES];
    while (fgets(line, sizeof(line), logFile)!= NULL) {
        char *token = strtok(line, WORD_DELIMITER);
        while (token!= NULL) {
            int i;
            for (i = 0; i < MAX_WORD_LENGTH; i++) {
                if (token[i] == '\0') {
                    break;
                }
                if (i == MAX_WORD_LENGTH - 1) {
                    break;
                }
            }
            strncpy(wordCounts[i].word, token, i);
            wordCounts[i].count++;
            token = strtok(NULL, WORD_DELIMITER);
        }
    }

    fclose(logFile);
}

void printWordCounts(WordCount *wordCounts) {
    int i;
    for (i = 0; i < MAX_WORD_LENGTH; i++) {
        if (wordCounts[i].count > 0) {
            printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    char logFilePath[MAX_LOG_ENTRIES];
    strcpy(logFilePath, argv[1]);

    WordCount wordCounts[MAX_WORD_LENGTH];
    memset(wordCounts, 0, sizeof(wordCounts));

    readLogFile(logFilePath, wordCounts);
    printWordCounts(wordCounts);

    return 0;
}