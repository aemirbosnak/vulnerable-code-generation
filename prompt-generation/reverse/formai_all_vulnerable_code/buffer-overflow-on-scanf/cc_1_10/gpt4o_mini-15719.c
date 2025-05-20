//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LOG_ENTRIES 1000
#define LOG_FILE "intrusion_log.txt"

typedef struct {
    time_t timestamp;
    char ip_address[16];
    char action[50];
} LogEntry;

LogEntry intrusion_logs[MAX_LOG_ENTRIES];
int log_count = 0;

void log_entry(const char *ip_address, const char *action) {
    if (log_count >= MAX_LOG_ENTRIES) {
        printf("Log is full, unable to log new entries.\n");
        return;
    }

    intrusion_logs[log_count].timestamp = time(NULL);
    strncpy(intrusion_logs[log_count].ip_address, ip_address, sizeof(intrusion_logs[log_count].ip_address) - 1);
    strncpy(intrusion_logs[log_count].action, action, sizeof(intrusion_logs[log_count].action) - 1);

    log_count++;

    // Append log to the log file
    FILE *file = fopen(LOG_FILE, "a");
    if (file) {
        fprintf(file, "[%ld] %s: %s\n", intrusion_logs[log_count - 1].timestamp, intrusion_logs[log_count - 1].ip_address, intrusion_logs[log_count - 1].action);
        fclose(file);
    } else {
        perror("Failed to open log file");
    }
}

void detect_intrusion(const char *ip_address) {
    // A simple intrusion detection logic.
    if (strcmp(ip_address, "192.168.1.1") == 0) { // Example for blacklisted IP
        log_entry(ip_address, "Blocked access attempt");
        printf("Intrusion detected from %s! Action logged.\n", ip_address);
    } else {
        printf("Access granted for %s.\n", ip_address);
    }
}

void print_log() {
    printf("Intrusion Log Entries:\n");
    for (int i = 0; i < log_count; i++) {
        printf("[%ld] %s: %s\n", intrusion_logs[i].timestamp, intrusion_logs[i].ip_address, intrusion_logs[i].action);
    }
}

void clear_log() {
    log_count = 0;
    remove(LOG_FILE);
    printf("Log cleared.\n");
}

int main() {
    char ip_address[16];
    int choice;

    while (1) {
        printf("1. Check access\n");
        printf("2. Print logs\n");
        printf("3. Clear logs\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter IP address to check: ");
                scanf("%15s", ip_address);
                detect_intrusion(ip_address);
                break;
            case 2:
                print_log();
                break;
            case 3:
                clear_log();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}