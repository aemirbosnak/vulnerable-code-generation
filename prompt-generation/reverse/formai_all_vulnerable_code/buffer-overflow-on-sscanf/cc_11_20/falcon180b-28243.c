//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LOG_FILE "log.txt"
#define MAX_LINE_LENGTH 1000

typedef struct {
    char ip[16];
    char date[20];
    char time[10];
    char request[100];
    int status_code;
} log_entry;

int main() {
    FILE *log_file;
    char line[MAX_LINE_LENGTH];
    int num_entries = 0;
    log_entry entries[1000];

    log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        if (num_entries >= 1000) {
            printf("Maximum number of entries reached\n");
            break;
        }

        log_entry entry;
        sscanf(line, "%15s %19s %9s %99s %d", entry.ip, entry.date, entry.time, entry.request, &entry.status_code);
        strcpy(entry.ip + strlen(entry.ip), "\0");
        strcpy(entry.date + strlen(entry.date), "\0");
        strcpy(entry.time + strlen(entry.time), "\0");
        strcpy(entry.request + strlen(entry.request), "\0");

        entries[num_entries++] = entry;
    }

    fclose(log_file);

    printf("Total number of entries: %d\n", num_entries);

    int num_requests = 0;
    int num_responses = 0;
    int num_errors = 0;
    int num_redirects = 0;

    for (int i = 0; i < num_entries; i++) {
        if (entries[i].status_code >= 200 && entries[i].status_code < 300) {
            num_responses++;
        } else if (entries[i].status_code >= 300 && entries[i].status_code < 400) {
            num_redirects++;
        } else if (entries[i].status_code >= 400 && entries[i].status_code < 500) {
            num_errors++;
        } else if (entries[i].status_code >= 500 && entries[i].status_code < 600) {
            num_responses++;
        }

        num_requests++;
    }

    printf("Number of requests: %d\n", num_requests);
    printf("Number of responses: %d\n", num_responses);
    printf("Number of errors: %d\n", num_errors);
    printf("Number of redirects: %d\n", num_redirects);

    return 0;
}