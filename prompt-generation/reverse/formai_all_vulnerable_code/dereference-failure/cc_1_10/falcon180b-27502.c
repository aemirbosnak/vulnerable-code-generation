//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1000

typedef struct {
    char *ip_address;
    char *date_time;
    char *request_method;
    char *request_url;
    int response_code;
} log_entry;

log_entry log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

void parse_log_file(char *filename) {
    FILE *log_file;
    char line[MAX_LOG_ENTRY_LENGTH];
    log_entry entry;

    log_file = fopen(filename, "r");
    if (log_file == NULL) {
        printf("error: could not open log file %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), log_file)!= NULL) {
        if (num_log_entries >= MAX_LOG_ENTRIES) {
            printf("error: log file is too large\n");
            exit(1);
        }

        entry.ip_address = strtok(line, " ");
        entry.date_time = strtok(NULL, " ");
        entry.request_method = strtok(NULL, " ");
        entry.request_url = strtok(NULL, " ");
        entry.response_code = atoi(strtok(NULL, " "));

        strcpy(log_entries[num_log_entries].ip_address, entry.ip_address);
        strcpy(log_entries[num_log_entries].date_time, entry.date_time);
        strcpy(log_entries[num_log_entries].request_method, entry.request_method);
        strcpy(log_entries[num_log_entries].request_url, entry.request_url);
        log_entries[num_log_entries].response_code = entry.response_code;

        num_log_entries++;
    }

    fclose(log_file);
}

void print_log_entries() {
    int i;

    printf("ip address\tdate and time\tmethod\turl\tresponse code\n");
    for (i = 0; i < num_log_entries; i++) {
        printf("%-15s %-30s %-8s %-30s %d\n",
               log_entries[i].ip_address,
               log_entries[i].date_time,
               log_entries[i].request_method,
               log_entries[i].request_url,
               log_entries[i].response_code);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("usage: %s log_file\n", argv[0]);
        exit(1);
    }

    parse_log_file(argv[1]);
    print_log_entries();

    return 0;
}