//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LINE_LENGTH 1024

typedef struct {
    char ip[16];
    char date_time[32];
    char request[MAX_LOG_LINE_LENGTH];
    int response_code;
} log_entry;

int compare_entries(const void *a, const void *b) {
    const log_entry *entry1 = a;
    const log_entry *entry2 = b;

    if (entry1->response_code > entry2->response_code) {
        return -1;
    } else if (entry1->response_code < entry2->response_code) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", argv[1]);
        exit(1);
    }

    log_entry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    while (fscanf(log_file, "%15s %31s %[^\r\n] %d\r\n", entries[num_entries].ip, entries[num_entries].date_time, entries[num_entries].request, &entries[num_entries].response_code) == 4) {
        num_entries++;

        if (num_entries == MAX_LOG_ENTRIES) {
            break;
        }
    }

    fclose(log_file);

    qsort(entries, num_entries, sizeof(log_entry), compare_entries);

    printf("IP\tDate/Time\tRequest\tResponse Code\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%15s %31s %s %d\n", entries[i].ip, entries[i].date_time, entries[i].request, entries[i].response_code);
    }

    return 0;
}