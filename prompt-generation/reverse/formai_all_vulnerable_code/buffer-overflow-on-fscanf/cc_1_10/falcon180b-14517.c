//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000

struct log_entry {
    time_t timestamp;
    char ip[16];
    char method[10];
    char url[256];
    int status_code;
};

void log_entry_init(struct log_entry* entry) {
    memset(entry, 0, sizeof(struct log_entry));
}

int log_entry_compare(const void* a, const void* b) {
    const struct log_entry* entry_a = (const struct log_entry*)a;
    const struct log_entry* entry_b = (const struct log_entry*)b;

    if (entry_a->timestamp > entry_b->timestamp) {
        return -1;
    } else if (entry_a->timestamp < entry_b->timestamp) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE* log_file = fopen("logfile.txt", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }

    struct log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    while (fscanf(log_file, "%s %s %s %d\n", log_entries[num_entries].ip, log_entries[num_entries].method, log_entries[num_entries].url, &log_entries[num_entries].status_code) == 4) {
        time_t timestamp = time(NULL);
        strftime(log_entries[num_entries].timestamp, sizeof(log_entries[num_entries].timestamp), "%Y-%m-%d %H:%M:%S", localtime(&timestamp));
        num_entries++;

        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Warning: Reached maximum number of log entries.\n");
            break;
        }
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(struct log_entry), log_entry_compare);

    printf("Log entries sorted by timestamp:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s %d\n", log_entries[i].timestamp, log_entries[i].ip, log_entries[i].method, log_entries[i].status_code);
    }

    return 0;
}