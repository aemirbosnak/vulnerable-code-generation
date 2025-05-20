//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

#define LOG_FILE "ids_log.txt"
#define MAX_LOG_SIZE 1024
#define THRESHOLD 5

typedef struct {
    int event_id;
    char event_type[50];
    char timestamp[20];
    char details[100];
} LogEntry;

void log_event(LogEntry log_entry) {
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        perror("Failed to open log file");
        return;
    }
    fprintf(logfile, "Event ID: %d\nType: %s\nTime: %s\nDetails: %s\n\n",
            log_entry.event_id, log_entry.event_type, log_entry.timestamp, log_entry.details);
    fclose(logfile);
}

void get_current_timestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", t);
}

void write_alert(const char *alert_message) {
    printf("\nALERT: %s\n", alert_message);
    // In a real scenario, you might notify administrators via email or SMS
}

int detect_intrusion(int login_attempts, const char *ip_address) {
    if (login_attempts > THRESHOLD) {
        char alert_message[100];
        snprintf(alert_message, sizeof(alert_message), "Too many login attempts from IP: %s", ip_address);
        write_alert(alert_message);
        return 1; // Intrusion detected
    }
    return 0; // No intrusion
}

void simulate_login_attempts() {
    int login_attempts = 0;
    char ip_address[16];
    char timestamp[20];

    printf("Enter IP Address of the user: ");
    scanf("%s", ip_address);

    while (1) {
        printf("Simulate a login attempt? (y/n): ");
        char response;
        scanf(" %c", &response);

        if (response == 'n' || response == 'N') {
            break;
        }

        login_attempts++;
        LogEntry log_entry;
        log_entry.event_id = login_attempts;
        strcpy(log_entry.event_type, "Login Attempt");
        get_current_timestamp(timestamp);
        strcpy(log_entry.timestamp, timestamp);
        snprintf(log_entry.details, sizeof(log_entry.details), "IP: %s - Attempt #%d", ip_address, login_attempts);

        log_event(log_entry);

        if (detect_intrusion(login_attempts, ip_address)) {
            printf("Intrusion detected! Locking the account...\n");
            break;
        } else {
            printf("Login attempt #%d recorded.\n", login_attempts);
        }
    }
}

void view_log() {
    printf("\nGenerating log report...\n");
    FILE *logfile = fopen(LOG_FILE, "r");
    if (logfile == NULL) {
        perror("Failed to open log file");
        return;
    }
    
    char buffer[MAX_LOG_SIZE];
    while (fgets(buffer, sizeof(buffer), logfile) != NULL) {
        printf("%s", buffer);
    }
    fclose(logfile);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Intrusion Detection System ===\n");
        printf("1. Simulate Login Attempts\n");
        printf("2. View Log\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                simulate_login_attempts();
                break;
            case 2:
                view_log();
                break;
            case 3:
                printf("Exiting system.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}