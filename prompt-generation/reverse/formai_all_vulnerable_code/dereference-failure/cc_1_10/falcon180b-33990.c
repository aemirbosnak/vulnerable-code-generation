//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINE_LENGTH 1024
#define MAX_LOG_FILE_SIZE 1000000

struct log_entry {
    char *ip_address;
    char *timestamp;
    char *request_url;
    int response_code;
};

struct log_entry *parse_log_line(char *log_line) {
    struct log_entry *entry = malloc(sizeof(struct log_entry));
    char *token = strtok(log_line, " ");
    entry->ip_address = strdup(token);
    token = strtok(NULL, " ");
    entry->timestamp = strdup(token);
    token = strtok(NULL, " ");
    entry->request_url = strdup(token);
    token = strtok(NULL, " ");
    entry->response_code = atoi(token);
    return entry;
}

void print_log_entry(struct log_entry *entry) {
    printf("IP Address: %s\n", entry->ip_address);
    printf("Timestamp: %s\n", entry->timestamp);
    printf("Request URL: %s\n", entry->request_url);
    printf("Response Code: %d\n\n", entry->response_code);
}

int main() {
    FILE *log_file;
    char log_line[MAX_LOG_LINE_LENGTH];
    struct log_entry *entries = NULL;
    int entry_count = 0;

    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    while (fgets(log_line, MAX_LOG_LINE_LENGTH, log_file)!= NULL) {
        struct log_entry *entry = parse_log_line(log_line);
        if (entry_count >= MAX_LOG_FILE_SIZE) {
            printf("Error: Log file is too large.\n");
            exit(1);
        }
        entries = realloc(entries, sizeof(struct log_entry) * ++entry_count);
        entries[entry_count - 1] = *entry;
        free(entry);
    }

    fclose(log_file);

    for (int i = 0; i < entry_count; i++) {
        print_log_entry(&entries[i]);
    }

    free(entries);
    return 0;
}