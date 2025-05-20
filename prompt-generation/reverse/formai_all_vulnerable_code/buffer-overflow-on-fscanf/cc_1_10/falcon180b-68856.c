//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 10000
#define MAX_LOG_ENTRY_LENGTH 512

struct log_entry {
    char message[MAX_LOG_ENTRY_LENGTH];
    time_t timestamp;
};

int main() {
    FILE *log_file;
    char log_filename[100] = "log.txt";
    struct log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;
    int i;
    time_t current_time;

    // Open the log file
    log_file = fopen(log_filename, "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    // Read in the log entries
    while (fscanf(log_file, "%s %ld\n", log_entries[num_entries].message, &log_entries[num_entries].timestamp)!= EOF) {
        num_entries++;
        if (num_entries == MAX_LOG_ENTRIES) {
            printf("Log file contains too many entries.\n");
            exit(1);
        }
    }

    // Sort the log entries by timestamp
    for (i = 0; i < num_entries - 1; i++) {
        if (log_entries[i].timestamp > log_entries[i+1].timestamp) {
            struct log_entry temp = log_entries[i];
            log_entries[i] = log_entries[i+1];
            log_entries[i+1] = temp;
        }
    }

    // Print the sorted log entries
    printf("Sorted log entries:\n");
    for (i = 0; i < num_entries; i++) {
        current_time = log_entries[i].timestamp;
        strftime(log_entries[i].message, MAX_LOG_ENTRY_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&current_time));
        printf("%s\n", log_entries[i].message);
    }

    // Close the log file
    fclose(log_file);

    return 0;
}