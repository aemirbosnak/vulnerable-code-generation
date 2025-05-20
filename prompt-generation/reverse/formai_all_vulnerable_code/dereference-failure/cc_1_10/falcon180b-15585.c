//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LINE_LENGTH 2048

typedef struct {
    char ip[16];
    char date[20];
    char time[8];
    char request[MAX_LINE_LENGTH];
    char status[10];
    char user_agent[MAX_LINE_LENGTH];
} LOG_ENTRY;

int main() {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];
    char *token;
    LOG_ENTRY entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: Maximum number of log entries reached.\n");
            exit(1);
        }

        token = strtok(line, " ");
        strcpy(entries[num_entries].ip, token);

        token = strtok(NULL, " ");
        strcpy(entries[num_entries].date, token);

        token = strtok(NULL, " ");
        strcpy(entries[num_entries].time, token);

        token = strtok(NULL, " ");
        strcpy(entries[num_entries].request, token);

        token = strtok(NULL, " ");
        strcpy(entries[num_entries].status, token);

        token = strtok(NULL, " ");
        strcpy(entries[num_entries].user_agent, token);

        num_entries++;
    }

    fclose(log_file);

    printf("Number of log entries: %d\n", num_entries);

    printf("IP\tDate\tTime\tRequest\tStatus\tUser Agent\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", entries[i].ip, entries[i].date, entries[i].time, entries[i].request, entries[i].status, entries[i].user_agent);
    }

    return 0;
}