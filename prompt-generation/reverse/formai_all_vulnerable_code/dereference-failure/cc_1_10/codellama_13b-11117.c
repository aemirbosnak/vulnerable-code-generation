//Code Llama-13B DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LINE_LENGTH 100

typedef struct {
    char timestamp[30];
    char level[10];
    char message[MAX_LOG_LINE_LENGTH];
} LogEntry;

void print_log_entry(LogEntry* entry) {
    printf("%s - %s: %s\n", entry->timestamp, entry->level, entry->message);
}

void print_log_entries(LogEntry* entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        print_log_entry(&entries[i]);
    }
}

int main() {
    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    while (1) {
        char line[MAX_LOG_LINE_LENGTH];
        fgets(line, sizeof(line), stdin);

        if (strlen(line) == 0) {
            break;
        }

        char* timestamp = strtok(line, " ");
        char* level = strtok(NULL, " ");
        char* message = strtok(NULL, "\n");

        if (num_entries < MAX_LOG_ENTRIES) {
            strcpy(entries[num_entries].timestamp, timestamp);
            strcpy(entries[num_entries].level, level);
            strcpy(entries[num_entries].message, message);
            num_entries++;
        } else {
            printf("Maximum number of log entries reached.\n");
        }
    }

    print_log_entries(entries, num_entries);

    return 0;
}