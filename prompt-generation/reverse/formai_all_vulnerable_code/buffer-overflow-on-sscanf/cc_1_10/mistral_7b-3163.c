//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 4096
#define LOG_FILE "happy_log.txt"

struct LogEntry {
    char timestamp[20];
    char level[10];
    char message[MAX_LINE_LENGTH];
};

void parse_log_line(const char *line, struct LogEntry *entry) {
    sscanf(line, "%s %s %s", entry->timestamp, entry->level, entry->message);
}

int main(void) {
    FILE *file;
    size_t len;
    char line[MAX_LINE_LENGTH];
    struct LogEntry log_entry;

    file = fopen(LOG_FILE, "r");

    if (file == NULL) {
        perror("Error opening log file");
        return 1;
    }

    printf("\n===== WELCOME TO THE HAPPY LOG ANALYZER =====\n");
    printf("===========================================\n");

    while (fgets(line, sizeof(line), file) != NULL) {
        parse_log_line(line, &log_entry);

        if (strcmp(log_entry.level, "INFO") == 0) {
            printf("\n[INFO] %s: %s\n", log_entry.timestamp, log_entry.message);
        } else if (strcmp(log_entry.level, "WARNING") == 0) {
            printf("\n[WARNING] %s: %s\n", log_entry.timestamp, log_entry.message);
            printf("\n===========================================\n");
            printf(" Let's check this out, shall we?\n");
        } else if (strcmp(log_entry.level, "ERROR") == 0) {
            printf("\n[ERROR] %s: %s\n", log_entry.timestamp, log_entry.message);
            printf("\n===========================================\n");
            printf(" Oh noes! This doesn't look good!\n");
        } else {
            printf("\n[UNKNOWN] %s: %s\n", log_entry.timestamp, log_entry.message);
        }

        memset(&log_entry, 0, sizeof(log_entry));
    }

    fclose(file);
    printf("\n===== HAPPY LOG ANALYZING IS DONE! =====\n");

    return 0;
}