//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LOG_SIZE 1000000
#define MAX_WORD_LENGTH 50
#define MAX_IP_LENGTH 16

struct log_entry {
    char ip[MAX_IP_LENGTH];
    char date[20];
    char request[MAX_LOG_SIZE];
};

void read_log_file(FILE *log_file, struct log_entry *log_entries, int *num_entries) {
    char line[MAX_LOG_SIZE];
    int i = 0;

    while (fgets(line, MAX_LOG_SIZE, log_file)!= NULL) {
        if (i >= MAX_LOG_SIZE) {
            printf("Log file too large!\n");
            exit(1);
        }

        struct log_entry entry;
        sscanf(line, "%s %s %s", entry.ip, entry.date, entry.request);

        strcpy(log_entries[i].ip, entry.ip);
        strcpy(log_entries[i].date, entry.date);
        strcpy(log_entries[i].request, entry.request);

        i++;
        (*num_entries)++;
    }
}

int compare_entries(const void *a, const void *b) {
    struct log_entry entry1 = *(struct log_entry *)a;
    struct log_entry entry2 = *(struct log_entry *)b;

    int result = strcmp(entry1.ip, entry2.ip);

    if (result == 0) {
        result = strcmp(entry1.date, entry2.date);
    }

    return result;
}

void print_entries(struct log_entry *log_entries, int num_entries) {
    qsort(log_entries, num_entries, sizeof(struct log_entry), compare_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s\n", log_entries[i].ip, log_entries[i].date, log_entries[i].request);
    }
}

int main() {
    FILE *log_file;
    char log_filename[100];
    int num_entries = 0;

    printf("Enter log file name: ");
    scanf("%s", log_filename);

    log_file = fopen(log_filename, "r");

    if (log_file == NULL) {
        printf("Cannot open log file!\n");
        exit(1);
    }

    struct log_entry log_entries[MAX_LOG_SIZE];

    read_log_file(log_file, log_entries, &num_entries);

    fclose(log_file);

    printf("Total number of entries: %d\n", num_entries);
    print_entries(log_entries, num_entries);

    return 0;
}