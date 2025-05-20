//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_IP_LENGTH 15

typedef struct log_entry {
    char ip_address[MAX_IP_LENGTH];
    char timestamp[20];
    char action[10];
} log_entry;

void log_entry_display(log_entry *entry) {
    printf("%s %s %s\n", entry->ip_address, entry->timestamp, entry->action);
}

int log_entry_compare(const void *a, const void *b) {
    log_entry *entry_a = (log_entry*) a;
    log_entry *entry_b = (log_entry*) b;
    return strcmp(entry_a->ip_address, entry_b->ip_address);
}

int main() {
    log_entry log[MAX_LOG_ENTRIES];
    int log_size = 0;

    FILE *fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file!\n");
        return 1;
    }

    char line[50];
    while (fgets(line, 50, fp)) {
        if (log_size == MAX_LOG_ENTRIES) {
            printf("Warning: Maximum log size reached!\n");
            break;
        }

        sscanf(line, "%s %s %s", log[log_size].ip_address, log[log_size].timestamp, log[log_size].action);
        log_size++;
    }
    fclose(fp);

    qsort(log, log_size, sizeof(log_entry), log_entry_compare);

    char previous_ip[MAX_IP_LENGTH] = "";
    int consecutive_count = 0;

    for (int i = 0; i < log_size; i++) {
        if (strcmp(log[i].ip_address, previous_ip) == 0) {
            consecutive_count++;
            if (consecutive_count >= 5) {
                printf("Intrusion detected!\n");
                printf("IP address: %s\n", log[i].ip_address);
                printf("Timestamp: %s\n", log[i].timestamp);
                printf("Action: %s\n", log[i].action);
                break;
            }
        }
        else {
            consecutive_count = 1;
            strcpy(previous_ip, log[i].ip_address);
        }
    }

    return 0;
}