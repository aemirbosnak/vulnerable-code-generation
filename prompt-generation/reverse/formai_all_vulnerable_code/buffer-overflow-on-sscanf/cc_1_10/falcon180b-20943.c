//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 100000
#define MAX_LINE_LENGTH 512

struct log_entry {
    char ip[16];
    char date[32];
    char request[MAX_LINE_LENGTH];
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    struct log_entry entries[MAX_LOG_LINES];
    int num_entries = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_entries >= MAX_LOG_LINES) {
            printf("Error: Log file is too large.\n");
            fclose(fp);
            return 1;
        }

        struct log_entry *entry = &entries[num_entries];
        sscanf(line, "%15s %31s %511s", entry->ip, entry->date, entry->request);
        num_entries++;
    }

    fclose(fp);

    printf("IP\tDate\tRequest\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%15s\t%31s\t%s\n", entries[i].ip, entries[i].date, entries[i].request);
    }

    return 0;
}