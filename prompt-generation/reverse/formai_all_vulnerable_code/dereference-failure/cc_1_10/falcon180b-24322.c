//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_SIZE 1000

typedef struct {
    char ip[16];
    char method[10];
    char path[100];
    char user_agent[200];
    int status_code;
    char timestamp[30];
} log_entry;

int main() {
    FILE *log_file;
    char log_line[MAX_LOG_ENTRY_SIZE];
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;
    int i;

    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file\n");
        exit(1);
    }

    while (fgets(log_line, MAX_LOG_ENTRY_SIZE, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: Log file contains more than %d entries\n", MAX_LOG_ENTRIES);
            exit(1);
        }

        log_entry entry;
        strcpy(entry.ip, strtok(log_line, " "));
        strcpy(entry.method, strtok(NULL, " "));
        strcpy(entry.path, strtok(NULL, " "));
        strcpy(entry.user_agent, strtok(NULL, " "));
        entry.status_code = atoi(strtok(NULL, " "));
        strcpy(entry.timestamp, strtok(NULL, "\n"));

        strcat(entry.timestamp, " UTC");
        log_entries[num_entries++] = entry;
    }

    fclose(log_file);

    printf("Log analysis:\n");
    printf("Number of entries: %d\n", num_entries);
    printf("IP addresses:\n");
    for (i = 0; i < num_entries; i++) {
        printf("%s\n", log_entries[i].ip);
    }
    printf("Methods:\n");
    for (i = 0; i < num_entries; i++) {
        printf("%s\n", log_entries[i].method);
    }
    printf("Paths:\n");
    for (i = 0; i < num_entries; i++) {
        printf("%s\n", log_entries[i].path);
    }
    printf("User agents:\n");
    for (i = 0; i < num_entries; i++) {
        printf("%s\n", log_entries[i].user_agent);
    }
    printf("Status codes:\n");
    for (i = 0; i < num_entries; i++) {
        printf("%d\n", log_entries[i].status_code);
    }

    return 0;
}