//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of log entries to analyze
#define MAX_ENTRIES 1000

// Define the structure for each log entry
typedef struct {
    char ip_address[16];
    char date_time[32];
    char method[10];
    char url[256];
    int status_code;
} log_entry;

// Function to compare the status codes of two log entries
int compare_status_codes(const void *a, const void *b) {
    const log_entry *entry_a = (const log_entry *)a;
    const log_entry *entry_b = (const log_entry *)b;
    return entry_a->status_code - entry_b->status_code;
}

// Function to read the log file and store the entries in an array
int read_log_file(log_entry entries[], FILE *file) {
    int count = 0;
    char line[512];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (count >= MAX_ENTRIES) {
            printf("Maximum number of entries reached.\n");
            break;
        }
        char *token = strtok(line, " ");
        strcpy(entries[count].ip_address, token);
        token = strtok(NULL, " ");
        strcpy(entries[count].date_time, token);
        token = strtok(NULL, " ");
        strcpy(entries[count].method, token);
        token = strtok(NULL, " ");
        strcpy(entries[count].url, token);
        entries[count].status_code = atoi(strtok(NULL, " "));
        count++;
    }
    return count;
}

// Function to display the log entries sorted by status code
void display_log_entries(log_entry entries[], int count) {
    qsort(entries, count, sizeof(log_entry), compare_status_codes);
    printf("IP Address\tDate/Time\tMethod\tURL\tStatus Code\n");
    for (int i = 0; i < count; i++) {
        printf("%-16s %-24s %-8s %-32s %d\n", entries[i].ip_address, entries[i].date_time, entries[i].method, entries[i].url, entries[i].status_code);
    }
}

int main() {
    FILE *file;
    log_entry entries[MAX_ENTRIES];
    int count;

    // Open the log file for reading
    file = fopen("logfile.txt", "r");
    if (file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    // Read the log entries from the file
    count = read_log_file(entries, file);

    // Display the log entries sorted by status code
    if (count > 0) {
        display_log_entries(entries, count);
    }

    fclose(file);
    return 0;
}