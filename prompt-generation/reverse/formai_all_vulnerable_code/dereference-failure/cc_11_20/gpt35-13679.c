//FormAI DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_MSG_LEN 256
#define MAX_NUM_LOG_ENTRIES 1000

/* define a structure to hold each log entry */
typedef struct log_entry_t {
    char msg[MAX_LOG_MSG_LEN];
    unsigned int timestamp;
} log_entry;

int main() {
    /* allocate memory for an array of log_entry structs */
    log_entry* log_entries = (log_entry*) malloc(MAX_NUM_LOG_ENTRIES * sizeof(log_entry));
    if (log_entries == NULL) {
        fprintf(stderr, "Failed to allocate memory for log entries\n");
        return 1;
    }

    /* read in log entries from a file */
    FILE* fp = fopen("log.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open log file\n");
        return 1;
    }

    unsigned int num_entries = 0;
    char line[MAX_LOG_MSG_LEN];
    while (fgets(line, MAX_LOG_MSG_LEN, fp) != NULL && num_entries < MAX_NUM_LOG_ENTRIES) {
        /* remove trailing newline character */
        line[strcspn(line, "\n")] = 0;

        /* parse timestamp from line */
        char* timestamp_str = strtok(line, ",");
        if (timestamp_str == NULL) {
            fprintf(stderr, "Failed to parse timestamp from line\n");
            continue;
        }
        unsigned int timestamp = atoi(timestamp_str);

        /* copy message into log entry struct */
        char* msg_str = strtok(NULL, ",");
        if (msg_str == NULL) {
            fprintf(stderr, "Failed to parse message from line\n");
            continue;
        }
        strncpy(log_entries[num_entries].msg, msg_str, MAX_LOG_MSG_LEN);

        /* add timestamp to log entry struct */
        log_entries[num_entries].timestamp = timestamp;

        num_entries++;
    }

    fclose(fp);

    /* sort log entries in ascending order by timestamp using bubble sort */
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < num_entries - 1; i++) {
            if (log_entries[i].timestamp > log_entries[i+1].timestamp) {
                log_entry temp = log_entries[i];
                log_entries[i] = log_entries[i+1];
                log_entries[i+1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);

    /* print out log entries in chronological order */
    for (int i = 0; i < num_entries; i++) {
        printf("[%u] %s\n", log_entries[i].timestamp, log_entries[i].msg);
    }

    /* free memory allocated for log entries */
    free(log_entries);

    return 0;
}