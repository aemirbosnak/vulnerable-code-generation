//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 100
#define LOG_ENTRY_SIZE 256

// Struct to hold network log data
typedef struct {
    char timestamp[20];
    char ip_address[16];
    char action[30];
} LogEntry;

// An array to hold logs of network activity
LogEntry log_entries[MAX_LOG_ENTRIES];
int log_count = 0;

// Function to get the current timestamp
void get_current_time(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Function to log network activity
void log_activity(const char *ip, const char *action) {
    if (log_count < MAX_LOG_ENTRIES) {
        get_current_time(log_entries[log_count].timestamp, sizeof(log_entries[log_count].timestamp));
        strncpy(log_entries[log_count].ip_address, ip, sizeof(log_entries[log_count].ip_address) - 1);
        strncpy(log_entries[log_count].action, action, sizeof(log_entries[log_count].action) - 1);
        log_count++;
    } else {
        printf("Log capacity reached. Unable to log more entries.\n");
    }
}

// Function to display logs
void display_logs() {
    if (log_count == 0) {
        printf("No logs to display.\n");
        return;
    }
    
    printf("\n--- Network Activity Log ---\n");
    for (int i = 0; i < log_count; i++) {
        printf("%s | %s | %s\n", log_entries[i].timestamp, log_entries[i].ip_address, log_entries[i].action);
    }
    printf("-----------------------------\n");
}

// Function to simulate an intrusion attempt
void simulate_intrusion(const char *ip) {
    log_activity(ip, "Intrusion Attempt Detected");
    printf("Alert! Intrusion attempt from: %s\n", ip);
}

// Function to simulate normal activity
void simulate_normal_activity(const char *ip) {
    log_activity(ip, "Normal Activity");
    printf("Network activity from: %s\n", ip);
}

int main() {
    char input_ip[16];
    char action;
    
    printf("Welcome to the Artistic Intrusion Detection System!\n");
    
    while (1) {
        printf("Enter IP address (or type 'exit' to quit): ");
        scanf("%s", input_ip);
        
        if (strcmp(input_ip, "exit") == 0) {
            break;
        }

        printf("Choose action for %s (i for intrusion, n for normal): ", input_ip);
        scanf(" %c", &action);

        if (action == 'i') {
            simulate_intrusion(input_ip);
        } else if (action == 'n') {
            simulate_normal_activity(input_ip);
        } else {
            printf("Invalid action. Please enter 'i' or 'n'.\n");
        }
        
        display_logs();
    }

    printf("Exiting the Artistic Intrusion Detection System. Bye!\n");
    return 0;
}