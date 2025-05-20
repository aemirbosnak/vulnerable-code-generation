//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *filename;
    char *date;
    int pid;
    char *level;
    char *message;
} LogEntry;

LogEntry *parse_log_line(char *line) {
    LogEntry *entry = malloc(sizeof(LogEntry));
    int n = sscanf(line,
        "LOG %s %s %d %s %n",
        entry->filename,
        entry->date,
        &entry->pid,
        entry->level,
        &n);
    if (n == 4) {
        entry->message = strdup(line + n + 1);
    } else {
        free(entry);
        return NULL;
    }
    return entry;
}

void print_log_entry(LogEntry *entry) {
    printf("%s %s %d %s %s\n",
        entry->filename,
        entry->date,
        entry->pid,
        entry->level,
        entry->message);
}

int main(void) {
    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {
        LogEntry *entry = parse_log_line(line);
        if (entry != NULL) {
            print_log_entry(entry);
            free(entry);
            free(line);
            line = NULL;
        }
    }

    if (line) free(line);
    fclose(fp);
    return EXIT_SUCCESS;
}