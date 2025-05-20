//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1000000
#define MAX_LOG_ENTRY_LENGTH 1024
#define MAX_IP_LENGTH 16

// Log entry structure
typedef struct {
    char ip[MAX_IP_LENGTH];
    char method[10];
    char url[1024];
    char user_agent[2048];
    time_t timestamp;
} log_entry_t;

// Function to parse log entry from string
log_entry_t parse_log_entry(char* log_line) {
    log_entry_t entry = {0};
    char* token;
    
    // Parse IP address
    token = strtok(log_line, " ");
    strncpy(entry.ip, token, MAX_IP_LENGTH);
    
    // Parse method
    token = strtok(NULL, " ");
    strncpy(entry.method, token, 10);
    
    // Parse URL
    token = strtok(NULL, " ");
    strncpy(entry.url, token, MAX_LOG_ENTRY_LENGTH);
    
    // Parse user agent
    token = strtok(NULL, " ");
    strncpy(entry.user_agent, token, 2048);
    
    // Parse timestamp
    entry.timestamp = time(NULL);
    
    return entry;
}

// Function to print log entry
void print_log_entry(log_entry_t entry) {
    printf("IP: %s\nMethod: %s\nURL: %s\nUser Agent: %s\nTimestamp: %ld\n\n", entry.ip, entry.method, entry.url, entry.user_agent, entry.timestamp);
}

// Function to read log file and print entries
void analyze_log_file(FILE* log_file) {
    log_entry_t entry;
    char log_line[MAX_LOG_ENTRY_LENGTH];
    
    while (fgets(log_line, MAX_LOG_ENTRY_LENGTH, log_file)) {
        entry = parse_log_entry(log_line);
        print_log_entry(entry);
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }
    
    FILE* log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }
    
    analyze_log_file(log_file);
    
    fclose(log_file);
    return 0;
}