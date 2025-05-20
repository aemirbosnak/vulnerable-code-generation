//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1000

typedef struct {
    char ip[16];
    char date[20];
    char method[10];
    char url[100];
    int status_code;
} log_entry;

int main() {
    FILE *log_file;
    char log_buffer[MAX_LOG_ENTRY_LENGTH];
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;
    int i;

    log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        exit(1);
    }

    while (fgets(log_buffer, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        if (num_entries == MAX_LOG_ENTRIES) {
            printf("Error: log file contains more than %d entries.\n", MAX_LOG_ENTRIES);
            fclose(log_file);
            exit(1);
        }

        if (sscanf(log_buffer, "%15s %19s %9s %99s %d", log_entries[num_entries].ip, log_entries[num_entries].date, log_entries[num_entries].method, log_entries[num_entries].url, &log_entries[num_entries].status_code)!= 5) {
            printf("Error: could not parse log entry.\n");
            fclose(log_file);
            exit(1);
        }

        num_entries++;
    }

    fclose(log_file);

    printf("Log file analysis:\n");
    printf("--------------------\n");

    printf("Total number of entries: %d\n", num_entries);

    int num_200s = 0;
    int num_404s = 0;
    int num_other_status_codes = 0;

    for (i = 0; i < num_entries; i++) {
        if (log_entries[i].status_code == 200) {
            num_200s++;
        } else if (log_entries[i].status_code == 404) {
            num_404s++;
        } else {
            num_other_status_codes++;
        }
    }

    printf("Number of 200 status codes: %d\n", num_200s);
    printf("Number of 404 status codes: %d\n", num_404s);
    printf("Number of other status codes: %d\n", num_other_status_codes);

    return 0;
}