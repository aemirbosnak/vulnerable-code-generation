//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 256

typedef struct {
    char ip[16];
    char method[10];
    char url[256];
    char status_code[10];
    char user_agent[256];
} LogEntry;

int main() {
    FILE *log_file;
    char log_line[MAX_LOG_ENTRY_SIZE];
    LogEntry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file\n");
        return 1;
    }

    while (fgets(log_line, MAX_LOG_ENTRY_SIZE, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: maximum number of log entries reached\n");
            fclose(log_file);
            return 1;
        }

        LogEntry entry;
        char *token;
        token = strtok(log_line, " ");
        strcpy(entry.ip, token);

        token = strtok(NULL, " ");
        strcpy(entry.method, token);

        token = strtok(NULL, " ");
        strcpy(entry.url, token);

        token = strtok(NULL, " ");
        strcpy(entry.status_code, token);

        token = strtok(NULL, " ");
        strcpy(entry.user_agent, token);

        log_entries[num_entries++] = entry;
    }

    fclose(log_file);

    printf("Number of log entries: %d\n", num_entries);

    printf("IP addresses:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", log_entries[i].ip);
    }

    printf("\nMethods:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", log_entries[i].method);
    }

    printf("\nURLs:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", log_entries[i].url);
    }

    printf("\nStatus codes:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", log_entries[i].status_code);
    }

    printf("\nUser agents:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\n", log_entries[i].user_agent);
    }

    return 0;
}