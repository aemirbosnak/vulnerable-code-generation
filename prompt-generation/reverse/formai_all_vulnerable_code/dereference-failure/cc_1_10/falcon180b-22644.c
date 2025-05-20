//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1000

// Log entry struct
typedef struct {
    char ip[16];
    char method[10];
    char path[100];
    int status_code;
} LogEntry;

// Function to parse a log entry from a line of text
LogEntry parse_log_entry(char *line) {
    LogEntry entry;
    char *token;

    // Extract IP address
    token = strtok(line, " ");
    strncpy(entry.ip, token, sizeof(entry.ip));

    // Extract HTTP method
    token = strtok(NULL, " ");
    strncpy(entry.method, token, sizeof(entry.method));

    // Extract request path
    token = strtok(NULL, " ");
    strncpy(entry.path, token, sizeof(entry.path));

    // Extract status code
    token = strtok(NULL, " ");
    entry.status_code = atoi(token);

    return entry;
}

// Function to print a log entry
void print_log_entry(LogEntry entry) {
    printf("IP: %s\n", entry.ip);
    printf("Method: %s\n", entry.method);
    printf("Path: %s\n", entry.path);
    printf("Status code: %d\n\n", entry.status_code);
}

// Function to analyze log file and print statistics
void analyze_log_file(FILE *log_file) {
    int num_entries = 0;
    LogEntry prev_entry = {0};
    int num_404s = 0;

    // Read log file line by line
    char line[MAX_LOG_ENTRY_LENGTH];
    while (fgets(line, sizeof(line), log_file)!= NULL) {
        // Parse log entry from line
        LogEntry entry = parse_log_entry(line);

        // Increment number of entries
        num_entries++;

        // Check for 404 status codes
        if (entry.status_code == 404) {
            num_404s++;
        }

        // Print log entry
        print_log_entry(entry);
    }

    // Print statistics
    printf("Total number of entries: %d\n", num_entries);
    printf("Number of 404s: %d\n", num_404s);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    // Open log file for reading
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    // Analyze log file
    analyze_log_file(log_file);

    // Close log file
    fclose(log_file);

    return 0;
}