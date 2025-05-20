//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char *key;
    int value;
} LogEntry;

void parseLogFile(char *filename, LogEntry *entries, int *numEntries) {
    FILE *fp;
    char line[MAX_ENTRY_LENGTH];
    char *token;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_ENTRY_LENGTH, fp)!= NULL) {
        entries[i].key = strdup(line);
        token = strtok(line, " ");
        while (token!= NULL) {
            if (isdigit(token[0])) {
                entries[i].value = atoi(token);
            }
            token = strtok(NULL, " ");
        }
        i++;
        if (i >= MAX_LOG_ENTRIES) {
            printf("Warning: Reached maximum number of log entries.\n");
            break;
        }
    }

    *numEntries = i;
    fclose(fp);
}

void printLogEntries(LogEntry *entries, int numEntries) {
    int i;

    for (i = 0; i < numEntries; i++) {
        printf("%s -> %d\n", entries[i].key, entries[i].value);
    }
}

void sortLogEntries(LogEntry *entries, int numEntries, int (*compare)(const void *, const void *)) {
    qsort(entries, numEntries, sizeof(LogEntry), compare);
}

int compareLogEntries(const void *a, const void *b) {
    LogEntry *entryA = (LogEntry *)a;
    LogEntry *entryB = (LogEntry *)b;

    return strcmp(entryA->key, entryB->key);
}

int main() {
    char filename[100];
    LogEntry entries[MAX_LOG_ENTRIES];
    int numEntries;

    printf("Enter log file name: ");
    scanf("%s", filename);

    parseLogFile(filename, entries, &numEntries);
    printf("Log entries:\n");
    printLogEntries(entries, numEntries);

    sortLogEntries(entries, numEntries, compareLogEntries);
    printf("\nSorted log entries:\n");
    printLogEntries(entries, numEntries);

    return 0;
}