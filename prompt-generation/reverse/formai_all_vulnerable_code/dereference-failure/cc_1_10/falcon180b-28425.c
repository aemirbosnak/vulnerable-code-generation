//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 1024

typedef struct {
    char ip[16];
    char method[8];
    char url[256];
    char user_agent[512];
    time_t timestamp;
} log_entry_t;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    log_entry_t log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char line[MAX_LOG_ENTRY_SIZE];
    while (fgets(line, MAX_LOG_ENTRY_SIZE, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: log file is too large.\n");
            fclose(log_file);
            return 1;
        }

        log_entry_t *entry = &log_entries[num_entries++];
        char *token = strtok(line, " ");
        strcpy(entry->ip, token);

        token = strtok(NULL, " ");
        strcpy(entry->method, token);

        token = strtok(NULL, " ");
        strcpy(entry->url, token);

        token = strtok(NULL, " ");
        strcpy(entry->user_agent, token);

        entry->timestamp = time(NULL);
    }

    fclose(log_file);

    printf("Number of entries: %d\n", num_entries);

    for (int i = 0; i < num_entries; i++) {
        log_entry_t *entry = &log_entries[i];
        printf("Entry %d:\n", i+1);
        printf("IP: %s\n", entry->ip);
        printf("Method: %s\n", entry->method);
        printf("URL: %s\n", entry->url);
        printf("User agent: %s\n", entry->user_agent);
        printf("Timestamp: %s\n\n", ctime(&entry->timestamp));
    }

    return 0;
}