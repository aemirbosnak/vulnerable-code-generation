//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1000

typedef struct {
    char ip_address[16];
    char date[20];
    char time[20];
    char request[MAX_LOG_ENTRY_LENGTH];
} LogEntry;

void parse_log_file(FILE *log_file, LogEntry *entries, int *entry_count) {
    char line[MAX_LOG_ENTRY_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        char *token = strtok(line, " ");
        strcpy(entries[i].ip_address, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].date, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].time, token);

        token = strtok(NULL, " ");
        strcpy(entries[i].request, token);

        i++;
        if (i >= MAX_LOG_ENTRIES) {
            break;
        }
    }

    *entry_count = i;
}

void print_log_entries(LogEntry *entries, int entry_count) {
    for (int i = 0; i < entry_count; i++) {
        printf("IP Address: %s\nDate: %s\nTime: %s\nRequest: %s\n\n", entries[i].ip_address, entries[i].date, entries[i].time, entries[i].request);
    }
}

int main() {
    FILE *log_file;
    char log_file_path[100];
    printf("Enter the path of the log file: ");
    scanf("%s", log_file_path);

    log_file = fopen(log_file_path, "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    LogEntry entries[MAX_LOG_ENTRIES];
    int entry_count = 0;

    parse_log_file(log_file, entries, &entry_count);

    printf("Number of log entries: %d\n", entry_count);
    print_log_entries(entries, entry_count);

    fclose(log_file);

    return 0;
}