//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 10000
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    char ip_address[16];
    char date_time[32];
    char request_url[MAX_LOG_ENTRY_LENGTH];
    char response_code[10];
    int response_size;
} log_entry;

int main() {
    FILE *log_file;
    log_entry log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;
    char line[MAX_LOG_ENTRY_LENGTH];
    char *delimiter = " ";

    // Open the log file for reading
    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        exit(1);
    }

    // Read each line of the log file and parse it into a log_entry struct
    while (fgets(line, MAX_LOG_ENTRY_LENGTH, log_file)!= NULL) {
        log_entry entry;
        int i = 0;

        // Parse the IP address from the line
        char *ip_ptr = strtok(line, delimiter);
        strncpy(entry.ip_address, ip_ptr, sizeof(entry.ip_address));

        // Parse the date and time from the line
        ip_ptr = strtok(NULL, delimiter);
        strncpy(entry.date_time, ip_ptr, sizeof(entry.date_time));

        // Parse the request URL from the line
        ip_ptr = strtok(NULL, delimiter);
        strncpy(entry.request_url, ip_ptr, sizeof(entry.request_url));

        // Parse the response code from the line
        ip_ptr = strtok(NULL, delimiter);
        strncpy(entry.response_code, ip_ptr, sizeof(entry.response_code));

        // Parse the response size from the line
        ip_ptr = strtok(NULL, delimiter);
        entry.response_size = atoi(ip_ptr);

        // Add the log entry to the array
        log_entries[num_entries++] = entry;
    }

    // Close the log file
    fclose(log_file);

    // Print the log entries
    for (int i = 0; i < num_entries; i++) {
        printf("IP Address: %s\n", log_entries[i].ip_address);
        printf("Date and Time: %s\n", log_entries[i].date_time);
        printf("Request URL: %s\n", log_entries[i].request_url);
        printf("Response Code: %s\n", log_entries[i].response_code);
        printf("Response Size: %d\n\n", log_entries[i].response_size);
    }

    return 0;
}