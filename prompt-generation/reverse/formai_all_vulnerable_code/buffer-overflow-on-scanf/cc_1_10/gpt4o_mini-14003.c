//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define LOG_FILE "/var/log/syslog"
#define ALERT_THRESHOLD 5
#define BUFFER_SIZE 1024
#define SUSPICIOUS_KEYWORDS 4

const char *keywords[SUSPICIOUS_KEYWORDS] = {
    "failed",
    "unauthorized",
    "error",
    "warning"
};

void log_alert(const char *message) {
    FILE *alert_log = fopen("intrusion_alerts.log", "a");
    if (alert_log != NULL) {
        fprintf(alert_log, "%s\n", message);
        fclose(alert_log);
    }
}

int scan_logs() {
    int keyword_count[SUSPICIOUS_KEYWORDS] = {0};
    int total_alerts = 0;
    
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Could not open log file");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        for (int i = 0; i < SUSPICIOUS_KEYWORDS; i++) {
            if (strstr(buffer, keywords[i]) != NULL) {
                printf("Found suspicious keyword: %s in line: %s", keywords[i], buffer);
                keyword_count[i]++;
                total_alerts++;
            }
        }
    }

    fclose(file);

    return total_alerts;
}

void analyze_alerts(int total_alerts) {
    if (total_alerts >= ALERT_THRESHOLD) {
        char message[256];
        snprintf(message, sizeof(message), "Intrusion Alert! Detected %d suspicious events.", total_alerts);
        printf("%s\n", message);
        log_alert(message);
    } else {
        printf("Total suspicious events detected: %d. System safe!\n", total_alerts);
    }
}

void display_menu() {
    printf("====================================\n");
    printf("   Intrusion Detection System\n");
    printf("====================================\n");
    printf("1. Scan Logs\n");
    printf("2. Exit\n");
    printf("====================================\n");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Scanning logs..\n");
                int total_alerts = scan_logs();
                if (total_alerts >= 0) {
                    analyze_alerts(total_alerts);
                }
                break;
            }
            case 2:
                printf("Exiting the Intrusion Detection System. Stay Safe!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again!\n");
        }
    }
    return 0;
}