//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 100

typedef struct {
    char date[MAX_LINE_LEN];
    char time[MAX_LINE_LEN];
    char level[MAX_LINE_LEN];
    char message[MAX_LINE_LEN];
} LogEntry;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("USAGE: %s <logfile>\n", argv[0]);
        return 1;
    }

    char *logfile = argv[1];
    FILE *log = fopen(logfile, "r");

    if (!log) {
        printf("ERROR: Could not open file: %s\n", logfile);
        return 1;
    }

    LogEntry *entries = NULL;
    int entry_count = 0;

    char line[MAX_LINE_LEN];

    while (fgets(line, MAX_LINE_LEN, log)) {
        LogEntry *new_entry = malloc(sizeof(LogEntry));

        if (!new_entry) {
            printf("ERROR: Could not allocate memory for new log entry.\n");
            return 1;
        }

        sscanf(line, "%s %s %s %[^\n]", new_entry->date, new_entry->time, new_entry->level, new_entry->message);

        entry_count++;
        entries = realloc(entries, sizeof(LogEntry) * entry_count);
        entries[entry_count - 1] = *new_entry;

        free(new_entry);
    }

    fclose(log);

    printf("LOG FILE: %s\n", logfile);
    printf("ENTRY COUNT: %d\n", entry_count);

    for (int i = 0; i < entry_count; i++) {
        printf("\nENTRY %d:\n", i + 1);
        printf("DATE: %s\n", entries[i].date);
        printf("TIME: %s\n", entries[i].time);
        printf("LEVEL: %s\n", entries[i].level);
        printf("MESSAGE: %s\n", entries[i].message);
    }

    free(entries);

    return 0;
}