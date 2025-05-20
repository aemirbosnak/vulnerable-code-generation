//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000  // Maximum number of system events that can be logged
#define MAX_USERNAME_LEN 20   // Maximum length of a username
#define MAX_IP_ADDR_LEN 16    // Maximum length of an IP address

// Struct to hold information about a single system event (i.e., a login attempt)
typedef struct {
    char username[MAX_USERNAME_LEN];
    char ip_addr[MAX_IP_ADDR_LEN];
    char result[10];
} log_entry;

// Function to search the log for suspicious activity (i.e., multiple failed login attempts from the same IP address)
void search_for_suspicious_activity(log_entry log[], int num_entries) {
    int i, j, num_failed_attempts;
    char cur_ip[MAX_IP_ADDR_LEN], last_ip[MAX_IP_ADDR_LEN];

    // Sort the log entries by IP address
    for (i=0; i<num_entries-1; i++) {
        for (j=i+1; j<num_entries; j++) {
            if (strcmp(log[i].ip_addr, log[j].ip_addr) > 0) {
                log_entry temp_entry = log[i];
                log[i] = log[j];
                log[j] = temp_entry;
            }
        }
    }

    // Search for multiple failed login attempts from the same IP address
    num_failed_attempts = 0;
    strcpy(last_ip, "");
    for (i=0; i<num_entries; i++) {
        strcpy(cur_ip, log[i].ip_addr);
        if (strcmp(log[i].result, "FAIL") == 0) {
            if (strcmp(last_ip, "") == 0 || strcmp(cur_ip, last_ip) != 0) {
                // This is the first failed attempt from this IP address; reset the counter
                num_failed_attempts = 1;
            } else {
                // This is another failed attempt from the same IP address; increment the counter
                num_failed_attempts++;
                if (num_failed_attempts >= 5) {
                    // The same IP address has attempted to log in unsuccessfully 5 or more times; alert the user
                    printf("Suspicious activity detected from IP address %s\n", cur_ip);
                }
            }
            strcpy(last_ip, cur_ip);
        } else {
            // Successful login attempt; reset the counter
            num_failed_attempts = 0;
        }
    }
}

int main() {
    log_entry log[MAX_LOG_ENTRIES];
    int num_entries;
    char input_line[100];

    // Parse the log file to build the log array
    num_entries = 0;
    while (fgets(input_line, 100, stdin) != NULL) {
        sscanf(input_line, "%s %s %s", log[num_entries].username, log[num_entries].ip_addr, log[num_entries].result);
        num_entries++;
        if (num_entries >= MAX_LOG_ENTRIES) {
            // The log array is full; stop parsing the file
            break;
        }
    }

    // Search for suspicious activity in the log
    search_for_suspicious_activity(log, num_entries);

    return 0;
}