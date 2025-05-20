//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 10000
#define MAX_LOG_ENTRY_LENGTH 512

struct log_entry {
    char ip_address[16];
    char date_time[32];
    char request_type[32];
    char requested_url[MAX_LOG_ENTRY_LENGTH];
};

int compare_log_entries(const void *a, const void *b) {
    const struct log_entry *entry_a = (const struct log_entry *)a;
    const struct log_entry *entry_b = (const struct log_entry *)b;

    if (strcmp(entry_a->requested_url, entry_b->requested_url) == 0) {
        return 0;
    } else if (strcmp(entry_a->requested_url, entry_b->requested_url) < 0) {
        return -1;
    } else {
        return 1;
    }
}

int main() {
    FILE *log_file;
    struct log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;
    char line[MAX_LOG_ENTRY_LENGTH];

    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Log file contains more than %d entries.\n", MAX_LOG_ENTRIES);
            exit(1);
        }

        struct log_entry *entry = &log_entries[num_entries];
        sscanf(line, "%15s %30s %15s %s", entry->ip_address, entry->date_time, entry->request_type, entry->requested_url);
        num_entries++;
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(struct log_entry), compare_log_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s %s\n", log_entries[i].ip_address, log_entries[i].date_time, log_entries[i].request_type, log_entries[i].requested_url);
    }

    return 0;
}