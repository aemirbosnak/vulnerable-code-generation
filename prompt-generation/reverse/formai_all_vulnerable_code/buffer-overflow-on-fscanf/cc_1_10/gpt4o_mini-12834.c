//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define LOG_FILE "access.log"
#define ALERT_THRESHOLD 5

typedef struct {
    char username[50];
    time_t timestamp;
    int failed_attempts;
} AccessLog;

void analyze_logs(AccessLog *log, int count) {
    int alert_count = 0;

    for (int i = 0; i < count; i++) {
        if (log[i].failed_attempts >= ALERT_THRESHOLD) {
            alert_count++;
            printf("ALERT: User '%s' has triggered a security alert with %d failed attempts at %s\n",
                log[i].username, log[i].failed_attempts, ctime(&(log[i].timestamp)));
        }
    }

    if (alert_count == 0) {
        printf("No security alerts. All access attempts are within normal parameters.\n");
    }
}

void monitor_access_log() {
    FILE *file;
    AccessLog logs[100];
    int log_count = 0;

    while (1) {
        file = fopen(LOG_FILE, "r");
        if (file == NULL) {
            perror("Failed to open the log file");
            return;
        }

        while (fscanf(file, "%49s %ld %d", logs[log_count].username, &logs[log_count].timestamp, &logs[log_count].failed_attempts) == 3) {
            log_count++;
        }

        analyze_logs(logs, log_count);
        
        fclose(file);
        sleep(10);  // Monitor the log every 10 seconds
        log_count = 0; // Reset log count for the next iteration
    }
}

int main() {
    printf("Initiating Intrusion Detection System...\n");
    printf("Monitoring for unauthorized access attempts...\n");
    monitor_access_log();
    return 0;
}