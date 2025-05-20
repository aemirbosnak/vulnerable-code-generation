//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 10000
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    char *ip_address;
    char *url;
    char *user_agent;
} LogEntry;

int compare_log_entries(const void *a, const void *b) {
    const LogEntry *entry_a = (const LogEntry *)a;
    const LogEntry *entry_b = (const LogEntry *)b;

    if (strcmp(entry_a->ip_address, entry_b->ip_address) == 0) {
        return 0;
    } else if (strcmp(entry_a->ip_address, entry_b->ip_address) < 0) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    FILE *log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char line[MAX_LOG_ENTRY_LENGTH];
    while (fgets(line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Warning: log file contains more than %d entries, truncating.\n", MAX_LOG_ENTRIES);
            break;
        }

        char *ip_address = strtok(line, " ");
        char *url = strtok(NULL, " ");
        char *user_agent = strtok(NULL, "\n");

        LogEntry entry = {
           .ip_address = strdup(ip_address),
           .url = strdup(url),
           .user_agent = strdup(user_agent)
        };
        log_entries[num_entries++] = entry;
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(LogEntry), compare_log_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s\n", log_entries[i].ip_address, log_entries[i].url, log_entries[i].user_agent);
    }

    for (int i = 0; i < num_entries; i++) {
        free(log_entries[i].ip_address);
        free(log_entries[i].url);
        free(log_entries[i].user_agent);
    }

    return 0;
}