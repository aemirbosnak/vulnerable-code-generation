//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_FILE_SIZE (1024 * 1024 * 10) // 10MB
#define MAX_NUM_OF_LINES 10000

typedef struct {
    char *ip_address;
    char *date_time;
    char *request_url;
    char *response_code;
} log_entry_t;

log_entry_t log_entries[MAX_NUM_OF_LINES];
int num_of_log_entries = 0;

void parse_log_file(char *log_file_path) {
    FILE *fp = fopen(log_file_path, "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_of_log_entries >= MAX_NUM_OF_LINES) {
            printf("Error: Maximum number of log entries reached.\n");
            fclose(fp);
            exit(1);
        }

        char *ip_address = strtok(line, " ");
        char *date_time = strtok(NULL, " ");
        char *request_url = strtok(NULL, " ");
        char *response_code = strtok(NULL, " ");

        if (ip_address == NULL || date_time == NULL || request_url == NULL || response_code == NULL) {
            continue;
        }

        log_entry_t entry = {
           .ip_address = strdup(ip_address),
           .date_time = strdup(date_time),
           .request_url = strdup(request_url),
           .response_code = strdup(response_code)
        };
        log_entries[num_of_log_entries++] = entry;
    }

    fclose(fp);
}

void print_log_entries() {
    printf("IP Address\tDate and Time\tRequest URL\tResponse Code\n");
    for (int i = 0; i < num_of_log_entries; i++) {
        printf("%s\t%s\t%s\t%s\n", log_entries[i].ip_address, log_entries[i].date_time, log_entries[i].request_url, log_entries[i].response_code);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s log_file_path\n", argv[0]);
        return 1;
    }

    char *log_file_path = argv[1];
    if (strlen(log_file_path) >= MAX_LOG_FILE_SIZE) {
        printf("Error: Log file path is too long.\n");
        return 1;
    }

    parse_log_file(log_file_path);
    print_log_entries();

    for (int i = 0; i < num_of_log_entries; i++) {
        free(log_entries[i].ip_address);
        free(log_entries[i].date_time);
        free(log_entries[i].request_url);
        free(log_entries[i].response_code);
    }

    return 0;
}