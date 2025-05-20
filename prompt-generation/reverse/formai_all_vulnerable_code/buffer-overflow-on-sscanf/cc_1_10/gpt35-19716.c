//FormAI DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
/*
 * C Log Analysis Program 
 * By: Donald Knuth
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 10000

/* Log entry struct */
typedef struct {
    int timestamp;
    char message[256];
} LogEntry;

/* Function to read log entries from file */
void read_log_entries(LogEntry *log_entries, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    char buffer[256];
    int i = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        LogEntry entry;
        sscanf(buffer, "%d %s", &entry.timestamp, entry.message);
        log_entries[i++] = entry;
    }

    fclose(fp);
}

/* Function to print log entries */
void print_log_entries(LogEntry *log_entries, int num_entries) {
    printf("Log Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d %s\n", log_entries[i].timestamp, log_entries[i].message);
    }
}

/* Function to filter log entries by message substring */
int filter_log_entries(LogEntry *log_entries, int num_entries, char *substring) {
    int count = 0;

    for (int i = 0; i < num_entries; i++) {
        if (strstr(log_entries[i].message, substring) != NULL) {
            count++;
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries;
    char substring[256];
    int count;

    if (argc < 3) {
        printf("Usage: %s log_file message_substring\n", argv[0]);
        exit(1);
    }

    read_log_entries(log_entries, argv[1]);
    num_entries = sizeof(log_entries) / sizeof(log_entries[0]);

    print_log_entries(log_entries, num_entries);

    strcpy(substring, argv[2]);
    count = filter_log_entries(log_entries, num_entries, substring);

    printf("\n%d log entries contain the message '%s'\n", count, substring);

    return 0;
}