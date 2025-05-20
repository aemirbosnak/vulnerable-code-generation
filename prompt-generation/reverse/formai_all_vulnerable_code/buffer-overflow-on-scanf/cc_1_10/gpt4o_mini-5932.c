//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define TIMESTAMP_SIZE 20
#define LOG_FILE "system.log"

// Struct to represent a log entry
typedef struct {
    char timestamp[TIMESTAMP_SIZE];
    char level[10];
    char message[MAX_LOG_SIZE];
} LogEntry;

// Function to get the current timestamp in the required format
void get_current_timestamp(char* buffer) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, TIMESTAMP_SIZE, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Function to log messages
void log_message(const char *level, const char *message) {
    LogEntry entry;
    get_current_timestamp(entry.timestamp);
    strncpy(entry.level, level, sizeof(entry.level) - 1);
    strncpy(entry.message, message, sizeof(entry.message) - 1);
    
    // Open log file and append the entry
    FILE *logfile = fopen(LOG_FILE, "a");
    if (logfile == NULL) {
        perror("Could not open log file");
        return;
    }
    
    fprintf(logfile, "%s [%s]: %s\n", entry.timestamp, entry.level, entry.message);
    fclose(logfile);
}

// Function to read log from file
void read_logs() {
    char buffer[MAX_LOG_SIZE + TIMESTAMP_SIZE + 15]; // Additional space for formatting
    FILE *logfile = fopen(LOG_FILE, "r");
    if (logfile == NULL) {
        perror("Could not open log file");
        return;
    }
    
    printf("Log Entries:\n");
    while (fgets(buffer, sizeof(buffer), logfile) != NULL) {
        printf("%s", buffer);
    }
    fclose(logfile);
}

// Function to analyze logs based on severity level
void analyze_logs(const char *level) {
    char buffer[MAX_LOG_SIZE + TIMESTAMP_SIZE + 15]; // Additional space for formatting
    int count = 0;
    FILE *logfile = fopen(LOG_FILE, "r");
    if (logfile == NULL) {
        perror("Could not open log file");
        return;
    }

    printf("Analysis for logs with level [%s]:\n", level);
    while (fgets(buffer, sizeof(buffer), logfile) != NULL) {
        if (strstr(buffer, level) != NULL) {
            printf("%s", buffer);
            count++;
        }
    }
    printf("Total log entries with level [%s]: %d\n", level, count);
    fclose(logfile);
}

// Main application logic
int main() {
    int option;
    char level[10];
    char message[MAX_LOG_SIZE];

    // Display menu
    while (1) {
        printf("\nLog System Menu:\n");
        printf("1. Log Message\n");
        printf("2. Read Logs\n");
        printf("3. Analyze Logs by Level\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // Consume newline character left by scanf

        switch (option) {
            case 1:
                printf("Enter log level (INFO, WARNING, ERROR): ");
                fgets(level, sizeof(level), stdin);
                level[strcspn(level, "\n")] = 0; // Remove newline
                
                printf("Enter log message: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline
                
                log_message(level, message);
                printf("Log entry added.\n");
                break;
            case 2:
                read_logs();
                break;
            case 3:
                printf("Enter log level to analyze: ");
                fgets(level, sizeof(level), stdin);
                level[strcspn(level, "\n")] = 0; // Remove newline
                
                analyze_logs(level);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}