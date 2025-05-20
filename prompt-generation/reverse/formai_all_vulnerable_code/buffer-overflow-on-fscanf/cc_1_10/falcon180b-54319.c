//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_ENTRIES 1000

/* Struct to hold log entry data */
typedef struct {
    char ip[16];
    char date[20];
    char time[10];
    char url[100];
    int status_code;
} LogEntry;

/* Function to compare two log entries based on their IP addresses */
int compare_entries(const void *a, const void *b) {
    const LogEntry *entry_a = (const LogEntry *)a;
    const LogEntry *entry_b = (const LogEntry *)b;

    return strcmp(entry_a->ip, entry_b->ip);
}

/* Function to print the log entries in a sorted order */
void print_log_entries(LogEntry entries[], int num_entries) {
    qsort(entries, num_entries, sizeof(LogEntry), compare_entries);

    for (int i = 0; i < num_entries; i++) {
        printf("%s - %s %s - %s - %d\n", entries[i].ip, entries[i].date, entries[i].time, entries[i].url, entries[i].status_code);
    }
}

/* Function to read log entries from a file */
int read_log_file(const char *filename, LogEntry entries[], int max_entries) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open log file.\n");
        return 1;
    }

    int num_entries = 0;

    while (fscanf(file, "%s %s %s %s %d\n", entries[num_entries].ip, entries[num_entries].date, entries[num_entries].time, entries[num_entries].url, &entries[num_entries].status_code)!= EOF) {
        num_entries++;

        if (num_entries >= max_entries) {
            printf("Warning: Reached maximum number of log entries.\n");
            break;
        }
    }

    fclose(file);

    return 0;
}

int main() {
    LogEntry entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    /* Read the log file */
    if (read_log_file("logfile.txt", entries, MAX_LOG_ENTRIES)!= 0) {
        return 1;
    }

    /* Print the log entries in a sorted order */
    print_log_entries(entries, num_entries);

    return 0;
}