//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_LINES 100000
#define MAX_WORD_LENGTH 50

struct log_entry {
    char ip_address[MAX_WORD_LENGTH];
    char date_time[MAX_WORD_LENGTH];
    char request_type[MAX_WORD_LENGTH];
    char resource[MAX_WORD_LENGTH];
    int status_code;
    int byte_count;
};

int compare_log_entries(const void* a, const void* b) {
    const struct log_entry* entry_a = a;
    const struct log_entry* entry_b = b;

    int result = strcmp(entry_a->date_time, entry_b->date_time);

    if (result == 0) {
        result = strcmp(entry_a->ip_address, entry_b->ip_address);
    }

    return result;
}

int main() {
    FILE* log_file = fopen("access.log", "r");

    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    struct log_entry log_entries[MAX_LOG_LINES];
    int num_log_entries = 0;

    while (fscanf(log_file, "%s %s %s %s %d %d\n", 
                   log_entries[num_log_entries].ip_address, 
                   log_entries[num_log_entries].date_time, 
                   log_entries[num_log_entries].request_type, 
                   log_entries[num_log_entries].resource, 
                   &log_entries[num_log_entries].status_code, 
                   &log_entries[num_log_entries].byte_count) == 6) {
        num_log_entries++;
    }

    fclose(log_file);

    qsort(log_entries, num_log_entries, sizeof(struct log_entry), compare_log_entries);

    printf("Number of log entries: %d\n", num_log_entries);

    for (int i = 0; i < num_log_entries; i++) {
        printf("%s %s %s %s %d %d\n", 
               log_entries[i].ip_address, 
               log_entries[i].date_time, 
               log_entries[i].request_type, 
               log_entries[i].resource, 
               log_entries[i].status_code, 
               log_entries[i].byte_count);
    }

    return 0;
}