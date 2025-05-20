//FormAI DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5000
#define PARTITION "========================"

typedef struct {
    char date[11];
    char time[9];
    char level[8];
    char message[MAX];
} LogEntry;

typedef struct {
    int size;
    LogEntry* entries;
} LogFile;

void parseLine(char* line, LogEntry* entry) {
    sscanf(line, "%s %s %s %[^\n]", entry->date, entry->time, entry->level, entry->message);
}

void parseFile(FILE* fp, LogFile* log) {
    char line[MAX];
    log->size = 0;
    log->entries = malloc(sizeof(LogEntry));
    while (fgets(line, MAX, fp)) {
        LogEntry entry;
        parseLine(line, &entry);
        log->entries[log->size++] = entry;
        log->entries = realloc(log->entries, (log->size + 1) * sizeof(LogEntry));
    }
}

void printEntries(LogFile* log) {
    printf("Total Entries: %d\n", log->size);
    printf("%s\n", PARTITION);
    for (int i = 0; i < log->size; i++) {
        LogEntry entry = log->entries[i];
        printf("%s %s [%s]: %s\n", entry.date, entry.time, entry.level, entry.message);
    }
    printf("%s\n", PARTITION);
}

int main() {
    FILE* fp = fopen("example.log", "r");
    if (fp == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);
    }
    LogFile log;
    parseFile(fp, &log);
    fclose(fp);
    printEntries(&log);
    free(log.entries);
    return 0;
}