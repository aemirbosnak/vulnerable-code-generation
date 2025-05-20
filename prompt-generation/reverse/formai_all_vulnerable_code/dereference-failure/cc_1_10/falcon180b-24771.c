//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    time_t timestamp;
    char ip[16];
    char method[8];
    char url[1024];
    int response_code;
} log_entry_t;

int compare_log_entries(const void *a, const void *b) {
    const log_entry_t *entry1 = a;
    const log_entry_t *entry2 = b;

    if (entry1->timestamp > entry2->timestamp) {
        return -1;
    } else if (entry1->timestamp < entry2->timestamp) {
        return 1;
    } else {
        return 0;
    }
}

void print_log_entry(const log_entry_t *entry) {
    char timestamp_str[32];
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", gmtime(&entry->timestamp));

    printf("%s - %s %s %s (%d)\n", timestamp_str, entry->ip, entry->method, entry->url, entry->response_code);
}

int main() {
    FILE *log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file.\n");
        exit(1);
    }

    log_entry_t log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    while (fscanf(log_file, "%s %s %s [%d]", log_entries[num_entries].ip, log_entries[num_entries].method, log_entries[num_entries].url, &log_entries[num_entries].response_code) == 4) {
        if (num_entries >= MAX_LOG_ENTRIES) {
            fprintf(stderr, "Maximum number of log entries reached.\n");
            break;
        }

        time_t timestamp = time(NULL);
        strncpy(log_entries[num_entries].timestamp, ctime(&timestamp), sizeof(log_entries[num_entries].timestamp));
        num_entries++;
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(log_entry_t), compare_log_entries);

    for (int i = 0; i < num_entries; i++) {
        print_log_entry(&log_entries[i]);
    }

    return 0;
}