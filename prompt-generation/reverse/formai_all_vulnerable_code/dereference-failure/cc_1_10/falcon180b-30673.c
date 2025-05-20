//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_WORD_SIZE 50

typedef struct {
    char *word;
    int count;
} WordCount;

void parseLog(char *log, WordCount *wordCounts, int count) {
    char *token;
    char *saveptr;
    char *line = strtok_r(log, "\n", &saveptr);
    while (line!= NULL) {
        token = strtok_r(line, " ", &saveptr);
        while (token!= NULL) {
            if (strlen(token) > 0) {
                WordCount *word = NULL;
                for (int i = 0; i < count; i++) {
                    if (strcmp(token, wordCounts[i].word) == 0) {
                        word = &wordCounts[i];
                        break;
                    }
                }
                if (word == NULL) {
                    word = (WordCount *)malloc(sizeof(WordCount));
                    strcpy(word->word, token);
                    word->count = 1;
                    wordCounts = (WordCount *)realloc(wordCounts, sizeof(WordCount) * (count + 1));
                    wordCounts[count] = *word;
                    count++;
                } else {
                    word->count++;
                }
            }
            token = strtok_r(NULL, " ", &saveptr);
        }
        line = strtok_r(NULL, "\n", &saveptr);
    }
}

void printWordCounts(WordCount *wordCounts, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main() {
    FILE *logFile;
    char log[MAX_LOG_SIZE];
    WordCount wordCounts[MAX_WORD_SIZE];
    int wordCount = 0;

    logFile = fopen("logfile.log", "r");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    fseek(logFile, 0, SEEK_END);
    int logSize = ftell(logFile);
    rewind(logFile);

    if (logSize > MAX_LOG_SIZE) {
        printf("Log file is too large.\n");
        fclose(logFile);
        return 1;
    }

    fread(log, logSize, 1, logFile);
    fclose(logFile);

    parseLog(log, wordCounts, wordCount);
    printWordCounts(wordCounts, wordCount);

    return 0;
}