//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LOG_ENTRIES 1000000

typedef struct {
    char ip[16];
    char date[20];
    char time[10];
    char request[MAX_WORD_LENGTH];
    int status_code;
} LogEntry;

int compare_entries(const void *a, const void *b) {
    const LogEntry *entry1 = a;
    const LogEntry *entry2 = b;

    if (entry1->status_code > entry2->status_code) {
        return -1;
    } else if (entry1->status_code < entry2->status_code) {
        return 1;
    } else {
        return 0;
    }
}

void print_entry(LogEntry *entry) {
    printf("IP: %s\n", entry->ip);
    printf("Date: %s\n", entry->date);
    printf("Time: %s\n", entry->time);
    printf("Request: %s\n", entry->request);
    printf("Status Code: %d\n\n", entry->status_code);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    while (fscanf(log_file, "%s %s %s %s %d\n", entries[num_entries].ip, entries[num_entries].date, entries[num_entries].time, entries[num_entries].request, &entries[num_entries].status_code)!= EOF) {
        num_entries++;

        if (num_entries >= MAX_LOG_ENTRIES) {
            printf("Error: Log file is too large.\n");
            fclose(log_file);
            return 1;
        }
    }

    fclose(log_file);

    qsort(entries, num_entries, sizeof(LogEntry), compare_entries);

    for (int i = 0; i < num_entries; i++) {
        print_entry(&entries[i]);
    }

    return 0;
}