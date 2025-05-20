//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold log information
struct log_info {
    char log_type[50];
    char timestamp[50];
    char message[100];
};

// Function to parse a log entry and store its information in a log_info structure
void parse_log_entry(struct log_info* log_info, char* entry) {
    char* log_type_start = strstr(entry, "Log Type: ");
    char* timestamp_start = strstr(entry, "Timestamp: ");
    char* message_start = strstr(entry, "Message: ");

    // Check if all three fields exist
    if (log_type_start!= NULL && timestamp_start!= NULL && message_start!= NULL) {
        // Copy the log type, timestamp, and message into the log_info structure
        strncpy(log_info->log_type, log_type_start + 8, 50);
        strncpy(log_info->timestamp, timestamp_start + 11, 50);
        strncpy(log_info->message, message_start + 11, 100);
    }
}

// Function to print a log entry
void print_log_entry(struct log_info* log_info) {
    printf("Log Type: %s\n", log_info->log_type);
    printf("Timestamp: %s\n", log_info->timestamp);
    printf("Message: %s\n", log_info->message);
}

// Main function
int main() {
    // Create an array to hold log entries
    struct log_info log_entries[100];

    // Read in log entries from the console
    char entry[1000];
    for (int i = 0; i < 100; i++) {
        printf("Enter log entry %d:\n", i + 1);
        scanf("%s", entry);
        parse_log_entry(&log_entries[i], entry);
    }

    // Print the log entries
    for (int i = 0; i < 100; i++) {
        print_log_entry(&log_entries[i]);
    }

    return 0;
}