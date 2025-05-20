//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define LOG_FILE "log.txt"

typedef struct {
    char ip[16];
    char method[10];
    char url[256];
    char user_agent[256];
    time_t timestamp;
} log_entry_t;

int read_log_file(log_entry_t *log_entries, int max_entries) {
    FILE *fp = fopen(LOG_FILE, "r");
    if (fp == NULL) {
        printf("Error: could not open log file.\n");
        return -1;
    }

    int num_entries = 0;
    while (num_entries < max_entries && fscanf(fp, "%s %s %s %s %ld\n", log_entries[num_entries].ip, log_entries[num_entries].method, log_entries[num_entries].url, log_entries[num_entries].user_agent, &log_entries[num_entries].timestamp)!= EOF) {
        num_entries++;
    }

    fclose(fp);
    return num_entries;
}

void print_log_entries(log_entry_t *log_entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s %s %s\n", log_entries[i].ip, log_entries[i].method, log_entries[i].url, log_entries[i].user_agent, ctime(&log_entries[i].timestamp));
    }
}

int main() {
    log_entry_t log_entries[MAX_LOG_ENTRIES];
    int num_entries = read_log_file(log_entries, MAX_LOG_ENTRIES);

    if (num_entries > 0) {
        printf("Log entries:\n");
        print_log_entries(log_entries, num_entries);
    } else {
        printf("No log entries found.\n");
    }

    return 0;
}