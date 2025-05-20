//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_LINE_LENGTH 1024
#define MAX_NUM_KEYWORDS 50
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int frequency;
} KeywordFrequency;

typedef struct {
    KeywordFrequency *keywords;
    int numKeywords;
} KeywordFrequencyList;

void initializeKeywordFrequencyList(KeywordFrequencyList *list) {
    list->numKeywords = 0;
    list->keywords = NULL;
}

void addKeywordFrequency(KeywordFrequencyList *list, char *keyword) {
    list->numKeywords++;
    list->keywords = realloc(list->keywords, sizeof(KeywordFrequency) * list->numKeywords);
    strcpy(list->keywords[list->numKeywords - 1].keyword, keyword);
    list->keywords[list->numKeywords - 1].frequency = 0;
}

void incrementKeywordFrequency(KeywordFrequencyList *list, char *keyword) {
    int i;
    for (i = 0; i < list->numKeywords; i++) {
        if (strcmp(list->keywords[i].keyword, keyword) == 0) {
            list->keywords[i].frequency++;
            break;
        }
    }
    if (i == list->numKeywords) {
        addKeywordFrequency(list, keyword);
    }
}

void printKeywordFrequencyList(KeywordFrequencyList *list) {
    int i;
    for (i = 0; i < list->numKeywords; i++) {
        printf("%s: %d\n", list->keywords[i].keyword, list->keywords[i].frequency);
    }
}

void processLogLine(char *logLine, KeywordFrequencyList *keywordFrequencyList) {
    char *token;
    char *keyword;
    int keywordLength;
    int i;

    token = strtok(logLine, " ");
    while (token!= NULL) {
        keywordLength = strlen(token);
        if (keywordLength > 0 && keywordLength <= MAX_KEYWORD_LENGTH && isalpha(token[0])) {
            keyword = malloc(keywordLength + 1);
            strcpy(keyword, token);
            for (i = 0; i < keywordLength; i++) {
                if (!isalpha(keyword[i])) {
                    free(keyword);
                    break;
                }
            }
            if (i == keywordLength) {
                incrementKeywordFrequency(keywordFrequencyList, keyword);
            }
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    FILE *logFile;
    char logLine[MAX_LOG_LINE_LENGTH];
    KeywordFrequencyList keywordFrequencyList;

    initializeKeywordFrequencyList(&keywordFrequencyList);

    logFile = fopen("example.log", "r");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fgets(logLine, MAX_LOG_LINE_LENGTH, logFile)!= NULL) {
        processLogLine(logLine, &keywordFrequencyList);
    }

    fclose(logFile);

    printKeywordFrequencyList(&keywordFrequencyList);

    return 0;
}