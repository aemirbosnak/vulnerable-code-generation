//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 50

struct entry {
    char ip[MAX_ENTRY_LENGTH];
    int count;
};

int main() {
    FILE *fp;
    char line[MAX_ENTRY_LENGTH];
    struct entry entries[MAX_ENTRIES];
    int num_entries = 0;

    fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open logfile.\n");
        return 1;
    }

    while (fgets(line, MAX_ENTRY_LENGTH, fp)!= NULL) {
        char *ip = strtok(line, " ");
        if (ip == NULL) {
            continue;
        }

        struct entry *entry = NULL;
        for (int i = 0; i < num_entries; i++) {
            if (strcmp(entries[i].ip, ip) == 0) {
                entry = &entries[i];
                break;
            }
        }

        if (entry == NULL) {
            if (num_entries >= MAX_ENTRIES) {
                printf("Error: Too many unique IPs.\n");
                return 1;
            }

            strcpy(entry->ip, ip);
            entry->count = 1;
            entries[num_entries++] = *entry;
        } else {
            entry->count++;
        }
    }

    fclose(fp);

    printf("IP Address\tCount\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s\t%d\n", entries[i].ip, entries[i].count);
    }

    return 0;
}