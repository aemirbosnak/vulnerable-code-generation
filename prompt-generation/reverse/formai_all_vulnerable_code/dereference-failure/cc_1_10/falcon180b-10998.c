//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1024

struct log_entry {
    char *ip_address;
    char *date_time;
    char *request_type;
    char *request_url;
    int response_code;
};

struct log_entry log_entries[MAX_LOG_ENTRIES];
int num_log_entries = 0;

void parse_log_entry(const char *log_line) {
    char *ip_address = strtok(log_line, " ");
    char *date_time = strtok(NULL, " ");
    char *request_type = strtok(NULL, " ");
    char *request_url = strtok(NULL, " ");
    int response_code = atoi(strtok(NULL, " "));

    struct log_entry entry = {
       .ip_address = strdup(ip_address),
       .date_time = strdup(date_time),
       .request_type = strdup(request_type),
       .request_url = strdup(request_url),
       .response_code = response_code
    };

    if (num_log_entries < MAX_LOG_ENTRIES) {
        log_entries[num_log_entries] = entry;
        num_log_entries++;
    }
}

void print_log_entries() {
    for (int i = 0; i < num_log_entries; i++) {
        printf("IP Address: %s\n", log_entries[i].ip_address);
        printf("Date/Time: %s\n", log_entries[i].date_time);
        printf("Request Type: %s\n", log_entries[i].request_type);
        printf("Request URL: %s\n", log_entries[i].request_url);
        printf("Response Code: %d\n\n", log_entries[i].response_code);
    }
}

int main() {
    FILE *log_file = fopen("logfile.txt", "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char log_line[MAX_LOG_ENTRY_LENGTH];

    while (fgets(log_line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        parse_log_entry(log_line);
    }

    fclose(log_file);

    print_log_entries();

    return 0;
}