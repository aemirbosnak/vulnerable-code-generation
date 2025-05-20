//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
/*
 * C Program to Analyze Log Files
 *
 * Author: Linus Torvalds
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char line[MAX_LINE_LENGTH];
    char timestamp[10];
    char log_level[10];
    char message[MAX_LINE_LENGTH];
} log_entry;

int main() {
    FILE *log_file;
    log_entry entries[MAX_LOG_ENTRIES];
    int i, j, num_entries = 0;

    log_file = fopen("log.txt", "r");
    if (log_file == NULL) {
        printf("Error: Unable to open log file\n");
        return 1;
    }

    while (fgets(entries[num_entries].line, MAX_LINE_LENGTH, log_file) != NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: Too many log entries\n");
            break;
        }

        // Extract timestamp and log level
        sscanf(entries[num_entries].line, "%s %s %[^\n]", entries[num_entries].timestamp, entries[num_entries].log_level, entries[num_entries].message);

        num_entries++;
    }

    // Sort log entries by timestamp
    for (i = 0; i < num_entries - 1; i++) {
        for (j = i + 1; j < num_entries; j++) {
            if (strcmp(entries[i].timestamp, entries[j].timestamp) > 0) {
                log_entry temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }

    // Print log entries
    for (i = 0; i < num_entries; i++) {
        printf("%s %s %s\n", entries[i].timestamp, entries[i].log_level, entries[i].message);
    }

    fclose(log_file);
    return 0;
}