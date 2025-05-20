//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define LOG_FILE "intrusion_detection.log"

typedef struct {
    char ip[16];
    char user_agent[64];
    char url[256];
    time_t timestamp;
} LogEntry;

void log_entry(LogEntry* entry) {
    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    fprintf(log_file, "%s - %s - %s - %ld\n", entry->ip, entry->user_agent, entry->url, entry->timestamp);
    fclose(log_file);
}

int main() {
    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    while (1) {
        LogEntry new_entry;
        memset(&new_entry, 0, sizeof(LogEntry));

        printf("Enter IP address: ");
        scanf("%s", new_entry.ip);

        printf("Enter user agent: ");
        scanf("%s", new_entry.user_agent);

        printf("Enter URL: ");
        scanf("%s", new_entry.url);

        time_t now = time(NULL);
        new_entry.timestamp = now;

        log_entry(&new_entry);

        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Log is full. Exiting...\n");
            break;
        }

        num_entries++;
    }

    return 0;
}