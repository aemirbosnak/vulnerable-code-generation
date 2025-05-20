//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 512

typedef struct {
    char ip[16];
    char date[20];
    char method[10];
    char url[1024];
    int status_code;
} log_entry_t;

int main() {
    FILE *log_file;
    char log_filename[100];
    char line[MAX_LOG_ENTRY_LENGTH];
    log_entry_t log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    printf("Enter the name of the log file: ");
    scanf("%s", log_filename);

    log_file = fopen(log_filename, "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: Reached maximum number of log entries.\n");
            exit(1);
        }

        char *token = strtok(line, " ");
        strcpy(log_entries[num_entries].ip, token);

        token = strtok(NULL, " ");
        strcpy(log_entries[num_entries].date, token);

        token = strtok(NULL, " ");
        strcpy(log_entries[num_entries].method, token);

        token = strtok(NULL, " ");
        strcpy(log_entries[num_entries].url, token);

        token = strtok(NULL, " ");
        log_entries[num_entries].status_code = atoi(token);

        num_entries++;
    }

    fclose(log_file);

    printf("Number of log entries: %d\n", num_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("IP: %s\n", log_entries[i].ip);
        printf("Date: %s\n", log_entries[i].date);
        printf("Method: %s\n", log_entries[i].method);
        printf("URL: %s\n", log_entries[i].url);
        printf("Status code: %d\n\n", log_entries[i].status_code);
    }

    return 0;
}