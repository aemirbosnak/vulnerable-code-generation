//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000

struct log_entry {
    char *ip_address;
    char *request_method;
    char *request_uri;
    int response_code;
};

void parse_log_entry(char *log_line, struct log_entry *entry) {
    char *token;
    int i = 0;

    // Extract IP address
    token = strtok(log_line, " ");
    entry->ip_address = malloc(strlen(token) + 1);
    strcpy(entry->ip_address, token);

    // Extract request method and URI
    token = strtok(NULL, " ");
    entry->request_method = malloc(strlen(token) + 1);
    strcpy(entry->request_method, token);

    token = strtok(NULL, " ");
    entry->request_uri = malloc(strlen(token) + 1);
    strcpy(entry->request_uri, token);

    // Extract response code
    token = strtok(NULL, "\n");
    entry->response_code = atoi(token);
}

void print_log_entry(struct log_entry *entry) {
    printf("IP address: %s\n", entry->ip_address);
    printf("Request method: %s\n", entry->request_method);
    printf("Request URI: %s\n", entry->request_uri);
    printf("Response code: %d\n\n", entry->response_code);
}

int main() {
    FILE *log_file;
    char log_line[1024];
    struct log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    // Open log file for reading
    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    // Read log entries from file
    while (fgets(log_line, sizeof(log_line), log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: Maximum number of log entries reached.\n");
            break;
        }

        parse_log_entry(log_line, &log_entries[num_entries]);
        num_entries++;
    }

    // Print log entries
    printf("Log entries:\n");
    for (int i = 0; i < num_entries; i++) {
        print_log_entry(&log_entries[i]);
    }

    // Close log file
    fclose(log_file);

    return 0;
}