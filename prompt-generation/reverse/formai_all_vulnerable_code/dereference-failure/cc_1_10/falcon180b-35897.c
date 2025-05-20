//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 1024

struct log_entry {
    char ip[16];
    char method[8];
    char url[256];
    char user_agent[512];
    time_t timestamp;
};

void parse_log_entry(char* line, struct log_entry* entry) {
    char* token = strtok(line, " ");
    strcpy(entry->ip, token);

    token = strtok(NULL, " ");
    strcpy(entry->method, token);

    token = strtok(NULL, " ");
    strcpy(entry->url, token);

    token = strtok(NULL, " ");
    strcpy(entry->user_agent, token);

    entry->timestamp = time(NULL);
}

int compare_log_entries(const void* a, const void* b) {
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

void print_log_entry(const struct log_entry* entry) {
    printf("%s - %s %s\n", entry->ip, entry->method, entry->url);
}

int main() {
    FILE* log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    struct log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    char line[MAX_LOG_ENTRY_SIZE];
    while (fgets(line, MAX_LOG_ENTRY_SIZE, log_file)!= NULL) {
        parse_log_entry(line, &log_entries[num_entries]);
        num_entries++;
    }

    fclose(log_file);

    qsort(log_entries, num_entries, sizeof(struct log_entry), compare_log_entries);

    printf("Log entries sorted by timestamp:\n");
    for (int i = 0; i < num_entries; i++) {
        print_log_entry(&log_entries[i]);
    }

    return 0;
}