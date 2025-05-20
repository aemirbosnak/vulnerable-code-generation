//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define LOG_FILE "logs.txt"

typedef struct {
    char method[10];
    char status[5];
    char user_agent[50];
    char remote_addr[20];
    char request[MAX_LINE_LENGTH];
} log_entry;

void process_log(log_entry entry) {
    int status_code;

    sscanf(entry.status, "%d", &status_code);

    if (status_code >= 400) {
        printf("ERROR: %s %s from %s with status code %d\n", entry.method, entry.request, entry.remote_addr, status_code);
    } else {
        printf("INFO: %s %s from %s with status code %d\n", entry.method, entry.request, entry.remote_addr, status_code);
    }

    // Perform any additional analysis here
}

int main() {
    FILE *log_file;
    log_entry current_entry;

    log_file = fopen(LOG_FILE, "r");

    if (log_file == NULL) {
        printf("ERROR: Unable to open log file %s\n", LOG_FILE);
        return 1;
    }

    while (fgets(current_entry.request, MAX_LINE_LENGTH, log_file)) {
        sscanf(current_entry.request, "%s %s %s %s %s", current_entry.method, current_entry.status, current_entry.user_agent, current_entry.remote_addr, &current_entry.request[strlen(current_entry.request)]);
        process_log(current_entry);
    }

    fclose(log_file);

    return 0;
}