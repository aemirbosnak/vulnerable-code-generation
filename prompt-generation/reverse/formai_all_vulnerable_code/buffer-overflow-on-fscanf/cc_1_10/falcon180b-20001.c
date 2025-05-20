//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    char ip[16];
    char date[32];
    char method[16];
    char url[2048];
    char user_agent[2048];
} log_entry_t;

int compare_log_entries(const void *a, const void *b) {
    const log_entry_t *entry_a = (const log_entry_t *)a;
    const log_entry_t *entry_b = (const log_entry_t *)b;

    if (strcmp(entry_a->ip, entry_b->ip) == 0) {
        return 0;
    }

    return strcmp(entry_a->ip, entry_b->ip);
}

void log_entry_print(const log_entry_t *entry) {
    printf("IP: %s\n", entry->ip);
    printf("Date: %s\n", entry->date);
    printf("Method: %s\n", entry->method);
    printf("URL: %s\n", entry->url);
    printf("User-Agent: %s\n\n", entry->user_agent);
}

int main() {
    FILE *log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    log_entry_t log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    while (fscanf(log_file, "%15s %31s %15s %2047s %2047s\n",
                  &log_entries[num_entries].ip,
                  &log_entries[num_entries].date,
                  &log_entries[num_entries].method,
                  &log_entries[num_entries].url,
                  &log_entries[num_entries].user_agent) == 5) {
        num_entries++;

        if (num_entries >= MAX_LOG_ENTRIES) {
            break;
        }
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(log_entry_t), compare_log_entries);

    for (int i = 0; i < num_entries; i++) {
        log_entry_print(&log_entries[i]);
    }

    return 0;
}