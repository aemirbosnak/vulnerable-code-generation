//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_LOG_ENTRIES 1000

typedef struct {
    char ip_address[16];
    char request_method[10];
    char request_path[1024];
    int status_code;
    int bytes_sent;
} log_entry;

log_entry log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

void log_entry_parser(char* line) {
    char* token;
    token = strtok(line, " ");
    strcpy(log_entries[num_log_entries].ip_address, token);
    token = strtok(NULL, " ");
    strcpy(log_entries[num_log_entries].request_method, token);
    token = strtok(NULL, " ");
    strcpy(log_entries[num_log_entries].request_path, token);
    token = strtok(NULL, " ");
    log_entries[num_log_entries].status_code = atoi(token);
    token = strtok(NULL, " ");
    log_entries[num_log_entries].bytes_sent = atoi(token);
    num_log_entries++;
}

void print_log_entry(log_entry entry) {
    printf("IP Address: %s\n", entry.ip_address);
    printf("Request Method: %s\n", entry.request_method);
    printf("Request Path: %s\n", entry.request_path);
    printf("Status Code: %d\n", entry.status_code);
    printf("Bytes Sent: %d\n\n", entry.bytes_sent);
}

void print_log_entries() {
    int i;
    for (i = 0; i < num_log_entries; i++) {
        print_log_entry(log_entries[i]);
    }
}

int main() {
    FILE* log_file;
    char line[MAX_LINE_LENGTH];
    log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }
    while (fgets(line, MAX_LINE_LENGTH, log_file)!= NULL) {
        log_entry_parser(line);
    }
    fclose(log_file);
    print_log_entries();
    return 0;
}