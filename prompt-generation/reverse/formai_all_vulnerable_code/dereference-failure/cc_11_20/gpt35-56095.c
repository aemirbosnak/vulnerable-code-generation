//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LENGTH 200

typedef struct log_entry {
    char timestamp[20];
    char source_ip[20];
    char message[MAX_LOG_LENGTH];
} log_entry;

int main() {
    log_entry logs[MAX_LOG_ENTRIES];
    int log_count = 0;
    char input[MAX_LOG_LENGTH];
    char *token;
    
    printf("Enter logs (exit to stop):\n");
    
    while (strcmp(input, "exit") != 0 && log_count < MAX_LOG_ENTRIES) {
        fgets(input, MAX_LOG_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;  // remove trailing newline
        
        // tokenize input and store in log_entry
        token = strtok(input, ",");
        strcpy(logs[log_count].timestamp, token);
        
        token = strtok(NULL, ",");
        strcpy(logs[log_count].source_ip, token);
        
        token = strtok(NULL, ",");
        strcpy(logs[log_count].message, token);
        
        log_count++;
    }
    
    printf("\nAnalyzing logs...\n\n");
    
    // check for repeated log messages from same IP within 5 minutes
    for (int i = 0; i < log_count; i++) {
        for (int j = i+1; j < log_count; j++) {
            if (strcmp(logs[i].source_ip, logs[j].source_ip) == 0 &&
                strcmp(logs[i].message, logs[j].message) == 0 &&
                abs(atoi(logs[i].timestamp) - atoi(logs[j].timestamp)) <= 300) {
                printf("IP %s has repeated log message '%s' within 5 minutes.\n", logs[i].source_ip, logs[i].message);
            }
        }    
    }
    
    // check for possible brute force attacks
    for (int i = 0; i < log_count; i++) {
        int failed_login_count = 0;
        if (strstr(logs[i].message, "failed login")) {
            for (int j = i-1; j >= 0; j--) {
                if (strcmp(logs[i].source_ip, logs[j].source_ip) == 0 &&
                    strcmp(logs[j].message, "failed login") == 0 &&
                    abs(atoi(logs[i].timestamp) - atoi(logs[j].timestamp)) <= 300) {
                    failed_login_count++;
                    if (failed_login_count >= 5) {
                        printf("Possible brute force attack by IP %s.\n", logs[i].source_ip);
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}