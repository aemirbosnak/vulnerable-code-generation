//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 4096
#define NUM_FIELDS 5

typedef struct {
    char timestamp[20];
    char level[10];
    char thread_name[32];
    char message[MAX_LINE_SIZE];
} LogEntry;

void parse_log_line(char *line, LogEntry *entry) {
    sscanf(line, "%s %s %s %[^:]:%s", entry->timestamp, entry->level, entry->thread_name, entry->message, entry->message + strlen(entry->message) - strlen(strrchr(entry->message, ':')));
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    char line[MAX_LINE_SIZE];
    LogEntry entry;

    int total_entries = 0;
    int errors = 0;

    while (fgets(line, sizeof(line), fp)) {
        parse_log_line(line, &entry);

        if (strcmp(entry.level, "ERROR") == 0) {
            errors++;
        }

        printf("[%s] [%s] [%s] %s\n", entry.timestamp, entry.level, entry.thread_name, entry.message);

        total_entries++;
    }

    fclose(fp);

    printf("Total log entries: %d\n", total_entries);
    printf("Errors: %d\n", errors);

    return 0;
}