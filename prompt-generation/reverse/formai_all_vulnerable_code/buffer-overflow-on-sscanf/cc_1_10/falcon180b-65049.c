//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_SIZE 1024

typedef struct {
    char ip[16];
    char method[8];
    char url[512];
    char user_agent[512];
    int status_code;
    char timestamp[32];
} log_entry;

int compare_log_entries(const void *a, const void *b) {
    const log_entry *entry_a = (const log_entry *)a;
    const log_entry *entry_b = (const log_entry *)b;

    int cmp = strcmp(entry_a->ip, entry_b->ip);
    if (cmp!= 0) {
        return cmp;
    }

    cmp = strcmp(entry_a->url, entry_b->url);
    if (cmp!= 0) {
        return cmp;
    }

    return 0;
}

int main() {
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_log_entries = 0;

    char line[MAX_LOG_ENTRY_SIZE];
    while (fgets(line, MAX_LOG_ENTRY_SIZE, stdin)!= NULL) {
        if (num_log_entries >= MAX_LOG_ENTRIES) {
            printf("log is full. cannot store more entries.\n");
            break;
        }

        log_entry entry;
        sscanf(line, "%15s %7s %511s %511s %d %31s", entry.ip, entry.method, entry.url, entry.user_agent, &entry.status_code, entry.timestamp);
        strncpy(entry.ip, line, 16); // copy the ip address from the log line
        entry.ip[15] = '\0'; // null terminate the ip address

        qsort(log_entries, num_log_entries, sizeof(log_entry), compare_log_entries);
        log_entries[num_log_entries++] = entry;
    }

    qsort(log_entries, num_log_entries, sizeof(log_entry), compare_log_entries);

    printf("sherlock holmes' intrusion detection system\n");
    printf("=========================================\n");

    for (int i = 0; i < num_log_entries; i++) {
        log_entry entry = log_entries[i];
        printf("%-15s %-7s %-20s %-20s %d %s\n", entry.ip, entry.method, entry.url, entry.user_agent, entry.status_code, entry.timestamp);
    }

    return 0;
}